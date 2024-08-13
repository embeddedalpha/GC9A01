################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GC9A01/GC9A01.c 

OBJS += \
./GC9A01/GC9A01.o 

C_DEPS += \
./GC9A01/GC9A01.d 


# Each subdirectory must supply rules for building sources it contributes
GC9A01/%.o GC9A01/%.su GC9A01/%.cyclo: ../GC9A01/%.c GC9A01/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/Console" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/DMA" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/GPIO" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/USART" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/GC9A01" -I"B:/STM32F407V_Firmware_C_Lang/GC9A01_V2/SPI" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GC9A01

clean-GC9A01:
	-$(RM) ./GC9A01/GC9A01.cyclo ./GC9A01/GC9A01.d ./GC9A01/GC9A01.o ./GC9A01/GC9A01.su

.PHONY: clean-GC9A01

