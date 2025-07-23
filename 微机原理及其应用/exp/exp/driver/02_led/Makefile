BIN		= ledtest
OBJS		= ledtest.o

CC		= arm-poky-linux-gnueabi-gcc -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/fsl-imx-wayland/4.9.88-2.0.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi 
#CC=arm-poky-linux-gnueabi-gcc -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/fsl-imx-wayland/4.9.88-2.0.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi  
CFLAGS		= -O2

all:  clean $(BIN)

$(BIN):		$(OBJS)
		$(CC) $(CFLAGS)	-o $@ $(OBJS)
		$(STRIP) $@

clean:
	-rm -f $(BIN) *.o
