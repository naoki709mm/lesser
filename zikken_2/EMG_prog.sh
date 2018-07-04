#!/bin/sh

NAME=$1

python bandpass.py $NAME

A=${NAME::-4}.dat

./prog_emg $A