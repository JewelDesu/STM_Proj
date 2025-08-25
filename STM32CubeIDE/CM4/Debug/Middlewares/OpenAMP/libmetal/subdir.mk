################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/device.c \
C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/init.c \
C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/io.c \
C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/log.c \
C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/shmem.c 

OBJS += \
./Middlewares/OpenAMP/libmetal/device.o \
./Middlewares/OpenAMP/libmetal/init.o \
./Middlewares/OpenAMP/libmetal/io.o \
./Middlewares/OpenAMP/libmetal/log.o \
./Middlewares/OpenAMP/libmetal/shmem.o 

C_DEPS += \
./Middlewares/OpenAMP/libmetal/device.d \
./Middlewares/OpenAMP/libmetal/init.d \
./Middlewares/OpenAMP/libmetal/io.d \
./Middlewares/OpenAMP/libmetal/log.d \
./Middlewares/OpenAMP/libmetal/shmem.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/OpenAMP/libmetal/device.o: C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/device.c Middlewares/OpenAMP/libmetal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DMETAL_MAX_DEVICE_REGIONS=2 -DUSE_HAL_DRIVER -DSTM32MP157Cxx -D__LOG_TRACE_IO_ -DCORE_CM4 -DDEBUG -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DVIRTIO_SLAVE_ONLY -c -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Drivers/STM32MP1xx_HAL_Driver/Inc" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/OLED" -I../../../../../../../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../../../../../../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/BSP/STM32MP15xx_DISCO -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/virtual_driver -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/OpenAMP/libmetal/init.o: C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/init.c Middlewares/OpenAMP/libmetal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DMETAL_MAX_DEVICE_REGIONS=2 -DUSE_HAL_DRIVER -DSTM32MP157Cxx -D__LOG_TRACE_IO_ -DCORE_CM4 -DDEBUG -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DVIRTIO_SLAVE_ONLY -c -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Drivers/STM32MP1xx_HAL_Driver/Inc" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/OLED" -I../../../../../../../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../../../../../../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/BSP/STM32MP15xx_DISCO -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/virtual_driver -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/OpenAMP/libmetal/io.o: C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/io.c Middlewares/OpenAMP/libmetal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DMETAL_MAX_DEVICE_REGIONS=2 -DUSE_HAL_DRIVER -DSTM32MP157Cxx -D__LOG_TRACE_IO_ -DCORE_CM4 -DDEBUG -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DVIRTIO_SLAVE_ONLY -c -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Drivers/STM32MP1xx_HAL_Driver/Inc" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/OLED" -I../../../../../../../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../../../../../../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/BSP/STM32MP15xx_DISCO -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/virtual_driver -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/OpenAMP/libmetal/log.o: C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/log.c Middlewares/OpenAMP/libmetal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DMETAL_MAX_DEVICE_REGIONS=2 -DUSE_HAL_DRIVER -DSTM32MP157Cxx -D__LOG_TRACE_IO_ -DCORE_CM4 -DDEBUG -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DVIRTIO_SLAVE_ONLY -c -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Drivers/STM32MP1xx_HAL_Driver/Inc" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/OLED" -I../../../../../../../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../../../../../../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/BSP/STM32MP15xx_DISCO -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/virtual_driver -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/OpenAMP/libmetal/shmem.o: C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Middlewares/Third_Party/OpenAMP/libmetal/lib/shmem.c Middlewares/OpenAMP/libmetal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DMETAL_MAX_DEVICE_REGIONS=2 -DUSE_HAL_DRIVER -DSTM32MP157Cxx -D__LOG_TRACE_IO_ -DCORE_CM4 -DDEBUG -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DVIRTIO_SLAVE_ONLY -c -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Drivers/STM32MP1xx_HAL_Driver/Inc" -I"C:/Users/Crystic/Downloads/stm32cubemp1-v1-7-0/STM32Cube_FW_MP1_V1.7.0/Projects/STM32MP157C-DK2/Applications/OpenAMP/OpenAMP_TTY_echo/STM32CubeIDE/CM4/Drivers/OLED" -I../../../../../../../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../../../../../../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/BSP/STM32MP15xx_DISCO -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/OpenAMP/virtual_driver -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-OpenAMP-2f-libmetal

clean-Middlewares-2f-OpenAMP-2f-libmetal:
	-$(RM) ./Middlewares/OpenAMP/libmetal/device.cyclo ./Middlewares/OpenAMP/libmetal/device.d ./Middlewares/OpenAMP/libmetal/device.o ./Middlewares/OpenAMP/libmetal/device.su ./Middlewares/OpenAMP/libmetal/init.cyclo ./Middlewares/OpenAMP/libmetal/init.d ./Middlewares/OpenAMP/libmetal/init.o ./Middlewares/OpenAMP/libmetal/init.su ./Middlewares/OpenAMP/libmetal/io.cyclo ./Middlewares/OpenAMP/libmetal/io.d ./Middlewares/OpenAMP/libmetal/io.o ./Middlewares/OpenAMP/libmetal/io.su ./Middlewares/OpenAMP/libmetal/log.cyclo ./Middlewares/OpenAMP/libmetal/log.d ./Middlewares/OpenAMP/libmetal/log.o ./Middlewares/OpenAMP/libmetal/log.su ./Middlewares/OpenAMP/libmetal/shmem.cyclo ./Middlewares/OpenAMP/libmetal/shmem.d ./Middlewares/OpenAMP/libmetal/shmem.o ./Middlewares/OpenAMP/libmetal/shmem.su

.PHONY: clean-Middlewares-2f-OpenAMP-2f-libmetal

