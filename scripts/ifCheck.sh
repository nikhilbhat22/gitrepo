#!/bin/bash

num=$#

if [ "$num" -lt 2 ]
then
	echo " Atleast 2 args should be passed"
	exit
fi

x=$1
y=$2
