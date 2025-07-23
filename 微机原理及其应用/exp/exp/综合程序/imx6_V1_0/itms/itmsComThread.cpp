#include "itmsComThread.h"
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

#define IRDADevice "/dev/ttyS0"
 itmsComThread::itmsComThread(QObject *parent) :
     QThread(parent)
 {
     irdaDevice = com_init((char*)IRDADevice,B57600);
     if(irdaDevice <0)
         return;
 }

 itmsComThread::~itmsComThread()
 {
     ::close(irdaDevice);
 }

 void itmsComThread::run()
 {
     int re=0;
     char irdaData[50]="";
     while(1)
     {
         memset(irdaData,0,sizeof(irdaData));
         re = read(irdaDevice,irdaData,sizeof(irdaData));
         if(re>0)
         {
                 if(irdaData[0] == 'I' &&  irdaData[1] =='R'  &&  irdaData[2] == 'D'  &&  irdaData[3] == 'S'  &&  irdaData[4] == ' '  &&  irdaData[5] == 'W'
                         &&  irdaData[6] == 'a'  &&  irdaData[7] == 'r' )
                 {
                    emit comDataSignals();
                 }
         }
         usleep(1);
     }
 }

 int itmsComThread::com_init(char *DEVICE,speed_t speed)
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


