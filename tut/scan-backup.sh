#!/bin/bash
# Bash Shell Script that accepts a string (suffix of a file such as txt or jpg),
# and an integer N. Returns the largest N files to standard output within the current directory.

suffix=$1
N=$2
find . -type f -name "*.$suffix" -printf '%p\t%s\n' | sort -nr -k 2 | head -$N | awk '{ x += $2 ; print $1 "\t" $2} END { print "Total size: " x }'
