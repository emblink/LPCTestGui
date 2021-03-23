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

#define APPW_MANAGE_TEXT APPW_MANAGE_TEXT_EXT
extern const unsigned char acAPPW_Language_0[];

/*********************************************************************
*
*       Fonts
*/
extern const unsigned char acNettoOT_16_Normal_EXT_AA4[];

/*********************************************************************
*
*       Images
*/
extern const unsigned char acButtonDarkUnpressed_100x30[];
extern const unsigned char acButtonDarkPressed_100x30[];
extern const unsigned char acSliderDarkBlueLeft_30x16[];
extern const unsigned char acSliderDarkGrayRight_30x16[];
extern const unsigned char acSliderDarkThumbUnpressed_22x22[];

/*********************************************************************
*
*       Screens
*/
#define ID_SCREEN_00 (GUI_ID_USER + 4096)

extern APPW_ROOT_INFO ID_SCREEN_00_RootInfo;

#define APPW_INITIAL_SCREEN &ID_SCREEN_00_RootInfo

/*********************************************************************
*
*       Project path
*/
#define APPW_PROJECT_PATH "D:/__Developex__Work__/New_GUI/NewGui_108_614d"

#endif  // RESOURCE_H

/*************************** End of file ****************************/
