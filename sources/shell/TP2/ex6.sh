# !/bin/bash
# Axel LE BOT - 2017-10-02
clear
echo "Arguments"
printf "Liste des paramètres d'entrés : "
COUNT=0
for i in $@
do
    ((COUNT++))
    printf "$i "
done

printf "\nNombre d'arguments : $COUNT"