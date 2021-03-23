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
File        : ID_SCREEN_RUNNING.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "Resource.h"
#include "ID_SCREEN_RUNNING.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _aCreate
*/
static APPW_CREATE_ITEM _aCreate[] = {
  { WM_OBJECT_WINDOW_Create,
    ID_SCREEN_RUNNING, 0,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BOX_Create,
    ID_BOX_00, ID_SCREEN_RUNNING,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_PROGBAR_Create,
    ID_PROGBAR_00, ID_SCREEN_RUNNING,
    { { { DISPOSE_MODE_REL_PARENT, 140, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 110, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      200, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_00, ID_SCREEN_RUNNING,
    { { { DISPOSE_MODE_REL_PARENT, 190, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 180, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
};

/*********************************************************************
*
*       _aSetup
*/
static const APPW_SETUP_ITEM _aSetup[] = {
  { ID_SCREEN_RUNNING, APPW_SET_PROP_MOTIONH,      { ARG_VP(APPW_SWIPE_REPLACE, &ID_SCREEN_MAIN_RootInfo),
                                                     ARG_VP(0, NULL),
                                                     ARG_V(300) } },
  { ID_BOX_00,         APPW_SET_PROP_COLOR,        { ARG_V(0xff050b14) } },
  { ID_PROGBAR_00,     APPW_SET_PROP_RADIUS,       { ARG_V(5) } },
  { ID_PROGBAR_00,     APPW_SET_PROP_FRAME,        { ARG_V(0) } },
  { ID_PROGBAR_00,     APPW_SET_PROP_COLOR,        { ARG_V(0xff2c2c30) } },
  { ID_PROGBAR_00,     APPW_SET_PROP_VALUE,        { ARG_V(40) } },
  { ID_PROGBAR_00,     APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acProgbar_Full_H_Green_200x30),
                                                     ARG_VP(0, acProgbar_Full_H_White_200x30), } },
  { ID_PROGBAR_00,     APPW_SET_PROP_TILE,         { ARG_V(0) } },
  { ID_BUTTON_00,      APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Button_Up_100x30),
                                                     ARG_VP(0, acDARK_Button_Down_100x30), } },
  { ID_BUTTON_00,      APPW_SET_PROP_COLORS,       { ARG_V(GUI_RED),
                                                     ARG_V(0xffc0c0c0),
                                                     ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_00,      APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_8) } },
  { ID_BUTTON_00,      APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_24_Normal_EXT_AA4) } },
};

/*********************************************************************
*
*       Public data
*
**********************************************************************
*/
/*********************************************************************
*
*       ID_SCREEN_RUNNING_RootInfo
*/
APPW_ROOT_INFO ID_SCREEN_RUNNING_RootInfo = {
  ID_SCREEN_RUNNING,
  _aCreate, GUI_COUNTOF(_aCreate),
  _aSetup,  GUI_COUNTOF(_aSetup),
  NULL,  0,
  cbID_SCREEN_RUNNING,
  0
};

/*************************** End of file ****************************/
