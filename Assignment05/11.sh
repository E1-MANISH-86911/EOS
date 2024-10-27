#11. Write a program to calculate gross salary if the DA is 40%, HRA is 20% of basic salary. 
#Accept basic salary form user and display gross salary (Result can be floating point value).
#!/bin/bash
echo "Enter basic salary: "
read salary
DA=$(echo "scale=2; $salary * 0.4" | bc)
HRA=$(echo "scale=2; $salary * 0.2" | bc)
GROSS=$(echo "scale=2; $salary + $DA + $HRA" | bc)
echo "Gross salary = $GROSS"

