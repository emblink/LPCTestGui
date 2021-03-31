/*
* Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016 - 2017 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include <stdbool.h>
#include <stdio.h>
#include "pin_mux.h"
#include "fsl_power.h"
#include "fsl_ctimer.h"
#include "fsl_sctimer.h"
#include "fsl_common.h"
#include "fsl_rng.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
#include "fsl_sysmpu.h"
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */
#include "board.h"
#include "sdcard_fatfs.h"
#include "emwin_support.h"
#include "Resource.h"
#include "usb_host_config.h"
#include "usb_host.h"
#include "usb_host_hid.h"
#include "host_hid_generic.h"

#include "app.h"
#include "version.h"
#include "reportExtension.h"
#include "reportDescriptorParser.h"
#include "ringbuffer.h"
#include "gui.h"

#if ((!USB_HOST_CONFIG_KHCI) && (!USB_HOST_CONFIG_EHCI) && (!USB_HOST_CONFIG_OHCI) && (!USB_HOST_CONFIG_IP3516HS))
#error Please enable USB_HOST_CONFIG_KHCI, USB_HOST_CONFIG_EHCI, USB_HOST_CONFIG_OHCI, or USB_HOST_CONFIG_IP3516HS in file usb_host_config.
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
* @brief host callback function.
*
* device attach/detach callback function.
*
* @param deviceHandle          device handle.
* @param configurationHandle   attached device's configuration descriptor information.
* @param eventCode             callback event code, please reference to enumeration host_event_t.
*
* @retval kStatus_USB_Success              The host is initialized successfully.
* @retval kStatus_USB_NotSupported         The application don't support the configuration.
*/
static usb_status_t USB_HostEvent(usb_device_handle deviceHandle,
        usb_host_configuration_handle configurationHandle, uint32_t eventCode);

/*!
* @brief application initialization.
*/
static void USB_HostApplicationInit(void);

