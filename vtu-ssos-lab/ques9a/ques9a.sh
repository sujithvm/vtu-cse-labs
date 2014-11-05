#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Error in arguments"
fi

for i in $* ; do
	echo "extracting $i file " >> f.sh
	cat $i >> f.sh
	echo "EOF" >> f.sh
done
