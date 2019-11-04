#!usr/bin/sh

read basics
read ta

x=`bc<<<"$basics""+""$ta""+"0.1"*""$basics"`
echo $x