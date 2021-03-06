//
// Created by Axel LE BOT on 11/12/17.
//

#ifndef TP_CPP_PERSONNE_H
#define TP_CPP_PERSONNE_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Personne {
protected:
    string nom;
    int pointsVie;
    int pointsDefense;

public:
    Personne() = delete;

    Personne(string nom, int pointsVie, int pointsDefense);

    virtual ~Personne();

    virtual int attaque()=0; //pure specifier

    void recevoirCoup(int coup);

    bool estMorte();

    string getNom();

    int getPointsVie();

    int getPointsDefense();
};

#endif //TP_CPP_PERSONNE_H