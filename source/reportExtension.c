#include "stdint.h"
#include "reportExtension.h"

static const uint8_t ReportExtensionBytes[5] = {
    0x06, 0x00, 0xFF,  // Usage Page (Vendor Defined 0xFF00)
	0x09, 0xF1,        // Usage (0xF1)
};

bool isReportExtensionSupported(uint8_t const *reportDescriptor, uint32_t reportLength)
{
    uint32_t matchCount = 0;
    for (uint32_t i = 0; i < reportLength; i++) {
        if (reportDescriptor[i] == ReportExtensionBytes[matchCount]) {
            matchCount++;
        } else if (matchCount > 0) {
            matchCount = 0;
            if (reportDescriptor[i] == ReportExtensionBytes[matchCount])
                matchCount++;
        }

        if (matchCount == sizeof(ReportExtensionBytes))
            return true;
    }
    return false;
}
