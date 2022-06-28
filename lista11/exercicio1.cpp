#include <iostream>
#include <chrono> // biblioteca para receber o ano atual

using namespace std;

int main(){
    
    int anoNascimento, idade;
    char aniversario;

    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t); // recenbendo ano

    cout << "Em que ano voce nasceu? ";
    cin >> anoNascimento; // recebendo ano de nascimento

    cout << "Ja fez aniversario esse ano? ";
    cin >> aniversario; // recebendo se já fez aniversário


    idade = (1900 + pTInfo->tm_year) - anoNascimento; // calculando idade
    
    if (aniversario == 's' || aniversario == 'S'){ // verificando se já fez aniversário
        cout << "Voce tem " << idade << " anos.\n";
    }else
    {
        idade--; // removendo 1 ano
        cout << "Voce tem " << idade << " anos.\n";
    }

    if (idade >= 18) // verificando se é maior de idade
    {
        cout << "Voce ja pode fazer sua carteira de habilitacao.\n";
    }else{
        cout << "Voce ainda nao pode fazer sua carteira de habilitacao.\n";
    }
    
    
    return 0;
}
