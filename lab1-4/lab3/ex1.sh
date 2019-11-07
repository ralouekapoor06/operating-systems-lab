#!bin/sh

read x
if [ -d "$x" ];then
	echo "It is a directory"
else
	echo "It is a file"
fi

