#CC = arm-none-linux-gnueabi-gcc
CC	= arm-poky-linux-gnueabi-gcc -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/fsl-imx-wayland/4.9.88-2.0.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi
TARGET = eeprom
all:
		$(CC) -o  $(TARGET) $(TARGET).c -lm 
clean:
		rm $(TARGET)
