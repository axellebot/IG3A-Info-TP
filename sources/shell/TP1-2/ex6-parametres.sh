#!/bin/bash
# Axel LE BOT - 2017-10-02

echo "Liste des parametres entrés : "

# On utilie $* pour avoir tous les paramètres passés
for i in $*
do
	# On affiche le paramètre
	echo $i
done

# On utilise $# pour afficher le nombre de paramètres
echo "Nombre de parametres : $#"
