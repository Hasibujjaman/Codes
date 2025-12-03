#! /bin/bash

echo $0
echo $1
echo $2

echo Total number of args: $#

echo All args: $@ 


arr=(1 2 3 4 5)
echo ${arr[0]}
echo ${arr[4]}

args=($@)
echo First argument:  ${args[0]}

