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
File        : ID_SCREEN_MAIN.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "Resource.h"
#include "ID_SCREEN_MAIN.h"

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
    ID_SCREEN_MAIN, 0,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BOX_Create,
    ID_BOX_00, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_PERIOD, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 60, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 50, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      200, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_SLIDER_PERIOD, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 265, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 50, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      40, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_PROJECT_NAME, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 190, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 10, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_00, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      55, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_QUANTITY, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 60, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      200, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_PERIOD, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 50, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      55, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_SLIDER_QUANTITY, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 265, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      40, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SWITCH_Create,
    ID_SWITCH_00, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 320, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 50, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      55, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_02, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 320, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 23, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      55, 22, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SWITCH_Create,
    ID_SWITCH_01, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 320, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 100, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      55, 25, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_KEYBOARD_Create,
    ID_KEYBOARD_00, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 160, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 135, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      150, 120, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_03, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 320, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 80, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      55, 20, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_RESET, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 345, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_START, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 345, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 180, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_00, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 25, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 180, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_01, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 25, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
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
  { ID_SCREEN_MAIN,          APPW_SET_PROP_MOTIONH,      { ARG_VP(0, NULL),
                                                           ARG_VP(APPW_SWIPE_REPLACE, &ID_SCREEN_RUNNING_RootInfo),
                                                           ARG_V(300) } },
  { ID_BOX_00,               APPW_SET_PROP_COLOR,        { ARG_V(0xff191919) } },
  { ID_SLIDER_PERIOD,        APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Slider_Shaft_H_Left_Blue_30x16),
                                                           ARG_VP(0, acDARK_Slider_Shaft_H_Right_Gray_30x16),
                                                           ARG_VP(0, acDARK_Slider_Thumb_Up_22x22),
                                                           ARG_VP(0, acDARK_Slider_Thumb_Down_22x22), } },
  { ID_SLIDER_PERIOD,        APPW_SET_PROP_RANGE,        { ARG_V(65),
                                                           ARG_V(1000) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                           ARG_V(0xffdcdcdc),
                                                           ARG_V(GUI_WHITE) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_BKCOLORS,     { ARG_V(0xff191919),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_BLACK) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_PERIOD,       { ARG_V(300) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_INVERT,       { ARG_V(0) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(1) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_COLOR,        { ARG_V(0xffdcdcdc) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_SLIDER_PERIOD,   APPW_SET_PROP_RANGE,        { ARG_V(65),
                                                           ARG_V(1000) } },
  { ID_TEXT_PROJECT_NAME,    APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_PROJECT_NAME,    APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_PROJECT_NAME,    APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_0) } },
  { ID_TEXT_PROJECT_NAME,    APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_TEXT_00,              APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_00,              APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_00,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_TEXT_00,              APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_1) } },
  { ID_SLIDER_QUANTITY,      APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Slider_Shaft_H_Left_Blue_30x16),
                                                           ARG_VP(0, acDARK_Slider_Shaft_H_Right_Gray_30x16),
                                                           ARG_VP(0, acDARK_Slider_Thumb_Up_22x22),
                                                           ARG_VP(0, acDARK_Slider_Thumb_Down_22x22), } },
  { ID_TEXT_PERIOD,          APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_PERIOD,          APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_PERIOD,          APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_TEXT_PERIOD,          APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_2) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                           ARG_V(0xffdcdcdc),
                                                           ARG_V(GUI_WHITE) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_BKCOLORS,     { ARG_V(0xff191919),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_BLACK) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_PERIOD,       { ARG_V(300) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_INVERT,       { ARG_V(0) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_COLOR,        { ARG_V(0xffdcdcdc) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(0),
                                                           ARG_V(1) } },
  { ID_EDIT_SLIDER_QUANTITY, APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                           ARG_V(100) } },
  { ID_SWITCH_00,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Switch_Body_H_On_55x20),
                                                           ARG_VP(0, acDARK_Switch_Body_H_Off_55x20),
                                                           ARG_VP(0, NULL),
                                                           ARG_VP(0, acDARK_Switch_Thumb_26x26),
                                                           ARG_VP(0, acDARK_Switch_Thumb_26x26), } },
  { ID_SWITCH_00,            APPW_SET_PROP_FADE,         { ARG_V(0) } },
  { ID_TEXT_02,              APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_02,              APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_02,              APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_4) } },
  { ID_TEXT_02,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_SWITCH_01,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Switch_Body_H_On_55x20),
                                                           ARG_VP(0, acDARK_Switch_Body_H_Off_55x20),
                                                           ARG_VP(0, NULL),
                                                           ARG_VP(0, acDARK_Switch_Thumb_26x26),
                                                           ARG_VP(0, acDARK_Switch_Thumb_26x26), } },
  { ID_SWITCH_01,            APPW_SET_PROP_FADE,         { ARG_V(0) } },
  { ID_KEYBOARD_00,          APPW_SET_PROP_SLAYOUT,      { ARG_VP(824, acSKEYBOARD_NUMPAD) } },
  { ID_KEYBOARD_00,          APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c3c0),
                                                           ARG_V(GUI_INVALID_COLOR),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_TEXT_03,              APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_03,              APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_TEXT_03,              APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_TEXT_03,              APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_5) } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Button_Up_100x30),
                                                           ARG_VP(0, acDARK_Button_Down_100x30), } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_COLORS,       { ARG_V(GUI_RED),
                                                           ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_6) } },
  { ID_BUTTON_RESET,         APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_START,         APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Button_Up_100x30),
                                                           ARG_VP(0, acDARK_Button_Down_100x30), } },
  { ID_BUTTON_START,         APPW_SET_PROP_COLORS,       { ARG_V(GUI_GREEN),
                                                           ARG_V(0xffc0c0c0),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_START,         APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_START,         APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_7) } },
  { ID_BUTTON_START,         APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                           ARG_V(0),
                                                           ARG_V(0) } },
  { ID_BUTTON_00,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Button_Up_100x30),
                                                           ARG_VP(0, acDARK_Button_Down_100x30), } },
  { ID_BUTTON_00,            APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(0xff55ff7f),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_00,            APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
  { ID_BUTTON_00,            APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_9) } },
  { ID_BUTTON_00,            APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_01,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acDARK_Button_Up_100x30),
                                                           ARG_VP(0, acDARK_Button_Down_100x30), } },
  { ID_BUTTON_01,            APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                           ARG_V(0xff55ff7f),
                                                           ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_01,            APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_10) } },
  { ID_BUTTON_01,            APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
  { ID_BUTTON_01,            APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
};

/*********************************************************************
*
*       _aAction
*/
static const APPW_ACTION_ITEM _aAction[] = {
  { ID_SLIDER_PERIOD,        WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_SLIDER_PERIOD,   APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_00__WM_NOTIFICATION_VALUE_CHANGED__ID_EDIT_00__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_SLIDER_QUANTITY,      WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_SLIDER_QUANTITY, APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_01__WM_NOTIFICATION_VALUE_CHANGED__ID_EDIT_01__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_SLIDER_PERIOD,        WM_NOTIFICATION_VALUE_CHANGED,    ID_VAR_PERIOD,           APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_PERIOD__WM_NOTIFICATION_VALUE_CHANGED,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_SLIDER_QUANTITY,      WM_NOTIFICATION_VALUE_CHANGED,    ID_VAR_QUANTITY,         APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_QUANTITY__WM_NOTIFICATION_VALUE_CHANGED,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_BUTTON_RESET,         WM_NOTIFICATION_CLICKED,          ID_VAR_PERIOD,           APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_BUTTON_RESET__WM_NOTIFICATION_CLICKED,
    { ARG_V(65),
    }, 0, NULL
  },
  { ID_BUTTON_RESET,         WM_NOTIFICATION_CLICKED,          ID_VAR_QUANTITY,         APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_BUTTON_RESET__WM_NOTIFICATION_CLICKED_0,
    { ARG_V(1),
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
*       ID_SCREEN_MAIN_RootInfo
*/
APPW_ROOT_INFO ID_SCREEN_MAIN_RootInfo = {
  ID_SCREEN_MAIN,
  _aCreate, GUI_COUNTOF(_aCreate),
  _aSetup,  GUI_COUNTOF(_aSetup),
  _aAction, GUI_COUNTOF(_aAction),
  cbID_SCREEN_MAIN,
  0
};

/*************************** End of file ****************************/
