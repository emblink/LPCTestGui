#include "stdint.h"

#define USB_HOST_HID_PROTOCOL_UNSUPPORTED 0xFF

uint8_t parseReportDescriptorProtocol(uint8_t const *reportDescriptor, uint32_t reportLength);
