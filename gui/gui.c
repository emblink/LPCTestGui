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

static void screenMenuCb(WM_MESSAGE * pMsg)
{
    int Id, NCode;
    BUTTON_Handle hButton;
    char acBuffer[64];
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

        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();
        GUI_SetColor(GUI_LIGHTBLUE);
        GUI_DispStringAt("Menu Screen", 10, 10);
        break;
    case WM_NOTIFY_PARENT:
        //
        // Since the button is a child of this window, reacts on the button
        // are sent to its parent window.
        //
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
    int Id, NCode;
    BUTTON_Handle hButton;
    static WM_HWIN hBox;
    int Value;
    char acBuffer[64];
    int State;

    switch(pMsg->MsgId) {
    case WM_CREATE:
        hButton = BUTTON_CreateEx(10, LCD_GetYSize() - 50, 100, 40, pMsg->hWin, WM_CF_SHOW, 0, ID_BUTTON_BACK);
        BUTTON_SetText(hButton, "Back");

        hBox = CHECKBOX_CreateEx(350, 10, 80, 25, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_CHECK0);
        //
        // Edit widget properties.
        //
        CHECKBOX_SetText(hBox, "x10");
        CHECKBOX_SetTextColor(hBox, GUI_GREEN);
        CHECKBOX_SetFont(hBox, &GUI_Font16_1);
        //
        // Manually set the state
        //
        CHECKBOX_SetState(hBox, 1);
        break;
    case WM_PAINT:
        //
        // This case is called everytime the window has to be redrawn
        //
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();

        GUI_SetFont(&GUI_Font16_1);
        GUI_SetColor(GUI_LIGHTBLUE);
        GUI_DispStringAt("Test screen", 380, 240);
        //
        // Display current CHECKBOX state.
        //
        GUI_SetFont(&GUI_Font16_1);
        GUI_SetColor(GUI_BLACK);
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
        case GUI_ID_CHECK0:
            if (NCode == WM_NOTIFICATION_CLICKED) {
                // TODO: set x10 multiplier
                //
                // When the value of the checkbox changed, redraw parent window to update the display of the state.
                //
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
