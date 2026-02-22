################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.cpp 

OBJS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__designer/%.o TouchGFX/generated/images/src/__designer/%.su TouchGFX/generated/images/src/__designer/%.cyclo: ../TouchGFX/generated/images/src/__designer/%.cpp TouchGFX/generated/images/src/__designer/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32H743xx -DSTM32_THREAD_SAFE_STRATEGY=2 -DUSE_PWR_LDO_SUPPLY -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I"C:/Users/gomond/OneDrive/Documents/GitHub/ELOX_EDM_Controller/Core/User/GT911" -I"C:/Users/gomond/OneDrive/Documents/GitHub/ELOX_EDM_Controller/Core/User/Config" -I"C:/Users/gomond/OneDrive/Documents/GitHub/ELOX_EDM_Controller/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc" -I../Core/ThreadSafe -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer:
	-$(RM) ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.cyclo ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large.su ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.cyclo ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_large_pressed.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer
