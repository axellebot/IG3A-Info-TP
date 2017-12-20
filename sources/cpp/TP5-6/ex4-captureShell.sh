#!/bin/bash
trap "echo Signal CTRL-C capturé" SIGINT
echo "lancement du processus $$";
while :
do
    sleep 1;
done