#include "Headers.h"

#include "Mundo.h"
#include "Territorio.h"
#include "Jogo.h"
#include "Gestor.h"
using namespace std;

int main(int argc, char** argv) {
    
    Gestor* gestor = new Gestor(); //Class one estão as funções dos comandos respetivos
    srand(time(NULL)); //Gerador de numeros aleatorio 
    int flagConquista=0; //Usada para verificar se Jogador ja conquistou no turno atual
    string comando;
    Mundo* mundo = new Mundo();
    vector<string> result;   
    
    cout << "----Fase de setup----" <<endl;
    cout << "Comandos validos:\n";
    cout << "Cria - Cria um tipo de territorio;\n";
    cout << "Carrega - Carrega um ficheiro de texto;\n";
    cout << "Visualiza - Mostra todos os territorios;\n";
    cout << "Avanca - Avanca para o jogo.\n";    
     
    do{ 
    result.clear();  //Limpa Array de strings individuais
    comando.clear(); //Limpa Array getline
    cout <<"\nComando: "; //Obter o input do utilizador
    getline(cin, comando); //Obter o input do utilizador
    //separa o comando em palavras
    istringstream iss(comando); 
    for(string comando; iss >> comando;)   
        result.push_back(comando);
    
    if (result[0] == "carrega"){
        if(result.size() >1){
        gestor->carrega(result[1], mundo);
        }else{
            cout <<"Falta parametros\n"; 
        }
    
    }else if(result[0] == "cria"){
        gestor->cria(result, mundo);
       
        
    }else if (result[0] == "visualiza"){
        
        gestor->visualiza(mundo);
 
    }else if(result[0] == "avanca"){
        //Evitar o comando invalido ao avancar
    }else
        cout << "Comando ["<< result[0] <<"] invalido\n";
   
    }while(result[0]!="avanca");//Comando para avancar para a proxima fase                     
    
    
    
    //Cria Jogo
    Jogo* player = new Jogo();
    //Cria o territorio inicial
    player->setup();
    //LIMPAR O VETOR E A STRING PARA REUTILIZAR
    //Apos comando conquista
    cout << "-------------------------\n";
    cout << "Menu De Jogo:\n";
    cout << "-------------------------\n";  
    cout << "Conquistar Territorio;\n";
    cout << "Lista terreno especifico;\n";
    cout << "Conquista um territorio;\n";
    cout << "Lista Informacoes.\n";
    do{ 
    cout << "\nA espera de um comando:";
    result.clear();  //Array de strings individuais
    comando.clear(); //Array getline
    
    //separa o comando em strings individuais 
    getline(cin, comando);
    istringstream iss(comando); 
    for(string comando; iss >> comando;)       
        result.push_back(comando);
    
    if(result[0]=="lista"){
        
        gestor->lista (result, mundo, player);

    }else if(result[0] == "conquista"){  
        
        gestor->conquista(&flagConquista, result, mundo, player);

    }else if(result[0] == "avanca"){
        
        gestor->avanca(&flagConquista, result, player);

    }else if(result[0] == "Conquistados"){
        
        player->print();//Print do territorio inicial
        
    }else
         cout << "Comando ["<< result[0] <<"] invalido\n";
    //player->print();
    }while(result[0]!="sair");
    delete player;//Apaga player
    delete mundo;//Apaga mundo
    delete gestor;
    return 0;     
}