extern void USB_HostClockInit(void);
extern void USB_HostIsrEnable(void);
extern void USB_HostTaskFn(void *param);
void BOARD_InitHardware(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
usb_host_handle g_HostHandle;
/* each g_HostHidGeneric instance determine one hid interface */
extern usb_host_hid_generic_instance_t g_HostHidGeneric[USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE];

/*******************************************************************************
 * Code
 ******************************************************************************/
#if (defined(USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI > 0U))
void USB0_IRQHandler(void)
{
    USB_HostOhciIsrFunction(g_HostHandle);
}
#endif /* USB_HOST_CONFIG_OHCI */
#if (defined(USB_HOST_CONFIG_IP3516HS) && (USB_HOST_CONFIG_IP3516HS > 0U))
void USB1_IRQHandler(void) {
    USB_HostIp3516HsIsrFunction(g_HostHandle);
}
#endif /* USB_HOST_CONFIG_IP3516HS */

void USB_HostClockInit(void) {
#if ((defined USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI > 0U))
    CLOCK_EnableUsbfs0HostClock(kCLOCK_UsbSrcUsbPll, 48000000U);
#if ((defined FSL_FEATURE_USBFSH_USB_RAM) && (FSL_FEATURE_USBFSH_USB_RAM > 0U))
    for (int i = 0; i < (FSL_FEATURE_USBFSH_USB_RAM >> 2); i++)
    {
        ((uint32_t *)FSL_FEATURE_USBFSH_USB_RAM_BASE_ADDRESS)[i] = 0U;
    }
#endif
#endif /* USB_HOST_CONFIG_OHCI */

#if ((defined USB_HOST_CONFIG_IP3516HS) && (USB_HOST_CONFIG_IP3516HS > 0U))
    CLOCK_EnableUsbhs0HostClock(kCLOCK_UsbSrcUsbPll, 48000000U);
#if ((defined FSL_FEATURE_USBHSH_USB_RAM) && (FSL_FEATURE_USBHSH_USB_RAM > 0U))
    for (int i = 0; i < (FSL_FEATURE_USBHSH_USB_RAM >> 2); i++) {
        ((uint32_t*) FSL_FEATURE_USBHSH_USB_RAM_BASE_ADDRESS)[i] = 0U;
    }
#endif
#endif /* USB_HOST_CONFIG_IP3511HS */
}

void USB_HostIsrEnable(void) {
    uint8_t irqNumber;
#if ((defined USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI > 0U))
    IRQn_Type usbHsIrqs[] = {(IRQn_Type)USB0_IRQn};
    irqNumber             = usbHsIrqs[CONTROLLER_ID - kUSB_ControllerOhci0];
#endif /* USB_HOST_CONFIG_OHCI */
#if ((defined USB_HOST_CONFIG_IP3516HS) && (USB_HOST_CONFIG_IP3516HS > 0U))
    IRQn_Type usbHsIrqs[] = { (IRQn_Type) USB1_IRQn };
    irqNumber = usbHsIrqs[CONTROLLER_ID - kUSB_ControllerIp3516Hs0];
#endif /* USB_HOST_CONFIG_IP3511HS */

    /* Install isr, set priority, and enable IRQ. */
#if defined(__GIC_PRIO_BITS)
    GIC_SetPriority((IRQn_Type)irqNumber, USB_HOST_INTERRUPT_PRIORITY);
#else
    NVIC_SetPriority((IRQn_Type) irqNumber, USB_HOST_INTERRUPT_PRIORITY);
#endif
    EnableIRQ((IRQn_Type) irqNumber);
}

void USB_HostTaskFn(void *param) {
#if ((defined USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI > 0U))
    USB_HostOhciTaskFunction(param);
#endif /* USB_HOST_CONFIG_OHCI */
#if ((defined USB_HOST_CONFIG_IP3516HS) && (USB_HOST_CONFIG_IP3516HS > 0U))
    USB_HostIp3516HsTaskFunction(param);
#endif /* USB_HOST_CONFIG_IP3516HS */
}

/*!
* @brief USB isr function.
*/

static usb_status_t USB_HostEvent(usb_device_handle deviceHandle,
        usb_host_configuration_handle configurationHandle, uint32_t eventCode) {
    usb_status_t status = kStatus_USB_Success;

    switch (eventCode & 0x0000FFFFU) {
    case kUSB_HostEventAttach:
        status = USB_HostHidGenericEvent(deviceHandle, configurationHandle, eventCode);
        break;

    case kUSB_HostEventNotSupported:
        usb_echo("device not supported.\r\n");
        break;

    case kUSB_HostEventEnumerationDone:
        status = USB_HostHidGenericEvent(deviceHandle, configurationHandle, eventCode);
        break;

    case kUSB_HostEventDetach:
        status = USB_HostHidGenericEvent(deviceHandle, configurationHandle, eventCode);
        break;

    case kUSB_HostEventEnumerationFail:
        usb_echo("enumeration failed\r\n");
        break;

    default:
        break;
    }
    return status;
}

static void USB_HostApplicationInit(void) {
    usb_status_t status = kStatus_USB_Success;

    USB_HostClockInit();

#if ((defined FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT))
    SYSMPU_Enable(SYSMPU, 0);
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */

    status = USB_HostInit(CONTROLLER_ID, &g_HostHandle, USB_HostEvent);
    if (status != kStatus_USB_Success) {
        usb_echo("host init error\r\n");
        return;
    }
    USB_HostIsrEnable();

    usb_echo("Usb host init done, plug in device\r\n");
    usb_echo("If device doesn't appear from the first time reset the board\r\n");
}

/************************************** TEST CODE **************************************/

#define TIMER_US CTIMER1
#define TIMER_MS CTIMER2
#define GPIO_PORT 0
#define GPIO_PIN 16

#define CTIMER CTIMER3                 /* Timer 3 */
#define CTIMER_MAT_OUT kCTIMER_Match_1 /* Match output 1 */
#define CTIMER_CLK_FREQ CLOCK_GetFreq(kCLOCK_AsyncApbClk)
#define CTIMER_PRESCALE (CTIMER_CLK_FREQ / 1000)

typedef enum {
    DataOutputStreamConsole = 1UL,
    DataOutputStreamSDCard,
    DataOutputStreamCount
} DataOutputStream;

typedef enum {
    KeyInitStateFailed,
    KeyInitStateStart,
    KeyInitStateCapturePressReport,
    KeyInitStateCaptureOtherReports,
    KeyInitStateDetermineTestBit,
    KeyInitStateCaptureTriggerPressReport,
    KeyInitStateCaptureTriggerOtherReports,
    KeyInitStateCompareTestBit,
    KeyInitStateInited,
    KeyInitStateCount
} KeyInitState;

typedef enum {
    TestStateNotRunning,
    TestStateStart,
    TestStateWaitPressReport,
    TestStateWaitReflexReleaseReport,
    TestStateAppendResults,
    TestStateIdle,
    TestStateFinished,
} TestState;

typedef enum {
    ButtonStatePress = 0U,
    ButtonStateRelease = 1,
} ButtonState;

typedef struct {
    uint32_t quantity;
    uint32_t periodMs;
    DataOutputStream outputStream;
    uint32_t count;
    bool done;
} UserInput;

typedef struct {
    UserInput userInput;
    KeyInitState keyInitState;
    TestState testState;
    bool testIsRunning;
    bool keyIsPressed;
    bool sdCardInitDone;
    bool reflexSupported;
    bool reflexReportReceived;
    uint32_t testKeyBit;
    uint32_t testInterface;
    uint32_t numberOfDoneTests;
    uint32_t pressTimeUs;
    uint32_t releaseTimeUs;
    uint32_t nextPressTimeUs;
    uint32_t releaseDelayUs;
    uint32_t latency;
    uint32_t maxLatency;
    uint32_t reflexLatency;
    uint32_t reflexMaxLatency;
    uint64_t latencySumm;
    uint64_t reflexLatencySumm;
} TestHandle;

RingBuffer reportRingBuff;
static rbdatatype inReport[10] = {0};
static uint32_t zeroTransactionCount = 0;
static bool usbConfigured = false;

static void timeCounterInit(void)
{
    ctimer_config_t config;
    CTIMER_GetDefaultConfig(&config);
    config.prescale = SystemCoreClock / 1000000 - 1;
    CTIMER_Init(TIMER_US, &config);
    CTIMER_StartTimer(TIMER_US);

    config.prescale = SystemCoreClock / 1000 - 1;
    CTIMER_Init(TIMER_MS, &config);
    CTIMER_StartTimer(TIMER_MS);
}

static uint32_t getTimeMs()
{
    return CTIMER_GetTimerCountValue(TIMER_MS);
}

static uint32_t getTimeUs()
{
    return CTIMER_GetTimerCountValue(TIMER_US);
}

static uint32_t getTimeSinceMs(uint32_t tickMs)
{
    return getTimeMs() - tickMs;
}

static uint32_t getTimeSinceUs(uint32_t tickUs)
{
    return getTimeUs() - tickUs;
}

static void delayMs(uint32_t delay)
{
    uint32_t timestamp = getTimeMs() + delay;
    while (getTimeMs() < timestamp) { }
}

void delayUs(uint32_t delay)
{
    uint32_t timestamp = getTimeUs() + delay;
    while (getTimeUs() < timestamp) {
        // Wait
    }
}

static uint32_t getRandomNumber(uint32_t min, uint32_t max)
{
    if (min == max)
        return max;

    uint32_t num;
    do {
        num = RNG_GetRandomData() % max;
    } while (num < min);
    return num;
}

// TODO: add pinmux
/*! @name PIO1_1 (coord K12), USER_BUTTON
  @{ */
/* Routed pin properties */
#define BOARD_USER_BUTTON_PERIPHERAL GPIO                   /*!<@brief Peripheral name */
#define BOARD_USER_BUTTON_SIGNAL PIO1                       /*!<@brief Signal name */
#define BOARD_USER_BUTTON_CHANNEL 1                         /*!<@brief Signal channel */
#define BOARD_USER_BUTTON_PIN_NAME PIO1_1                   /*!<@brief Routed pin name */
#define BOARD_USER_BUTTON_LABEL "USER_BUTTON"               /*!<@brief Label */
#define BOARD_USER_BUTTON_NAME "USER_BUTTON"                /*!<@brief Identifier */
#define BOARD_USER_BUTTON_DIRECTION kPIN_MUX_DirectionInput /*!<@brief Direction */

/* Symbols to be used with GPIO driver */
#define BOARD_USER_BUTTON_GPIO GPIO                         /*!<@brief GPIO peripheral base pointer */
#define BOARD_USER_BUTTON_GPIO_PIN 1U                       /*!<@brief GPIO pin number */
#define BOARD_USER_BUTTON_GPIO_PIN_MASK (1U << 1U)          /*!<@brief GPIO pin mask */
#define BOARD_USER_BUTTON_PORT 1U                           /*!<@brief PORT peripheral base pointer */
#define BOARD_USER_BUTTON_PIN 1U                            /*!<@brief PORT pin number */
#define BOARD_USER_BUTTON_PIN_MASK (1U << 1U)               /*!<@brief PORT pin mask */
                                                            /* @} */

static void triggerPinInit(void)
{
    GPIO_PortInit(GPIO, GPIO_PORT);
    GPIO_PortInit(BOARD_USER_BUTTON_GPIO, BOARD_USER_BUTTON_GPIO_PIN);
    gpio_pin_config_t pinConfig = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = ButtonStateRelease,
    };
    GPIO_PinInit(GPIO, GPIO_PORT, GPIO_PIN, &pinConfig);
    IOCON->PIO[GPIO_PORT][GPIO_PIN] = 0x300;
    GPIO_PinWrite(GPIO, GPIO_PORT, GPIO_PIN, ButtonStateRelease);
}

