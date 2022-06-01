#include <stdio.h>
#include <stdlib.h>]
#include <string.h>

typedef struct carro_
{ /* criação da struct */
    char modelo[25];
    int consumo;

} carro;

int main()
{
    int quant, maior = -1;
    char nome[15];

    printf("Quantos carros? ");
    scanf("%d", &quant);

    carro *p = (carro *)malloc(quant * sizeof(carro)); /* alocando memória com aquantidade de carros recebido */

    for (int i = 0; i < quant; i++)
    { /* Recebendo modelo e consumo */
        printf("Modelo do carro: ");
        scanf("%s", p[i].modelo);

        printf("Consumo do carro: ");
        scanf("%d", &p[i].consumo);

        printf("\n");
        if (p[i].consumo > maior)
        { /* Veridicando qual é mais econômico */
            maior = p[i].consumo;
            strcpy(nome, p[i].modelo);
        }
    }

    printf("%s\n", nome); /* Carro mais econômico */

    return 0;
}