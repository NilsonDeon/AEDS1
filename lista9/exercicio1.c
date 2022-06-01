#include <stdio.h>
#include <stdlib.h>

typedef struct eletro_
{

    char nome[30];
    float pot;
    float temp;

    float consumoInd;
} eletro;

int main()
{
    int quant;
    float consumoTot;
    eletro *maquinas;

    printf("Quantos eletrodomesticos? ");
    scanf("%i", &quant);

    maquinas = (eletro *)malloc(quant * sizeof(eletro)); // aloca quantidade de eletrodomesticos

    for (int i = 0; i < quant; i++)
    {
        printf("Nome: ");
        scanf("%s", maquinas[i].nome);

        printf("Potencia: ");
        scanf("%f", &maquinas[i].pot);

        printf("Tempo de uso por dia (em horas): ");
        scanf("%f", &maquinas[i].temp);

        printf("\n");
    }

    for (int i = 0; i < quant; i++)
    {
        consumoTot += (maquinas[i].pot * maquinas[i].temp); // calcula consumo total
    }

    for (int i = 0; i < quant; i++)
    {

        maquinas[i].consumoInd = (((maquinas[i].pot * maquinas[i].temp) * 100) / consumoTot); // calcula o consumo de cada máquina em porcentagem

        printf("Nome: %s\n", maquinas[i].nome);
        printf("Potencia: %.2f\n", maquinas[i].pot);
        printf("Tempo: %.2f\n", maquinas[i].temp);
        printf("Consumo em relacao ao total: %.2f\n", maquinas[i].consumoInd);
        printf("-------------------------------------\n");
    }

    printf("Consumo total: %.2f kWh", consumoTot);

    return 0;
}
