#include "tubeNixieThread.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/mman.h>
#include <math.h>
#include <sys/time.h>
#include <QDebug>


unsigned char tube[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x7f,0xbf,0xff};
unsigned char addr[] = {0x10,0x20,0x40,0x80,0x01,0x02,0x04};

tubeNixieThread::tubeNixieThread(QObject *parent) :
    QThread(parent)
{
    speed = 0;
    angle = 0;
    direction = 0;

    mem_fd = open("/dev/mem", O_RDWR);
    cpld = (unsigned char*)mmap(NULL,(size_t)0x10,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
    if(cpld == MAP_FAILED)
        return;
}

tubeNixieThread::~tubeNixieThread()
{
    munmap(cpld,0x10);
    ::close(mem_fd);
}

void tubeNixieThread::run()
{
    int i=0;
    while(1)
    {
                switch(i)
                {
                    case 0:
                        *(cpld+(0xe6<<1)) = addr[i];   //数码管地址  (0xe6<<1)为地址
                        *(cpld+(0xe4<<1)) = tube[angle%10];   //数码管个位   (0xe4<<1)为地址
                        break;
                    case 1:
                        *(cpld+(0xe6<<1)) = addr[i];   //数码管地址
                        *(cpld+(0xe4<<1)) = tube[(angle%100)/10] & tube[10];   //数码管十位
                        break;
                    case 2:
                        if((angle%1000)/100 > 0)
                            *(cpld+(0xe6<<1)) = addr[i];   //数码管地址
                        else
                            *(cpld+(0xe6<<1)) = 0;   //数码管地址
                        *(cpld+(0xe4<<1)) = tube[(angle%1000)/100];   //数码管百位2
                        break;
                    case 3:
                        if(direction == 1)
                            *(cpld+(0xe6<<1)) = addr[i];   //数码管地址
                        else
                            *(cpld+(0xe6<<1)) = 0;   //数码管地址
                        *(cpld+(0xe4<<1)) = tube[11];   //数码管百位
                        break;
                    case 4:
                        *(cpld+(0xe6<<1)) = addr[i];   //数码管地址
                        *(cpld+(0xe4<<1)) = tube[speed%10];   //数码管个位
                        break;
                    case 5:
                        if((speed%100)/10 > 0)
                            *(cpld+(0xe6<<1)) = addr[i];   //数码管地址
                        else
                            *(cpld+(0xe6<<1)) = 0;   //数码管地址
                        *(cpld+(0xe4<<1)) = tube[(speed%100)/10];   //数码管十位
                        break;
                    case 6:
                         if((speed%1000)/100 > 0)
                             *(cpld+(0xe6<<1)) = addr[i];   //数码管地址
                         else
                             *(cpld+(0xe6<<1)) = 0;   //数码管地址
                         *(cpld+(0xe4<<1)) = tube[(speed%1000)/100];   //数码管百位
                        break;
                    default:break;
                }
                usleep(10);
                if((++i)==7)
                    i=0;
    }
}

 void tubeNixieThread::tubeDataSlot(unsigned char *ch)
 {
    speed = ch[3]*2;
    angle = (ch[2]&0x7F)*1.8*10;
    direction = ch[2]>>7;
 }

 //==============================================================================

#define COMDEV   "/dev/ttymxc3"
 trackingComThread::trackingComThread(QObject *parent) :
     QThread(parent)
 {
     trackDevice = com_init((char*)COMDEV,B115200);
     if(trackDevice <0)
     {
           qDebug()<<"trackingbus com init error";
         return;
     }
 }

 trackingComThread::~trackingComThread()
 {
     ::close(trackDevice);
 }

 void trackingComThread::run()
 {
     int re=0;
     unsigned char buf[50];
     while(1)
     {
        re = read(trackDevice,buf,sizeof(buf));
        if(re>0)
        {
            if(buf[0] == 0xff && buf[4] == 0xfe)
            {
               emit comDataSignals(buf);
               emit comDataShowSignals(buf);
            }
        }
         usleep(1);
     }
 }

void trackingComThread::trackcarWorkSlot(bool b)
{
    unsigned char buf[3] = {};
    buf[0] = 0xff;
    buf[2] = 0xfe;
    buf[1] = b;
    write(trackDevice,buf,sizeof(buf));
}

 int trackingComThread::com_init(char *DEVICE,speed_t speed)
 {
     struct termios options;
     int COMDevice;
     COMDevice = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);// | O_NONBLOCK
     if(COMDevice < 0)
     {
          printf("open com device failure");
          return COMDevice;
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


