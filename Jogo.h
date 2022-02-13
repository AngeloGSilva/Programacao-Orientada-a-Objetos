#include "Headers.h"
#include "Territorio.h"


#ifndef JOGO_H
#define JOGO_H

class Jogo {
    vector <Territorio> jog;
    int armazem=0;
    int GProdutos=0;
    int cofre=0;
    int GOuro=0;
    int totalPontos=0;
    int forcaMilitar=0;
    static int counter;
public:
    Jogo();
    Jogo(const Jogo& orig);
    ~Jogo();
    void avancaturno();
    int fatorsorte();
    void setup();
    void print();
    void addTerritorio(Territorio* p);
    string getasstring();
};

#endif /* JOGO_H */

