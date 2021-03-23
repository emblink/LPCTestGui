/*********************************************************************
*                     SEGGER Microcontroller GmbH                    *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2021  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File        : ID_SCREEN_MAIN.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef ID_SCREEN_MAIN_H
#define ID_SCREEN_MAIN_H

#include "AppWizard.h"

/*********************************************************************
*
*       Objects
*/
#define ID_BOX_00               (GUI_ID_USER + 0)
#define ID_SLIDER_PERIOD        (GUI_ID_USER + 1)
#define ID_EDIT_SLIDER_PERIOD   (GUI_ID_USER + 2)
#define ID_TEXT_PROJECT_NAME    (GUI_ID_USER + 3)
#define ID_TEXT_00              (GUI_ID_USER + 4)
#define ID_SLIDER_QUANTITY      (GUI_ID_USER + 5)
#define ID_TEXT_PERIOD          (GUI_ID_USER + 6)
#define ID_EDIT_SLIDER_QUANTITY (GUI_ID_USER + 7)
#define ID_SWITCH_00            (GUI_ID_USER + 8)
#define ID_TEXT_02              (GUI_ID_USER + 9)
#define ID_SWITCH_01            (GUI_ID_USER + 10)
#define ID_KEYBOARD_00          (GUI_ID_USER + 11)
#define ID_TEXT_03              (GUI_ID_USER + 12)
#define ID_BUTTON_RESET         (GUI_ID_USER + 13)
#define ID_BUTTON_START         (GUI_ID_USER + 14)
#define ID_BUTTON_00            (GUI_ID_USER + 15)
#define ID_BUTTON_01            (GUI_ID_USER + 16)

/*********************************************************************
*
*       Slots
*/
void ID_SCREEN_00__ID_SLIDER_00__WM_NOTIFICATION_VALUE_CHANGED__ID_EDIT_00__APPW_JOB_SETVALUE(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_00__ID_SLIDER_01__WM_NOTIFICATION_VALUE_CHANGED__ID_EDIT_01__APPW_JOB_SETVALUE(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_00__ID_SLIDER_PERIOD__WM_NOTIFICATION_VALUE_CHANGED                           (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_00__ID_SLIDER_QUANTITY__WM_NOTIFICATION_VALUE_CHANGED                         (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_00__ID_BUTTON_RESET__WM_NOTIFICATION_CLICKED                                  (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_00__ID_BUTTON_RESET__WM_NOTIFICATION_CLICKED_0                                (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);

/*********************************************************************
*
*       Callback
*/
void cbID_SCREEN_MAIN(WM_MESSAGE * pMsg);

#endif  // ID_SCREEN_MAIN_H

/*************************** End of file ****************************/
