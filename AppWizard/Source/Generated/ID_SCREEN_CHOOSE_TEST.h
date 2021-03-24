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
File        : ID_SCREEN_CHOOSE_TEST.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef ID_SCREEN_CHOOSE_TEST_H
#define ID_SCREEN_CHOOSE_TEST_H

#include "AppWizard.h"

/*********************************************************************
*
*       Objects
*/
#define ID_BOX_00               (GUI_ID_USER + 0)
#define ID_BUTTON_STANDART_TEST (GUI_ID_USER + 1)
#define ID_BUTTON_RANDOM_TEST   (GUI_ID_USER + 2)
#define ID_BUTTON_PATTERN_TEST  (GUI_ID_USER + 3)
#define ID_TEXT_00              (GUI_ID_USER + 4)

/*********************************************************************
*
*       Slots
*/
void ID_SCREEN_CHOOSE_TEST__ID_BUTTON_STANDART_TEST__WM_NOTIFICATION_CLICKED(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);

/*********************************************************************
*
*       Callback
*/
void cbID_SCREEN_CHOOSE_TEST(WM_MESSAGE * pMsg);

#endif  // ID_SCREEN_CHOOSE_TEST_H

/*************************** End of file ****************************/