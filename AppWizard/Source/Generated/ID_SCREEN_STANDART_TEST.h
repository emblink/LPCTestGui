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
File        : ID_SCREEN_STANDART_TEST.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef ID_SCREEN_STANDART_TEST_H
#define ID_SCREEN_STANDART_TEST_H

#include "AppWizard.h"

/*********************************************************************
*
*       Objects
*/
#define ID_BOX_00                  (GUI_ID_USER + 0)
#define ID_TEXT_QUANTITY           (GUI_ID_USER + 1)
#define ID_EDIT_QUANTITY           (GUI_ID_USER + 2)
#define ID_BUTTON_X10_MULTIPLYER   (GUI_ID_USER + 3)
#define ID_BUTTON_X1000_MULTIPLYER (GUI_ID_USER + 4)
#define ID_SLIDER_QUANTITY         (GUI_ID_USER + 5)
#define ID_TEXT_PRESS_PERIOD       (GUI_ID_USER + 6)
#define ID_EDIT_PERIOD             (GUI_ID_USER + 7)
#define ID_SLIDER_PRESS_PERIOD     (GUI_ID_USER + 8)
#define ID_TEXT_PRESS_DURATION     (GUI_ID_USER + 9)
#define ID_EDIT_PRESS_DURATION     (GUI_ID_USER + 10)
#define ID_SLIDER_PRESS_DURATION   (GUI_ID_USER + 11)
#define ID_BUTTON_CLEAR            (GUI_ID_USER + 12)
#define ID_BUTTON_BACK             (GUI_ID_USER + 13)
#define ID_BUTTON_CONSOLE          (GUI_ID_USER + 14)
#define ID_BUTTON_SD_CARD          (GUI_ID_USER + 15)
#define ID_BUTTON_START            (GUI_ID_USER + 16)

/*********************************************************************
*
*       Slots
*/
void ID_SCREEN_STANDART_TEST__ID_SLIDER_QUANTITY__WM_NOTIFICATION_VALUE_CHANGED                                                (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_QUANTITY__APPW_JOB_SETVALUE                               (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_SLIDER_PRESS_PERIOD__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_PRESS_PERIOD__APPW_JOB_SETVALUE   (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_00__ID_SLIDER_01__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_01__APPW_JOB_SETVALUE                                  (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_SLIDER_PRESS_DURATION__WM_NOTIFICATION_VALUE_CHANGED                                          (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_SLIDER_PRESS_DURATION__WM_NOTIFICATION_VALUE_CHANGED__ID_EDIT_RELEASE_DELAY__APPW_JOB_SETVALUE(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_EDIT_QUANTITY__APPW_JOB_SETVALUE                    (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_EDIT_PERIOD__APPW_JOB_SETVALUE                      (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_EDIT_PRESS_DURATION__APPW_JOB_SETVALUE              (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_BUTTON_X10_MULTIPLYER__APPW_JOB_CLEAR               (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_BUTTON_X1000_MULTIPLYER__APPW_JOB_CLEAR             (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_BACK__WM_NOTIFICATION_CLICKED                                                          (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_BACK__WM_NOTIFICATION_CLICKED__ID_BUTTON_CLEAR__APPW_JOB_TOGGLE                        (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_CONSOLE__WM_NOTIFICATION_CLICKED__ID_BUTTON_SD_CARD__APPW_JOB_TOGGLE                   (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_STANDART_TEST__ID_BUTTON_SD_CARD__WM_NOTIFICATION_CLICKED__ID_BUTTON_CONSOLE__APPW_JOB_TOGGLE                   (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);

/*********************************************************************
*
*       Callback
*/
void cbID_SCREEN_STANDART_TEST(WM_MESSAGE * pMsg);

#endif  // ID_SCREEN_STANDART_TEST_H

/*************************** End of file ****************************/
