#include <stdbool.h>
#include <stdio.h>
#include "DIALOG.h"
#include "corsairLogoCubeGif100x100_30fps.h"
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

static void _cbWinScreenSaver(WM_MESSAGE * pMsg) {
    int           Id, NCode;
    static int    Clicked, Released;
    BUTTON_Handle hButton;
    char          acBuffer[64];
    static IMAGE_Handle logo;

    switch(pMsg->MsgId) {
    case WM_CREATE:
        //
        // Create a button as child of this window.
        //
        // hButton = BUTTON_CreateEx(190, 230, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_UNLOCK);
        // BUTTON_SetText(hButton, "Press to unlock");
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
    case WM_NOTIFY_PARENT:
        //
        // Since the button is a child of this window, reacts on the button
        // are sent to its parent window.
        //
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        //
        // Check if notification was sent from the button.
        //
        if (Id == ID_IMAGE_CORSAIR_LOGO && NCode == WM_NOTIFICATION_CLICKED) {
            WM_HideWin(screenHandle[SCREEN_ID_SAVER]);
            WM_ShowWin(screenHandle[SCREEN_ID_MENU]);
            WM_InvalidateWindow(pMsg->hWin);
        }
    default:
        WM_DefaultProc(pMsg);
    }
}

static void screenSaverCb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId) {
    case WM_CREATE:
        WM_CreateWindowAsChild(0, 0, LCD_GetXSize(), LCD_GetYSize(), pMsg->hWin, WM_CF_SHOW, _cbWinScreenSaver, 0);
        break;
    case WM_PAINT:
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
        //
        // Anything drawn here will be how the button looks.
        //
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
        //
        // Anything else apart from drawing is handled by the default callback.
        //
        BUTTON_Callback(pMsg);
    }
}

static void _cbWin(WM_MESSAGE * pMsg) {
    int           Id, NCode;
    static int    Clicked, Released;
    BUTTON_Handle hButton;
    char          acBuffer[64];
    GUI_RECT Rect;

    switch(pMsg->MsgId) {
    case WM_CREATE:
        //
        // Create a button as child of this window.
        //
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
        //
        // This case is called everytime the window has to be redrawn
        //
        if (BUTTON_IsPressed(pMsg->hWin)) {
            GUI_SetColor(GUI_LIGHTRED);
        } else {
            GUI_SetColor(GUI_GRAY_AA);
        }
        WM_GetClientRect(&Rect);
        Rect.x0 += 1;
        Rect.x1 -= 1;
        Rect.y0 += 1;
        Rect.y1 -= 1;
        GUI_FillRoundedRectEx(&Rect, 3);
        GUI_SetColor(GUI_BLACK);
        GUI_DrawRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, 3);
        GUI_SetColor(GUI_WHITE);
        GUI_SetTextMode(GUI_TM_TRANS);
        GUI_DispStringInRect("Button", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);

        GUI_SetBkColor(GUI_LIGHTCYAN);
        GUI_Clear();
        GUI_SetColor(GUI_BLACK);
        GUI_DispStringAt("Menu Screen", 10, 10);
        break;
    case WM_NOTIFY_PARENT:
        //
        // Since the button is a child of this window, reacts on the button
        // are sent to its parent window.
        //
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        //
        // Check if notification was sent from the button.
        //
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
        //
        // Check for the correct notification code.
        //
        default:
            break;
        }
        break;
    default:
        WM_DefaultProc(pMsg);
    }
}


