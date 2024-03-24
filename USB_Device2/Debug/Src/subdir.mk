################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/systeminit.c \
../Src/usbd_driver.c \
../Src/usbd_framework.c 

OBJS += \
./Src/main.o \
./Src/systeminit.o \
./Src/usbd_driver.o \
./Src/usbd_framework.o 

C_DEPS += \
./Src/main.d \
./Src/systeminit.d \
./Src/usbd_driver.d \
./Src/usbd_framework.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -c -I../Inc -I"D:/Courses/Fastbit/Embedded-C/my_workspace/USB_Guide/USB_Device2/Inc/CMSIS/Include" -I"D:/Courses/Fastbit/Embedded-C/my_workspace/USB_Guide/USB_Device2/Inc/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/systeminit.cyclo ./Src/systeminit.d ./Src/systeminit.o ./Src/systeminit.su ./Src/usbd_driver.cyclo ./Src/usbd_driver.d ./Src/usbd_driver.o ./Src/usbd_driver.su ./Src/usbd_framework.cyclo ./Src/usbd_framework.d ./Src/usbd_framework.o ./Src/usbd_framework.su

.PHONY: clean-Src

