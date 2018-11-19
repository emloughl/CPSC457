#!/bin/bash

function numbers 
{
for i in {10..20}
do
echo $i
done
}

function hello
{
echo hello
}

hello
sleep 1
numbers
exit
