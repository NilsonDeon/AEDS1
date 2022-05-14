#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    int quant, len;
    char **meus_pokemons = NULL, nome[30];

    printf("Quantos pokemons voce possui? ");
    scanf("%d", &quant);

    meus_pokemons = (char **) malloc(quant * (sizeof(char *)));

    for (int i = 0; i < quant; i++)
    {
        printf("Digite o nome do Pokemon: ");
        scanf("%s", nome);
        len = strlen(nome);
        meus_pokemons[i] = (char *) realloc(meus_pokemons, len * (sizeof(char)));

        for (int j = 0; j < len; j++){
            meus_pokemons[i][j] = nome[j];

            printf("%c", meus_pokemons[i][j]);
        } 
        printf("\n");
    }
    
    

    return 0;
}
