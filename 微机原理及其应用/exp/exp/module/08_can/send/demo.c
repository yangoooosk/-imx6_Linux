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
	int s, nbytes; 
	//int recv_own_msgs = 1;
	struct sockaddr_can addr; 
	struct ifreq ifr; 
	struct can_frame frame[2] = {{0}}; 
	
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);//�����׽��� 
	strcpy(ifr.ifr_name, "can0" ); 
	ioctl(s, SIOCGIFINDEX, &ifr); //ָ�� can0 �豸 
	
	addr.can_family = AF_CAN; 
	addr.can_ifindex = ifr.ifr_ifindex; 
	
	bind(s, (struct sockaddr *)&addr, sizeof(addr));//���׽����� can0 �� 
	
	//���ù��˹��򣬱����̲����ձ��ģ�ֻ������ 
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0); 
	//setsockopt(s, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(recv_own_msgs));
	//������������ 
	frame[0].can_id = 0x00; 
	frame[0].can_dlc = 1; 
	frame[0].data[0] = 'Y'; 
	frame[1].can_id = 0x00; 
	frame[1].can_dlc = 1; 
	frame[1].data[0] = 'N'; 
	//ѭ�������������� 
	while(1) 
	{ 
		nbytes = write(s, &frame[0], sizeof(frame[0])); //���� frame[0] 
		if(nbytes != sizeof(frame[0])) 
		{ 
			printf("Send Error frame[0]\n!"); 
			break; //���ʹ����˳� 
		}
 		printf("Send success frame[0]\n!"); 
		sleep(1); 
		nbytes = write(s, &frame[1], sizeof(frame[1])); //���� frame[1] 
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