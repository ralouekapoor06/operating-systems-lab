read x
r=2
flag=0;
for ((i=2;i<$x;i++));do
	f=`bc<<<"$x""%""$i"`
	if [ "$f" == 0 ];then
		flag=1
		break
	fi
done
if [ "$flag" == 0 ];then
	echo "It is a prime number"
else
	echo "It is not a prime number"
fi

