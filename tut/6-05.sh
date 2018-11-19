#!/bin/bash
# This script is about password !! and read from user
echo "What is the password?"
sleep 3
read pass
if [ "$pass" = "password" ]; then
	echo "That is okay!"
elif [ "$pass" = "ubuntu" ] ; then
	echo " Nice. "
else
	echo "That is not okay, " $pass " is not the correct password. :("
fi
