#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Eletro{

    private:

        string nome;
        int telefone;
        float preco;

    public:
        // contrutor
        Eletro(string nome, int telefone, float preco);

        // assesor
        void getPreco();
};

Eletro::Eletro(string nome, int telefone, float preco){
    // atribuindo valores
    this->nome = nome;
    this->telefone = telefone;
    this->preco = preco;
}

void Eletro::getPreco(){

    

}



int main(){

    string nome;
    int num;
    float preco;

    FILE *file = fopen("listaeletro.txt", "r");
    if (file == NULL){
        cout << "Deu ruim";
        return 1;
    }
    
    while(!feof(file)){
        fscanf(file, "%s %i %f", &nome, &num, &preco);
        cout << nome << " " << num << " " << preco << "\n";
    }
    
    fclose(file);
    return 0;
}
