#9. Write a program to find the factorial of given number.
#!/bin/bash
echo "Enter a number to print its factorial: "
read n
fact=1
while [ $n -ge 1 ]
do
	fact=`expr $fact \* $n`
	n=`expr $n - 1`
done
echo "factorial=$fact"