static void userButtonInit(void)
{
    // /* Enables the clock for the GPIO1 module */
    // gpio_pin_config_t USER_BUTTON_config = {
    //     .pinDirection = kGPIO_DigitalInput,
    //     .outputLogic = 0U
    // };
    // GPIO_PinInit(BOARD_USER_BUTTON_GPIO, BOARD_USER_BUTTON_PORT, BOARD_USER_BUTTON_PIN, &USER_BUTTON_config);
    //     /* Initialize GPIO functionality on pin PIO1_1 (pin K12)  */
    //     IOCON->PIO[1][1] = ((IOCON->PIO[1][1] &
    //                     /* Mask bits to zero which are setting */
    //                     (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_FILTEROFF_MASK)))

    //                     /* Selects pin function.
    //                     * : PORT11 (pin K12) is configured as PIO1_1. */
    //                     | IOCON_PIO_FUNC(PIO11_FUNC_ALT0)

    //                     /* Select Analog/Digital mode.
    //                     * : Digital mode. */
    //                     | IOCON_PIO_DIGIMODE(PIO11_DIGIMODE_DIGITAL)

    //                     /* Controls input glitch filter.
    //                     * : Filter enabled.
    //                     * Noise pulses below approximately 10 ns are filtered out. */
    //                     | IOCON_PIO_FILTEROFF(PIO11_FILTEROFF_ENABLED));
}

