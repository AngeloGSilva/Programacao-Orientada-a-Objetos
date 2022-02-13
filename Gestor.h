#include "Headers.h"
#include "Mundo.h"
#include "Jogo.h"
#include "Territorio.h"
#ifndef GESTOR_H
#define GESTOR_H

class Gestor {
public:
    Gestor();
    Gestor(const Gestor& orig);
    virtual ~Gestor();
    int VerificaTipo(string teste, int numero);
    void carrega (string ficheiro, Mundo *mundo);
    void cria(vector <string> result, Mundo *mundo);
    void visualiza(Mundo *mundo);
    void lista(vector <string> result, Mundo *mundo, Jogo *player);
    void conquista(int *flagConquista, vector <string> result, Mundo *mundo, Jogo *player);
    void avanca(int *flagConquista, vector <string> result, Jogo *player);
private:

};

#endif /* GESTOR_H */

