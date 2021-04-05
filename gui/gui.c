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
    ID_BUTTON_UNLOCK,
    ID_BUTTON_STANDART_TEST,
    ID_BUTTON_LOCK,
    ID_BUTTON_TRIGGER_CHECK,
    ID_BUTTON_RESET_BOARD,
    ID_BUTTON_BACK,
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
        //
        // This case is called everytime the window has to be redrawn
        //
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

static void _cbTriggerButton(WM_MESSAGE * pMsg)
{
    GUI_RECT Rect;
    static bool triggerState = 0;

    switch(pMsg->MsgId) {
    case WM_PAINT:
        // Anything drawn here will be how the button looks.
        if (BUTTON_IsPressed(pMsg->hWin)) {
            triggerState = !triggerState;
        }
        if (triggerState) {
            GUI_SetColor(GUI_GREEN);
        } else {
            GUI_SetColor(GUI_GRAY_C8);
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
        if (triggerState) {
            GUI_DispStringInRect("Trigger ON", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
        } else {
            GUI_DispStringInRect("Trigger OFF", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
        }
        break;
    default:
        // Anything else apart from drawing is handled by the default callback.
        BUTTON_Callback(pMsg);
    }
}

static void screenMenuCb(WM_MESSAGE * pMsg)
{
    int Id, NCode;
    BUTTON_Handle hButton;
    char acBuffer[64];
    GUI_RECT Rect;

    switch(pMsg->MsgId) {
    case WM_CREATE:
        // Create a button as child of this window.
        hButton = BUTTON_CreateEx(100, 50, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_STANDART_TEST);
        BUTTON_SetText(hButton, "Standart test");
        hButton = BUTTON_CreateEx(300, 50, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_LOCK);
        BUTTON_SetText(hButton, "Lock");
        hButton = BUTTON_CreateEx(100, 150, 100, 40, pMsg->hWin, WM_CF_SHOW , 0, ID_BUTTON_TRIGGER_CHECK);
        WM_SetCallback(hButton, _cbTriggerButton);
        hButton = BUTTON_CreateEx(300, 150, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_RESET_BOARD);
        BUTTON_SetText(hButton, "Reset Board");
        break;
    case WM_PAINT:
        // This case is called everytime the window has to be redrawn
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();
        GUI_SetColor(GUI_LIGHTBLUE);
        GUI_DispStringAt("Menu Screen", 10, 10);
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

            }
            break;
        case ID_BUTTON_RESET_BOARD:
            if (NCode == WM_NOTIFICATION_RELEASED) {
                onBoardReset();
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
        hButton = BUTTON_CreateEx(10, LCD_GetYSize() - 50, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_BACK);
        BUTTON_SetText(hButton, "Back");

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

        // Create SWITCH widget.
        hSwitchRandomTest = SWITCH_CreateUser(380, 150, 80, 30, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_SWITCH0, 0);
        // Set background bitmaps for different states.
        SWITCH_SetBitmap(hSwitchRandomTest, SWITCH_BI_BK_LEFT,     &bmLeft_80x30);
        SWITCH_SetBitmap(hSwitchRandomTest, SWITCH_BI_BK_RIGHT,    &bmRight_80x30);
        SWITCH_SetBitmap(hSwitchRandomTest, SWITCH_BI_BK_DISABLED, &bmDisabled_80x30);
        // Set thumb bitmaps for different states.
        SWITCH_SetBitmap(hSwitchRandomTest, SWITCH_BI_THUMB_LEFT,     &bmThumbLeft_30x30);
        SWITCH_SetBitmap(hSwitchRandomTest, SWITCH_BI_THUMB_RIGHT,    &bmThumbRight_30x30);
        SWITCH_SetBitmap(hSwitchRandomTest, SWITCH_BI_THUMB_DISABLED, &bmThumbDisabled_30x30);
        // Set font.
        SWITCH_SetFont(hSwitchRandomTest, &GUI_Font16_ASCII);
        // Set texts for different states.
        SWITCH_SetText(hSwitchRandomTest, SWITCH_TI_LEFT,  "On");
        SWITCH_SetText(hSwitchRandomTest, SWITCH_TI_RIGHT, "Off");
        // Set text colors for different states.
        SWITCH_SetTextColor(hSwitchRandomTest, SWITCH_TI_LEFT,  GUI_BLACK);
        SWITCH_SetTextColor(hSwitchRandomTest, SWITCH_TI_RIGHT, GUI_RED);
        // Set SWITCH to fade mode.
        SWITCH_SetMode(hSwitchRandomTest, SWITCH_MODE_FADE);
        // Change period it takes to stop the animation.
        SWITCH_SetPeriod(hSwitchRandomTest, 75);

        // Create quantity text
        TEXT_Handle hTextQuantity = TEXT_CreateEx(5, 0, 70, 20, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_TEXT0, "Quantity");
        TEXT_SetBkColor(hTextQuantity, GUI_BLACK);
        TEXT_SetFont(hTextQuantity, &GUI_Font20_1);
        TEXT_SetTextColor(hTextQuantity, GUI_LIGHTBLUE);

        // Create quantity edit
        hEditQuantity = EDIT_CreateEx(5, 20, 70, 30, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_EDIT0, 6);
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
        DROPDOWN_SetTextColor(hDropdown, DROPDOWN_CI_UNSEL, GUI_LIGHTRED); 
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

        // Display screen name
        GUI_SetColor(GUI_LIGHTBLUE);
        GUI_DispStringAt("Test screen", 380, 240);
    
        // Display state of SWITCH widget.
        GUI_SetColor(GUI_YELLOW);
        GUI_SetFont(&GUI_Font16B_1);
        GUI_DispStringAt("Random test", 380, 130);
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
    // Enable multi-buffering to avoid flickering.
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
