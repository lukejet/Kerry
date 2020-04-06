#!/bin/sh

TIME=`date`

cd ~/Kerry/
git pull

wget -qO- -t1 -T2 ipv4.icanhazip.com > ips.txt
IP=`cat ips.txt`

git commit ips.txt  --message="update ip to $IP $TIME"
git push origin master
