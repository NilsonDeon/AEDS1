#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Pessoa{// criando classe

    private:
        // variaveis da classe
        string nome;
        int dia;
        int mes;

    public:

        // construtor
        Pessoa(string nome, int dia, int mes){
            this->nome = nome;
            this->dia = dia;
            this->mes = mes;
        }
        
        // metodo
        void addFile(string nome){
            // criando arquivo 
            fstream file; 
            file.open(nome, ios::app); 

            // adicionando conteúdo
            file << this->nome;
            file << " ";
            file << dia;
            file << " "; 
            file << mes;
            file << "\n";

            file.close(); // fechando arquivo
        }

        //assesor
        int getDia(){
            return dia; // retornando dia
        }
};




int main(){
    
    string nome;

    Pessoa obj1("Totoro", 16, 4);
    Pessoa obj2("Takuma", 3, 8);
    Pessoa obj3("Seita", 16, 4);
    Pessoa obj4("Kiki", 29, 7);
    Pessoa obj5("Taeko", 20, 7);
    Pessoa obj6("Toshio", 10, 7);
    Pessoa obj7("Claudio", 5, 2);
    Pessoa obj8("Mauricio", 22, 11);
    Pessoa obj9("Marta", 31, 10);
    Pessoa obj10("Maria", 1, 12);

    //recebendo nome do aquivo
    cout << "Digite o nome do arquivo (mais o tipo de arquivo): ";
    cin >> nome;
     

    
    return 0;
}
