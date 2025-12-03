#! /bin/bash
echo Hello world

a=10
b=20
echo a = $a and b = $b

echo a + b = $((a+b))

c=$a+$b
echo $c|bc


