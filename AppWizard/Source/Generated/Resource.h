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
File        : Resource.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef RESOURCE_H
#define RESOURCE_H

#include "AppWizard.h"

/*********************************************************************
*
*       Keyboard layouts
*/
extern const unsigned char acSKEYBOARD_NUMPAD[];

/*********************************************************************
*
*       Text
*/
#define ID_RTEXT_0 0
#define ID_RTEXT_1 1
#define ID_RTEXT_2 2
#define ID_RTEXT_3 3
#define ID_RTEXT_4 4
#define ID_RTEXT_5 5
#define ID_RTEXT_6 6
#define ID_RTEXT_7 7
#define ID_RTEXT_8 8
#define ID_RTEXT_9 9
#define ID_RTEXT_10 10
#define ID_RTEXT_11 11
#define ID_RTEXT_12 12

#define APPW_MANAGE_TEXT APPW_MANAGE_TEXT_EXT
extern const unsigned char acAPPW_Language_0[];

/*********************************************************************
*
*       Fonts
*/
extern const unsigned char acNettoOT_16_Normal_EXT_AA4[];
extern const unsigned char acRoboto_24_Normal_EXT_AA4[];

/*********************************************************************
*
*       Images
*/
extern const unsigned char acButtonDarkUnpressed_100x30[];
extern const unsigned char acButtonDarkPressed_100x30[];
extern const unsigned char accorsairLogoCubeGif100x100_30fps[];
extern const unsigned char acSliderDarkBlueLeft_30x16[];
extern const unsigned char acSliderDarkGrayRight_30x16[];
extern const unsigned char acSliderDarkThumbUnpressed_22x22[];

/*********************************************************************
*
*       Screens
*/
#define ID_SCREEN_SCREENSAVER (GUI_ID_USER + 4096)
#define ID_SCREEN_CHOOSE_TEST (GUI_ID_USER + 4097)
#define ID_SCREEN_STANDART_TEST (GUI_ID_USER + 4098)

extern APPW_ROOT_INFO ID_SCREEN_SCREENSAVER_RootInfo;
extern APPW_ROOT_INFO ID_SCREEN_CHOOSE_TEST_RootInfo;
extern APPW_ROOT_INFO ID_SCREEN_STANDART_TEST_RootInfo;

#define APPW_INITIAL_SCREEN &ID_SCREEN_SCREENSAVER_RootInfo

/*********************************************************************
*
*       Project path
*/
#define APPW_PROJECT_PATH "D:/__Developex__Work__/GUI/AppWizard"

#endif  // RESOURCE_H

/*************************** End of file ****************************/
