//
// Created by Axel LE BOT on 20/12/17.
//

#include "Personne.h"

using namespace std;

Personne::Personne(string nom, int pointsVie, int pointsDefense) {
    this->nom = nom;
    this->pointsVie = pointsVie;
    this->pointsDefense = pointsDefense;
}

Personne::~Personne() {
    cout << "Personne is being deleted\n";
}

void Personne::recevoirCoup(int coup) {
    if (coup > this->pointsDefense) {
        pointsVie -= (coup - pointsDefense);
    }
}

bool Personne::estMorte() {
    return (pointsVie <= 0);
}

string Personne::getNom() {
    return nom;
}

int Personne::getPointsVie() {
    return pointsVie;
}

int Personne::getPointsDefense() {
    return pointsDefense;
}

