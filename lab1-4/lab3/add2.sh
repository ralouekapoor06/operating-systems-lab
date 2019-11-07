#!usr/bin/sh

read x
res=1
for ((i=$x;i>0;i--));do
	res=`bc<<<"$i""*""$res"`
done
echo "$res"
