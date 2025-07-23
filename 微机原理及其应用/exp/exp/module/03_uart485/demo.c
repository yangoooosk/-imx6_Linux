#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>

#define  UARTDevice "/dev/ttyS1"

#define UART485_TX 1
#define UART485_RX 0

int com_init(speed_t speed)
{
    struct termios options;
	int COMDevice;
    COMDevice = open(UARTDevice, O_RDWR | O_NOCTTY | O_NDELAY);// | O_NONBLOCK
    if(COMDevice < 0)
    {
         printf("open com device failure");
    }
    tcgetattr(COMDevice,&options);
    cfsetispeed(&options,speed);//²¨ÌØÂÊ
    cfsetospeed(&options,speed);
    options.c_cflag |= (CLOCAL|CREAD);
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    tcsetattr(COMDevice,TCSANOW,&options);
	
	return COMDevice;
}

int main(int argc, char *argv[])
{
	int COMDevice,com485;
	char buf[100];
	COMDevice = com_init(B115200);
	int re;
    com485 = open("/dev/UART485", O_RDWR);
	if(com485 < 0)
    {
         printf("open com485 device failure");
    }
	printf("Please enter the data:\n");
	scanf("%s",buf);
	
	ioctl(com485,UART485_TX);
	re = write(COMDevice,buf,strlen(buf));
	if(re>0)
		printf("write ok\n");
	else
		printf("write error\n");
		
	while(1)
	{
		usleep(10000);
		ioctl(com485,UART485_RX);
		re = read(COMDevice,buf,sizeof(buf));
		if(re>0)
		{
			printf("The information is: %s\n",buf);
			printf("Please enter the data:\n");
			scanf("%s",buf);
			ioctl(com485,UART485_TX);
			re = write(COMDevice,buf,strlen(buf));
			if(re>0)
				printf("write ok\n");
			else
				printf("write error\n");
			
		}
	}
	close(com485);
	close(COMDevice);
	return 0;
}












