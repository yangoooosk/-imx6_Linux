#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

unsigned char tube[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x7f,0xff};
unsigned char addr[] = {0x11,0x22,0x44,0x88};
int main(int argc, char *argv[])
{
	int num=0;
	int i=0,j=0;
	int mem_fd;
	unsigned char *cpld;
	mem_fd = open("/dev/mem", O_RDWR);
	cpld = (unsigned char*)mmap(NULL,(size_t)0x10,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
	if(cpld == MAP_FAILED)
		return 0;
	while(1)
	{	
		for(j=0;j<245*4;j++)
		{
			switch(i)
			{
				case 0:
					*(cpld+(0xe6<<1)) = addr[i];   //数码管地址  (0xe6<<1)为地址
					*(cpld+(0xe4<<1)) = tube[num%10];   //数码管个位   (0xe4<<1)为地址
					break;
				case 1:
					*(cpld+(0xe6<<1)) = addr[i];   //数码管地址
					*(cpld+(0xe4<<1)) = tube[(num%100)/10];   //数码管十位
					break;
				case 2:
					*(cpld+(0xe6<<1)) = addr[i];   //数码管地址
					*(cpld+(0xe4<<1)) = tube[(num%1000)/100];   //数码管百位2
					break;
				case 3:
					*(cpld+(0xe6<<1)) = addr[i];   //数码管地址
					*(cpld+(0xe4<<1)) = tube[num/1000];   //数码管千位
					break;
				default:break;
			}
			usleep(1000);
			if((++i)==4)
				i=0;
		}
		if((++num) == 10000)
			num = 0;
	}
	munmap(cpld,0x10);
	close(mem_fd);
	return 0;
}












