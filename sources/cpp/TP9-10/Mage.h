//
// Created by Axel LE BOT on 20/12/17.
//

#ifndef TP_CPP_MAGE_H
#define TP_CPP_MAGE_H

#include "Personne.h"

using namespace std;

class Mage : public virtual Personne {
protected:
    int magie;
    int forceMagique;

public:
    Mage() = delete;

    Mage(string nom, int pointsVie, int pointsDefense, int magie, int forceMagique);

    ~Mage();

    int attaque();

};

#endif
