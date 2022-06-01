#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float verificaPasso(char passo[])
{
    float soma = 0;

    for (int i = 0; i <= strlen(passo); i++)
    {

        switch (passo[i])
        { // verifica qual a letra e soma o seu valor na variável
        case 'W':
            soma += 1;
            break;

        case 'H':
            soma += 0.5;
            break;

        case 'Q':
            soma += 0.25;
            break;

        case 'E':
            soma += 0.125;
            break;

        case 'S':
            soma += 0.625;
            break;

        case 'T':
            soma += 0.03125;
            break;

        case 'X':
            soma += 0.015625;
            break;
        }
    }

    if (soma != 1)
    {
        return 0; // Se a soma do paaso for diferente de 1 retorna 0
    }

    return 1;
}

int main(void)
{

    int soma = 0;
    char entrada[100];

    printf("Digite a partitura: ");
    scanf("%s", entrada);

    for (int i = 1; i < strlen(entrada); i++)
    {
        char passo[10];
        int cont = 0; // index do passo a ser inviado para a função

        if (entrada[i] == '/')
        {
            soma += verificaPasso(passo); // chama a funcção e soma o seu retorno na variável soma
        }
        else
        {
            passo[cont++] = entrada[i]; // adiciona as letras do passo a ser contado
        }
    }

    printf("%d\n", soma);

    return 0;
}