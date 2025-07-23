#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

/********************************************************************************
ºì£ºD16¡¢D20   0xfe(~0x1)  //µÍµçÆ½µÆÁÁ
»Æ£ºD18¡¢D19   0xfd(~0x2)
ÂÌ£ºD21¡¢D17   0xfb(~0x4)

ºì£ºD15¡¢D24   0xf7(~0x8)  
»Æ£ºD14¡¢D25   0xef(~0x10)
ÂÌ£ºD13¡¢D26   0xdf(~0x20)

È«ÁÁ£º         0xc0(~0x3f) / 0x00(~0xff)
È«Ãð£º         0xff(~0x00)
*********************************************************************************/

unsigned char data[] = {
	0x01,0x02,0x04,0x08,0x10,0x20,0x10,0x08,0x04,0x02,0x01,
	0x09,0x12,0x24,0x12,0x09,0x01,0x04,0x10,0x20,0x08,0x02,
	0x01,0x08,0x02,0x10,0x04,0x20,0xff,0x00,0xff,0x00,0xff,0x00
};

int main(int argc, char *argv[])
{
	int mem_fd,i;
	unsigned char *cpld;
	mem_fd = open("/dev/mem", O_RDWR);
	cpld = (unsigned char*)mmap(NULL,(size_t)0x4,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
	if(cpld == MAP_FAILED)
		return 0;
	while(1)
	{
		for(i=0;i<sizeof(data);i++)
		{
			*(cpld+(0xe8<<1)) = ~data[i];  //ledµØÖ·Îªoxe8<<1
			usleep(200000);
		}
	}
	munmap(cpld,0x4);
	close(mem_fd);
	return 0;
}












