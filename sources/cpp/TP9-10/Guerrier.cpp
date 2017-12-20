//
// Created by axel on 20/12/17.
//

#include "Guerrier.h"

Guerrier::Guerrier(string nom,
                   int pointsVie,
                   int pointsDefense,
                   int pointAttaque) : Personne(nom, pointsVie,
                                                                                              pointsDefense){
    this->pointsAttaque = pointAttaque;
}

int Guerrier::attaquePhysique(){
    return rand() % this->pointsAttaque / 2 + this->pointsAttaque;
}
