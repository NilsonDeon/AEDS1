#include <iostream>

using namespace std;

class MaiorMenor{
    public: 
        MaiorMenor(int *ptr1, int *ptr2, int x, int y){
            
            // verificando qual é maior e adicionando no seu respectivo ponteiro;
            if (x > y){ 
                *ptr1 = x;
                *ptr2 = y;
            }else{
                *ptr1 = y;
                *ptr2 = x;
            }
        }
};



int main(){

    // criando ponteiros e alocando memória
    int *maior = new int; 
    int *menor = new int;

    int n1, n2; // variáveis de controle

    cout << "Digite um numero: ";
    cin >> n1;
    cout << "Digite outro numero: ";
    cin >> n2;

    MaiorMenor(maior, menor, n1, n2); // chamando funcção
    
    //mostrando resultados
    cout << "Maior numero: " << *maior << "\n";
    cout << "Menor numero: " << *menor << "\n";

    // liberando memória dos ponteiros
    delete maior;
    delete menor;
    return 0;
}
