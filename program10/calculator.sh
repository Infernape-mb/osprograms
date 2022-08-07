#!/bin/bash
#Shell script to simulate simple calulator
echo "Enter any two non-zero numbers: "
read a b 

echo "Enter The Operator: "
echo "Addition +"
echo "Subtraction -"
echo "Product *"
echo "Division /"
read op

case $op in
'+') echo "Sum of $a and $b is : $(( a + b ))"
;;
'-') echo "Difference of $a and $b is : $(( a - b ))"
;;
'*') echo "Product of $a and $b is : $(( a * b ))"
;;
'/') echo "Division of $a and $b is : $(( a / b ))"
;;
*) echo "Invalid Input Operator"
;;
esac
