cmake_minimum_required(VERSION 3.21)

project(ELOX_EDM_Controller LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MCU_FLAGS
	-mcpu=cortex-m7
	-mthumb
	-mfpu=fpv5-d16
	-mfloat-abi=hard
)

add_compile_options(
	${MCU_FLAGS}
	-ffunction-sections
	-fdata-sections
)

add_compile_options(
	$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
	$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
	$<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
)

if(WIN32)
	set(ARM_GCC_ROOT "C:/Program Files/arm-gnu-toolchain-14.3.rel1")
	if(EXISTS "${ARM_GCC_ROOT}/arm-none-eabi/include")
		include_directories(SYSTEM
			"${ARM_GCC_ROOT}/lib/gcc/arm-none-eabi/14.3.1/include"
			"${ARM_GCC_ROOT}/lib/gcc/arm-none-eabi/14.3.1/include-fixed"
			"${ARM_GCC_ROOT}/arm-none-eabi/include"
		)
	endif()
endif()

add_link_options(
	${MCU_FLAGS}
	-T${CMAKE_SOURCE_DIR}/STM32H743XX_FLASH.ld
	--specs=nano.specs
	-Wl,--gc-sections
	-Wl,-Map=${CMAKE_PROJECT_NAME}.map
	-Wl,--print-memory-usage
)

add_executable(${CMAKE_PROJECT_NAME})

add_subdirectory(cmake/stm32cubemx)

file(GLOB_RECURSE TOUCHGFX_APP_SOURCES CONFIGURE_DEPENDS
	${CMAKE_SOURCE_DIR}/TouchGFX/generated/fonts/src/*.cpp
	${CMAKE_SOURCE_DIR}/TouchGFX/generated/gui_generated/src/*.cpp
	${CMAKE_SOURCE_DIR}/TouchGFX/generated/images/src/*.cpp
	${CMAKE_SOURCE_DIR}/TouchGFX/generated/texts/src/*.cpp
	${CMAKE_SOURCE_DIR}/TouchGFX/gui/src/*.cpp
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	${TOUCHGFX_APP_SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	Core/User
	Core/User/Config
	Core/User/GT911
	Middlewares/ST/touchgfx/framework/include
	TouchGFX/generated/fonts/include
	TouchGFX/generated/gui_generated/include
	TouchGFX/generated/images/include
	TouchGFX/generated/texts/include
	TouchGFX/generated/videos/include
	TouchGFX/gui/include
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	Core/ThreadSafe/newlib_lock_glue.c
	Core/Src/BSP_RGB_LCD.c
	Core/Src/BSP_SDRAM.c
	Core/User/Config/DEV_Config.c
	Core/User/GT911/Analog_I2C.c
	Core/User/GT911/GT911.c
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	Core/ThreadSafe
)

target_link_libraries(${CMAKE_PROJECT_NAME}
	${CMAKE_SOURCE_DIR}/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc/libtouchgfx-float-abi-hard.a
)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
	COMMENT "Generating ${CMAKE_PROJECT_NAME}.bin"
)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
	COMMENT "Printing size"
)
