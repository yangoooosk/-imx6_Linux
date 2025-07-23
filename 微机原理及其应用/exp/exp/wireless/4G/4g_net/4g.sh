#!/bin/sh
#Closed other network
ifconfig eth0 down
ifconfig wlan0 down
pppd /dev/ttyUSB2 connect "chat -v -f /etc/ppp/ppp-on-dialer"
time=0
echo "Connected to 3G network"
dev=`ifconfig |grep "ppp0" |busybox cut -d: -f0 |busybox cut -d" " -f1`
while [ "$dev" != "ppp0" ] && [ $time -lt 10 ]
do
	sleep 1
	time=`expr $time + 1`
	dev=`ifconfig |grep "ppp0" |busybox cut -d: -f0 |busybox cut -d" " -f1`
done

if  [ "$dev" == "ppp0" ]
then echo "Connection successful"
	route add default gw 10.64.64.64 dev ppp0
	ifconfig ppp0
else
	echo "Connection failed,Please try again"
fi
