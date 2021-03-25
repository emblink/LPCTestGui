#include "stdbool.h"

#define REPORT_EXTENSION_DATA_LENGTH 5

typedef enum {
	ReportExtensionIdWirelessMouse = 0x01,
	ReportExtensionIdWiredMouse = 0x02,
	ReportExtensionIdLatency = 0x03,
} ReportExtensionId;

/* function searches for extension descriptor defined by USB Report Extensions Revision 1.1 specification */
bool isReportExtensionSupported(uint8_t const *reportDescriptor, uint32_t reportLength);
