#!/bin/bash
#Shell script to find largest of n numbers, storing numbers in an array.
echo "Enter the Elements of The Array "
read -a A
max=0
for i in ${A[@]}
  do
    if [ $i -gt $max ] ; then
      max=$i
    fi
  done 

echo "Largest element in the array is : $max"
