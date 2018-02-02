#!/bin/bash
# Author : Axel LE BOT

for signal in "seq 1 31"
do
    # On lance le script de la boucle infinie en arrière plan et en redirigeant la sortie dans le fichier fantôme
    ./boucleShell.sh & > /dev/null 2>&1
    # On récupère l'id du processus
    PID=$!
    echo "Process $PID"

    # On tue le processus avec le signal
    kill -$signal $PID > /dev/null 2>&1

    # On vérifie si le processus est en cours d'execution
    if ps -p $PID > /dev/null 2>&1
    then
        # Si il est toujours en cours d'execution, on le tue.
        echo "Process not ended"
        kill -9 $PID > /dev/null 2>&1
    else
        # Sinon on affiche le signal qui à réussi à tuer
        echo "Process ended with the signal : $signal"
    fi
    echo "------"
    # Attendre
    sleep 0
done
