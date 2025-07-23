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
    char *bufw1="12345678";//Ҫд�������,����8
    char *bufw2="abcdefgh";//Ҫд�������,����8

    len=strlen(bufw1);//���ݳ���
    fd= open("/sys/bus/i2c/devices/0-0051/eeprom",O_RDWR);//���ļ�
    if(fd< 0)
    {
        printf("####i2c test device open failed####/n");
        return(-1);
    }
    //д����
    lseek(fd,0x00,SEEK_SET); //��λ��ַ����ַ��0x00
    if((size=write(fd,bufw1, len))<0)//д������
    {
        printf("write error\n");
        return 1;
    }
    printf("writeok\n");
    //������
    lseek(fd,0x00, SEEK_SET);//׼���������ȶ�λ��ַ����Ϊǰ��д���ʱ������˵�ǰ�ļ�ƫ���������������Ҫ���¶�λ��0x00.
    if((size=read(fd,buf,len))<0)//������
    {
        printf("readerror\n");
        return 1;
    }
    printf("readok\n");
//  for(i=0; i< len; i++)
//	{
//		printf("buff[%d]=%c\n",i, buf[i]);//��ӡ����
//	}
    printf("buff = %s\n", buf);//��ӡ����


    //д����
    lseek(fd,0x08,SEEK_SET); //��λ��ַ����ַ��0x08
    if((size=write(fd,bufw2, len))<0)//д������
    {
        printf("write error\n");
        return 1;
    }
    printf("writeok\n");
    //������
    lseek(fd,0x08, SEEK_SET);//׼���������ȶ�λ��ַ����Ϊǰ��д���ʱ������˵�ǰ�ļ�ƫ���������������Ҫ���¶�λ��0x08.
    if((size=read(fd,buf,len))<0)//������
    {
        printf("readerror\n");
        return 1;
    }
    printf("readok\n");
    printf("buff = %s\n", buf);//��ӡ����
    close(fd);

    return 0;
}
