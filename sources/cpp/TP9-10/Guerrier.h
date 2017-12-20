//
// Created by axel on 20/12/17.
//

#ifndef TP_CPP_GUERRIER_H
#define TP_CPP_GUERRIER_H

#include "Personne.h"

class Guerrier : public Personne{
protected:
    int pointsAttaque;
public :
    Guerrier() = delete;

    Guerrier(string nom, int pointsVie, int pointsDefense, int pointAttaque);

    int attaquePhysique();
};


#endif //TP_CPP_GUERRIER_H
