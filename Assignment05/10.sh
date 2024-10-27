#10. Write a program to find given number of terms in the Fibonacci series.
#!bin/bash
echo "Enter a number to find given number of terms in fibonacci series: "
read num
i=1
fibo=0
fibo1=1
while [ $i -le $num ]
do
	echo -n -e "$fibo "
	temp=`expr $fibo + $fibo1`
	fibo=$fibo1
	fibo1=$temp
	i=`expr $i + 1`
done
echo
