//
// Created by Axel LE BOT on 19/01/18.
//

#ifndef TP_CPP_MAGE_GUERRIER_H
#define TP_CPP_MAGE_GUERRIER_H

#include <string>
#include <cstdlib>
#include <ctime>
#include "Mage.h"
#include "Guerrier.h"

using namespace std;

class MageGuerrier : public Mage, public Guerrier {
public:
    MageGuerrier(string name, int pointsVie, int pointsDefense, int pointsAttaque, int magie, int forceMagique);

    ~MageGuerrier();

    int attaque() override;
};

#endif
