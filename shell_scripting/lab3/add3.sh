#!usr/bin/sh
read x
sed "1d;n;d" $x > evenfile
sed "n;d" $x > oddfile