static void setKeyState(TestHandle *handle, bool press)
{
    handle->keyIsPressed = press;
    if (press) {
        // calculate when to perform release and the next press
        handle->nextPressTimeUs = handle->userInput.periodMs * 1000 + getRandomNumber(0, 1000);
        handle->releaseDelayUs = handle->userInput.periodMs * 1000 / 2 + getRandomNumber(0, 1000);
        handle->pressTimeUs = getTimeUs();
    } else {
        handle->releaseTimeUs = getTimeUs();
    }
    GPIO_PinWrite(GPIO, GPIO_PORT, GPIO_PIN, press ? ButtonStatePress : ButtonStateRelease);
}

void onUsbConfigured(bool configured)
{
    if (configured) {
        usbConfigured = true;
        APPW_SetVarData(ID_VAR_USB_DEVICE_CONFIGURED, 1);
    } else {
        usb_echo("Device detached, test stoped\r\n");
        usbConfigured = false;
        APPW_SetVarData(ID_VAR_USB_DEVICE_CONFIGURED, 0);
    }
}

static bool determineTestBit(uint32_t *testBit, rbdatatype inReport[], uint32_t inReportCount)
{
    uint32_t differentBytesCount = 0;
    uint32_t testByteIndex = 0;
    // inReport[0] - assumed to be a press report
    // inReport[1 - n] - assumed to be a release or a reflex reports.
    /* Compare bytes in all reports and determine which bytes are different.
    Nvidia reflex extension bytes are cut off. If the count of different bytes 
    is more than 1 then captured reports are invalid */
    uint32_t reportLen = inReport[0].reflexSupported ? inReport[0].length - REPORT_EXTENSION_DATA_LENGTH : inReport[0].length;
    for (uint32_t i = 0; i < reportLen; i++) {
        for (uint32_t inRepIdx = 1; inRepIdx < inReportCount; inRepIdx++) {
            if (inReport[0].interface == inReport[inRepIdx].interface) { // compare reports only from the same interface 
                if (inReport[0].data[i] != inReport[inRepIdx].data[i]) {
                    differentBytesCount++;
                    if (differentBytesCount > 1) {
                        return false;
                    }
                    testByteIndex = i;
                    break;
                }
            }
        }
    }
    uint32_t bit;
    for (bit = 0; bit < 8; bit++) {
        if (inReport[0].data[testByteIndex] & 1 << bit) {
            break;
        }
    }
    *testBit = testByteIndex * 8 + bit;
    return true;
}

static bool isTestKeyPressed(const uint8_t *data, uint32_t testKeyBit)
{
    uint32_t byte = testKeyBit / 8;
    uint32_t bit = testKeyBit - (byte * 8);

    bool result = (data[byte] & (1 << bit)) > 0 ? true : false;
    return result;
}

static void promtUserInput(TestHandle *handle)
{
    if (handle->userInput.count == 0) {
        uint32_t quantity = 0;
        usb_echo("\r\nInput test quantity 1 - 500000\r\n");
        if (SCANF("%u", &quantity) != 1 || quantity < 1 || quantity > 500000) {
            usb_echo("Wrong input\r\n");
        } else {
            usb_echo("test quantity == %u\r\n", quantity);
            handle->userInput.quantity = quantity;
            handle->userInput.count++;
        }
    }

    if (handle->userInput.count == 1) {
        uint32_t period = 0;
        usb_echo("Input button click period 65ms - 1000ms\r\n");
        if (SCANF("%u", &period) != 1 || period < 65 || period > 1000) {
            usb_echo("Wrong input\r\n");
        } else {
            usb_echo("click period == %u ms\r\n", period);
            handle->userInput.periodMs = period;
            handle->userInput.count++;
        }
    }

    if (handle->userInput.count == 2) {
        uint32_t outputStream = DataOutputStreamConsole;
        usb_echo("Choose data output stream\r\nConsole - press 1\r\nSD card - press 2\r\n");
        if (SCANF("%u", &outputStream) != 1 || outputStream < DataOutputStreamConsole || outputStream >= DataOutputStreamCount) {
            usb_echo("Wrong input\r\n");
        } else {
            handle->userInput.outputStream = outputStream;
            if (outputStream == DataOutputStreamConsole) {
                usb_echo("Output redirected to console\r\n");
            } else {
                usb_echo("Output will be stored on sd card\r\n");
            }
            handle->userInput.count++;
        }
    }
    
    handle->userInput.done = handle->userInput.count == 3 ? true : false;
}

