#include <iostream>


using namespace std;

int main(){
    
    int n, val, neg = 0, pos = 0, neu = 0;

    cout << "Quantos numeros? ";
    cin >> n;

    for (int i = 0; i < n; i++){ // loop de 0 até n
        cout << "Digite um numero: ";
        cin >> val;
        if (val > 0){ // verificando se é positivo
            pos++;
        }else if (val < 0){ // verificando se é negativo
            neg++;
        }else{
            neu++;
        }
    }
    
    // mostrando resultados
    cout << "Numeros positivos: " << pos << "\n";
    cout << "Zeros: " << neu << "\n";
    cout << "Numeros negativos: " << neg << "\n";

    return 0;
}
