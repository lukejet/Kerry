#!/bin/bash

FIX=jpg
URL=$1

DATE=`date +%y%m%d_%H_%M_%S`
REC_PATH=$2
FILE_NAME=${REC_PATH}_$DATE.$FIX

wget -qO- -t1 -T2 $URL -O $FILE_NAME || rm -f $FILE_NAME
