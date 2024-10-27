#7. Write a Program to find whether a given number is positive or negative
#!/bin/bash
echo "Enter a number: "
read n
if [ $n -gt 0 ]
then
echo "The given number is positive"
else
echo "The given number is negative"
fi
