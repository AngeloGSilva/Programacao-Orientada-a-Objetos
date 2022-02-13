#ifndef ILHA_H
#define ILHA_H
#include "Headers.h"
#include "Territorio.h"

#define REFUGIO 1 
#define PESCARIA 2 

class Ilha : public Territorio {

    int tipo;
public:    
    Ilha(string Nome, int tipo = REFUGIO);
    //Territorio(const Territorio& orig);
    ~Ilha();

    string getasstring();
    
};

#endif 

