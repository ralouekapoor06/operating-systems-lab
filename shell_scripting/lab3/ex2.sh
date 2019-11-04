#!usr/bin/sh

read x

for y in `find -maxdepth 1 -name "*$x*"`;do
	echo $y
done