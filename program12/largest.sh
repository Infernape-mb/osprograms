#!/bin/bash
#Shell script to find largest of three numbers
echo -ne "Enter any three numbers : "
read a b c
max=$a
if [ $b -gt $a ] ; then
  max=$b
fi
if [ $c -gt $a ] ; then
  max=$c
fi
echo "Largest number is $max"
