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
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_QUANTITY, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 8, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      120, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_QUANTITY, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 139, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 8, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_X10_MULTIPLYER, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 255, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 8, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      40, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_X1000_MULTIPLYER, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 315, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 8, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      40, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_QUANTITY, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 46, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      440, 20, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_PRESS_PERIOD, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 75, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      120, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_PERIOD, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 140, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 75, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_PRESS_PERIOD, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 116, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      440, 20, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_PRESS_DURATION, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 142, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      120, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_EDIT_Create,
    ID_EDIT_PRESS_DURATION, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 140, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 142, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      100, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_SLIDER_Create,
    ID_SLIDER_PRESS_DURATION, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 20, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 181, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      440, 22, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_CLEAR, ID_SCREEN_STANDART_TEST,
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
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_CONSOLE, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 179, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_SD_CARD, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 255, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 225, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      60, 30, 0, 0, 0, 0
    },
  },
  { WM_OBJECT_BUTTON_Create,
    ID_BUTTON_START, ID_SCREEN_STANDART_TEST,
    { { { DISPOSE_MODE_REL_PARENT, 332, 0, 0 },
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
  { ID_BOX_00,                  APPW_SET_PROP_COLOR,        { ARG_V(GUI_BLACK) } },
  { ID_TEXT_QUANTITY,           APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_QUANTITY,           APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                              ARG_V(0),
                                                              ARG_V(0) } },
  { ID_TEXT_QUANTITY,           APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_0) } },
  { ID_TEXT_QUANTITY,           APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_QUANTITY,           APPW_SET_PROP_BKCOLORS,     { ARG_V(0x00ffffff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_QUANTITY,           APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_QUANTITY,           APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_QUANTITY,           APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                              ARG_V(10) } },
  { ID_EDIT_QUANTITY,           APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_QUANTITY,           APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                              ARG_V(0),
                                                              ARG_V(0),
                                                              ARG_V(0) } },
  { ID_BUTTON_X10_MULTIPLYER,   APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_X10_MULTIPLYER,   APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                              ARG_V(0xff55ff00),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_X10_MULTIPLYER,   APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_16) } },
  { ID_BUTTON_X10_MULTIPLYER,   APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
  { ID_BUTTON_X1000_MULTIPLYER, APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_X1000_MULTIPLYER, APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                              ARG_V(0xff55ff00),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_X1000_MULTIPLYER, APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_15) } },
  { ID_BUTTON_X1000_MULTIPLYER, APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
  { ID_SLIDER_QUANTITY,         APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acSliderDarkBlueLeft_30x16),
                                                              ARG_VP(0, acSliderDarkGrayRight_30x16),
                                                              ARG_VP(0, acSliderDarkThumbUnpressed_22x22), } },
  { ID_SLIDER_QUANTITY,         APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                              ARG_V(10) } },
  { ID_TEXT_PRESS_PERIOD,       APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_PRESS_PERIOD,       APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                              ARG_V(0),
                                                              ARG_V(0) } },
  { ID_TEXT_PRESS_PERIOD,       APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_1) } },
  { ID_TEXT_PRESS_PERIOD,       APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_PERIOD,             APPW_SET_PROP_BKCOLORS,     { ARG_V(0x00ffffff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_PERIOD,             APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_PERIOD,             APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_PERIOD,             APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                              ARG_V(0),
                                                              ARG_V(0),
                                                              ARG_V(0) } },
  { ID_EDIT_PERIOD,             APPW_SET_PROP_RANGE,        { ARG_V(65),
                                                              ARG_V(1000) } },
  { ID_EDIT_PERIOD,             APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_SLIDER_PRESS_PERIOD,     APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acSliderDarkBlueLeft_30x16),
                                                              ARG_VP(0, acSliderDarkGrayRight_30x16),
                                                              ARG_VP(0, acSliderDarkThumbUnpressed_22x22), } },
  { ID_SLIDER_PRESS_PERIOD,     APPW_SET_PROP_RANGE,        { ARG_V(65),
                                                              ARG_V(1000) } },
  { ID_TEXT_PRESS_DURATION,     APPW_SET_PROP_COLOR,        { ARG_V(0xffc0c0c0) } },
  { ID_TEXT_PRESS_DURATION,     APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                              ARG_V(0),
                                                              ARG_V(0) } },
  { ID_TEXT_PRESS_DURATION,     APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_17) } },
  { ID_TEXT_PRESS_DURATION,     APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_EDIT_PRESS_DURATION,     APPW_SET_PROP_BKCOLORS,     { ARG_V(0x00ffffff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_PRESS_DURATION,     APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_EDIT_PRESS_DURATION,     APPW_SET_PROP_ALIGN,        { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER) } },
  { ID_EDIT_PRESS_DURATION,     APPW_SET_PROP_DECMODE,      { ARG_V(0),
                                                              ARG_V(0),
                                                              ARG_V(0),
                                                              ARG_V(0) } },
  { ID_EDIT_PRESS_DURATION,     APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                              ARG_V(1000) } },
  { ID_EDIT_PRESS_DURATION,     APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_SLIDER_PRESS_DURATION,   APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acSliderDarkBlueLeft_30x16),
                                                              ARG_VP(0, acSliderDarkGrayRight_30x16),
                                                              ARG_VP(0, acSliderDarkThumbUnpressed_22x22), } },
  { ID_SLIDER_PRESS_DURATION,   APPW_SET_PROP_RANGE,        { ARG_V(1),
                                                              ARG_V(1000) } },
  { ID_BUTTON_CLEAR,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_CLEAR,            APPW_SET_PROP_COLORS,       { ARG_V(GUI_WHITE),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_CLEAR,            APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_5) } },
  { ID_BUTTON_CLEAR,            APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_BACK,             APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_BACK,             APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_BACK,             APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_10) } },
  { ID_BUTTON_BACK,             APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_CONSOLE,          APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_CONSOLE,          APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                              ARG_V(0xff55ff00),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_CONSOLE,          APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_2) } },
  { ID_BUTTON_CONSOLE,          APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_CONSOLE,          APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
  { ID_BUTTON_SD_CARD,          APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_SD_CARD,          APPW_SET_PROP_COLORS,       { ARG_V(0xffc0c0c0),
                                                              ARG_V(0xff55ff7f),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_SD_CARD,          APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_3) } },
  { ID_BUTTON_SD_CARD,          APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
  { ID_BUTTON_SD_CARD,          APPW_SET_PROP_TOGGLE,       { ARG_V(0) } },
  { ID_BUTTON_START,            APPW_SET_PROP_SBITMAPS,     { ARG_VP(0, acButtonDarkUnpressed_100x30),
                                                              ARG_VP(0, acButtonDarkPressed_100x30), } },
  { ID_BUTTON_START,            APPW_SET_PROP_COLORS,       { ARG_V(0xff55aaff),
                                                              ARG_V(GUI_INVALID_COLOR),
                                                              ARG_V(GUI_INVALID_COLOR) } },
  { ID_BUTTON_START,            APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_4) } },
  { ID_BUTTON_START,            APPW_SET_PROP_FONT,         { ARG_VP(0, acNettoOT_16_Normal_EXT_AA4) } },
};

