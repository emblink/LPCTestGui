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

#define APPW_MANAGE_TEXT APPW_MANAGE_TEXT_EXT
extern const unsigned char acAPPW_Language_0[];

/*********************************************************************
*
*       Fonts
*/
extern const unsigned char acNettoOT_16_Normal_EXT_AA4[];
extern const unsigned char acNettoOT_24_Normal_EXT_AA4[];

/*********************************************************************
*
*       Images
*/
extern const unsigned char acDARK_Slider_Shaft_H_Left_Blue_30x16[];
extern const unsigned char acDARK_Slider_Shaft_H_Right_Gray_30x16[];
extern const unsigned char acDARK_Slider_Thumb_Up_22x22[];
extern const unsigned char acDARK_Slider_Thumb_Down_22x22[];
extern const unsigned char acDARK_Switch_Body_H_On_55x20[];
extern const unsigned char acDARK_Switch_Body_H_Off_55x20[];
extern const unsigned char acDARK_Switch_Thumb_26x26[];
extern const unsigned char acDARK_Button_Up_100x30[];
extern const unsigned char acDARK_Button_Down_100x30[];
extern const unsigned char acProgbar_Full_H_Green_200x30[];
extern const unsigned char acProgbar_Full_H_White_200x30[];

/*********************************************************************
*
*       Variables
*/
#define ID_VAR_QUANTITY 4096
#define ID_VAR_PERIOD 4097

/*********************************************************************
*
*       Screens
*/
#define ID_SCREEN_MAIN (GUI_ID_USER + 4096)
#define ID_SCREEN_RUNNING (GUI_ID_USER + 4097)

extern APPW_ROOT_INFO ID_SCREEN_MAIN_RootInfo;
extern APPW_ROOT_INFO ID_SCREEN_RUNNING_RootInfo;

#define APPW_INITIAL_SCREEN &ID_SCREEN_MAIN_RootInfo

/*********************************************************************
*
*       Project path
*/
#define APPW_PROJECT_PATH "D:/__Developex__Work__/GUI/AppWizard"

#endif  // RESOURCE_H

/*************************** End of file ****************************/
