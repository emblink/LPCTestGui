cmake_minimum_required (VERSION 3.13)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CROSSCOMPILING 1)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_SIZE arm-none-eabi-size)
set (CMAKE_C_FLAGS_INIT "--specs=nosys.specs") # fixes cmake compiler error
set (CMAKE_CXX_FLAGS_INIT "--specs=nosys.specs")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")

set(LANGUAGES C CXX ASM)
project("GUI" ${LANGUAGES})
set(TARGET ${PROJECT_NAME})

add_definitions(
    -std=gnu99
    -DCPU_LPC54608J512ET180=1
    -DCPU_LPC54608J512ET180_cm4
    -DCPU_LPC54608
    -D__USE_CMSIS
    -DSERIAL_PORT_TYPE_UART=1
    -DSDK_DEBUGCONSOLE=1
    -DCR_INTEGER_PRINTF
    -DPRINTF_FLOAT_ENABLE=0
    -D__MCUXPRESSO
    -DDEBUG
    -D__NEWLIB__
)

add_compile_options(
    -fno-common
    -g3
    -c
    -ffunction-sections
    -fdata-sections
    -ffreestanding
    -fno-builtin
    -fmerge-constants
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -mthumb
    -D__NEWLIB__
    -fstack-usage
    -specs=nano.specs
)

add_link_options(
    -nostdlib
    -Wl,-Map=${TARGET}.map
    -Wl,--gc-sections
    -Wl,-print-memory-usage
    -Wl,--sort-section=alignment
    -Wl,--cref
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -mthumb
)

# find . -type d
include_directories(
    ./AppWizard/Resource
    ./AppWizard/Resource/Font
    ./AppWizard/Resource/Image
    ./AppWizard/Resource/Keyboard
    ./AppWizard/Resource/Text
    ./AppWizard/Source
    ./AppWizard/Source/CustomCode
    ./AppWizard/Source/Generated
    ./board
    ./CMSIS
    ./component
    ./component/lists
    ./component/serial_manager
    ./component/uart
    ./device
    ./drivers
    ./emwin/emWin_Config
    ./emwin/emWin_header
    ./libs
    ./linker
    ./Resources
    ./source
    ./startup
    ./touchpanel
    ./utilities
    ./tools/redlib/include
    ./tools/redlib/include/sys
    ./tools/features/include
    ./tools/features/include/NXP
)

# find -name '*.c'
set(APP_SOURCE_FILES
    ./AppWizard/Resource/Font/NettoOT_16_Normal_EXT_AA4.c
    ./AppWizard/Resource/Image/ButtonDarkPressed_100x30.c
    ./AppWizard/Resource/Image/ButtonDarkUnpressed_100x30.c
    ./AppWizard/Resource/Image/SliderDarkBlueLeft_30x16.c
    ./AppWizard/Resource/Image/SliderDarkGrayRight_30x16.c
    ./AppWizard/Resource/Image/SliderDarkThumbUnpressed_22x22.c
    ./AppWizard/Resource/Keyboard/SKEYBOARD_NUMPAD.c
    ./AppWizard/Resource/Text/APPW_Language_0.c
    ./AppWizard/Resource/Text/APPW_Pattern.c
    ./AppWizard/Source/APPW_MainTask.c
    ./AppWizard/Source/CustomCode/Application.c
    ./AppWizard/Source/CustomCode/ID_SCREEN_00_Slots.c
    ./AppWizard/Source/Generated/APPWConf.c
    ./AppWizard/Source/Generated/ID_SCREEN_00.c
    ./AppWizard/Source/Generated/Resource.c
    
    ./board/board.c
    ./board/clock_config.c
    ./board/emwin_support.c
    ./board/pin_mux.c
    ./component/lists/generic_list.c
    ./component/serial_manager/serial_manager.c
    ./component/serial_manager/serial_port_uart.c
    ./component/uart/usart_adapter.c
    ./device/system_LPC54608.c
    ./drivers/fsl_clock.c
    ./drivers/fsl_common.c
    ./drivers/fsl_ctimer.c
    ./drivers/fsl_emc.c
    ./drivers/fsl_flexcomm.c
    ./drivers/fsl_gpio.c
    ./drivers/fsl_i2c.c
    ./drivers/fsl_lcdc.c
    ./drivers/fsl_power.c
    ./drivers/fsl_reset.c
    ./drivers/fsl_sctimer.c
    ./drivers/fsl_usart.c
    ./emwin/emWIn_Config/APPW_X_NoFS.c
    ./source/emwin_temperature_control.c
    ./source/semihost_hardfault.c
    ./startup/startup_lpc54608.c
    ./touchpanel/fsl_ft5406.c
    ./utilities/fsl_assert.c
    ./utilities/fsl_debug_console.c
    ./utilities/fsl_str.c
)

add_executable(${TARGET}
    ${APP_SOURCE_FILES}
)

target_compile_options(${TARGET} PRIVATE
    $<$<CONFIG:DEBUG>: -O0>
    $<$<CONFIG:RELEASE>: -Os>
    # -Wall
    # -Wextra
)

target_link_directories(${TARGET} PRIVATE
    libs
    emwin/emWin_library/ARMGCC
    linkerScript
)

target_link_libraries(${TARGET}
    libcr_newlib_nohost.a
    libpower_hardabi.a
    libemWin_M4F.a
)

target_link_options(${TARGET} PRIVATE
    -T lpcxpresso54608_emwin_temperature_control_Debug.ld
)

add_custom_command(TARGET ${PROJECT_NAME}
	POST_BUILD
    COMMAND ${CMAKE_SIZE} ARGS ${TARGET}.elf
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex ${TARGET}.elf ${TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${TARGET}.elf firmware.bin
)

find_package (Python)
if(${Python_FOUND})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMENT "Signing ${BINARY}"
        COMMAND ${Python_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/signer.py firmware.bin
    )
else()
    message (WARNING "Python not found. Target binary will be not signed")
endif()