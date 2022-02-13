#ifndef CONTINENTE_H
#define CONTINENTE_H
#include "Headers.h"
#include "Territorio.h"

#define PLANICE 1
#define MONTANHA 2
#define FORTALEZA 3
#define MINA 4
#define DUNA 5
#define CASTELO 6

class Continente: public Territorio {
protected:
    int tipo;
public:
    Continente(string Nome, int tipo = PLANICE);
    //Territorio(const Territorio& orig);
    ~Continente();

    string getasstring();
    
};

#endif 

