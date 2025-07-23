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
	int s, nbytes, nbytes_send; 
	//int recv_own_msgs = 1
	struct sockaddr_can addr; 
	struct ifreq ifr;
	struct can_frame frame_rev; 
	struct can_frame frame_send; 
	struct can_filter rfilter[1]; 
	int len = sizeof(addr);
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW); //创建套接字 
	strcpy(ifr.ifr_name, "can0" ); 
	ioctl(s, SIOCGIFINDEX, &ifr); //指定 can0 设备 
	addr.can_family = AF_CAN; 
	addr.can_ifindex = ifr.ifr_ifindex; 
	bind(s, (struct sockaddr *)&addr, sizeof(addr)); //将套接字与 can0 绑定 
	//定义接收规则，只接收表示符等于 0x11 的报文 
	rfilter[0].can_id = 0x00; 
	rfilter[0].can_mask = CAN_SFF_MASK; 
	//设置过滤规则 
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter)); 
	//setsockopt(s, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(recv_own_msgs)); 
	while(1)
	{ 
		nbytes = read(s, &frame_rev, sizeof(frame_rev)); //接收报文 
		//显示报文 
		if(nbytes > 0)
		{
			printf("ID=0x%X DLC=%d data[0]=%X\n",frame_rev.can_id,frame_rev.can_dlc,frame_rev.data[0]); 
		} 
	} 
	close(s); 
	return 0; 
}