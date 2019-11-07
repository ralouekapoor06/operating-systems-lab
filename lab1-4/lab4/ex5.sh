#!usr/bin/sh

patterns=$1
operation=$2
read z

case $operation in
	1)echo `grep -E "$patterns" $z`;;
	2)echo `sed '/"$patterns"/d' $z`;;
	3)exit;;
esac


