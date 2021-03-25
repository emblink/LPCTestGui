/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_host_config.h"
#include "usb_host.h"
#include "usb_host_hid.h"
#include "host_hid_generic.h"
#include "app.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief host hid generic control transfer callback.
 *
 * This function is used as callback function for control transfer .
 *
 * @param param      the host hid generic instance pointer.
 * @param data       data buffer pointer.
 * @param dataLength data length.
 * @status           transfer result status.
 */
static void USB_HostHidControlCallback(void *param, uint8_t *data, uint32_t dataLength, usb_status_t status);

/*!
 * @brief host hid generic interrupt in transfer callback.
 *
 * This function is used as callback function when call USB_HostHidRecv .
 *
 * @param param      the host hid generic instance pointer.
 * @param data       data buffer pointer.
 * @param dataLength data length.
 * @status           transfer result status.
 */
static void USB_HostHidInCallback(void *param, uint8_t *data, uint32_t dataLength, usb_status_t status);

/*******************************************************************************
 * Variables
 ******************************************************************************/

usb_host_hid_generic_instance_t g_HostHidGeneric[USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE]; /* hid generic instance */
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
uint8_t s_GenericInBuffer[USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE][HID_GENERIC_IN_BUFFER_SIZE]; /*!< use to receive report descriptor and data */
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
uint8_t s_GenericOutBuffer[USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE][HID_GENERIC_OUT_BUFFER_SIZE]; /*!< use to send data */

/*******************************************************************************
 * Code
 ******************************************************************************/

static void USB_HostHidControlCallback(void *param, uint8_t *data, uint32_t dataLength, usb_status_t status)
{
    usb_host_hid_generic_instance_t *genericInstance = (usb_host_hid_generic_instance_t *)param;

    if (kStatus_USB_TransferStall == status)
    {
        // usb_echo("device don't support this ruquest \r\n");
    }
    else if (kStatus_USB_Success != status)
    {
        usb_echo("control transfer failed\r\n");
    }
    else
    {
    }

    if (genericInstance->runWaitState == kUSB_HostHidRunWaitSetInterface) /* set interface finish */
    {
        genericInstance->runState = kUSB_HostHidRunSetInterfaceDone;
    }
    else if (genericInstance->runWaitState == kUSB_HostHidRunWaitSetIdle) /* hid set idle finish */
    {
        genericInstance->runState = kUSB_HostHidRunSetIdleDone;
    }
    else if (genericInstance->runWaitState ==
             kUSB_HostHidRunWaitGetReportDescriptor) /* hid get report descriptor finish */
    {
        onGetReportDescriptor(data, dataLength, genericInstance);
        genericInstance->runState = kUSB_HostHidRunGetReportDescriptorDone;
    }
    else if (genericInstance->runWaitState == kUSB_HostHidRunWaitSetProtocol) /* hid set protocol finish */
    {
        genericInstance->runState = kUSB_HostHidRunSetProtocolDone;
        onUsbConfigured(true);
    }
    else
    {
    }
}

static void USB_HostHidInCallback(void *param, uint8_t *data, uint32_t dataLength, usb_status_t status)
{
    usb_host_hid_generic_instance_t *genericInstance = (usb_host_hid_generic_instance_t *)param;
    onReportReceived(data, dataLength, genericInstance);

    if (genericInstance->runWaitState == kUSB_HostHidRunWaitDataReceived)
    {
        if (status == kStatus_USB_Success)
        {
            genericInstance->runState = kUSB_HostHidRunDataReceived; /* go to process data */
        }
        else
        {
            if (genericInstance->deviceState == kStatus_DEV_Attached)
            {
                genericInstance->runState = kUSB_HostHidRunPrimeDataReceive; /* go to prime next receiving */
            }
        }
    }
}

