#define USAGE_PAGE_PREFIX 0x05
#define USAGE_PREFIX 0x09

typedef enum {
    UsagePageUndefined = 0x00,
    UsagePageGenericDesktopControls = 0x01,
    UsagePageKeyboardKeypad = 0x07,
    UsagePageLEDs = 0x08,
    UsagePageButton = 0x09,
    UsagePageConsumer = 0x0C,
} UsagePage;

typedef enum {
    UsageUndefined = 0x00,
    UsagePointer = 0x01,
    UsageMouse = 0x02,
    UsageReserved = 0x03,
    UsageJoystick = 0x04,
    UsageGamePad = 0x05,
    UsageKeyboard = 0x06,
    UsageKeypad = 0x07,
} Usage;