/*********************************************************************
*
*       Comparison(s)
*/
static APPW_COND_COMP _aComparison_04[] = {
  { { { APPW_IS_OBJ, ID_SLIDER_PRESS_DURATION }, { APPW_IS_VAR, ID_VAR_PRESS_PERIOD } }, APPW__CompareIsLess },
};

static APPW_COND_COMP _aComparison_05[] = {
  { { { APPW_IS_OBJ, ID_SLIDER_PRESS_DURATION }, { APPW_IS_OBJ, ID_SLIDER_PRESS_PERIOD } }, APPW__CompareIsLess },
};

/*********************************************************************
*
*       Condition(s)
*/
static const APPW_COND _Condition_04 = { "A", _aComparison_04, GUI_COUNTOF(_aComparison_04) };
static const APPW_COND _Condition_05 = { "A", _aComparison_05, GUI_COUNTOF(_aComparison_05) };

/*********************************************************************
*
*       _aAction
*/
static const APPW_ACTION_ITEM _aAction[] = {
  { ID_SLIDER_QUANTITY,         WM_NOTIFICATION_VALUE_CHANGED,    ID_VAR_QUANTITY,            APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_SLIDER_QUANTITY__WM_NOTIFICATION_VALUE_CHANGED,
    { ARG_V(4096),
    }, 65537, NULL
  },
  { ID_SLIDER_QUANTITY,         WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_QUANTITY,           APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_QUANTITY__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_SLIDER_PRESS_PERIOD,     WM_NOTIFICATION_VALUE_CHANGED,    ID_VAR_PRESS_PERIOD,        APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_SLIDER_PRESS_PERIOD__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_PRESS_PERIOD__APPW_JOB_SETVALUE,
    { ARG_V(4097),
    }, 65537, NULL
  },
  { ID_SLIDER_PRESS_PERIOD,     WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_PERIOD,             APPW_JOB_SETVALUE,       ID_SCREEN_00__ID_SLIDER_01__WM_NOTIFICATION_VALUE_CHANGED__ID_TEXT_01__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, NULL
  },
  { ID_SLIDER_PRESS_DURATION,   WM_NOTIFICATION_VALUE_CHANGED,    ID_VAR_PRESS_DURATION,      APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_SLIDER_PRESS_DURATION__WM_NOTIFICATION_VALUE_CHANGED,
    { ARG_V(0),
    }, 0, &_Condition_04
  },
  { ID_SLIDER_PRESS_DURATION,   WM_NOTIFICATION_VALUE_CHANGED,    ID_EDIT_PRESS_DURATION,     APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_SLIDER_PRESS_DURATION__WM_NOTIFICATION_VALUE_CHANGED__ID_EDIT_RELEASE_DELAY__APPW_JOB_SETVALUE,
    { ARG_V(0),
    }, 0, &_Condition_05
  },
  { ID_BUTTON_CLEAR,            WM_NOTIFICATION_CLICKED,          ID_SLIDER_QUANTITY,         APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_EDIT_QUANTITY__APPW_JOB_SETVALUE,
    { ARG_V(1),
    }, 0, NULL
  },
  { ID_BUTTON_CLEAR,            WM_NOTIFICATION_CLICKED,          ID_SLIDER_PRESS_PERIOD,     APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_EDIT_PERIOD__APPW_JOB_SETVALUE,
    { ARG_V(65),
    }, 0, NULL
  },
  { ID_BUTTON_CLEAR,            WM_NOTIFICATION_CLICKED,          ID_SLIDER_PRESS_DURATION,   APPW_JOB_SETVALUE,       ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_EDIT_PRESS_DURATION__APPW_JOB_SETVALUE,
    { ARG_V(1),
    }, 0, NULL
  },
  { ID_BUTTON_CLEAR,            WM_NOTIFICATION_CLICKED,          ID_BUTTON_X10_MULTIPLYER,   APPW_JOB_CLEAR,          ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_BUTTON_X10_MULTIPLYER__APPW_JOB_CLEAR,
  },
  { ID_BUTTON_CLEAR,            WM_NOTIFICATION_CLICKED,          ID_BUTTON_X1000_MULTIPLYER, APPW_JOB_CLEAR,          ID_SCREEN_STANDART_TEST__ID_BUTTON_CLEAR__WM_NOTIFICATION_CLICKED__ID_BUTTON_X1000_MULTIPLYER__APPW_JOB_CLEAR,
  },
  { ID_BUTTON_BACK,             WM_NOTIFICATION_CLICKED,          0,                          APPW_JOB_SHOWSCREEN,     ID_SCREEN_STANDART_TEST__ID_BUTTON_BACK__WM_NOTIFICATION_CLICKED,
    { ARG_V(ID_SCREEN_CHOOSE_TEST),
    }, 0, NULL
  },
  { ID_BUTTON_BACK,             WM_NOTIFICATION_CLICKED,          ID_BUTTON_CLEAR,            APPW_JOB_TOGGLE,         ID_SCREEN_STANDART_TEST__ID_BUTTON_BACK__WM_NOTIFICATION_CLICKED__ID_BUTTON_CLEAR__APPW_JOB_TOGGLE,
  },
  { ID_BUTTON_CONSOLE,          WM_NOTIFICATION_CLICKED,          ID_BUTTON_SD_CARD,          APPW_JOB_CLEAR,          ID_SCREEN_STANDART_TEST__ID_BUTTON_CONSOLE__WM_NOTIFICATION_CLICKED__ID_BUTTON_SD_CARD__APPW_JOB_TOGGLE,
  },
  { ID_BUTTON_SD_CARD,          WM_NOTIFICATION_CLICKED,          ID_BUTTON_CONSOLE,          APPW_JOB_CLEAR,          ID_SCREEN_STANDART_TEST__ID_BUTTON_SD_CARD__WM_NOTIFICATION_CLICKED__ID_BUTTON_CONSOLE__APPW_JOB_TOGGLE,
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