static void screenMenuCb(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId) {
    case WM_CREATE:
        WM_CreateWindowAsChild(0, 0, LCD_GetXSize(), LCD_GetYSize(), pMsg->hWin, WM_CF_SHOW, _cbWin, 0);
        break;
    case WM_PAINT:
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static const CHECKBOX_SKINFLEX_PROPS _PropsEnabled = {
  { GUI_BLUE, GUI_WHITE, GUI_MAGENTA },
  { GUI_GRAY_3F, GUI_GRAY_AA },
  GUI_RED,
  20
};

static void _cbStandartTest(WM_MESSAGE * pMsg) {
    int Id, NCode;
    static SPINBOX_Handle hSpinbox;
    BUTTON_Handle hButton;
    int Value;
    char acBuffer[64];

    switch(pMsg->MsgId) {
    case WM_CREATE:
        //
        // Create a button as child of this window.
        //
        hButton = BUTTON_CreateEx(10, LCD_GetYSize() - 50, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_BACK);
        BUTTON_SetText(hButton, "Back");

        //
        // Create spinbox widget
        //
        hSpinbox = SPINBOX_CreateEx(10, 10, 150, 50, pMsg->hWin, WM_CF_SHOW, GUI_ID_SPINBOX0, 0, 100);
        //
        // Manually edit the range
        //
        SPINBOX_SetRange(hSpinbox, 1, 100);
        //
        // Set step if required
        //
        SPINBOX_SetStep(hSpinbox, 1);
        //
        // Change appearance if wanted
        //
        SPINBOX_SetFont(hSpinbox, &GUI_Font32_1);
        SPINBOX_SetTextColor(hSpinbox, SPINBOX_CI_ENABLED, GUI_RED);
        SPINBOX_SetBkColor(hSpinbox, SPINBOX_CI_ENABLED, GUI_GRAY_AA);

        CHECKBOX_Handle hBox = CHECKBOX_CreateEx(350, 10, 25, 25, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_CHECK0);
        // CHECKBOX_SetTextColor(hBox, GUI_WHITE);
        CHECKBOX_SetText(hBox, "x10");
        CHECKBOX_SetBoxBkColor(hBox, GUI_WHITE, CHECKBOX_CI_ENABLED);
        // //
        // // Set skinning properties
        // //
        // CHECKBOX_SetSkinFlexProps(&_PropsEnabled, CHECKBOX_SKINFLEX_PI_ENABLED);
        // //
        // Manually set the button size property
        //
        CHECKBOX_SetSkinFlexButtonSize(hBox, 25);
        break;
    case WM_PAINT:
        //
        // This case is called everytime the window has to be redrawn
        //
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();
        GUI_SetFont(&GUI_Font16_1);
        GUI_SetColor(GUI_WHITE);
        GUI_DispStringAt("Test screen 2", 240, 240);
        // //
        // // Display current value
        // //
        // Value = SPINBOX_GetValue(hSpinbox);
        // sprintf(acBuffer, "The current value is: %d", Value);
        // GUI_DispStringAt(acBuffer, 10, 50);
        break;
    case WM_NOTIFY_PARENT:
        //
        // Since the button is a child of this window, reacts on the button
        // are sent to its parent window.
        //
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        //
        // Check if notification was sent from the button.
        //
        switch(Id) {
        case ID_BUTTON_BACK:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                WM_HideWin(screenHandle[SCREEN_ID_TEST]);
                WM_ShowWin(screenHandle[SCREEN_ID_MENU]);
            }
            break;
        case GUI_ID_SPINBOX0:
            switch(NCode) {
            case WM_NOTIFICATION_VALUE_CHANGED:
                //
                // Redraw the window when a value has changed so the displayed value will be updated.
                //
                WM_InvalidateWindow(pMsg->hWin);
                break;
            default:
                break;
            }
        case GUI_ID_CHECK0:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                // TODO: set x10 multiplier
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
    switch (pMsg->MsgId) {
    case WM_CREATE:
        //
        // We land here right after the window has been created.
        //
        WM_CreateWindowAsChild(0, 0, LCD_GetXSize(), LCD_GetYSize(), pMsg->hWin, WM_CF_SHOW, _cbStandartTest, 0);
        break;
    case WM_PAINT:
        break;
    default:
        WM_DefaultProc(pMsg);
        break;
    }
}

static WM_CALLBACK *screenCb[SCREEN_ID_COUNT] = {
    screenSaverCb,
    screenMenuCb,
    screenTestCb
};

bool guiInit(void) {
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
