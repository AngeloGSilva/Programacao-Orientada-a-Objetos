

#ifndef MUNDO_H
#define MUNDO_H
#include "Headers.h"
#include "Territorio.h"
class Mundo {
    vector <Territorio> t;
    //vector <Territorio> i;
public:
    Mundo();
    //Mundo(const Mundo& orig);
    ~Mundo();
    
    void Lista();
    void adicionaTerritorio(Territorio p);
    int getTerritorioSize();
    Territorio* getTerritorio(int i);
};

#endif /* MUNDO_H */

