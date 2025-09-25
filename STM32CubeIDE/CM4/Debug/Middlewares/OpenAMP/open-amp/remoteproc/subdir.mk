################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/open-amp/lib/remoteproc/remoteproc_virtio.c 

OBJS += \
./Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.o 

C_DEPS += \
./Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.o: C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/open-amp/lib/remoteproc/remoteproc_virtio.c Middlewares/OpenAMP/open-amp/remoteproc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DMETAL_MAX_DEVICE_REGIONS=2 -DUSE_HAL_DRIVER -DSTM32MP157Cxx -D__LOG_TRACE_IO_ -DCORE_CM4 -DDEBUG -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DVIRTIO_SLAVE_ONLY -c -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Drivers/STM32MP1xx_HAL_Driver/Inc" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/BME280" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/OLED" -I../../../../../../../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../../../../../../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/BSP/STM32MP15xx_DISCO -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/virtual_driver -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-OpenAMP-2f-open-2d-amp-2f-remoteproc

clean-Middlewares-2f-OpenAMP-2f-open-2d-amp-2f-remoteproc:
	-$(RM) ./Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.cyclo ./Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.d ./Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.o ./Middlewares/OpenAMP/open-amp/remoteproc/remoteproc_virtio.su

.PHONY: clean-Middlewares-2f-OpenAMP-2f-open-2d-amp-2f-remoteproc