void cardInit(TestHandle *handle)
{
    if (sdCardInit() == 0 && sdCardCreateResultsFile()) {
        handle->sdCardInitDone = true;
    }
}

void appendResults(uint32_t latencyUs, uint32_t reflexData, DataOutputStream outputStream)
{
    static char tempStr[20] = {0};
    if (reflexData) {
        sprintf(tempStr, "%u,%u,\r\n", latencyUs, reflexData);
    } else {
        sprintf(tempStr, "%u\r\n", latencyUs);
    }
    int size = strlen(tempStr);

    if (outputStream == DataOutputStreamConsole) {
        usb_echo("%s", tempStr);
    } else if (outputStream == DataOutputStreamSDCard) {
        sdCardAppendResults((uint8_t *) tempStr, size);
    }
}

static void keyTestInit(TestHandle *handle)
{
    static uint32_t timestamp = 0;
    static rbdatatype inReport[5] = {0};
    static uint32_t inReportCount = 0;

    if (RingBuffer_IsFull(&reportRingBuff)) {
        handle->keyInitState = KeyInitStateFailed;
        usb_echo("In reports overflow\r\n");
        RingBuffer_Clear(&reportRingBuff);
    }

    switch (handle->keyInitState) {
    case KeyInitStateFailed:
        timestamp = getTimeMs();
        handle->keyInitState = KeyInitStateStart;
        break;
    
    case KeyInitStateStart:
        // delay to enshure that all reports arrived after failed cycle.
        if (getTimeSinceMs(timestamp) > 500) {
            memset(inReport, 0, sizeof(inReport));
            RingBuffer_Clear(&reportRingBuff);
            usb_echo("\r\nPress and release the key that will be triggered\r\n");
            handle->keyInitState = KeyInitStateCapturePressReport;
        }
        break;

    case KeyInitStateCapturePressReport: {
        rbdatatype *report = RingBuffer_Get(&reportRingBuff);
        if (report != NULL) {
            handle->keyInitState = KeyInitStateCaptureOtherReports;
            usb_echo("Press report received, release the key\r\n");
            inReportCount = 0;
            memcpy(&inReport[0], report, sizeof(rbdatatype));
            inReportCount++;
            timestamp = getTimeMs();
        }
    }   break;

    case KeyInitStateCaptureOtherReports:
        if (getTimeSinceMs(timestamp) > 500) {
            // capture one or two more reports and try to determine test bit
            rbdatatype *report;
            do {
                report = RingBuffer_Get(&reportRingBuff);
                if (report != NULL) {
                    memcpy(&inReport[inReportCount], report, sizeof(rbdatatype));
                    inReportCount++;
                }
            } while (report != NULL && inReportCount < sizeof(inReport) / sizeof(inReport[0]));

            if (inReportCount == 1) {
                usb_echo("Release/reflex reports capture timeout\r\n");
                handle->keyInitState = KeyInitStateFailed;
            } else {
                handle->keyInitState = KeyInitStateDetermineTestBit;
            }
        }
        break;

    case KeyInitStateDetermineTestBit: {
        bool reportsValid = determineTestBit(&handle->testKeyBit, inReport, inReportCount);
        usb_echo("Captured %u reports, test bit is %u\r\n", inReportCount, handle->testKeyBit);
        if (reportsValid) {
            handle->keyInitState = KeyInitStateCaptureTriggerPressReport;
            usb_echo("Checking trigger\r\n");
            timestamp = getTimeMs();
            memset(inReport, 0, sizeof(inReport));
            RingBuffer_Clear(&reportRingBuff);
            setKeyState(handle, true);
        } else {
            usb_echo("Received reports are not valid.\r\n");
            handle->keyInitState = KeyInitStateFailed;
        }
    }   break;
    
    case KeyInitStateCaptureTriggerPressReport: {
        rbdatatype *report = RingBuffer_Get(&reportRingBuff);
        if (report != NULL) {
            usb_echo("Trigger Press report received\r\n");
            handle->keyInitState = KeyInitStateCaptureTriggerOtherReports;
            inReportCount = 0;
            memcpy(&inReport[inReportCount], report, sizeof(rbdatatype));
            inReportCount++;
            timestamp = getTimeMs();
            setKeyState(handle, false);
        } else if (getTimeSinceMs(timestamp) > 200) {
            usb_echo("Trigger timeout! Seems like optocoupler is not triggering button.\r\n");
            handle->keyInitState = KeyInitStateFailed;
        }
    }   break;

    case KeyInitStateCaptureTriggerOtherReports:
        if (getTimeSinceMs(timestamp) > 500) {
            // capture one or two more reports and try to determine test bit
            rbdatatype *report;
            do {
                report = RingBuffer_Get(&reportRingBuff);
                if (report != NULL) {
                    memcpy(&inReport[inReportCount], report, sizeof(rbdatatype));
                    inReportCount++;
                }
            } while (report != NULL && inReportCount < sizeof(inReport) / sizeof(inReport[0]));

            if (inReportCount == 1) {
                usb_echo("Trigger release/reflex reports were not captured\r\n");
                handle->keyInitState = KeyInitStateFailed;
            } else {
                handle->keyInitState = KeyInitStateCompareTestBit;
            }
        }
        break;

    case KeyInitStateCompareTestBit: {
        uint32_t triggerTestBit = 0;
        bool reportsValid = determineTestBit(&triggerTestBit, inReport, inReportCount);
        usb_echo("Captured %u reports, test bit is %u\r\n", inReportCount, triggerTestBit);
        if (reportsValid) {
            if (triggerTestBit == handle->testKeyBit) {
                usb_echo("Test bits matched\r\n");
                timestamp = getTimeMs();
                handle->keyInitState = KeyInitStateInited;
            } else {
                usb_echo("Test bits didn't matched!\r\n");
                handle->keyInitState = KeyInitStateFailed;
            }
        } else {
            usb_echo("Triggered reports are not valid.\r\n");
            handle->keyInitState = KeyInitStateFailed;
        }
    }   break;

    case KeyInitStateInited:
        if (getTimeSinceMs(timestamp) > 200) { // delay to enshure that debounce time is passed
            uint32_t testTime = (handle->userInput.quantity * handle->userInput.periodMs / 1000);
            uint32_t hours = testTime / 3600;
            uint32_t minutes = (testTime % 3600) / (60);
            usb_echo("\r\nTest will approximately take %u hours %u minutes\r\n", hours, minutes);
            usb_echo("Start measurements\r\n");
            zeroTransactionCount = 0;
            handle->testIsRunning = true;
            handle->testState = TestStateStart;
        }
        break;

    default:
        usb_echo("Unnexpected State!\r\n");
        __asm("BKPT #255");
        break;
    }
}

