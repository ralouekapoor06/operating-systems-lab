#!usr/bin/sh

read x
num1=1
num0=0
sum=0
echo $num0
echo $num1

while (("$sum"<"$x"));do
    sum=`bc<<<"$num1""+""$num0"`
    echo "$sum"
    num0=$num1
    num1=$sum
done