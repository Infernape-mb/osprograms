#palindrome 
#!bin/bash
echo "enter string "
read str
len=${#str}
 for(( i=$len-1;i>=0;i-- ))
  do 
   Rev=$Rev${str:$i:1}
  done 
 echo "reversed string is $Rev "
  if [ $str == $Rev ]; then
   echo "$str is a palindrome "
   else
    echo "$str is not a palindrome "
   fi
