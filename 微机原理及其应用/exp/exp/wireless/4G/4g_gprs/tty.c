/************************************************
 *  TTY SERIAL ROUTES 
 *  use ttyS1 to ctrol GPRS
 *  by Zou jian guo <ah_zou@163.com>   
 *  2004-11-02
 *  
 *  edited by wbin <wbinbuaa@163.com>
 *  2005-01-19
 *  
 *  modify by sprife <tdd_uptech@126.com> 
 *  support for UP_CUP6410 GPRS COM
 *  2009-11-18 
*************************************************/
#include <sys/types.h>                                                  
#include <sys/stat.h>                                                      
#include <fcntl.h>                                                       
#include <termios.h>                                                    
#include <stdio.h>    
#include <stdlib.h>
#include <string.h>

#define COM "/dev/ttyUSB2"
//#define COM "/dev/ttySAC2"

static int fd;
static struct termios oldtio,newtio;

//==============================================================
int tty_end()
{
  	tcsetattr(fd,TCSANOW,&oldtio);	 	/* restore old modem setings */
//  	tcsetattr(0,TCSANOW,&oldstdtio); 	/* restore old tty setings */
  	close(fd);
}
//==============================================================
int tty_read(char *buf,int nbytes)
{
	return read(fd,buf,nbytes);
}
//==============================================================
void tty_flush()
{
	tcflush(fd, TCIFLUSH);
}
int tty_write(char *buf,int nbytes)
{
	int i;
	for(i=0; i<nbytes; i++) {
		write(fd,&buf[i],1);
		usleep(200);
	}
	return tcdrain(fd);
}

//==============================================================
int tty_writecmd(char *buf,int nbytes)
{
	int i;
	for(i=0; i<nbytes; i++) {
		write(fd,&buf[i],1);
		usleep(200);
	}
	write(fd,"\r",1);
	usleep(300000);
	return tcdrain(fd);
}

//==============================================================
extern int baud;
int tty_init()
{
	fd = open(COM, O_RDWR ); //| O_NONBLOCK);//
	if (fd <0) {
	    	perror(COM);
	    	exit(-1);
  	}
	
  	tcgetattr(fd,&oldtio); /* save current modem settings */
	bzero(&newtio, sizeof(newtio)); 

	newtio.c_cflag = baud | /*CRTSCTS |*/ CS8 /*| CLOCAL | CREAD */;
	newtio.c_iflag = IGNPAR | ICRNL; 
	newtio.c_oflag = 0; 
	newtio.c_lflag = ICANON;

	 newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */  
	 newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */ 
	 newtio.c_cc[VERASE]   = 0;     /* del */ 
	 newtio.c_cc[VKILL]    = 0;     /* @ */ 
	 newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */ 
	 newtio.c_cc[VTIME]    = 0;     /* 不使用分割字元组的计时器 */ 
	 newtio.c_cc[VMIN]     = 1;     /* 在读取到 1 个字元前先停止 */ 
	 newtio.c_cc[VSWTC]    = 0;     /* '\0' */ 
	 newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */  
	 newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */ 
	 newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */ 
	 newtio.c_cc[VEOL]     = 0;     /* '\0' */ 
	 newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */ 
	 newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */ 
	 newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */ 
	 newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */ 
	 newtio.c_cc[VEOL2]    = 0;     /* '\0' */ 


 	tcflush(fd, TCIFLUSH);
	tcsetattr(fd,TCSANOW,&newtio);/*set attrib	  */

	return 0;
}
