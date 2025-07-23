
BIN		= gprs
OBJS		= main.o tty.o gprs.o keyshell.o

CC		= arm-poky-linux-gnueabi-gcc -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi 
STRIP		= arm-poky-linux-gnueabi-strip
CFLAGS		= -O2

all:  clean $(BIN)

$(BIN):		$(OBJS)
		$(CC) $(CFLAGS)	-o $@ $(OBJS) -lpthread
		$(STRIP) $@

clean:
	-rm -f $(BIN) *.o
