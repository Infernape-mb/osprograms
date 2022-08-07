#!/bin/bash
#Shell Script to check whether the number is palindrome or not

echo "Enter any number: "
read num

sum=0
temp=$num
while [ $num -gt 0 ]
do
    r=$((num%10))
    sum=$((sum*10+r))
    num=$((num/10))
done
echo "Number after reversing: $sum"
if [ $temp == $sum ];then
    echo "$temp is a palindrome"
else
    echo "$temp is not palindrome"
fi
