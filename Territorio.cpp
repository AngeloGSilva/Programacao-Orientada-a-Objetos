
#include "Headers.h"
#include "Territorio.h"

int Territorio::counter = 0;

Territorio::Territorio(string Nome) {
    counter++;
    this->nome=Nome + to_string(counter);
    this->resistencia;
    this->criaproduto;
    this->criaouro;
    this->pontosvitoria;
    this->conquistado=0;
    //cout << "Construtor chamado\n";
}
Territorio::Territorio(string str,int a1,int a2, int a3, int a4){
    this->nome="Territorio Inicial";
    this->resistencia=a1;
    this->criaproduto=a2;
    this->criaouro=a3;
    this->pontosvitoria=a4;
    this->conquistado=1;
}
//Construtor por copia
//Territorio::Territorio(const Territorio& orig) {
//    this->nome=orig.nome;
//    this->criaouro=orig.criaouro;
//    this->criaproduto=orig.criaproduto;
//    this->pontosvitoria=orig.pontosvitoria;
//    this->resistencia=orig.resistencia;
//   // cout << "Construtor por copia\n";
//}

Territorio::~Territorio() {
   // cout << "Destrutor chamado\n";
}

string Territorio::getasstring(){
    ostringstream oss;
    oss << "\nNome:" << nome << "\n" << "resistencia:" << resistencia << "\n" << "Gera Ouro:" << criaouro << "\n" << "Gera Produtos" << criaproduto << "\n" << "Pontos de Vitoria" << pontosvitoria << "\nConquistado:"<< conquistado <<endl;
    return oss.str();
}