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
    -DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING
    -DCR_INTEGER_PRINTF
    -DPRINTF_FLOAT_ENABLE=0
    -D__MCUXPRESSO
    -D__NEWLIB__
    -DUSB_STACK_BM
    -DUSB_STACK_USE_DEDICATED_RAM=1
    -DFSL_OSA_BM_TASK_ENABLE=0
    -DFSL_OSA_BM_TIMER_CONFIG=0
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
    ./AppWizard
./AppWizard/Resource
./AppWizard/Resource/Font
./AppWizard/Resource/Image
./AppWizard/Resource/Text
./AppWizard/Source
./AppWizard/Source/CustomCode
./AppWizard/Source/Generated

    ./board
    ./CMSIS
    ./component
    ./component/lists
    ./component/osa
    ./component/serial_manager
    ./component/uart
    ./device
    ./doc
    ./drivers
    ./emwin
    ./emwin/emWin_Config
    ./emwin/emWin_header
    ./emwin/emWin_library
    ./emwin/emWin_library/ARMGCC
    ./emwin/emWin_library/IAR
    ./emwin/emWin_library/Keil
    ./emwin/emWin_library/MCUXpresso
    ./fatfs
    ./fatfs/source
    ./fatfs/source/fsl_ram_disk
    ./fatfs/source/fsl_sd_disk
    ./gui
    ./libs
    ./linkerScript
    ./scripts
    ./sdmmc
    ./sdmmc/inc
    ./sdmmc/port
    ./sdmmc/src
    ./source
    ./startup
    ./tools
    ./tools/features
    ./tools/features/include
    ./tools/features/include/NXP
    ./touchpanel
    ./usb
    ./usb/host
    ./usb/host/class
    ./usb/include
    ./utilities
)

# find -name '*.c'
set(APP_SOURCE_FILES
    ./board/board.c
    ./board/clock_config.c
    ./board/emwin_support.c
    ./board/pin_mux.c
    ./board/sdcard_pin_mux.c
    ./component/lists/generic_list.c
    ./component/osa/fsl_os_abstraction_bm.c
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
    ./drivers/fsl_sdif.c
    ./emwin/emWin_Config/APPW_X_NoFS.c
    ./fatfs/source/diskio.c
    ./fatfs/source/ff.c
    ./fatfs/source/ffsystem.c
    ./fatfs/source/ffunicode.c
    ./fatfs/source/fsl_ram_disk/fsl_ram_disk.c
    ./fatfs/source/fsl_sd_disk/fsl_sd_disk.c
    ./sdmmc/port/fsl_sdmmc_event.c
    ./sdmmc/port/fsl_sdmmc_host.c
    ./sdmmc/src/fsl_sd.c
    ./sdmmc/src/fsl_sdmmc_common.c
    ./source/app.c
    ./source/semihost_hardfault.c
    ./source/host_hid_generic.c
    ./source/reportDescriptorParser.c
    ./source/reportExtension.c
    ./source/ringbuffer.c
    ./source/sdcard_fatfs.c
    ./source/semihost_hardfault.c
    ./gui/gui.c
    ./gui/corsairLogoCubeGif100x100_30fps.c
    ./startup/startup_lpc54608.c
    ./touchpanel/fsl_ft5406.c
    ./usb/host/class/usb_host_hid.c
    ./usb/host/class/usb_host_hub.c
    ./usb/host/class/usb_host_hub_app.c
    ./usb/host/usb_host_devices.c
    ./usb/host/usb_host_framework.c
    ./usb/host/usb_host_hci.c
    ./usb/host/usb_host_ip3516hs.c
    ./usb/host/usb_host_ohci.c
    ./utilities/fsl_assert.c
    ./utilities/fsl_debug_console.c
    ./utilities/fsl_str.c
)

add_executable(${TARGET}
    ${APP_SOURCE_FILES}
)

add_subdirectory(AppWizard)

target_compile_options(${TARGET} PRIVATE
    $<$<CONFIG:DEBUG>: -O0>
    $<$<CONFIG:RELEASE>: -Os>
    # -Wall
    # -Wextra
)

target_link_directories(${TARGET} PRIVATE
    libs
    linkerScript
)

target_link_libraries(${TARGET}
    libcr_newlib_nohost.a
    libpower_hardabi.a
    appwizard
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