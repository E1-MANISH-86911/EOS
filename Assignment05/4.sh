#4. Write a shell script to determine whether a given number is prime or not

#!/bin/bash
echo "Enter a number: "
read num
check=1
i=2
if [ $num -lt 2 ]
then
	echo "Not Prime"
else
	while [ $i -le `expr $num / 2` ]
	do
    	if [ `expr $num % $i` -eq 0 ]
    	then
        	check=0
        	break
    	fi
    	i=`expr $i + 1`
	done
	if [ $check -eq 1 ]
	then
    	echo "Prime number"
	else
    	echo "Not Prime"
	fi
fi
