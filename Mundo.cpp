#include "Headers.h"
#include "Mundo.h"
Mundo::Mundo() {
}

//Mundo::Mundo(const Mundo& orig) {
//}

Mundo::~Mundo() {
}

void Mundo::adicionaTerritorio(Territorio p){
    this->t.push_back(p);
};

int Mundo::getTerritorioSize(){
    return t.size();
}

Territorio* Mundo::getTerritorio(int i){
    return &this->t[i];
};