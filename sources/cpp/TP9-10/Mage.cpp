//
// Created by Axel LE BOT on 20/12/17.
//

#include "Mage.h"

Mage::Mage(string nom,
           int pointsVie,
           int pointsDefense,
           int magie,
           int forceMagique) : Personne(nom, pointsVie,
                                        pointsDefense){
    this->forceMagique = forceMagique;
}

int Mage::attaqueMagique(){
    if(this->magie > 0) this->magie--;
    return (this->magie > 0) ? rand() % this->forceMagique / 2 + this->forceMagique : 0;
}