void USB_HostHidGenericTask(void *param)
{
    usb_host_hid_descriptor_t *hidDescriptor;
    uint32_t hidReportLength = 0;
    uint8_t *descriptor;
    uint32_t endPosition;
    usb_host_hid_generic_instance_t *genericInstance = (usb_host_hid_generic_instance_t *)param;

    /* device state changes, process once for each state */
    if (genericInstance->deviceState != genericInstance->prevState)
    {
        genericInstance->prevState = genericInstance->deviceState;
        switch (genericInstance->deviceState)
        {
            case kStatus_DEV_Idle:
                break;

            case kStatus_DEV_Attached: /* deivce is attached and numeration is done */
                genericInstance->runState = kUSB_HostHidRunSetInterface;
                if (USB_HostHidInit(genericInstance->deviceHandle, &genericInstance->classHandle) !=
                    kStatus_USB_Success)
                {
                    usb_echo("host hid class initialize fail\r\n");
                }
                else
                {
                    // usb_echo("hid generic attached\r\n");
                }
                genericInstance->sendIndex = 0;
                break;

            case kStatus_DEV_Detached: /* device is detached */
                genericInstance->deviceState = kStatus_DEV_Idle;
                genericInstance->runState    = kUSB_HostHidRunIdle;
                USB_HostHidDeinit(genericInstance->deviceHandle, genericInstance->classHandle);
                genericInstance->classHandle = NULL;
                usb_echo("hid generic detached\r\n");
                onUsbConfigured(false);
                break;

            default:
                break;
        }
    }

    /* run state */
    switch (genericInstance->runState)
    {
        case kUSB_HostHidRunIdle:
            break;

        case kUSB_HostHidRunSetInterface: /* 1. set hid interface */
            genericInstance->runWaitState = kUSB_HostHidRunWaitSetInterface;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            if (USB_HostHidSetInterface(genericInstance->classHandle, genericInstance->interfaceHandle, 0,
                                        USB_HostHidControlCallback, genericInstance) != kStatus_USB_Success)
            {
                usb_echo("set interface error\r\n");
            }
            break;

        case kUSB_HostHidRunSetInterfaceDone: /* 2. hid set idle */
            genericInstance->inMaxPacketSize =
                USB_HostHidGetPacketsize(genericInstance->classHandle, USB_ENDPOINT_INTERRUPT, USB_IN);
            genericInstance->outMaxPacketSize =
                USB_HostHidGetPacketsize(genericInstance->classHandle, USB_ENDPOINT_INTERRUPT, USB_OUT);

            /* first: set idle */
            genericInstance->runWaitState = kUSB_HostHidRunWaitSetIdle;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            if (USB_HostHidSetIdle(genericInstance->classHandle, 0, 0, USB_HostHidControlCallback, genericInstance) !=
                kStatus_USB_Success)
            {
                usb_echo("Error in USB_HostHidSetIdle\r\n");
            }
            break;

        case kUSB_HostHidRunSetIdleDone: /* 3. hid get report descriptor */
            /* get report descriptor's length */
            hidDescriptor = NULL;
            descriptor    = (uint8_t *)((usb_host_interface_t *)genericInstance->interfaceHandle)->interfaceExtension;
            endPosition   = (uint32_t)descriptor +
                          ((usb_host_interface_t *)genericInstance->interfaceHandle)->interfaceExtensionLength;

            while ((uint32_t)descriptor < endPosition)
            {
                if (*(descriptor + 1) == USB_DESCRIPTOR_TYPE_HID) /* descriptor type */
                {
                    hidDescriptor = (usb_host_hid_descriptor_t *)descriptor;
                    break;
                }
                else
                {
                    descriptor = (uint8_t *)((uint32_t)descriptor + (*descriptor)); /* next descriptor */
                }
            }

            if (hidDescriptor != NULL)
            {
                usb_host_hid_class_descriptor_t *hidClassDescriptor;
                hidClassDescriptor = (usb_host_hid_class_descriptor_t *)&(hidDescriptor->bHidDescriptorType);
                for (uint8_t index = 0; index < hidDescriptor->bNumDescriptors; ++index)
                {
                    hidClassDescriptor += index;
                    if (hidClassDescriptor->bHidDescriptorType == USB_DESCRIPTOR_TYPE_HID_REPORT)
                    {
                        hidReportLength =
                            (uint16_t)USB_SHORT_FROM_LITTLE_ENDIAN_ADDRESS(hidClassDescriptor->wDescriptorLength);
                        break;
                    }
                }
            }
            if (hidReportLength > HID_GENERIC_IN_BUFFER_SIZE)
            {
                usb_echo("hid buffer is too small\r\n");
                genericInstance->runState = kUSB_HostHidRunIdle;
                return;
            }

            genericInstance->runWaitState = kUSB_HostHidRunWaitGetReportDescriptor;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            /* second: get report descriptor */
            USB_HostHidGetReportDescriptor(genericInstance->classHandle, genericInstance->genericInBuffer,
                                           hidReportLength, USB_HostHidControlCallback, genericInstance);
            break;

        case kUSB_HostHidRunGetReportDescriptorDone: /* 4. hid set protocol */
            genericInstance->runWaitState = kUSB_HostHidRunWaitSetProtocol;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            /* third: set protocol */
            if (USB_HostHidSetProtocol(genericInstance->classHandle, USB_HOST_HID_REQUEST_PROTOCOL_REPORT,
                                       USB_HostHidControlCallback, genericInstance) != kStatus_USB_Success)
            {
                usb_echo("Error in USB_HostHidSetProtocol\r\n");
            }
            break;

        case kUSB_HostHidRunSetProtocolDone: /* 5. start to receive data and send data */
            genericInstance->runWaitState = kUSB_HostHidRunWaitDataReceived;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            if (USB_HostHidRecv(genericInstance->classHandle, genericInstance->genericInBuffer,
                                genericInstance->inMaxPacketSize, USB_HostHidInCallback,
                                genericInstance) != kStatus_USB_Success)
            {
                usb_echo("Error in USB_HostHidRecv\r\n");
            }
            break;

        case kUSB_HostHidRunDataReceived: /* process received data, receive next data and send next data */
            genericInstance->runWaitState = kUSB_HostHidRunWaitDataReceived;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            if (USB_HostHidRecv(genericInstance->classHandle, genericInstance->genericInBuffer,
                                genericInstance->inMaxPacketSize, USB_HostHidInCallback,
                                genericInstance) != kStatus_USB_Success)
            {
                usb_echo("Error in USB_HostHidRecv\r\n");
            }
            break;

        case kUSB_HostHidRunPrimeDataReceive: /* receive next data and send next data */
            genericInstance->runWaitState = kUSB_HostHidRunWaitDataReceived;
            genericInstance->runState     = kUSB_HostHidRunIdle;
            if (USB_HostHidRecv(genericInstance->classHandle, genericInstance->genericInBuffer,
                                genericInstance->inMaxPacketSize, USB_HostHidInCallback,
                                genericInstance) != kStatus_USB_Success)
            {
                usb_echo("Error in USB_HostHidRecv\r\n");
            }
            break;

        default:
            break;
    }
}

