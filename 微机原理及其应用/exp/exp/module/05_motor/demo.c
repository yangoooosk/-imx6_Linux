#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

/***************************************************************
0:	ֹͣ
1:	ֹͣ
2��	��ʱ��
3��	˳ʱ��
****************************************************************/

int main(int argc, char *argv[])
{
	unsigned char data;
	int mem_fd;
	unsigned char *cpld;
	mem_fd = open("/dev/mem", O_RDWR);
	cpld = (unsigned char*)mmap(NULL,(size_t)0x04,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_SHARED,mem_fd,(off_t)(0x8000000));
	if(cpld == MAP_FAILED)
		return 0;
	while(1)
	{
		printf("�����벽�����״̬��\n");
		scanf("%d",&data);
		*(cpld+(0xe2<<1)) = data;   //���������ַ0xe2<<1
	}
	munmap(cpld,0x04);
	close(mem_fd);
	return 0;
}












