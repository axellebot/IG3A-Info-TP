//
// Created by Axel LE BOT on 20/12/17.
//


extern "C" {
void displayHeader(int level, char *string);
bool endOfProgram();
}

#include <vector>
#include "../libs/libs.h"
#include "Personne.h"
#include "Guerrier.h"
#include "Mage.h"
#include "MageGuerrier.h"

using namespace std;

void combat(Personne *p1, Personne *p2) {
    Personne *winner = NULL;
    bool finDuCombat = false;

    vector<Personne *> personneList;
    personneList.push_back(p1);
    personneList.push_back(p2);

    while (!finDuCombat) {
        p1->recevoirCoup(p2->attaque());
        p2->recevoirCoup(p1->attaque());

        for (Personne *p : personneList) {
            if (p->estMorte()) {
                finDuCombat = true;
                winner = p;
            }
        }
    }

    cout << winner->getNom() << " à gagner" << endl;
}

int main() {
    displayHeader(1, (char *) "TP 9-10");
    bool finished = false;

    Guerrier *g1 = new Guerrier("Guerrier 1", 50, 5, 15);
    Mage *m1 = new Mage("Mage 1", 100, 3, 30, 12);
    MageGuerrier *mg = new MageGuerrier("MageGuerrier 1", 100, 4, 20, 10, 25);

    while (!finished) {
        combat(m1, mg);
        finished = endOfProgram();
    }

    delete g1;
    delete m1;
    delete mg;

    printf("Bye !!!");
    exit(0);
}