TOPDIR = ../
include $(TOPDIR)Rules.mak

EXEC = $(INSTALL_DIR)/demo ./demo
OBJS = demo.o 

all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) 
install:
	$(EXP_INSTALL) $(EXEC) $(INSTALL_DIR)


clean:
	-rm -f $(EXEC) *.elf *.gdb *.o
