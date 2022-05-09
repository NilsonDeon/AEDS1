#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int* aloca(int n, int preenche){
    int *p = NULL;

    if(preenche == TRUE){
        p = (int*) calloc(n , (sizeof(int))); // Criando vetor sem atribuir conteúdo
    }
    else if (preenche == FALSE)
    {
        p = (int*) malloc(n * (sizeof(int))); // Criando vetor com conteúdo 0
    }
    
    return p;
}

void imprime(int *v, int n){
    for (int i = 0; i < n; i++){
    
        printf("%i ", *(v+i)); // Imprimindo conteúdo na posição i
    }
    
}

int* Preenche(int *v, int n, int valor, int is_aleatorio){
    if (is_aleatorio == TRUE)
    {
        for (int i = 0; i < n; i++){
            int num = rand()%100; 
            *(v+i) = num; // Atribuindo número aleatório para a posição i
        }
      
    }
    else if (is_aleatorio == FALSE){
        for (int i = 0; i < n; i++)
        {
           *(v+i) = valor; // Atribuindo valor para a posição i
        }
        
    }

    return v;
    
}

void inverte(int *v, int n){
    int vet[n], cont = 0;

    for (int i = 0; i < n; i++)
    {
        vet[i] = *(v+i); // Copiando o vetor recebido para outro 
    }

    for (int i = n-1; i >= 0; i--)
    {
       *(v+cont) = vet[i]; // Invertendo vetor
       cont++;
    }
    
}

int main(){

    // f)
    int *v1, *v2; 

    // g)
    v1 = aloca(5, FALSE); 

    // h)
    v2 = aloca(2, TRUE); 

    // i)
    imprime(v1, 5);
    printf("\n");
    imprime(v2, 2);
    printf("\n");

    // j)
    printf("\n");
    v1 = Preenche(v1, 5, 0, TRUE);

    // k)
    imprime(v1, 5);
    printf("\n");

    // l)
    printf("\n");
    inverte(v1, 5);
    inverte(v2, 2);

    // m)
    imprime(v1, 5);
    printf("\n");
    imprime(v2, 2);
    printf("\n");

    return 0;
}
