#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int* aloca(int n, int preenche){
    int *p = NULL;
    if(preenche == TRUE){
        p = (int*) calloc(n , (sizeof(int)));
    }
    else if (preenche == FALSE)
    {
        p = (int*) malloc(n * (sizeof(int)));
    }
    
    return p;
}

void imprime(int *v, int n){
    for (int i = 0; i < n; i++){
    
        printf("%i ", *(v+i));
    }
    
}

int* Preenche(int *v, int n, int valor, int is_aleatorio){
    if (is_aleatorio == TRUE)
    {
        for (int i = 0; i < n; i++)
        {
            int num = rand()%100;
            *(v+i) += num;
        }
      
    }
    else{
        for (int i = 0; i < n; i++)
        {
           *(v+i) += valor;
        }
        
    }

    return v;
    
}

void inverte(int *v, int n){
    int vet[n], cont = 0;

    for (int i = 0; i < n; i++)
    {
        vet[i] = *(v+i);
    }

    for (int i = n-1; i > 0; i--)
    {
       *(v+cont) = vet[i];
       cont++;
    }
    
}

int main(){
    int tamanho = 5, *r = NULL, valor = 0;
    
    r = aloca(tamanho, FALSE);
    r = Preenche(r, tamanho, valor, TRUE);
    imprime(r, tamanho);
    inverte(r, tamanho);
    printf("\n");
    imprime(r, tamanho);

    return 0;
}
