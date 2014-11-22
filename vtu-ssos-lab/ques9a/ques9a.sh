#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Error in arguments"
fi

for i in $* ; do
	echo "echo EXTRACTING $i FILE " >> f.sh
	cat $i >> f.sh
	echo "echo END OF $i FILE" >> f.sh	
done
