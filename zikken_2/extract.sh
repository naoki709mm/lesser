#!/bin/sh

./getdat.sh $1

NAME=$1
NAME=${NAME::-4}.dat

sed -e "1,4d" info-$NAME > info.dat
cut -f 2 -d , info.dat > subinfo.dat

cat subinfo.dat | tr -dc '0123456789.\n' > info.dat

MARK=$(sed -n 1p info.dat)
SAMPLE=$(sed -n 2p info.dat)

rm info.dat subinfo.dat

NAME=pos-$NAME

./extract $SAMPLE $MARK $NAME