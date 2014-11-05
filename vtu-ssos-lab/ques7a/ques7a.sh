#!/bin/bash

if [ $# -eq 0 ]; then
	echo "No command line arguments"
	exit
fi

rev=""
echo "The number of arguments : $# and args : $* "

for arg in $* ; do 
	rev=$arg" "$rev
done
echo "Reversed arguments : $rev"
