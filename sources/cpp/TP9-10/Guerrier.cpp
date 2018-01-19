//
// Created by axel on 20/12/17.
//

#include "Guerrier.h"

Guerrier::Guerrier(string nom,
                   int pointsVie,
                   int pointsDefense,
                   int pointAttaque) : Personne(nom, pointsVie, pointsDefense) {
    this->pointsAttaque = pointAttaque;
}

Guerrier::~Guerrier() {
    cout << "Guerrier is being deleted\n";
}

int Guerrier::attaquePhysique() {
    srand(time(NULL));
    return rand() % this->pointsAttaque / 2 + this->pointsAttaque;
}

