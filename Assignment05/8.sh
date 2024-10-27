#8. Write a program to print the table of a given number.
#!/bin/bash
echo "Enter a number to print its table: "
read n
i=1
while [ $i -le 10 ]
do
	o=`expr $i \* $n`
	echo "$o"
	i=`expr $i + 1`
done
