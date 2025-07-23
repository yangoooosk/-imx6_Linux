#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#define NOKEY 0

int main(int argc,char *argv[])
{
	int keys_fd;	
        char ret[2]; 
	struct input_event t;

        keys_fd = open(argv[1], O_RDONLY);
	if(keys_fd<=0)
	{
                printf("open %s device error!\n",argv[1]);
		return 0;
	}


	while(1)
	{	
                if(read(keys_fd,&t,sizeof(t))==sizeof(t)) {
		    if(t.type==EV_KEY)
			if(t.value==0 || t.value==1)
			    printf("key %d %s\n",t.code,(t.value)?"Pressed":"Released");
		}
	}	
	close(keys_fd);
	
        return 0;
}
