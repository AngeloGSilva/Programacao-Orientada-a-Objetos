#include "Headers.h"
#include "Continente.h"

Continente::Continente(string Nome, int tipo) : Territorio(Nome) {
    this->nome = Nome;
    this->tipo = tipo;
    

    switch (this->tipo)
    {
        case PLANICE:
            this->resistencia = 5;
            break;
        case MONTANHA:
            this->resistencia = 6;
            break;
        case FORTALEZA:
            this->resistencia = 8;
            break;
        case MINA:
            this->resistencia = 5;
            break;
        case DUNA:
            this->resistencia = 4;
            break;
        case CASTELO:
            this->resistencia = 7;
            break;
        default:
            break;
    }


}

Continente::~Continente() {
    // cout << "Destrutor chamado\n";
}
string Continente::getasstring() {
    ostringstream oss;
    oss << "\nNome:" << nome << "\n" << "resistencia:" << resistencia << "\n" << "Gera Ouro:" << criaouro << "\n" << "Gera Produtos" << criaproduto << "\n" << "Pontos de Vitoria" << pontosvitoria << "\nConquistado: " << conquistado << "\nTipo: " << this->tipo << endl;
    return oss.str();
}