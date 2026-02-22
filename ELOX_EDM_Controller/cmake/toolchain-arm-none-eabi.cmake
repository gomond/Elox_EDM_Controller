# Toolchain file for ARM GNU toolchain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m7)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Point this to the bin folder that contains arm-none-eabi-gcc.exe
set(ARM_GNU_TOOLCHAIN "C:/Program Files/Arm GNU Toolchain/13.3.rel1/bin" CACHE PATH "Path to ARM GCC bin directory")

set(_arm_prefix "${ARM_GNU_TOOLCHAIN}/arm-none-eabi")
if(NOT EXISTS "${_arm_prefix}-gcc.exe")
    message(FATAL_ERROR "arm-none-eabi-gcc.exe not found. Update ARM_GNU_TOOLCHAIN to your installed ARM GCC bin directory.")
endif()

set(CMAKE_C_COMPILER "${_arm_prefix}-gcc.exe")
set(CMAKE_CXX_COMPILER "${_arm_prefix}-g++.exe")
set(CMAKE_ASM_COMPILER "${_arm_prefix}-gcc.exe")
set(CMAKE_OBJCOPY "${_arm_prefix}-objcopy.exe")
set(CMAKE_SIZE "${_arm_prefix}-size.exe")
set(CMAKE_AR "${_arm_prefix}-ar.exe")
set(CMAKE_RANLIB "${_arm_prefix}-ranlib.exe")
set(CMAKE_STRIP "${_arm_prefix}-strip.exe")
set(CMAKE_OBJDUMP "${_arm_prefix}-objdump.exe")
