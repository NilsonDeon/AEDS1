#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Pessoa{// criando classe

    private:
        // variaveis da classe
        string nome;
        int dia;
        int mes;

    public:

        // construtor
        Pessoa(string nome, int dia, int mes);
        
        // metodo
        void addFile(FILE *file, string nome);

        //assesor
        int getDia();
};

Pessoa::Pessoa(string nome, int dia, int mes){
    // atribuindo às variáveis
    this->nome = nome;
    this->dia = dia;
    this->mes = mes;
}

void Pessoa::addFile(FILE *file, string nome){
    file = fopen(nome.c_str(), "a+"); // abrindo aquivo

    int m;
    while(!feof(file)){ // loop infinito

        fscanf(file, "%i", &m);

        if( mes == this->mes ){ // verifica se meses são iguais
            fprintf(file, " %s", this->nome);
            break;   
        }
        
    } 

    fclose(file); // fechando arquivo
}

int Pessoa::getDia(){
    return dia; // retornando dia
}

int main(){
    
    string nome;

    // criando objetos
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

    // recebendo nome do aquivo
    cout << "Digite o nome do arquivo: ";
    cin >> nome;

    // criando arquivo
    FILE *file; 
    file = fopen(nome.c_str(), "a"); 

    // inserindo mêses
    for (int i = 1; i <= 12; i++){
        
        if(i == 12){
            fprintf(file, "Mes %i:", i);
        }else{
            fprintf(file, "Mes %i:\n", i);
        }
    } 
    
    //fechando arquivos
    fclose(file); 
    
    //adicionando ao arquivo
    obj1.addFile(file, nome);
    obj2.addFile(file, nome);
    obj3.addFile(file, nome);
    obj4.addFile(file, nome);
    obj5.addFile(file, nome);
    obj6.addFile(file, nome);
    obj7.addFile(file, nome);
    obj8.addFile(file, nome);
    obj9.addFile(file, nome);
    obj10.addFile(file, nome);

    return 0;
}
