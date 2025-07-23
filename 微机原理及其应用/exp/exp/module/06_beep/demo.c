#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/input.h>

int main(int argc, char *argv[])
{
	int fd, version,i;
	struct input_event event;

	if ((fd = open("/dev/input/event1", O_RDWR)) < 0) {
		perror("beep test");
		return 1;
	}
	
	event.type = EV_SND;
	event.code = SND_BELL;
	
    while(1)
	{
		for(i=200;i>0;i--)
		{
			if(i%2 == 0)
				event.value = 1;
			else
				event.value = 0;
			write(fd, &event, sizeof(struct input_event)); 
			usleep(100000);
		}
	}

	close(fd);
    return 0;
}












