#!/bin/bash
# Axel LE BOT - 2017-10-02
echo "Ex6 - paramètres"
echo -n "-Liste des parametres entres : "
COUNT=0

for i in $*
do
	echo -n "$i "
	(( COUNT++ ))
done

echo -e "\n-Nombre de parametres : $COUNT"
