#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pessoa{// criando classe

    private:
        // variaveis da classe
        int codigo;
        string nome;
        int idade;
        string endereco;
        int numero;
        string complemento;

    public:

        // construtor
        Pessoa(int id, string name, int age, string address, int number, string complement){
            codigo = id;
            nome = name;
            idade = age;
            endereco = address;
            numero = number;
            complemento = complement;
        }
        
        // metodo
        void addFile(string nome){
            fstream file; 
            file.open(nome, ios::app); // criando arquivo 

            // adicionando conteúdo
            file << codigo;
            file << " ";
            file << this->nome;
            file << " ";
            file << idade;
            file << " ";
            file << endereco;
            file << " ";
            file << numero;
            file << " ";
            file << complemento;
            file << "\n";

            file.close(); // fechando arquivo
        }
};




int main(){
    string nome;

    // criando objetos
    Pessoa obj1(1, "sheeta", 35, "Japão", 0, "céu");
    Pessoa obj2(2,"seita", 34, "Cobe, Japão", 98, "abrigo abandonado");
    Pessoa obj3(3, "Totoro", 33, "Aichi, Japão", 0, "Floresta");
    
    //recebendo nome do aquivo
    cout << "Digite o nome do arquivo (mais o tipo de arquivo): ";
    cin >> nome;
    
    // chamando função que adiciona conteúdo no arquivo, para cada objeto
    obj1.addFile(nome);
    obj2.addFile(nome);
    obj3.addFile(nome);   

    
    return 0;
}
