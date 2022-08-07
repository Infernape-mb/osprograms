#!/bin/bash
#Shell script for addition of two matrices

#!/bin/bash
echo -ne "enter the size of matrix\n"
read n
declare -A X   
declare -A Y
declare -A Z

echo "Enter the elements of the first matrix"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        read X[$i,$j]
    done
done


echo "Enter the elements of the second matrix"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        read Y[$i,$j]
    done
done

echo "The first matrix is :"
echo
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        echo -ne " ${X[$i,$j]}"
    done
    echo
    echo
done


echo "The second matrix is:"
echo
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        echo -ne " ${Y[$i,$j]}"
    done
    echo -e "\n"
done

echo "The result is :"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
        echo -ne " ${Z[$i,$j]}"
    done
    echo -e "\n"
done
