#!/bin/bash

sed -e 's/^[,]*//' $1 > sample.csv
sed -e 's/["]*//' sample.csv > /dev/null

NAME=${1::-4}


egrep -v ^'[0-9]' sample.csv > info-$NAME.dat
egrep ^'[0-9]' sample.csv > pos-$NAME.dat

rm sample.csv