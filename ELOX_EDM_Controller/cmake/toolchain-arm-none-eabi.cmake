# Toolchain file for ARM GNU toolchain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m7)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Configure ARM_GNU_TOOLCHAIN as either:
# - a full path to the toolchain bin directory, or
# - empty to auto-detect from ARM_GNU_TOOLCHAIN environment variable/common install locations.
set(ARM_GNU_TOOLCHAIN "" CACHE PATH "Path to ARM GCC toolchain directory (root or bin)")

set(_arm_toolchain_dir "")

if(ARM_GNU_TOOLCHAIN)
    if(EXISTS "${ARM_GNU_TOOLCHAIN}/arm-none-eabi-gcc.exe")
        set(_arm_toolchain_dir "${ARM_GNU_TOOLCHAIN}")
    elseif(EXISTS "${ARM_GNU_TOOLCHAIN}/bin/arm-none-eabi-gcc.exe")
        set(_arm_toolchain_dir "${ARM_GNU_TOOLCHAIN}/bin")
    endif()
endif()

if(NOT _arm_toolchain_dir AND DEFINED ENV{ARM_GNU_TOOLCHAIN})
    if(EXISTS "$ENV{ARM_GNU_TOOLCHAIN}/arm-none-eabi-gcc.exe")
        set(_arm_toolchain_dir "$ENV{ARM_GNU_TOOLCHAIN}")
    elseif(EXISTS "$ENV{ARM_GNU_TOOLCHAIN}/bin/arm-none-eabi-gcc.exe")
        set(_arm_toolchain_dir "$ENV{ARM_GNU_TOOLCHAIN}/bin")
    endif()
endif()

if(NOT _arm_toolchain_dir)
    file(GLOB _arm_toolchain_candidates
        "C:/Program Files/arm-gnu-toolchain-*/bin"
        "C:/Program Files (x86)/arm-gnu-toolchain-*/bin"
        "C:/Program Files/Arm GNU Toolchain arm-none-eabi/*/bin"
        "C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/*/bin"
    )
    foreach(_candidate IN LISTS _arm_toolchain_candidates)
        if(EXISTS "${_candidate}/arm-none-eabi-gcc.exe")
            set(_arm_toolchain_dir "${_candidate}")
            break()
        endif()
    endforeach()
endif()

if(NOT _arm_toolchain_dir)
    message(FATAL_ERROR "arm-none-eabi-gcc.exe not found. Set CMake cache variable ARM_GNU_TOOLCHAIN to your ARM GCC install root or bin directory.")
endif()

set(ARM_GNU_TOOLCHAIN "${_arm_toolchain_dir}" CACHE PATH "Path to ARM GCC toolchain directory (root or bin)" FORCE)

set(_arm_prefix "${ARM_GNU_TOOLCHAIN}/arm-none-eabi")

set(CMAKE_C_COMPILER "${_arm_prefix}-gcc.exe")
set(CMAKE_CXX_COMPILER "${_arm_prefix}-g++.exe")
set(CMAKE_ASM_COMPILER "${_arm_prefix}-gcc.exe")
set(CMAKE_OBJCOPY "${_arm_prefix}-objcopy.exe")
set(CMAKE_SIZE "${_arm_prefix}-size.exe")
set(CMAKE_AR "${_arm_prefix}-ar.exe")
set(CMAKE_RANLIB "${_arm_prefix}-ranlib.exe")
set(CMAKE_STRIP "${_arm_prefix}-strip.exe")
set(CMAKE_OBJDUMP "${_arm_prefix}-objdump.exe")
