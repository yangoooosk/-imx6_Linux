#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>

#define  UARTDevice "/dev/ttyS2"

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
    cfsetispeed(&options,speed);//波特率
    cfsetospeed(&options,speed);
    options.c_cflag |= (CLOCAL|CREAD);
	options.c_cflag |= CS8;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	options.c_cc[VTIME] = 0;//设置超时
    options.c_cc[VMIN] = 1;//最少读1个数据
    tcsetattr(COMDevice,TCSANOW,&options);
	
	return COMDevice;
}

unsigned char wakeup[] = {0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x03,0xfd,0xd4,0x14,0x01,0x17,0x00}; //唤醒指令
unsigned char getUID[] = {0x00, 0x00, 0xFF, 0x04, 0xFC, 0xD4, 0x4A, 0x01, 0x00, 0xE1, 0x00}; //获取UID
int main(int argc, char *argv[])
{
	unsigned char uartdata[25],c;
	unsigned long uid;
	int re,i,COMDevice;
	COMDevice = com_init(B115200);
	
	
	re = write(COMDevice,wakeup,sizeof(wakeup));
	if(re>0)
		printf("write ok\n");
	else
		printf("write error\n");
		
	while(1)
	{
		re = read(COMDevice,&c,1);
		if(re==1)
		{
			for(i=0;i<24;i++)
            {
                uartdata[i]=uartdata[i+1];
            }
			uartdata[24] = c;
			//=========================================================
			printf("0x%x  ",c);
			
			if(uartdata[24-3] == 0xd5 && uartdata[24-2] == 0x15)  // 唤醒指令返回值 D5  15表示正确执行并完毕
            {
				printf("\n");
                write(COMDevice,getUID,sizeof(getUID));
            }
            else if(uartdata[0]==0x00 && uartdata[1]==0x00 && uartdata[2]==0xFF && uartdata[3]==0x00 && uartdata[4]==0xff
                    && uartdata[5]==0x00 && uartdata[6]==0x00 && uartdata[7] == 0x00 && uartdata[8] == 0xFF && uartdata[12] == 0x4b && uartdata[18] == 0x04 && uartdata[24] == 0x00 )//UID返回值
            {
				printf("\n\n");
                uid = uartdata[19]<<24 | uartdata[20]<<16 | uartdata[21]<<8 | uartdata[22];
				printf("uid=0x%x\n",uid);
				write(COMDevice,getUID,sizeof(getUID));
				
			}
			
			
			
		}
		
	}
	close(COMDevice);
	return 0;
}












