//
// Created by Axel LE BOT on 19/01/18.
//

#include "MageGuerrier.h"

MageGuerrier::MageGuerrier(string name, int pointsVie, int pointsDefense, int pointsAttaque, int magie,
                           int forceMagique) :
        Personne(name, pointsVie, pointsDefense),
        Mage(name, pointsVie, pointsDefense, magie, forceMagique),
        Guerrier(name, pointsVie, pointsDefense, pointsAttaque) {
}

MageGuerrier::~MageGuerrier() {
    cout << "MageGuerrier is being deleted\n";
}

int MageGuerrier::attaque() {
    srand(time(NULL));
    return rand() % 2 ? Mage::attaque() : Guerrier::attaque();;
}
