#!/bin/bash
# Axel LE BOT - 2017-10-02

echo "Liste des parametres entres : "

# On récupère le nombre de paramètres total
COUNT=$#

# Tant que shift décale
while shift
	# On affiche le paramètre
	echo $1
done

# Affichage du nombre de paramètre total
echo "Nombre de parametres : $COUNT"
