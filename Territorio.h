#ifndef TERRITORIO_H
#define TERRITORIO_H
#include "Headers.h"

class Territorio {
protected:
    static int counter;
    string nome;
    int resistencia=5;
    int criaproduto=1;
    int criaouro=1;
    int pontosvitoria=2;
    int conquistado=0; //0 de nao estáconquistado, 1 se está conquistado
public:
    Territorio(string Nome);
    Territorio(string str,int a1,int a2, int a3, int a4);
    //Territorio(const Territorio& orig);
    ~Territorio();
    string getasstring();
    int getresistencia()const{ return this->resistencia;};
    int getGproduto()const{ return this->criaproduto;};
    int getGouro()const{ return this->criaouro;};
    int getpontos()const{ return this->pontosvitoria;};
    int getC(){return this->conquistado;};
    void setC(int p){this->conquistado=p;};
    string getN(){return this->nome;};
};

#endif 

