#!/bin/sh

TIME=`date`
IPFILE=$1

if [ -z "$IPFILE" ]; then
	IPFILE=ips.txt
fi

cd ~/Kerry/
git pull

wget -qO- -t1 -T2 ipv4.icanhazip.com > tmp.txt

IP=`cat tmp.txt`
if [ -z "$IP"  ]; then
	echo "The return IP is empty, will exit!"
	rm tmp.txt
	exit 0
fi

#echo "return $IP "
mv tmp.txt $IPFILE
git commit $IPFILE --message="update ip to $IP $TIME"
git push origin master
