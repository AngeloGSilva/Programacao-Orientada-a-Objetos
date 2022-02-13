
#include "Jogo.h"

Jogo::Jogo() {
}

Jogo::Jogo(const Jogo& orig) {
}

Jogo::~Jogo() {
}

int Jogo::fatorsorte(){
    int prob = rand() % 6 + 1;
    return prob;
}

int Jogo::counter = 0;

void Jogo::setup(){
    Territorio inicial("Territorio inicial",9,1,1,0);
    this->jog.push_back(inicial);
    this->armazem=0;
    this->GProdutos=inicial.getGproduto();
    this->cofre=0;
    this->GOuro=inicial.getGouro();
    this->totalPontos=0;
    this->forcaMilitar=3;
}

void Jogo::print(){
    for(int i=0;i<this->jog.size();i++)
        cout << this->jog[i].getasstring();
}

void Jogo::addTerritorio(Territorio* p){
    if(this->forcaMilitar + fatorsorte() > p->getresistencia()){
    p->setC(1);
    this->jog.push_back(*p);
    this->GOuro+=p->getGouro();
    this->GProdutos+=p->getGproduto();
    this->totalPontos+=p->getpontos();
    cout << "Territorio Conquistado\n";
    }else{
        cout << "Conquista Falhada! Forca Militar + Fator de sorte foi inferior a resistencia do terreno!\n";
        if(this->forcaMilitar > 0){    
            cout << "Forca Militar perdeu 1 valor!\n";
            this->forcaMilitar--;
        }
    }
}

void Jogo::avancaturno(){
    cofre+=GOuro;
    armazem+=GProdutos;
    counter++;
    if(cofre>3)
        cofre=3;
    if(armazem>3)
        armazem=3;
    cout <<"Avancaste um turno\n";
         cout <<"A gerar recursos......\n";
         cout <<"A gerar tempo ......\n";
         cout <<"Concluido!\n";
}

string Jogo::getasstring(){
    ostringstream oss;
    oss <<"Estatisticas do Imperio:\n" << "Ouro Armazenado:"<< cofre << "\nProdutos Armazenados:"<< armazem << "\nGeracao de produtos:" << GProdutos << "\nGeracao de ouro:"<< GOuro << "\nTotal de pontos:" << totalPontos << "\nForca Militar:" << forcaMilitar <<"\nTurno:" << counter <<endl;
    return oss.str();
}