static void initTest(TestHandle *handle)
{
    if (!handle->userInput.done) {
        promtUserInput(handle);
    } else if (handle->userInput.outputStream == DataOutputStreamSDCard && !handle->sdCardInitDone) {
        cardInit(handle);
    } else {
        keyTestInit(handle);
    }
}

static void keyTestProcess(TestHandle *handle)
{
    rbdatatype *report = RingBuffer_Get(&reportRingBuff);

    switch (handle->testState) {
    case TestStateStart:
        setKeyState(handle, true);
        handle->testState = TestStateWaitPressReport;
        break;
    case TestStateWaitPressReport:
        if (report != NULL && isTestKeyPressed(report->data, handle->testKeyBit)) {
            // if press report recieved, save results
            handle->latency = report->timestamp - handle->pressTimeUs;
            handle->latencySumm += handle->latency;
            if (handle->latency > handle->maxLatency) {
                handle->maxLatency = handle->latency;
            }
            handle->reflexSupported = report->reflexSupported;
            handle->testInterface = report->interface;
            handle->testState = TestStateWaitReflexReleaseReport;
        }
        break;
    case TestStateWaitReflexReleaseReport:
        // if received press report supports reflex, wait for the next report and parse reflex data
        if (handle->reflexSupported && !handle->reflexReportReceived) {
            if (report != NULL && handle->testInterface == report->interface) {
                // this report should contain reflex extention id and data
                uint32_t extentionIdOffset = report->length - REPORT_EXTENSION_DATA_LENGTH;
                if (report->data[extentionIdOffset] == ReportExtensionIdLatency) {
                    handle->reflexLatency = *((uint32_t *) (&report->data[extentionIdOffset + 1])) * 10;
                    handle->reflexLatencySumm += handle->reflexLatency;
                    if (handle->reflexLatency > handle->reflexMaxLatency) {
                        handle->reflexMaxLatency = handle->reflexLatency;
                    }
                } else {
                    // shouldn't get here
                    usb_echo("Error, extension ID %u != %u\r\n",
                    report->data[extentionIdOffset], ReportExtensionIdLatency);
                    handle->reflexLatency = 0;
                }
                handle->reflexReportReceived = true;
            }
        }
        // release the key after the press report received and release delay passed
        if (handle->keyIsPressed && getTimeSinceUs(handle->pressTimeUs) >= handle->releaseDelayUs) {
            setKeyState(handle, false);
        }
        // If reflex is not supported append results. If reflex is supported, wait for reflex data.
        if (!handle->keyIsPressed && (!handle->reflexSupported || handle->reflexReportReceived)) {
            handle->testState = TestStateAppendResults;
        }
        break;
    case TestStateAppendResults:
        appendResults(handle->latency, handle->reflexSupported ? handle->reflexLatency : 0, handle->userInput.outputStream);
        handle->numberOfDoneTests++;
        /* if test is finished */
        if (handle->numberOfDoneTests >= handle->userInput.quantity) {
            handle->testState = TestStateFinished;
        } else {
            handle->testState = TestStateIdle;
        }
        break;
    case TestStateIdle:
        // simply wait for the next trigger time
        if (getTimeSinceUs(handle->pressTimeUs) >= handle->nextPressTimeUs) {
            handle->reflexSupported = false;
            handle->reflexReportReceived = false;
            // trigger next latency measurement
            setKeyState(handle, true);
            handle->testState = TestStateWaitPressReport;
        }
        break;
    case TestStateFinished:
        usb_echo("\r\n************  Measurement Finished  ************\r\n");
        if (handle->userInput.outputStream == DataOutputStreamSDCard) {
            if (!sdCardCloseFile()) {
                usb_echo("sdCardCloseFile failed\r\n");
            }
        }
        usb_echo("max latency %u us\r\n", handle->maxLatency);
        uint32_t average = handle->latencySumm / handle->userInput.quantity; // handling such expression is not supported by the usb_echo
        usb_echo("average latency %u us\r\n", average);

        if (handle->reflexLatencySumm) {
            usb_echo("max reflex latency %u us\r\n", handle->reflexMaxLatency);
            average = handle->reflexLatencySumm / handle->userInput.quantity; // handling such expression is not supported by the usb_echo
            usb_echo("average reflex latency %u us\r\n", average);
        }

        if (zeroTransactionCount > 0) {
            usb_echo("zero-length IN packets count %u \r\n", zeroTransactionCount);
            zeroTransactionCount = 0;
        }
        memset(handle, 0, sizeof(TestHandle)); // reset all handle values and restart test
        break;
    default:
        break;
    }
}

