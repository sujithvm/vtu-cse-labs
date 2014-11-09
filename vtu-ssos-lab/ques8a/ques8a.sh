#!/bin/bash

file1=`ls -l | grep $1 | cut -d " " -f1`
file2=`ls -l | grep $2 | cut -d " " -f1`

if [ $file1 = $file2 ]; then
	echo "File permissions are same : $file1"
else
	echo "File permissions are different"
	echo "File $1 : $file1"
	echo "File $2 : $file2"
fi




 
