cmake_minimum_required(VERSION 3.16)

project(firmware C)

# =====================================
# Cross toolchain
# =====================================
set(CROSS arm-none-eabi-)
set(CMAKE_C_COMPILER ${CROSS}gcc)
set(OBJCOPY ${CROSS}objcopy)
set(SIZE_TOOL ${CROSS}size)

# Tell CMake this is a generic embedded target
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m4)

# =====================================
# Directories
# =====================================
set(SRCDIR ${CMAKE_SOURCE_DIR}/src)
set(INCDIR ${CMAKE_SOURCE_DIR}/include)
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker.ld)

# =====================================
# Source files
# =====================================
set(SOURCES
    ${SRCDIR}/main.c
    ${SRCDIR}/uart.c
    ${SRCDIR}/startup.c
)

# =====================================
# ELF target
# =====================================
add_executable(firmware.elf ${SOURCES})

# =====================================
# Include directories
# =====================================
target_include_directories(firmware.elf PRIVATE
    ${INCDIR}
)

# =====================================
# Compile options
# =====================================
target_compile_options(firmware.elf PRIVATE
    -Wall
    -Wextra
    -O2
    -ffreestanding
    -mcpu=cortex-m4
    -mthumb
)

# =====================================
# Link options
# =====================================
target_link_options(firmware.elf PRIVATE
    -T${LINKER_SCRIPT}
    -nostdlib
    -Wl,--gc-sections
    -mcpu=cortex-m4
    -mthumb
)

# =====================================
# Extra output formats
# =====================================
add_custom_command(
    TARGET firmware.elf POST_BUILD
    COMMAND ${OBJCOPY} -O binary
            $<TARGET_FILE:firmware.elf>
            ${CMAKE_BINARY_DIR}/firmware.bin
    COMMAND ${OBJCOPY} -O ihex
            $<TARGET_FILE:firmware.elf>
            ${CMAKE_BINARY_DIR}/firmware.hex
    COMMAND ${SIZE_TOOL} $<TARGET_FILE:firmware.elf>
    COMMENT "Generating BIN/HEX and printing size"
)