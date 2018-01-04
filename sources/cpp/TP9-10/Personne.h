//
// Created by Axel LE BOT on 11/12/17.
//

#ifndef TP_CPP_PERSONNE_H
#define TP_CPP_PERSONNE_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Personne{
protected:
    string nom;
    int pointsVie;
    int pointsDefense;

public:
    Personne() = delete;

    Personne(string nom, int pointsVie, int pointsDefense);

    string getNom();

    int getPointsVie();

    int getPointsDefense();

    void recevoirCoup(int coup);
};

#endif