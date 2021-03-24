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
File        : ID_SCREEN_STANDART_TEST.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "Resource.h"
#include "ID_SCREEN_STANDART_TEST.h"

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
    ID_SCREEN_STANDART_TEST, 0,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BOX_Create,
    ID_BOX_00, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_KEYBOARD_Create,
    ID_KEYBOARD_00, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 268, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      212, 273, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_CONSOLE, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 15, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_SD_CARD, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 15, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_00, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 120, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 58, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_00, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      200, 20, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_01, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 120, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 130, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_01, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 171, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      200, 20, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_00, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 58, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_01, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 130, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_START, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 180, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_RESET, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_BACK, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
};

/*********************************************************************
*
*       _aSetup
*/
static const APPW_SETUP_ITEM _aSetup[] = {
  { ID_BOX_00,               APPW_SET_PROP_COLOR,        { ARG_V(GUI_BLACK) } },
  { ID_KEYBOARD_00,          APPW_SET_PROP_SLAYOUT,      { ARG_VP(824, acSKEYBOARD_NUMPAD) } },
  { ID_KEYBOARD_00,          APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c3c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_CONSOLE,       APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_CONSOLE,       APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_CONSOLE,       APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_2) } },
  { ID_BUTTON_CONSOLE,       APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_SD_CARD,       APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_SD_CARD,       APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_SD_CARD,       APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_3) } },
  { ID_BUTTON_SD_CARD,       APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_00,              APPW_SET_PROP_BKCOLORS,     { ARG_V(0x00ffffff),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_00,              APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_00,              APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_00,              APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_EDIT_00,              APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                           ARG_V(500000) } },
  { ID_EDIT_00,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_SLIDER_00,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acSliderDarkBlueLeft_30x16),
                                                           ARG_VP(0, acSliderDarkGrayRight_30x16),
                                                           ARG_VP(0, acSliderDarkThumbUnpressed_22x22), } },
  { ID_SLIDER_00,            APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                           ARG_V(500000) } },
  { ID_EDIT_01,              APPW_SET_PROP_BKCOLORS,     { ARG_V(0x00ffffff),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_01,              APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_01,              APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_01,              APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_EDIT_01,              APPW_SET_PROP_RANGE,        { ARG_V(65),
                                                           ARG_V(1000) } },
  { ID_EDIT_01,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_SLIDER_01,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acSliderDarkBlueLeft_30x16),
                                                           ARG_VP(0, acSliderDarkGrayRight_30x16),
                                                           ARG_VP(0, acSliderDarkThumbUnpressed_22x22), } },
  { ID_SLIDER_01,            APPW_SET_PROP_RANGE,        { ARG_V(65),
                                                           ARG_V(1000) } },
  { ID_TEXT_00,              APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_00,              APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_00,              APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_0) } },
  { ID_TEXT_00,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_TEXT_01,              APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_01,              APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_01,              APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_1) } },
  { ID_TEXT_01,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_START,         APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_START,         APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_START,         APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_4) } },
  { ID_BUTTON_START,         APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_COLORS,       { ARG_V(GUI_RED),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_5) } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_BACK,          APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                           ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_BACK,          APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_BACK,          APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_10) } },
  { ID_BUTTON_BACK,          APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
};

/*********************************************************************
*
*       _aAction
*/
static const APPW_ACTION_ITEM _aAction[] = {
  { ID_SLIDER_00,            WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_00,              APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_00__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_00__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_SLIDER_01,            WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_01,              APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_01__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_01__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_BUTTON_BACK,          WM_NOTIFICATION_CLICKED,          0,                       APPW_JOB_SHIFTSCREEN,    ID_SCREEN_STANDART_TEST__ID_BUTTON_BACK__WM_NOTIFICATION_CLICKED,
    { ARG_V(ID_SCREEN_CHOOSE_TEST),
      ARG_V(APPW_EDGE_RIGHT),
      ARG_F((void (*)(void))ANIM_LINEAR),
      ARG_V(100),
      ARG_V(1),
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
*       ID_SCREEN_STANDART_TEST_RootInfo
*/
APPW_ROOT_INFO ID_SCREEN_STANDART_TEST_RootInfo = {
  ID_SCREEN_STANDART_TEST,
  _aCreate, GUI_COUNTOF(_aCreate),
  _aSetup,  GUI_COUNTOF(_aSetup),
  _aAction, GUI_COUNTOF(_aAction),
  cbID_SCREEN_STANDART_TEST,
  0
};

/*************************** End of file ****************************/
