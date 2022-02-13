
#include "Gestor.h"

Gestor::Gestor() {
}

Gestor::Gestor(const Gestor& orig) {
}

Gestor::~Gestor() {
}

int Gestor::VerificaTipo(string teste, int numero){
    vector<string> comValidos = {"planicie","montanha","fortaleza","mina","duna","castelo",
                                 "pescario","refugio dos piratas"};

    if(numero > 0 && numero < 10){
        for(int i=0;i<comValidos.size();i++){
                    if(teste == comValidos[i]){
                        return 1;
                    }
        }
    }
    return 0;
}

void Gestor::carrega (string ficheiro, Mundo *mundo){
    vector <string> resultT;
    string linha;
    
        ifstream ifs(ficheiro);
        if(ifs.is_open()){
        while(!ifs.eof()){
            resultT.clear();
            linha.clear();
            getline(ifs, linha);
            istringstream iss(linha); 
            for(string linha; iss >> linha;)     //separa o comando em palavras   
                resultT.push_back(linha);
        
        if(resultT[0] == "cria"){
            if(resultT.size() > 2){
               
        if(VerificaTipo(resultT[1],stoi(resultT[2])) == 1){
                cout <<"Estas a criar " << resultT[2] <<" territorios do tipo " <<resultT[1] << "\n"; 
            for(int j=0; j <stoi(resultT[2]) ; j++){
                mundo->adicionaTerritorio(Territorio(resultT[1]));
            }
        }else{
            cout <<"Tipo de territorio ("<< resultT[1] <<") nao existe ou numero a criar ("<< resultT[2] <<" )invalido\n";
        }
        }else{
            cout<< "Parametros do comando cria em falta\n";
        }
        }
    }  
    ifs.close();
    }else
        cout <<"Ficheiro ["<< ficheiro <<"] nao existe\n"; 

        return;
}

void Gestor::cria(vector <string> result, Mundo *mundo){
        if(result.size() > 2){
        
        if(VerificaTipo(result[1],stoi(result[2]))==1){
            cout <<"Estas a criar " << result[2] <<" territorios do tipo " <<result[1] << "\n"; 
            for(int j=0; j <stoi(result[2]) ; j++){
                mundo->adicionaTerritorio(Territorio(result[1]));
            }
        }else{
            cout <<"Tipo de territorio ("<< result[1] <<") nao existe ou numero a criar ("<< result[2] <<") invalido\n";
        }
        }else{
            cout<< "Parametros do comando cria em falta\n";
        }

}

void Gestor::visualiza(Mundo *mundo){
        cout <<"Mostrar tudo\n";
        for(int i=0; i< mundo->getTerritorioSize(); i++){
            cout << mundo->getTerritorio(i)->getasstring() <<"\n";
        }
};

void Gestor::lista(vector <string> result, Mundo *mundo, Jogo *player){
    int indice = -1;
        if(result.size() > 1){
            for(int i=0; i< mundo->getTerritorioSize(); i++){
            //teste=mundo->getTerritorio(i)->getN();
                if(mundo->getTerritorio(i)->getN()== result[1]){
                    indice=i;
                }
            }
           if(indice!=-1){
               cout << "-----Territorio encontrado----\n";
               cout << mundo->getTerritorio(indice)->getasstring();
           }else
               cout << "---Territorio nao encontrado!---\n";
        }else{
            cout << "---->A listar informações do imperio\n";
            cout << player->getasstring();
            cout << "---->Territorios do jogador:\n";
            player->print();
            cout << "---->Territorios por conquistar no mundo:\n";
            for(int i=0; i< mundo->getTerritorioSize(); i++){
                if(mundo->getTerritorio(i)->getC()==0)
                cout << mundo->getTerritorio(i)->getasstring() <<"\n";
            }
        }  
};

void Gestor::conquista(int *flagConquista, vector <string> result, Mundo *mundo, Jogo *player){
    int indice = -1;
     if(*flagConquista==0){
        if(result.size() < 2){
            cout<< "Comando incompleto\n";
        }else{    
        for(int i=0; i< mundo->getTerritorioSize(); i++){
            //teste=mundo->getTerritorio(i)->getN();
                if(mundo->getTerritorio(i)->getN()== result[1]){
                    indice=i;
                }
            }
           if(indice!=-1 && mundo->getTerritorio(indice)->getC()==0){
               cout << "-----Territorio encontrado----\n";
               player->addTerritorio(mundo->getTerritorio(indice));
               *flagConquista=1;
           }else{
               if(mundo->getTerritorio(indice)->getC()==1)
                   cout <<"Esse territorio ja te pertence!";
               else   
            cout << "---Territorio nao encontrado!---\n";
            }
        }
     }else
         cout << "Ja conquistaste um territorio neste turno!\n";


};

void Gestor::avanca(int *flagConquista, vector <string> result, Jogo *player){
    string buff;
    buff.clear();
        if(*flagConquista == 0){
            cout <<"Vais passar o turno sem conquistar\n Tens a certeza?[sim/nao]";
            //cin.clear();
            getline(cin,buff);
            if(buff == "sim"){
                player->avancaturno();
            }else
                cout<< "Inseriste ["<< buff << "]A continuar no mesmo turno\n";
        }else{
         player->avancaturno();
        }
        *flagConquista = 0;

};
