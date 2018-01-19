#!/bin/bash
# Axel LE BOT - 2017-10-01

# Récupération du nom de l'utilisateur
USER=$(whoami)

# On utilise la commande echo pour communiquer avec l'utilisateur
echo "Hello $USER !"
echo "Do you like fishsticks? (y/n)"

# On utilise la commande read pour récupère la réponse de l'utilisateur
read answer

# On vérifie si l'utilisateur a répondu oui
if [ "$answer" = "y" ]
then
	# Si il a répondu oui, on affiche le message suivant
	echo "Then, you are a gayfish!"
fi
