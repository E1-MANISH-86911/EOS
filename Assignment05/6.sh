#6. Write a Program to find whether a given year is a leap year or not
#!/bin/bash
echo "Enter a year: "
read year
if [ $((year % 4)) -eq 0 ] && { [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; }
then
	echo "It is a learp year"
else
	echo "It is not a leap year"
fi