static char * getEndpointPolligRate(uint32_t usbSpeed, uint8_t bInterval)
{
    if (usbSpeed == USB_SPEED_HIGH) {
        switch (bInterval) {
        case 7:
            return "125";
        case 6:
            return "250";
        case 5:
            return "500";
        case 4:
            return "1000";
        case 3:
            return "2000";
        case 2:
            return "4000";
        case 1:
            return "8000";
        default:
            break;;
        }
    } else if (usbSpeed == USB_SPEED_FULL || usbSpeed == USB_SPEED_LOW) {
        switch (bInterval) {
        case 8:
            return "125";
        case 4:
            return "250";
        case 2:
            return "500";
        case 1:
            return "1000";
        default:
            break;
        }
    }
    return "???";
}

usb_status_t USB_HostHidGenericEvent(usb_device_handle deviceHandle,
                                     usb_host_configuration_handle configurationHandle,
                                     uint32_t eventCode)
{
    usb_host_configuration_t *configuration;
    usb_host_interface_t *interface;
    uint32_t infoValue;
    char *speed[] = {
        [USB_SPEED_FULL] = "USB_SPEED_FULL",
        [USB_SPEED_LOW] = "USB_SPEED_LOW",
        [USB_SPEED_HIGH] = "USB_SPEED_HIGH",
        [USB_SPEED_SUPER] = "USB_SPEED_SUPER",
    };
    usb_status_t status = kStatus_USB_Success;
    uint8_t interfaceIndex;
    uint8_t id;

    switch (eventCode)
    {
        case kUSB_HostEventAttach:
            /* judge whether is configurationHandle supported */
            configuration = (usb_host_configuration_t *)configurationHandle;
            USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDeviceSpeed, &infoValue);
            for (interfaceIndex = 0; interfaceIndex < configuration->interfaceCount; ++interfaceIndex)
            {
                interface = &configuration->interfaceList[interfaceIndex];
                id        = interface->interfaceDesc->bInterfaceClass;
                if (id != USB_HOST_HID_CLASS_CODE)
                {
                    continue;
                }
                id = interface->interfaceDesc->bInterfaceSubClass;
                if ((id != USB_HOST_HID_SUBCLASS_CODE_NONE) && (id != USB_HOST_HID_SUBCLASS_CODE_BOOT))
                {
                    continue;
                }

                if (g_HostHidGeneric[interfaceIndex].deviceState == kStatus_DEV_Idle)
                {
                    /* the interface is supported by the application */
                    g_HostHidGeneric[interfaceIndex].genericInBuffer  = (uint8_t *) &s_GenericInBuffer[interfaceIndex];
                    g_HostHidGeneric[interfaceIndex].genericOutBuffer = (uint8_t *) &s_GenericOutBuffer[interfaceIndex];
                    g_HostHidGeneric[interfaceIndex].deviceHandle     = deviceHandle;
                    g_HostHidGeneric[interfaceIndex].interfaceHandle  = interface;
                    g_HostHidGeneric[interfaceIndex].configHandle     = configurationHandle;
                    g_HostHidGeneric[interfaceIndex].interfaceNumber  = interfaceIndex;
                    g_HostHidGeneric[interfaceIndex].interfaceProtocolType = interface->interfaceDesc->bInterfaceProtocol;
                    g_HostHidGeneric[interfaceIndex].interfaceUsed    = 1;

                    switch (g_HostHidGeneric[interfaceIndex].interfaceProtocolType) {
                    case USB_HOST_HID_PROTOCOL_KEYBOARD:
                        usb_echo("recognized keyboard interface %d\r\n", interfaceIndex);
                        for (uint32_t i = 0; i < g_HostHidGeneric[interfaceIndex].endpointCount; i++) {
                            if (g_HostHidGeneric[interfaceIndex].endpoint[i].epAddress & 0x80) {
                                usb_echo("IN endpoint %u with polling rate %s Hz\r\n", g_HostHidGeneric[interfaceIndex].endpoint[i].epAddress & (~0x80),
                                getEndpointPolligRate(infoValue, g_HostHidGeneric[interfaceIndex].endpoint[i].bInterval));
                            } else {
                                usb_echo("OUT endpoint %u\r\n", g_HostHidGeneric[interfaceIndex].endpoint[i].epAddress);
                            }
                        }
                        break;
                    case USB_HOST_HID_PROTOCOL_MOUSE:
                        usb_echo("recognized mouse interface %d\r\n", interfaceIndex);
                        for (uint32_t i = 0; i < g_HostHidGeneric[interfaceIndex].endpointCount; i++) {
                            if (g_HostHidGeneric[interfaceIndex].endpoint[i].epAddress & 0x80) {
                                usb_echo("IN endpoint %u with polling rate %s Hz\r\n", g_HostHidGeneric[interfaceIndex].endpoint[i].epAddress & (~0x80),
                                getEndpointPolligRate(infoValue, g_HostHidGeneric[interfaceIndex].endpoint[i].bInterval));
                            } else {
                                usb_echo("OUT endpoint %u\r\n", g_HostHidGeneric[interfaceIndex].endpoint[i].epAddress);
                            }
                        }
                        break;
                    case USB_HOST_HID_PROTOCOL_NONE:
                    default:
                        usb_echo("found interface %d with protocol %d\r\n", interfaceIndex,
                                 g_HostHidGeneric[interfaceIndex].interfaceProtocolType);
                        g_HostHidGeneric[interfaceIndex].interfaceProtocolType = USB_HOST_HID_PROTOCOL_NONE;
                        break;
                    }
                    status = kStatus_USB_Success;
                }
                else
                {
                    continue;
                }
            }
            break;

        case kUSB_HostEventNotSupported:
            break;

        case kUSB_HostEventEnumerationDone:
            for (uint32_t i = 0; i < USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE; i++) {
                if (g_HostHidGeneric[i].configHandle == configurationHandle)
                {
                    if ((g_HostHidGeneric[i].deviceHandle != NULL) && (g_HostHidGeneric[i].interfaceHandle != NULL))
                    {
                        /* the device enumeration is done */
                        if (g_HostHidGeneric[i].deviceState == kStatus_DEV_Idle)
                        {
                            g_HostHidGeneric[i].deviceState = kStatus_DEV_Attached;
                        }
                        else
                        {
                            usb_echo("not idle generic instance\r\n");
                            status = kStatus_USB_Error;
                        }
                    }
                }
            }
            USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDevicePID, &infoValue);
            usb_echo("device attached: pid = 0x%x ", infoValue);
            USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDeviceVID, &infoValue);
            usb_echo("vid = 0x%x ", infoValue);
            USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDeviceAddress, &infoValue);
            usb_echo("address = %d\r\n", infoValue);
            USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDeviceSpeed, &infoValue);
            usb_echo("device %s\r\n", speed[infoValue]);
            break;

        case kUSB_HostEventDetach:
            for (uint32_t i = 0; i < USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE; i++) {
                if (g_HostHidGeneric[i].configHandle == configurationHandle)
                {
                    /* the device is detached */
                    g_HostHidGeneric[i].configHandle = NULL;
                    if (g_HostHidGeneric[i].deviceState != kStatus_DEV_Idle)
                    {
                        g_HostHidGeneric[i].deviceState = kStatus_DEV_Detached;
                    }
                }
            }
            onUsbConfigured(false);
            break;

        default:
            break;
    }
    return status;
}
