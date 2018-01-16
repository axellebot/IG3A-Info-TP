#!/bin/bash
# Axel LE BOT - 2017-10-01
clear
USER=$(whoami)
echo "Hello $USER"
echo -e "\"\e[9mhello world\e[0m\" \"hello Kitty\""
echo "Do you like fishsticks(y/n)?"
read answer

if [ "$answer" = "y" ]
then
	echo "then you are a gayfish!"
else
	echo "OK"
fi
