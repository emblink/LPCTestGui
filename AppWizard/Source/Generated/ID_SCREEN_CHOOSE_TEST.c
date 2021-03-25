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
File        : ID_SCREEN_CHOOSE_TEST.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "Resource.h"
#include "ID_SCREEN_CHOOSE_TEST.h"

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
    ID_SCREEN_CHOOSE_TEST, 0,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BOX_Create,
    ID_BOX_00, ID_SCREEN_CHOOSE_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_STANDART_TEST, ID_SCREEN_CHOOSE_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 120, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 85, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      80, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_LOCK, ID_SCREEN_CHOOSE_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 120, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 160, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      80, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_BOARD_RESET, ID_SCREEN_CHOOSE_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 280, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 160, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      80, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_TRIGGER, ID_SCREEN_CHOOSE_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 280, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 85, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      80, 30, 0, 0, 0, 0
    },
  },
};

/*********************************************************************
*
*       _aSetup
*/
static const APPW_SETUP_ITEM _aSetup[] = {
  { ID_BOX_00,               APPW_SET_PROP_COLOR,        { ARG_V(GUI_BLACK) } },
  { ID_BUTTON_STANDART_TEST, APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_STANDART_TEST, APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_STANDART_TEST, APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_6) } },
  { ID_BUTTON_STANDART_TEST, APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_LOCK,          APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_LOCK,          APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_LOCK,          APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_LOCK,          APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_8) } },
  { ID_BUTTON_BOARD_RESET,   APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_BOARD_RESET,   APPW_SET_PROP_COLORS,       { ARG_V(0xffff557f),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_BOARD_RESET,   APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_12) } },
  { ID_BUTTON_BOARD_RESET,   APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_BOARD_RESET,   APPW_SET_PROP_BKCOLORS,     { ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_TRIGGER,       APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_TRIGGER,       APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(0xff55ff7f),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_TRIGGER,       APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_13) } },
  { ID_BUTTON_TRIGGER,       APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_TRIGGER,       APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
};

/*********************************************************************
*
*       Comparison(s)
*/
static APPW_COND_COMP _aComparison_00[] = {
  { { { APPW_IS_VAR, ID_VAR_USB_DEVICE_CONFIGURED }, { APPW_IS_VAL, 1 } }, APPW__CompareIsEqual },
};

/*********************************************************************
*
*       Condition(s)
*/
static const APPW_COND _Condition_00 = { "A", _aComparison_00, GUI_COUNTOF(_aComparison_00) };

/*********************************************************************
*
*       _aAction
*/
static const APPW_ACTION_ITEM _aAction[] = {
  { ID_BUTTON_STANDART_TEST, WM_NOTIFICATION_CLICKED,          0,                       APPW_JOB_SHOWSCREEN,     ID_SCREEN_CHOOSE_TEST__ID_BUTTON_STANDART_TEST__WM_NOTIFICATION_CLICKED,
    { ARG_V(ID_SCREEN_STANDART_TEST),
    }, 0, &_Condition_00
  },
  { ID_BUTTON_BOARD_RESET,   WM_NOTIFICATION_RELEASED,         0,                       APPW_JOB_NULL,           ID_SCREEN_CHOOSE_TEST__ID_BUTTON_BOARD_RESET__WM_NOTIFICATION_CLICKED,
  },
  { ID_BUTTON_LOCK,          WM_NOTIFICATION_CLICKED,          0,                       APPW_JOB_SHOWSCREEN,     ID_SCREEN_CHOOSE_TEST__ID_BUTTON_LOCK__WM_NOTIFICATION_CLICKED,
    { ARG_V(ID_SCREEN_SCREENSAVER),
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
*       ID_SCREEN_CHOOSE_TEST_RootInfo
*/
APPW_ROOT_INFO ID_SCREEN_CHOOSE_TEST_RootInfo = {
  ID_SCREEN_CHOOSE_TEST,
  _aCreate, GUI_COUNTOF(_aCreate),
  _aSetup,  GUI_COUNTOF(_aSetup),
  _aAction, GUI_COUNTOF(_aAction),
  cbID_SCREEN_CHOOSE_TEST,
  0
};

/*************************** End of file ****************************/
