################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f407vgtx.s 

OBJS += \
./Startup/startup_stm32f407vgtx.o 

S_DEPS += \
./Startup/startup_stm32f407vgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/Console" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/DMA" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/GPIO" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/USART" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/GC9A01" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/SPI" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f407vgtx.d ./Startup/startup_stm32f407vgtx.o

.PHONY: clean-Startup

