add_compile_options(
    -w
    -Os
)

set(TARGET appwizard)
add_library(${TARGET} STATIC "")

target_link_directories(${TARGET} INTERFACE
    ../emwin/emWin_library/ARMGCC/
)

target_link_libraries(${TARGET} INTERFACE
    libemWin_M4F.a
)

target_sources(${TARGET} PRIVATE
    ./Resource/Font/NettoOT_16_Normal_EXT_AA4.c
    ./Resource/Font/NotoSans_24_Normal_EXT_AA4.c
    ./Resource/Image/ButtonDarkPressed_100x30.c
    ./Resource/Image/ButtonDarkUnpressed_100x30.c
    ./Resource/Image/corsairLogoCubeGif100x100_30fps.c
    ./Resource/Image/gif_orig.c
    ./Resource/Image/SliderDarkBlueLeft_30x16.c
    ./Resource/Image/SliderDarkGrayRight_30x16.c
    ./Resource/Image/SliderDarkThumbUnpressed_22x22.c
    ./Resource/Text/APPW_Language_0.c
    ./Resource/Text/APPW_Pattern.c
    ./Source/APPW_MainTask.c
    ./Source/CustomCode/Application.c
    ./Source/CustomCode/ID_SCREEN_CHOOSE_TEST_Slots.c
    ./Source/CustomCode/ID_SCREEN_SCREENSAVER_Slots.c
    ./Source/CustomCode/ID_SCREEN_STANDART_TEST_Slots.c
    ./Source/Generated/APPWConf.c
    ./Source/Generated/ID_SCREEN_CHOOSE_TEST.c
    ./Source/Generated/ID_SCREEN_SCREENSAVER.c
    ./Source/Generated/ID_SCREEN_STANDART_TEST.c
    ./Source/Generated/Resource.c
)

target_include_directories(${TARGET} INTERFACE
    CustomCode
    Generated
)