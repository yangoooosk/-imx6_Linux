#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>

#define  UARTDevice "/dev/ttyS0"

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
	int COMDevice;
	char buf[100]="";
	COMDevice = com_init(B57600);
	int re,i;
	while(1)
	{
		re = read(COMDevice,buf,sizeof(buf));
		if(re>0)
		{
			printf("%s\n",buf);
		}
		memset(buf,0,sizeof(buf));
	}
	close(COMDevice);
	return 0;
}












