#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>

int main(void){
    int fd, size, len, i;
    char buf[16]= {0};
    char *bufw1="12345678";//要写入的数据,长度8
    char *bufw2="abcdefgh";//要写入的数据,长度8

    len=strlen(bufw1);//数据长度
    fd= open("/sys/bus/i2c/devices/0-0051/eeprom",O_RDWR);//打开文件
    if(fd< 0)
    {
        printf("####i2c test device open failed####/n");
        return(-1);
    }
    //写操作
    lseek(fd,0x00,SEEK_SET); //定位地址，地址是0x00
    if((size=write(fd,bufw1, len))<0)//写入数据
    {
        printf("write error\n");
        return 1;
    }
    printf("writeok\n");
    //读操作
    lseek(fd,0x00, SEEK_SET);//准备读，首先定位地址，因为前面写入的时候更新了当前文件偏移量，所以这边需要重新定位到0x00.
    if((size=read(fd,buf,len))<0)//读数据
    {
        printf("readerror\n");
        return 1;
    }
    printf("readok\n");
//  for(i=0; i< len; i++)
//	{
//		printf("buff[%d]=%c\n",i, buf[i]);//打印数据
//	}
    printf("buff = %s\n", buf);//打印数据


    //写操作
    lseek(fd,0x08,SEEK_SET); //定位地址，地址是0x08
    if((size=write(fd,bufw2, len))<0)//写入数据
    {
        printf("write error\n");
        return 1;
    }
    printf("writeok\n");
    //读操作
    lseek(fd,0x08, SEEK_SET);//准备读，首先定位地址，因为前面写入的时候更新了当前文件偏移量，所以这边需要重新定位到0x08.
    if((size=read(fd,buf,len))<0)//读数据
    {
        printf("readerror\n");
        return 1;
    }
    printf("readok\n");
    printf("buff = %s\n", buf);//打印数据
    close(fd);

    return 0;
}
