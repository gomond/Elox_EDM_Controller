################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/GT911/Analog_I2C.c \
../Core/User/GT911/GT911.c 

C_DEPS += \
./Core/User/GT911/Analog_I2C.d \
./Core/User/GT911/GT911.d 

OBJS += \
./Core/User/GT911/Analog_I2C.o \
./Core/User/GT911/GT911.o 


# Each subdirectory must supply rules for building sources it contributes
Core/User/GT911/%.o Core/User/GT911/%.su Core/User/GT911/%.cyclo: ../Core/User/GT911/%.c Core/User/GT911/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -DSTM32_THREAD_SAFE_STRATEGY=2 -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Core/ThreadSafe -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/gomond/OneDrive/Documents/GitHub/ELOX_EDM_Controller/Core/User" -I"C:/Users/gomond/OneDrive/Documents/GitHub/ELOX_EDM_Controller/Core/User/Config" -I"C:/Users/gomond/OneDrive/Documents/GitHub/ELOX_EDM_Controller/Core/User/GT911" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-User-2f-GT911

clean-Core-2f-User-2f-GT911:
	-$(RM) ./Core/User/GT911/Analog_I2C.cyclo ./Core/User/GT911/Analog_I2C.d ./Core/User/GT911/Analog_I2C.o ./Core/User/GT911/Analog_I2C.su ./Core/User/GT911/GT911.cyclo ./Core/User/GT911/GT911.d ./Core/User/GT911/GT911.o ./Core/User/GT911/GT911.su

.PHONY: clean-Core-2f-User-2f-GT911

