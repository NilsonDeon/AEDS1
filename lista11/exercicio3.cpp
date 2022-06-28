#include <iostream>

using namespace std;

int main(){
    
    int n, num1 = 0, num2 = 1, prox;

    cout << "Quantos numeros? ";
    cin >> n;

    for (int i = 0; i < n; i++){ // Loop de 0 até n
        if (i == 0){ // se for o primeiro número da sequência, mostra num1
            cout << num1 << " ";
            continue;

        }else if (i == 1){ // se for o segundo número da sequência, mostra num2
            cout << num2 << " ";
            continue;

        }else{ // se não for os dois primeiro números, calcula fibonacci
            prox = num1 + num2;

            //atualizando valores
            num1 = num2;
            num2 = prox;
            // mostrando próximo número
            cout << prox << " ";
        }
    }
    

    return 0;
}
