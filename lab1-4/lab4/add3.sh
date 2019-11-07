#!usr/bin/sh

x=$1
y=$2
z=$3
d=1
i=1
while read p;do
	if [[ "$i">"$y" && "$i"<"$z" ]];then
		echo $p
	fi
	i=`bc<<<"$i""+""$d"`
done < $x