
#include "Headers.h"
#include "Ilha.h"


Ilha::Ilha(string nome, int tipo) : Territorio(nome) {
    this->nome = nome;
    this->tipo = tipo;
    switch (this->tipo)
    {
    case REFUGIO:
        this->resistencia = 9;
        break;
    case PESCARIA:
        this->resistencia = 9;
        break;
    default:
        break;
    }
}

Ilha::~Ilha() {
    // cout << "Destrutor chamado\n";
}

string Ilha::getasstring() {
    ostringstream oss;
    oss << "\nNome:" << nome << "\n" << "resistencia:" << resistencia << "\n" << "Gera Ouro:" << criaouro << "\n" << "Gera Produtos" << criaproduto << "\n" << "Pontos de Vitoria" << pontosvitoria << "\nConquistado: " << conquistado << "\nTipo: " << this->tipo << endl;
    return oss.str();
}