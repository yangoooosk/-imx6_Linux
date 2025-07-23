#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
int main(int argc ,char* argv[])
{
	int fd;
	int ret;
	fd = open(argv[1],O_RDWR,0777);
	if(fd<0)
	{
		printf("open device %s err",argv[1]);
		return -1;
	}
//	printf("argv[2] = %d,argv[3] = %d\n",*argv[2],*argv[3]);
//	printf("argv[2] = %s,argv[3] = %s\n",argv[2],argv[3]);
	ret = ioctl(fd,*argv[2]-'0',*argv[3]-'0');
	if(ret <0)
	{
		printf("ioctl err\n");
		return -1;
	}
}

