/************************************************
 *  GPRS demo, use ppp to connect internet
 *  use ttyS1 to ctrol GPRS
 *  by Zou jian guo <ah_zou@163.com>   
 *  2004-11-02
 *  modify by sprife for UP_CUP6410II GPRS 
*************************************************/


#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

//#include <sys/signal.h>
#include <pthread.h>
#include "tty.h"
#include "gprs.h"

/*--------------------------------------------------------*/
#define ENDMINITERM 27 /* ESC to quit miniterm */
#define FALSE		0
#define TRUE  		1


/*--------------------------------------------------------*/
volatile int STOP=FALSE;
int GET_GPRS_OK=FALSE;
volatile int baud=B9600;

char * cmd[20]={
		"AT",
		"ATE1",
		"AT+CHFA=1", 			//设置通话通道为1,AT+CHFA 命令切换主副音频通道
		"AT+CLVL=100",			//设置受话器音量最大, AT+CLVL 命令可以调节输出音频信号增益
		"AT+CMIC=1,10"			//设置通道1的话筒增益
};

void * keyshell() ;


/* modem input handler */
void* gprs_read(void * data)
{
	int i=0;
	char c;
	char buf[1024];
  	printf("\nread modem\n");
	
  	while (STOP==FALSE) 	{		

	    	tty_read(&c,1); 	
		printf("%c",c);	
	}
  	printf("exit from reading modem\n");
  	return NULL; 
}

int get_baudrate(int argc,char** argv)
{	
	int v=atoi(argv[1]);
	switch(v){		
		case 4800:
			return B4800;
		case 9600:
			return B9600;
		case 19200:
			return B19200;
		case 38400:
			return B38400;
		case 57600:
			return B57600;
		case 115200:	
			return B115200;
		default:
			return -1;
		} 
}

/*--------------------------------------------------------*/
int main(int argc,char** argv)
{
	int ok;
 	pthread_t th_a, th_b;
 	void * retval;
	if (argc >1)
		{
			baud=get_baudrate(argc, argv);
		}
	tty_init();

	pthread_create(&th_b, NULL, gprs_read, 0);
  	pthread_create(&th_a, NULL, keyshell, 0); 
	
	while(!STOP){
		usleep(100000);
	}
  	tty_end();
  	exit(0); 
}
