#!/bin/sh

NAME=$1

mkdir ${NAME::-4}

./extract.sh $NAME 

NAME_D=${NAME::-4}.dat
NAME_P=pos-$NAME_D

DIR=$(pwd)

mkdir $DIR/${NAME::-4}/xy
mkdir $DIR/${NAME::-4}/pos

./cut23.sh 1-$NAME_P
./cut23.sh 2-$NAME_P
./cut23.sh 3-$NAME_P

NAME_XY=xy-$NAME_D

mv $NAME_P info-$NAME_D ${NAME::-4}
mv 1-$NAME_P 2-$NAME_P 3-$NAME_P $DIR/${NAME::-4}/pos
mv 1-$NAME_XY 2-$NAME_XY 3-$NAME_XY $DIR/${NAME::-4}/xy