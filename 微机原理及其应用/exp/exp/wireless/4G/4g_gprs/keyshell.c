#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>

char shell_s[]="\nkeyshell>$: ";

/*int argc, char *argv[]*/
#define CMD_TPYE			(0)
#define PHONE_NUMBER		(1)
#define MAX_CMD_DEPTH  	(2)
extern volatile int STOP ;

int get_line(char *cmd)
{
 	int i=0;
 	char temp;
	while (1) { 
		temp = getchar();
		if (temp == '\r' || temp == '\n') {return 0 ;}	
		cmd[i]=temp;
 
             if(cmd[i]==13){
                        cmd[i]=0;
                        break;
                }
		  fflush(stdout);
		  i++;
		}
}

void * keyshell()
{

	char cmd[256]={0,};
	
	gprs_init();		//GPRS 初始化	
	
	printf("\n<gprs control shell>");
	printf("\n [1]  give a call");		
	printf("\n [2]  respond a call");		
	printf("\n [3]  hold a call");		
	printf("\n [4]  send a msg");
	printf("\n [5]  change baudrate");
	printf("\n [6]  exit");
	printf("\n [**] help menu");

	while(1){

		printf(shell_s);
		fflush(stdout);

		get_line(cmd);
		printf("\r\n");				//显示必要的输出

		if(strncmp("1",cmd,1)==0){
			
			printf("\nyou select to gvie a call, please input number:");	
			fflush(stdout);
			get_line(cmd);
			gprs_call(cmd, strlen(cmd));
			printf("\ncalling......");		
		} else if(strncmp("2",cmd,1)==0){
			
			gprs_ans();
			printf("\nanswering.......");	
		} else if(strncmp("3",cmd,1)==0){

			gprs_hold();
			printf("\nhold a call");
		}else if (strncmp("4",cmd,1)==0){
		
			printf("\nyou select to send a message, please input number:");	
			fflush(stdout);
			get_line(cmd);
			gprs_msg(cmd, strlen(cmd));
			printf("\nsending......");	
		} else if(strncmp("6",cmd,1)==0){
			printf("\nexit this program!\n");
			STOP=1;
			break;
		} else if(strncmp("5",cmd,1)==0){
			printf("\nyou select to change baudrate, please input baudrate:");
			fflush(stdout);
			get_line(cmd);
			gprs_baud(cmd, strlen(cmd));
			printf("please exit and run as another baudrate.");
		}else if (strncmp("**",cmd,2)==0){
			printf("\n<gprs control shell>");
			printf("\n [1]  give a call");
			printf("\n [2]  respond a call");		
			printf("\n [3]  hold a call");		
			printf("\n [4]  send a msg");
			printf("\n [5]  change baudrate");
			printf("\n [6]  exit");
			printf("\n [**] help menu");
		}else if(cmd[0] != 0){
		
			system(cmd);
		}		
	}		
}
