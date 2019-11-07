#!usr/bin/sh

x=$1
y=$2

case $y in
	"l") echo `wc -l $x`;;
	"c") echo `wc -c $x`;;
	"w") echp `wc -w $x`;;
esac