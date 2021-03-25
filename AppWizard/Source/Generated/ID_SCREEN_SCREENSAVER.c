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
File        : ID_SCREEN_SCREENSAVER.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "Resource.h"
#include "ID_SCREEN_SCREENSAVER.h"

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
    ID_SCREEN_SCREENSAVER, 0,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BOX_Create,
    ID_BOX_00, ID_SCREEN_SCREENSAVER,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_IMAGE_Create,
    ID_IMAGE_00, ID_SCREEN_SCREENSAVER,
    { { { DISPOSE_MODE_REL_PARENT, 190, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 80, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 100, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_UNLOCK, ID_SCREEN_SCREENSAVER,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      480, 272, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_00, ID_SCREEN_SCREENSAVER,
    { { { DISPOSE_MODE_REL_PARENT, 165, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      150, 32, 0, 0, 0, 0
    },
  },
};

/*********************************************************************
*
*       _aSetup
*/
static const APPW_SETUP_ITEM _aSetup[] = {
  { ID_BOX_00,             APPW_SET_PROP_COLOR,        { ARG_V(GUI_BLACK) } },
  { ID_IMAGE_00,           APPW_SET_PROP_TILE,         { ARG_V(0) } },
  { ID_IMAGE_00,           APPW_SET_PROP_GIF,          { ARG_VP(0, accorsairLogoCubeGif100x100_30fps),
                                                         ARG_V(46936), } },
  { ID_BUTTON_UNLOCK,      APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, NULL), } },
  { ID_BUTTON_UNLOCK,      APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                         ARG_V(GUI_INVALID_COLOR),
                                                         ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_UNLOCK,      APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_18) } },
  { ID_BUTTON_UNLOCK,      APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_BOTTOM),
                                                         ARG_V(0),
                                                         ARG_V(0) } },
  { ID_TEXT_00,            APPW_SET_PROP_COLOR,        { ARG_V(0xffffff7f) } },
  { ID_TEXT_00,            APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                         ARG_V(0),
                                                         ARG_V(0) } },
  { ID_TEXT_00,            APPW_SET_PROP_FONT,         { ARG_VP(0, acNotoSans_24_Normal_EXT_AA4) } },
  { ID_TEXT_00,            APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_19) } },
};

/*********************************************************************
*
*       _aAction
*/
static const APPW_ACTION_ITEM _aAction[] = {
  { ID_BUTTON_UNLOCK,      WM_NOTIFICATION_CLICKED,          0,                     APPW_JOB_SHOWSCREEN,     ID_SCREEN_SCREEN_SAVER__ID_BUTTON_UNLOCK__WM_NOTIFICATION_CLICKED,
    { ARG_V(ID_SCREEN_CHOOSE_TEST),
    }, 0, NULL
  },
};

/*********************************************************************
*
*       Public data
*
**********************************************************************
*/
/*********************************************************************
*
*       ID_SCREEN_SCREENSAVER_RootInfo
*/
APPW_ROOT_INFO ID_SCREEN_SCREENSAVER_RootInfo = {
  ID_SCREEN_SCREENSAVER,
  _aCreate, GUI_COUNTOF(_aCreate),
  _aSetup,  GUI_COUNTOF(_aSetup),
  _aAction, GUI_COUNTOF(_aAction),
  cbID_SCREEN_SCREENSAVER,
  0
};

/*************************** End of file ****************************/
