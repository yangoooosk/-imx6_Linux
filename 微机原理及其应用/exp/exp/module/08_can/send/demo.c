#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <net/if.h> 
#include <sys/ioctl.h> 
#include <sys/socket.h> 
#include <linux/can.h> 
#include <linux/can/raw.h> 

#ifndef PF_CAN
#define PF_CAN 29
#endif
#ifndef AF_CAN
#define AF_CAN PF_CAN
#endif

/************************************************************************
1、运行前先设置can网络：
	设置波特率：ip link set can0 up type can bitrate 125000
	打开can0: ifconfig can0 up
	关闭can0: ifconfig can0 down
	查看can0总线初始化：dmesg | grep can
	查看can0连接状态：ip -details link show can0
2、可用以下命令代替代码实现功能
	接收can0数据：candump can0
	发送can0数据：cansend can0 123#11223344556677
*************************************************************************/

int main(int argc, char *argv[]) 
{ 
	int s, nbytes; 
	//int recv_own_msgs = 1;
	struct sockaddr_can addr; 
	struct ifreq ifr; 
	struct can_frame frame[2] = {{0}}; 
	
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);//创建套接字 
	strcpy(ifr.ifr_name, "can0" ); 
	ioctl(s, SIOCGIFINDEX, &ifr); //指定 can0 设备 
	
	addr.can_family = AF_CAN; 
	addr.can_ifindex = ifr.ifr_ifindex; 
	
	bind(s, (struct sockaddr *)&addr, sizeof(addr));//将套接字与 can0 绑定 
	
	//禁用过滤规则，本进程不接收报文，只负责发送 
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0); 
	//setsockopt(s, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(recv_own_msgs));
	//生成两个报文 
	frame[0].can_id = 0x00; 
	frame[0].can_dlc = 1; 
	frame[0].data[0] = 'Y'; 
	frame[1].can_id = 0x00; 
	frame[1].can_dlc = 1; 
	frame[1].data[0] = 'N'; 
	//循环发送两个报文 
	while(1) 
	{ 
		nbytes = write(s, &frame[0], sizeof(frame[0])); //发送 frame[0] 
		if(nbytes != sizeof(frame[0])) 
		{ 
			printf("Send Error frame[0]\n!"); 
			break; //发送错误，退出 
		}
 		printf("Send success frame[0]\n!"); 
		sleep(1); 
		nbytes = write(s, &frame[1], sizeof(frame[1])); //发送 frame[1] 
		if(nbytes != sizeof(frame[1])) 
		{ 
			printf("Send Error frame[1]\n!"); 
			break; 
		} 
		printf("Send success frame[1]\n!"); 
		sleep(1); 
	} 
	close(s); 
	return 0; 
}