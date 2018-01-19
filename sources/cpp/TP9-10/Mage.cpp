//
// Created by Axel LE BOT on 20/12/17.
//

#include "Mage.h"

Mage::Mage(string nom,
           int pointsVie,
           int pointsDefense,
           int magie,
           int forceMagique) : Personne(nom,
                                        pointsVie,
                                        pointsDefense) {
    this->magie = magie;
    this->forceMagique = forceMagique;
}

Mage::~Mage() {
    cout << "Mage is being deleted\n";
}

int Mage::attaqueMagique() {
    srand(time(NULL));
    int attaque = 0;
    if (magie > 0) {
        attaque = rand() % forceMagique / 2 + forceMagique;
        magie--;
    }
    return attaque;
}

