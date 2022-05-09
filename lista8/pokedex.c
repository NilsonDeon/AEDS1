#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    int quant;
    char **meus_pokemons, nome[30];

    printf("Quantos pokemons voce possui? ");
    scanf("%d", &quant);

    meus_pokemons = (char **) malloc(quant * (sizeof(char *)));

    for (int i = 0; i < quant; i++)
    {
        printf("Digite o nome do Pokemon: ");
        scanf("%s", nome);

        int len = strlen(nome);

        meus_pokemons = (char *) malloc(len * (sizeof(char)));
        
    }
    

    return 0;
}
