#!/bin/bash
# Author : Axel LE BOT

echo "lancement du processus $$";

while :
do
    sleep 1;
    echo ".";
    trap "echo SIGNAL CAPTURE; echo FIN" SIGINT
    trap "echo SIGNAL USER01 ; echo FIN" SIGUSR1
done