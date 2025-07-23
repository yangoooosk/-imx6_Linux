
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/signal.h>
#include "tty.h"
#include"gprs.h"


void gprs_init()
{ 
	int i;
	for(i=0; i<5; i++) {
		tty_writecmd(cmd[i], strlen(cmd[i])); 
		
	}
}

void gprs_hold()
{
	tty_writecmd("AT", strlen("AT"));
	tty_writecmd("ATH", strlen("ATH"));//发送挂机命令ATH 
	tty_writecmd("AT+CHUP\r", strlen("AT+CHUP\r"));//发送挂机命令ATH 
}

void gprs_ans()
{ 
	tty_writecmd("AT", strlen("AT"));
	tty_writecmd("ATA", strlen("ATA"));//发送接听命令ATA
}

//拨叫  
void gprs_call(char *number, int num)			
{ 

	tty_writecmd("AT", strlen("AT"));
        tty_writecmd("ATH", strlen("ATH"));
	tty_writecmd("AT", strlen("AT"));
	tty_write("ATD", strlen("ATD")); //发送拨打命令ATD	
	tty_write(number, num);
	tty_write(";\r", strlen(";\r"));
	usleep(200000);

}

//发送短信
void gprs_msg(char *number, int num)		
{ 
	char ctl[]={26,0};
	char text[]="Welcome to use up-tech embedded platform!";
	tty_writecmd("AT", strlen("AT"));
	//usleep(5000);

	tty_writecmd("ATE1", strlen("ATE1"));
	tty_writecmd("AT+CMGF=1", strlen("AT+CMGF=1"));		//发送修改字符集命令
	tty_write("AT+CMGS=", strlen("AT+CMGS="));	//发送发短信命令，具体格式见手册
	tty_write("\"", strlen("\""));
	tty_write(number, strlen(number));
  	tty_write("\"", strlen("\""));
  	tty_write("\r", strlen("\r"));
	usleep(10000);
        tty_write( text, strlen(text));
	tty_write(ctl, 1);      //“CTRL+Z"的ASCII码

	usleep(300000);
}

void gprs_baud(char *baud,int num)
{
	tty_write("AT+IPR=", strlen("AT+IPR="));
	tty_writecmd(baud, strlen(baud) );
	usleep(200000);
}