static void triggerTestProcess(TestHandle *handle)
{
    APPW_VAR_OBJECT *trigger = APPW_GetVar(ID_VAR_TRIGGER_PRESSED);
    if (trigger && (bool) trigger->Data != handle->keyIsPressed) {
        setKeyState(handle, trigger->Data ? true : false);
        usb_echo("Trigger %s\r\n", handle->keyIsPressed ? "ON" : "OFF");
    }
}

void onReportReceived(const uint8_t *data, uint32_t dataLength, usb_host_hid_generic_instance_t *genericHidInterface)
{
    if (dataLength == 0) {
        zeroTransactionCount++; // sometimes USB driver sends zero transactions
        return;
    }
    rbdatatype report = {0};
    report.timestamp = getTimeUs();
    report.length = dataLength;
    report.interface = genericHidInterface->interfaceNumber;
    report.reflexSupported = genericHidInterface->reportExtensionSupported;
    memcpy(report.data, data, dataLength);
    if (RingBuffer_Put(&reportRingBuff, report) != 1) {
        usb_echo("reports overflow\r\n"); // normally shouldn't happen
    }
}

void onGetReportDescriptor(const uint8_t *data, uint32_t dataLength, usb_host_hid_generic_instance_t *genericHidInterface)
{
    /* if interface protocol not specified, parse report descriptor for keyboard or mouse usage pages */
    if (genericHidInterface->interfaceProtocolType == USB_HOST_HID_PROTOCOL_NONE) {
        uint8_t protocol = parseReportDescriptorProtocol(data, dataLength);
        if (protocol == USB_HOST_HID_PROTOCOL_UNSUPPORTED) {
            genericHidInterface->interfaceUsed = 0;
        } else {
            char *str1 = "keyboard";
            char *str2 = "mouse";
            usb_echo("recognize %s report in %d interface hid descriptor\r\n", 
                    protocol == USB_HOST_HID_PROTOCOL_KEYBOARD ? str1 : str2, genericHidInterface->interfaceNumber);
        }
    }

    if (genericHidInterface->interfaceUsed) {
        if (isReportExtensionSupported(data, dataLength)) {
            genericHidInterface->reportExtensionSupported = 1;
            usb_echo("interface %u report supports extension\r\n", genericHidInterface->interfaceNumber);
        }
    }
}

