#include<stdint.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<linux/input.h>
#include<unistd.h>
#include<stdlib.h>

/************************************************************************
1、运行程序：./demo /dev/input/event2  1  			注意陀螺仪是哪个input设备,	1为陀螺仪开
2、运行程序：./demo /dev/input/event2  0			0为陀螺仪关
3、注意/sys/devices/virtual/input/input2/gyro_enable里面的“gyro_enable”文件在/sys/devices/virtual/input/下哪个文件夹里
*************************************************************************/

int main(int argc, char *argv[])
{
    char          buf[256] = { 0, };  /* RATS: Use ok */  
    unsigned char mask[EV_MAX/8 + 1]; /* RATS: Use ok */  
    int           version;  
    int           fd = 0;  
    char          *tmp;
	int           ID;
	struct input_event event;
	char          common[200];
	
	sprintf(common,"echo %s > %s",argv[2],"/sys/devices/virtual/input/input2/gyro_enable");
	system(common);
	if ((fd = open(argv[1], O_RDONLY)) < 0) 
	{
		perror("gyro test");
		return 1;
	}
	ioctl(fd, EVIOCGVERSION, &version);  
	ioctl(fd, EVIOCGID, &ID);  
	ioctl(fd, EVIOCGNAME(sizeof(buf)), buf);    
	printf("    evdev version: %d.%d.%d\n",  
		   version >> 16, (version >> 8) & 0xff, version & 0xff);  
	printf("    evdev id: %d\n",ID);
	printf("    name: %s\n", buf);  
			
	while(1)
	{	
            if(read(fd,&event,sizeof(event))==sizeof(event)) {
		    if(event.type==EV_ABS)
			{
				switch (event.code) {  
                    case ABS_X:        tmp = "ABS_X";        break;  
                    case ABS_Y:        tmp = "ABS_Y";        break;  
                    case ABS_Z:        tmp = "ABS_Z";        break;  
                    case ABS_RX:       tmp = "ABS_RX";       break;  
                    case ABS_RY:       tmp = "ABS_RY";       break;  
                    case ABS_RZ:       tmp = "ABS_RZ";       break;  
				}
				printf("gyro %s : %d\n", tmp, event.value); 
			}
		}
	}	
	close(fd);
    return 0;

}