#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "DIALOG.h"
#include "corsairLogoCubeGif100x100_30fps.h"
#include "toggleSwitch.h"
#include "version.h"

typedef enum {
    SCREEN_ID_SAVER,
    SCREEN_ID_MENU,
    SCREEN_ID_TEST,
    SCREEN_ID_COUNT,
} SCREEN_ID;

static WM_HWIN screenHandle[SCREEN_ID_COUNT] = {0};

typedef enum {
    ID_BUTTON_UNLOCK = GUI_ID_BUTTON0,
    ID_BUTTON_STANDART_TEST,
    ID_BUTTON_LOCK,
    ID_BUTTON_TRIGGER_CHECK,
    ID_BUTTON_RESET_BOARD,
    ID_BUTTON_CLEAR_LOG,
    ID_BUTTON_BACK,
    ID_BUTTON_CLEAR,
    ID_BUTTON_START,
    ID_BUTTON_COUNT,
} ID_BUTTON;

typedef enum {
    ID_IMAGE_CORSAIR_LOGO,
} ID_IMAGE;

extern void onBoardReset(void);

static void screenSaverCb(WM_MESSAGE * pMsg)
{
    int Id, NCode;
    char acBuffer[64];
    static IMAGE_Handle logo;

    switch (pMsg->MsgId) {
    case WM_CREATE:
        logo = IMAGE_CreateEx(190, 84, 100, 100, pMsg->hWin, WM_CF_SHOW, 0, ID_IMAGE_CORSAIR_LOGO);
        IMAGE_SetGIF(logo, accorsairLogoCubeGif100x100_30fps, sizeof(accorsairLogoCubeGif100x100_30fps));
        break;
    case WM_PAINT:
        // This case is called everytime the window has to be redrawn
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();
        GUI_SetFont(&GUI_Font20_ASCII);
        GUI_SetColor(GUI_LIGHTYELLOW);
        sprintf(acBuffer, "Latency test v%u.%u.%u", PROJECT_MAJOR_VERSION, PROJECT_MINOR_VERSION, PROJECT_BUILD_NUMBER);
        GUI_DispStringAt(acBuffer, 150, 10);
        GUI_SetFont(&GUI_Font16_ASCII);
        GUI_SetColor(GUI_LIGHTBLUE);
        GUI_DispStringAt("Press logo to unlock", 180, 250);
        break;
    case WM_TOUCH_CHILD:
        // logo image is child here
        WM_HideWin(screenHandle[SCREEN_ID_SAVER]);
        WM_ShowWin(screenHandle[SCREEN_ID_MENU]);
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static bool triggerState = false;
extern void onTriggerPress(bool triggerIsOn);

static void _cbTriggerButton(WM_MESSAGE * pMsg)
{
    GUI_RECT Rect;
    switch(pMsg->MsgId) {
    case WM_PAINT:
        // Anything drawn here will be how the button looks.
        if (BUTTON_IsPressed(pMsg->hWin)) {
            triggerState = !triggerState;
        }
        if (triggerState) {
            GUI_SetColor(GUI_GREEN);
        } else {
            GUI_SetColor(GUI_DARKRED);
        }
        WM_GetClientRect(&Rect);
        Rect.x0 += 1;
        Rect.x1 -= 1;
        Rect.y0 += 1;
        Rect.y1 -= 1;
        GUI_FillRoundedRectEx(&Rect, 3);
        GUI_DrawRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 3);
        GUI_SetColor(GUI_BLACK);
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_SetFont(&GUI_Font13B_1);
        if (triggerState) {
            GUI_SetColor(GUI_BLACK);
            GUI_DispStringInRect("Trigger\nON", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
        } else {
            GUI_SetColor(GUI_WHITE);
            GUI_DispStringInRect("Trigger\nOFF", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
        }
        break;
    default:
        // Anything else apart from drawing is handled by the default callback.
        BUTTON_Callback(pMsg);
    }
}

#define MSG_UPDATE_TERMINAL (WM_USER + 0x01)
static WM_HWIN hTerminal;
static char terminalBuff[1024] = {'\0'};
static uint32_t terminalBuffIdx = 0;

static void guiTerminalUpdate(void)
{
    WM_MESSAGE Message;
    // Fill message struct with data needed for the message
    Message.hWin = hTerminal; // Window to receive the message
    Message.hWinSrc = hTerminal; // Source window sending the message
    Message.MsgId = MSG_UPDATE_TERMINAL;    // Message ID
    // Message.Data.v  = GUI_GetTime(); // Custom data value
    WM_SendMessage(hTerminal, &Message);
}

void guiTerminalEcho(const char *message, int len)
{
    if (terminalBuffIdx + len + 1 > sizeof(terminalBuff) - 1) {
        terminalBuffIdx = 0;
    }
    while(*message) {
        terminalBuff[terminalBuffIdx++] = *message++;
    }
    terminalBuff[terminalBuffIdx] = '\0';
    guiTerminalUpdate();
}

static void _cbTerminal(WM_MESSAGE * pMsg)
{
    GUI_RECT         Rect;
    GUI_RECT         CRect;
    WM_MOTION_INFO * pInfo;
    WM_SCROLL_STATE State;
    static int       yOffset;
    static int       MaxOffset;

    switch (pMsg->MsgId) {
    case WM_MOTION:
        pInfo = (WM_MOTION_INFO *)pMsg->Data.p;
        switch (pInfo->Cmd) {
        case WM_MOTION_INIT:
            // Tell the motion module to move in y direction and that we manage it on our own
            pInfo->Flags = WM_CF_MOTION_Y | WM_MOTION_MANAGE_BY_WINDOW;
        break;
        case WM_MOTION_MOVE:
            // Move the text rectangle up or down
            yOffset += pInfo->dy;
            // if (pInfo->dy > 0) {
            //     SCROLLBAR_Inc(hTerminalScroll);
            // } else {
            //     SCROLLBAR_Dec(hTerminalScroll);
            // }
            if (yOffset < MaxOffset) {
                // If reach the end, make sure we stop there
                yOffset = MaxOffset;
                pInfo->StopMotion = 1;
            }
            else if (yOffset > 0) {
                // If reach the top, make sure we stop there
                yOffset = 0;
                pInfo->StopMotion = 1;
            }
            // Tell the window to redraw
            WM_InvalidateWindow(pMsg->hWin);
        break;
        case WM_MOTION_GETPOS:
            pInfo->yPos = yOffset;
        break;
        }
        break;
    case WM_PAINT:
        // Draw something
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();

        GUI_SetColor(GUI_BLACK);
        WM_GetClientRect(&Rect);
        Rect.x0 += 2;
        Rect.y0 += 2;
        Rect.x1 -= 2;
        Rect.y1 -= 2;
        GUI_SetPenSize(2);
        GUI_DrawGradientRoundedV(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 3, GUI_MAKE_COLOR(0x00DFD9CF), GUI_MAKE_COLOR(0x00F0EBE2));
        GUI_AA_DrawRoundedRectEx(&Rect, 3);
        // Copy current rectangle into a clip rectangle
        CRect = Rect;
        GUI_SetClipRect(&CRect);
        // Prepare rect to display text
        Rect.x0 += 10;
        Rect.y0 += 10;
        Rect.x1 -= 10;
        Rect.y1 -= 10;
        GUI_SetFont(&GUI_Font13_1);
        // Calculate size of rectangle, so that the entire text will fit in
        Rect.y1 += GUI_WrapGetNumLines(terminalBuff, Rect.x1 - Rect.x0, GUI_WRAPMODE_WORD) * GUI_GetFontSizeY();
        // Calculate MaxOffset, so that the scrolling ends right at the end of the text
        MaxOffset = -(Rect.y1) / 2;
        // Add the current yOffset to the rectangle, so the text is displayed accordingly
        Rect.y0 += yOffset;
        Rect.y1 += yOffset;
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_SetFont(&GUI_Font13_1);
        GUI_DispStringInRectWrap(terminalBuff, &Rect, GUI_TA_LEFT, GUI_WRAPMODE_WORD);
        // Clear the clipping rectangle
        GUI_SetClipRect(NULL);
        break;
    case MSG_UPDATE_TERMINAL:
        WM_InvalidateWindow(pMsg->hWin);
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static void screenMenuCb(WM_MESSAGE * pMsg)
{
    int Id, NCode;
    BUTTON_Handle hButton;
    char acBuffer[64];
    GUI_RECT Rect;
    switch(pMsg->MsgId) {
    case WM_CREATE:6
        // Create a button as child of this window.
        hButton = BUTTON_CreateEx(400, 5, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_STANDART_TEST);
        BUTTON_SetText(hButton, "Standart Test");
        hButton = BUTTON_CreateEx(400, 60, 75, 40, pMsg->hWin, WM_CF_SHOW , 0, ID_BUTTON_TRIGGER_CHECK);
        WM_SetCallback(hButton, _cbTriggerButton);
        hButton = BUTTON_CreateEx(400, 115, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_LOCK);
        BUTTON_SetText(hButton, "Lock");
        hButton = BUTTON_CreateEx(400, 170, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_RESET_BOARD);
        BUTTON_SetText(hButton, "Reset Board");
        hButton = BUTTON_CreateEx(400, 225, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_CLEAR_LOG);
        BUTTON_SetText(hButton, "Clear Log");
        // Create terminal log
        hTerminal = WM_CreateWindowAsChild(5, 5, LCD_GetXSize() - 90, LCD_GetYSize() - 10, pMsg->hWin, WM_CF_SHOW | WM_CF_HASTRANS, _cbTerminal, 0);
        // hTerminalScroll = SCROLLBAR_CreateEx(375, 5, 15, WM_GetWindowSizeY(pMsg->hWin), pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_SCROLLBAR0);
        break;
    case WM_PAINT:
        // This case is called everytime the window has to be redrawn
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();
        break;
    case WM_NOTIFY_PARENT:
        // Since the button is a child of this window, reacts on the button
        // are sent to its parent window.
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id) {
        case ID_BUTTON_STANDART_TEST:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                WM_HideWin(screenHandle[SCREEN_ID_MENU]);
                WM_ShowWin(screenHandle[SCREEN_ID_TEST]);
            }
            break;
        case ID_BUTTON_LOCK:
            if (NCode == WM_NOTIFICATION_RELEASED) {
                WM_HideWin(screenHandle[SCREEN_ID_MENU]);
                WM_ShowWin(screenHandle[SCREEN_ID_SAVER]);
            }
            break;
        case ID_BUTTON_TRIGGER_CHECK:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                onTriggerPress(triggerState);
            }
            break;
        case ID_BUTTON_RESET_BOARD:
            if (NCode == WM_NOTIFICATION_RELEASED) {
                onBoardReset();
            }
            break;
        case ID_BUTTON_CLEAR_LOG:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                terminalBuffIdx = 0;
                terminalBuff[terminalBuffIdx] = '\0';
                guiTerminalUpdate();
            }
            break;
        default:
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
    }
}

static void _cbRandomTestButton(WM_MESSAGE * pMsg)
{
    static bool randomTestOn = false;
    GUI_RECT Rect;
    switch(pMsg->MsgId) {
    case WM_PAINT:
        // Anything drawn here will be how the button looks.
        if (BUTTON_IsPressed(pMsg->hWin)) {
            randomTestOn = !randomTestOn;
        }
        if (randomTestOn) {
            GUI_SetColor(GUI_GREEN);
        } else {
            // GUI_SetColor(GUI_GRAY_C8);
            GUI_SetColor(GUI_DARKRED);
        }
        WM_GetClientRect(&Rect);
        Rect.x0 += 1;
        Rect.x1 -= 1;
        Rect.y0 += 1;
        Rect.y1 -= 1;
        GUI_FillRoundedRectEx(&Rect, 3);
        GUI_DrawRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 3);
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_SetFont(&GUI_Font13B_1);
        if (randomTestOn) {
            GUI_SetColor(GUI_BLACK);
            GUI_DispStringInRect("Random\ntest ON", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
        } else {
            GUI_SetColor(GUI_WHITE);
            GUI_DispStringInRect("Random\ntest OFF", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
        }
        break;
    default:
        // Anything else apart from drawing is handled by the default callback.
        BUTTON_Callback(pMsg);
    }
}

static void screenTestCb(WM_MESSAGE * pMsg)
{
    static int Id;
    int NCode;
    int Value;
    int State;
    char acBuffer[64];

    WM_MESSAGE Message;
    WM_PID_STATE_CHANGED_INFO * pInfo;
    BUTTON_Handle hButton;
    static EDIT_Handle hEditQuantity;
    static DROPDOWN_Handle hDropdown;
    static WM_HWIN hBoxX10;
    static WM_HWIN hBoxX1000;
    static WM_HWIN hSwitchRandomTest;
    static WM_HWIN hSliderPressPeriod;
    static WM_HWIN hSliderPressHoldTime;

    static const char * _acContent[] = {
        "Console",
        "SD_Card",
    };

    switch(pMsg->MsgId) {
    case WM_CREATE:
        hButton = BUTTON_CreateEx(10, LCD_GetYSize() - 50, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_BACK);
        BUTTON_SetText(hButton, "Back");
        hButton = BUTTON_CreateEx(10 + 75 + 20, LCD_GetYSize() - 50, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_CLEAR);
        BUTTON_SetText(hButton, "Clear");
        hButton = BUTTON_CreateEx(10 + 75 + 20 + 75 + 20, LCD_GetYSize() - 50, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_START);
        BUTTON_SetText(hButton, "Start");
        hButton = BUTTON_CreateEx(380, 130, 75, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_START);
        WM_SetCallback(hButton, _cbRandomTestButton);

        hBoxX10 = CHECKBOX_CreateEx(350, 10, 60, 30, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_CHECK0);
        hBoxX1000 = CHECKBOX_CreateEx(350, 40, 80, 30, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_CHECK1);
        // Edit widget properties.
        CHECKBOX_SetText(hBoxX10, "x10");
        CHECKBOX_SetText(hBoxX1000, "x1000");
        CHECKBOX_SetTextColor(hBoxX10, GUI_GREEN);
        CHECKBOX_SetTextColor(hBoxX1000, GUI_GREEN);
        CHECKBOX_SetFont(hBoxX10, &GUI_Font16_1);
        CHECKBOX_SetFont(hBoxX1000, &GUI_Font16_1);
        // Manually set the state
        CHECKBOX_SetState(hBoxX1000, 1);
    
        // Create horizonzal slider. A vertical slider can be created with SLIDER_CF_VERTICAL instead.
        hSliderPressPeriod = SLIDER_CreateEx(10, 60, 220, 40, pMsg->hWin, WM_CF_SHOW, SLIDER_CF_HORIZONTAL, GUI_ID_SLIDER0);
        // Set range of slider
        SLIDER_SetRange(hSliderPressPeriod, 65, 1000);
        // Set number of tick marks
        SLIDER_SetNumTicks(hSliderPressPeriod, 25);
        // Set value of slider
        SLIDER_SetValue(hSliderPressPeriod, 65);
        // Set width of thumb
        SLIDER_SetWidth(hSliderPressPeriod, 25);

        // Create horizonzal slider. A vertical slider can be created with SLIDER_CF_VERTICAL instead.
        hSliderPressHoldTime = SLIDER_CreateEx(10, 110, 220, 40, pMsg->hWin, WM_CF_SHOW, SLIDER_CF_HORIZONTAL, GUI_ID_SLIDER1);
        // Set range of slider
        SLIDER_SetRange(hSliderPressHoldTime, 1, 64);
        // Set number of tick marks
        SLIDER_SetNumTicks(hSliderPressHoldTime, 25);
        // Set value of slider
        SLIDER_SetValue(hSliderPressHoldTime, 32);
        // Set width of thumb
        SLIDER_SetWidth(hSliderPressHoldTime, 25);

        // Create quantity text
        TEXT_Handle hTextQuantity = TEXT_CreateEx(10, 0, 70, 20, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_TEXT0, "Quantity");
        TEXT_SetBkColor(hTextQuantity, GUI_BLACK);
        TEXT_SetFont(hTextQuantity, &GUI_Font20_1);
        TEXT_SetTextColor(hTextQuantity, GUI_LIGHTBLUE);

        // Create quantity edit
        hEditQuantity = EDIT_CreateEx(10, 20, 70, 30, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_EDIT0, 6);
        EDIT_SetUlongMode(hEditQuantity, 1000, 1, 500000);
        EDIT_SetFont(hEditQuantity, &GUI_Font20B_1);
        EDIT_SetInsertMode(hEditQuantity, 1);
        EDIT_EnableBlink(hEditQuantity, 250, 1);
        EDIT_SetCursorAtChar(hEditQuantity, 0);

        // Create DropDown menu
        // Create listbox widget
        // The flag DROPDOWN_CF_AUTOSCROLLBAR makes sure that a scrollbar is added, if the text is too big
        hDropdown = DROPDOWN_CreateEx(380, 100, 90, GUI_COUNTOF(_acContent) * 25, pMsg->hWin, WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, GUI_ID_DROPDOWN0);
        // Add items to widget
        for (int i = 0; i < GUI_COUNTOF(_acContent); i++) {
            DROPDOWN_AddString(hDropdown, *(_acContent + i));
        }
        // Edit some properties
        DROPDOWN_SetFont(hDropdown, &GUI_Font16B_1);
        DROPDOWN_SetItemSpacing(hDropdown, 5);
        DROPDOWN_SetTextColor(hDropdown, DROPDOWN_CI_UNSEL, GUI_DARKRED); 
        break;
    case WM_PAINT:
        // This case is called everytime the window has to be redrawn
        // GUI_SetBkColor(GUI_BLACK);
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();

        // Display slider value
        GUI_SetFont(&GUI_Font16_1);
        GUI_SetColor(GUI_WHITE);
        
        Value = SLIDER_GetValue(hSliderPressPeriod);
        sprintf(acBuffer, "Period: %d, ms", Value);
        GUI_DispStringAt(acBuffer, 245, 60);
        
        Value = SLIDER_GetValue(hSliderPressHoldTime);
        sprintf(acBuffer, "Press hold: %d, ms", Value);
        GUI_DispStringAt(acBuffer, 245, 110);
        break;
    case WM_SET_ID:
        Id = pMsg->Data.v;  // Remember Id
        break;
    case WM_GET_ID:
        pMsg->Data.v = Id;  // Return Id
        break;
    case WM_SET_FOCUS:
        // If pMsg->Data.v is 1 the window manager tries to set the focus
        if (pMsg->Data.v == 1) {
            pMsg->Data.v = 0;
            Message.Data.v = WM_NOTIFICATION_GOT_FOCUS;  // Prepare get-focus message
        } else if (pMsg->Data.v == 0) {
            Message.Data.v = WM_NOTIFICATION_LOST_FOCUS; // Prepare lost-focus message
        }
        Message.MsgId   = WM_NOTIFY_PARENT;
        Message.hWin    = WM_GetParent(pMsg->hWin);
        Message.hWinSrc = pMsg->hWin;
        WM_SendMessage(Message.hWin, &Message); // Send message to parent
        break;
    case WM_PID_STATE_CHANGED:
    // Check how pid state has changed
    pInfo = (WM_PID_STATE_CHANGED_INFO *)pMsg->Data.p;
    if (pInfo) {
      // If previous state is 0 and current is 1 we have a click
      if ((pInfo->State == 1) && (pInfo->StatePrev == 0)) {
        // On click set focus to this window
        WM_SetFocus(pMsg->hWin);
      }
    }   break;
    case WM_NOTIFY_PARENT:
        // Since the button is a child of this window, reacts on the button
        // are sent to its parent window.
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        // Check if notification was sent from the button.
        switch(Id) {
        case ID_BUTTON_BACK:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                WM_HideWin(screenHandle[SCREEN_ID_TEST]);
                WM_ShowWin(screenHandle[SCREEN_ID_MENU]);
            }
            break;
        case GUI_ID_CHECK0:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                // TODO: set x10 multiplier
                //
                // When the value of the checkbox changed, redraw parent window to update the display of the state.
                //
                WM_InvalidateWindow(pMsg->hWin);
            }
            break;
        case GUI_ID_SLIDER0:
            if (NCode == WM_NOTIFICATION_VALUE_CHANGED) {
                Value = SLIDER_GetValue(hSliderPressPeriod);
                if (Value < 65) {
                    Value = 65;
                    SLIDER_SetValue(hSliderPressPeriod, Value);
                }
                int pressPeriod = SLIDER_GetValue(hSliderPressHoldTime);
                SLIDER_SetRange(hSliderPressHoldTime, 1, Value - 1);
                if (pressPeriod >= Value) {
                    SLIDER_SetValue(hSliderPressHoldTime, Value - 1);
                }
                // Redraw the window when a value has changed so the displayed value will be updated.
                WM_InvalidateWindow(pMsg->hWin);
            }
            break;
        case GUI_ID_SLIDER1:
            if (NCode == WM_NOTIFICATION_VALUE_CHANGED) {
                Value = SLIDER_GetValue(hSliderPressPeriod);
                int pressPeriod = SLIDER_GetValue(hSliderPressHoldTime);
                if (pressPeriod >= Value) {
                    SLIDER_SetValue(hSliderPressHoldTime, Value - 1);
                }
                // Redraw the window when a value has changed so the displayed value will be updated.
                WM_InvalidateWindow(pMsg->hWin);
            }
        case GUI_ID_SWITCH0:
            if (NCode == WM_NOTIFICATION_VALUE_CHANGED) {
                // Redraw parent window when the value has changed.
                WM_InvalidateWindow(pMsg->hWin);
            }
            break;
        case GUI_ID_EDIT0:
            if (NCode == WM_NOTIFICATION_GOT_FOCUS) {
                // Selects all characters of the widget
                EDIT_SetSel(hEditQuantity, 0, -1);
                EDIT_SetTextColor(hEditQuantity, GUI_ID_EDIT0, GUI_GREEN);
                // TODO: show keyboard
            } else if (NCode = WM_NOTIFICATION_LOST_FOCUS) {
                // Deselects all characters
                // EDIT_SetSel(hEditQuantity, -1, 0);
                // EDIT_SetTextColor(hEditQuantity, GUI_ID_EDIT0, GUI_LIGHTBLUE);
                // TODO: hide keyboard
            }
            break;
        case GUI_ID_DROPDOWN0:
            if (NCode == WM_NOTIFICATION_SEL_CHANGED) {
                if (DROPDOWN_GetSel(hDropdown) == 1) {
                    // WM_HWIN hMessage = GUI_MessageBox("Wait...","Initing SD_Card", GUI_MESSAGEBOX_CF_MOVEABLE);
                    // WM_HWIN hMessageMove = GUI_MessageBox("This message is movable!", "Movable Messagebox", GUI_MESSAGEBOX_CF_MOVEABLE);
                }
                // Invalidate parent window when a new item has been selected to display the new selection.
                WM_InvalidateWindow(pMsg->hWin);
            }
            break;
        default:
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
    }
}

static WM_CALLBACK *screenCb[SCREEN_ID_COUNT] = {
    screenSaverCb,
    screenMenuCb,
    screenTestCb
};

bool guiInit(void)
{
    GUI_Init();
    // Enable motion support
    WM_MOTION_Enable(1);
    // Enable multi-buffering to avoid flickering during motion
    WM_MULTIBUF_Enable(1);
    // Create screens
    for (SCREEN_ID screenID = SCREEN_ID_SAVER; screenID < SCREEN_ID_COUNT; screenID++) {
        WM_HWIN screen = WM_CreateWindowAsChild(0, 0, LCD_GetXSize(), LCD_GetYSize(),
                         WM_HBKWIN, WM_CF_SHOW, screenCb[screenID], 0);
        if (screen) {
            screenHandle[screenID] = screen;
        } else {
            return false;
        }
        WM_HideWin(screenHandle[screenID]);
    }
    WM_ShowWin(screenHandle[SCREEN_ID_SAVER]);
    return true;
}
