#include "reportDescriptorParser.h"
#include "usbUsagePages.h"

uint8_t parseReportDescriptorProtocol(uint8_t const *reportDescriptor, uint32_t reportLength)
{
    for (uint32_t i = 0; i < reportLength; i++) {
        if (reportDescriptor[i] == USAGE_PAGE_PREFIX && reportDescriptor[i + 1] == UsagePageGenericDesktopControls) {
            if (reportDescriptor[i + 2] == USAGE_PREFIX) {
                if (reportDescriptor[i + 3] == UsageMouse) {
                    return 2;
                } else if (reportDescriptor[i + 3] == UsageKeyboard) {
                    return 1;
                } else {
                    continue;
                }
            }
        }
    }
    return USB_HOST_HID_PROTOCOL_UNSUPPORTED;
}