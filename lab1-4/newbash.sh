#!usr/bin/sh

x=`bc<<<2"+"3`
echo $x

if [[ $x == 5 ]];then
	echo "output is right"
fi

case $x in
5) echo "It is five";;
6) echo "It is six";;
esac

for (( i=0;i<$x;i++ ));do
	echo $i
done

j=0

while (( $j<$x ));do
	j=`bc<<<"$j""+"1`
done

read u
x=$1
y=$2

for i in "$@";do
	echo $i
done

function_add(){
a=$1
b=$2
c=`bc<<$a"+"$b`
echo $c
}

function_add 3 5






