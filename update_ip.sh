#!/bin/sh

TIME=`date`

cd ~/Kerry/
git pull

wget -qO- -t1 -T2 ipv4.icanhazip.com > tmp.txt

IP=`cat tmp.txt`
if [ -z "$IP"  ]; then
	echo "The return IP is empty, will exit!"
	exit 0
fi

#echo "return $IP "
mv tmp.txt ips.txt
git commit ips.txt  --message="update ip to $IP $TIME"
git push origin master
