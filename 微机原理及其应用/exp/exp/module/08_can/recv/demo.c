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
1������ǰ������can���磺
	���ò����ʣ�ip link set can0 up type can bitrate 125000
	��can0: ifconfig can0 up
	�ر�can0: ifconfig can0 down
	�鿴can0���߳�ʼ����dmesg | grep can
	�鿴can0����״̬��ip -details link show can0
2��������������������ʵ�ֹ���
	����can0���ݣ�candump can0
	����can0���ݣ�cansend can0 123#11223344556677
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
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW); //�����׽��� 
	strcpy(ifr.ifr_name, "can0" ); 
	ioctl(s, SIOCGIFINDEX, &ifr); //ָ�� can0 �豸 
	addr.can_family = AF_CAN; 
	addr.can_ifindex = ifr.ifr_ifindex; 
	bind(s, (struct sockaddr *)&addr, sizeof(addr)); //���׽����� can0 �� 
	//������չ���ֻ���ձ�ʾ������ 0x11 �ı��� 
	rfilter[0].can_id = 0x00; 
	rfilter[0].can_mask = CAN_SFF_MASK; 
	//���ù��˹��� 
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter)); 
	//setsockopt(s, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(recv_own_msgs)); 
	while(1)
	{ 
		nbytes = read(s, &frame_rev, sizeof(frame_rev)); //���ձ��� 
		//��ʾ���� 
		if(nbytes > 0)
		{
			printf("ID=0x%X DLC=%d data[0]=%X\n",frame_rev.can_id,frame_rev.can_dlc,frame_rev.data[0]); 
		} 
	} 
	close(s); 
	return 0; 
}