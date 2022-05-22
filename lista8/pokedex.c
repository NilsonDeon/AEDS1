#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ERRO -1

int encontra_nome(char **lista, char *nome, int quant){
  for(int i = 0; i < quant; i++){
    
    if(strcmp(lista[i], nome) == 0){ // verifica se são iguais
        
      return i;
    }

  }

  return ERRO; // se não são iguais retorna ERRO

}

char** lista_por_incial(char **lista, char letra, int quant){
  char **lista_retorno = NULL;
  int cont = 0; // contador para linha da matriz de pokemons com p

  for (int i = 0; i < quant; i++)
  {
    
    if (lista[i][0] == letra){
      
      lista_retorno = (char **) realloc(lista_retorno, sizeof(char *));
      lista_retorno[i] = (char *) malloc(strlen(lista[cont]) * sizeof(char));
      for (int j = 0; j < strlen(lista[i]); j++)
      {
        lista_retorno[cont][j] =lista[i][j];
      }
      cont++;
    }
    

  }
  
  return lista_retorno; // matriz com nome dos pokemons que tem a letra p

}

int main(){
  int quant, len;
  char **meus_pokemons = NULL, nome[30], **p;

  printf("Quantos pokemons voce possui? ");
  scanf("%d", &quant);

  meus_pokemons = (char **) malloc(quant * (sizeof(char *))); // atribui a quantidade de linhas

  for (int i = 0; i < quant; i++){

    printf("Digite o nome do Pokemon: ");
    scanf("%s", nome);
    len = strlen(nome); // tamanho da palavra

    meus_pokemons[i] = (char *) malloc(len * (sizeof(char)));// atribui a quantidade de colunas

    for (int j = 0; j < len; j++){
        meus_pokemons[i][j] =  toupper(nome[j]); // adiciona o nome em maiusculo para a matriz
    } 

  }

  char pokemon[7] = "TOGEPI";
  if (encontra_nome(meus_pokemons, pokemon, quant) != ERRO){ // verifica se o retorno não é ERRO
    printf("Possui o Togepi.\n");
  }
  else{
    printf("Nao possui o Togepi.\n");
  }
  
  int c = 0;
  p = lista_por_incial(meus_pokemons, 'P',quant); // recebe a posição onde está a lista de pokemons com a letra p
  for (int i = 0; i < sizeof(p); i++){
    printf("%s \n", p[i]); // imprime os pokemons, tem um bug
  }
  
  free(p); // libera o espaço de memoria
  free(meus_pokemons); // libera o espaço de memoria
  
  return 0;
}