void USB_DeviceHsPhyChirpIssueWorkaround(void *hostHandle);

void BOARD_InitPWM(void)
{
    sctimer_config_t config;
    sctimer_pwm_signal_param_t pwmParam;
    uint32_t event;

    CLOCK_AttachClk(kMAIN_CLK_to_SCT_CLK);

    CLOCK_SetClkDiv(kCLOCK_DivSctClk, 2, true);

    SCTIMER_GetDefaultConfig(&config);

    SCTIMER_Init(SCT0, &config);

    pwmParam.output           = kSCTIMER_Out_5;
    pwmParam.level            = kSCTIMER_HighTrue;
    pwmParam.dutyCyclePercent = 5;

    SCTIMER_SetupPwm(SCT0, &pwmParam, kSCTIMER_CenterAlignedPwm, 1000U, CLOCK_GetSctClkFreq(), &event);
}

void Init_CTIMER(void)
{
    ctimer_config_t config;
    /* Enable the asynchronous bridge */
    SYSCON->ASYNCAPBCTRL = 1;

    /* Use 12 MHz clock for some of the Ctimers */
    CLOCK_AttachClk(kFRO12M_to_ASYNC_APB);

    CTIMER_GetDefaultConfig(&config);
    config.prescale = CTIMER_PRESCALE;

    CTIMER_Init(CTIMER, &config);
    CTIMER_StartTimer(CTIMER);
}

void onBoardReset(void)
{
    NVIC_SystemReset();
}

int main(void) {
    /* Delay at the beginning of the main, you know...
    nothing works without it, fixes display initialization */
    // for (volatile uint32_t i = 0; i < 1000000; i++);
    BOARD_InitPins();
    BOARD_BootClockPLL180M();

    CLOCK_EnableClock(kCLOCK_InputMux);
    /* Route Main clock to LCD. */
    CLOCK_AttachClk(kMAIN_CLK_to_LCD_CLK);
    /* attach 12 MHz clock to FLEXCOMM2 (I2C master for touch controller) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    CLOCK_EnableClock(kCLOCK_Gpio2);
    CLOCK_SetClkDiv(kCLOCK_DivLcdClk, 1, true);
    /* need call this function to clear the halt bit in clock divider register */
    CLOCK_SetClkDiv(kCLOCK_DivSdioClk, (uint32_t)(SystemCoreClock / FSL_FEATURE_SDIF_MAX_SOURCE_CLOCK + 1U), true);

    BOARD_InitDebugConsole();
    BOARD_InitSDRAM();

    /* Set the back light PWM. */
    BOARD_InitPWM();
    Init_CTIMER();

    // code from MainTask();
    // Setup configuration dependent pointers
    // APPW_X_Setup();
    // //
    // // Initialize AppWizard
    // //
    // APPW_Init(APPW_PROJECT_PATH);
    // //
    // // Create initial screen...
    // //
    // APPW_CreateRoot(APPW_INITIAL_SCREEN, WM_HBKWIN);
    guiInit();

    triggerPinInit();
    // userButtonInit();
    timeCounterInit();

    usb_echo("\r\n************  Latency test FW version %d.%d.%d  ************\r\n",
            PROJECT_MAJOR_VERSION, PROJECT_MINOR_VERSION, PROJECT_BUILD_NUMBER);
    POWER_DisablePD(kPDRUNCFG_PD_USB1_PHY); /*< Turn on USB Phy */
    USB_HostApplicationInit();
    RingBuffer_Init(&reportRingBuff, inReport, sizeof(inReport) / sizeof(inReport[0]));
    TestHandle handle = {
        .testIsRunning = false,
    };
    uint32_t timestamp = getTimeMs();
    uint32_t guiTimestamp = getTimeMs();

    while (1)
    {
        USB_HostTaskFn(g_HostHandle);
        for (uint32_t interface = 0; interface < USB_HOST_CONFIG_CONFIGURATION_MAX_INTERFACE; interface++) {
            if (g_HostHidGeneric[interface].interfaceUsed) {
                USB_HostHidGenericTask(&g_HostHidGeneric[interface]);
            }
        }

        if (usbConfigured) {
            if (!handle.testIsRunning) {
                // initTest(&handle);
            } else {
                keyTestProcess(&handle);
            }
        } else {
            if (getTimeSinceMs(timestamp) > 250) {
                /* partially implemented fix for HS enumeration */
                USB_DeviceHsPhyChirpIssueWorkaround(g_HostHandle);
                timestamp = getTimeMs();
            }
        }
        triggerTestProcess(&handle);

        if (getTimeSinceMs(guiTimestamp) > 40) {
        //     // APPW_Exec();
            GUI_Delay(1);
            guiTimestamp = getTimeMs();
        }
    }
}
