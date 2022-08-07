#!bin/bash
#Shell Script to generate prime numbers in a given range
echo -ne "Enter lower bound of the interval: "
read a
echo -ne "Enter upper bound of the interval: "
read b
echo -ne "Prime numbers in the range $a and $b is/are: "
for((i=$a; i<=b; i++))
do
  if [[ $i == 0 || $i == 1 ]]; then
    continue
  fi
  
  count=0
  for((j=1; j<=i; j++))
  do
    if [ $((i%j)) == 0 ]; then
      count=$((count+1))
    fi
  done
  if [ $count == 2 ]; then
    echo -ne "$i "
  fi
done
echo 
