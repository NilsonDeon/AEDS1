#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_linhas(FILE *pfile){

    char cha;
    int num = 1;

    while (!feof(pfile)) {
        cha = fgetc(pfile);

        if (cha == '\n'){
            num++;
        }
    }
    return num;
}

int maior_linha(FILE *pfile, int quant){

    char frase[100];
    int maior = 0, len = 0, maiorLen = 0;
    
    for (int i = 0; i < quant; i++){
        
        fgets(frase, 100, pfile);
        len = strlen(frase);

        if (len > maiorLen){
            maiorLen = len;
            maior = i;
        }
        
    }

    return maior;
}

int menor_linha(FILE *pfile, int quant){

    char frase[100];
    int menor = 0, len = 0, menorLen = 100;
    
    for (int i = 0; i < quant; i++){
        
        fgets(frase, 100, pfile);
        len = strlen(frase);

        if (len < menorLen){
            menorLen = len;
            menor = i;
        }
        
    }

    return menor;
}

int conta_vogais(){
    
}

int main(){   

    int quant = 0, maior = 0, menor = 0, vogais = 0;
    char caminho[100];
    FILE *pfile;

    printf("Caminho do arquivo: ");
    scanf("%s", caminho);

    pfile = fopen(caminho, "r");
    if(pfile == NULL) {
        printf("Erro");
        return 1;
    }

    quant = conta_linhas(pfile);
    maior = maior_linha(pfile, quant);
    menor = menor_linha(pfile, quant);

    printf("%d\n", quant);
    printf("%d\n", maior);
    printf("%d\n", menor);

    return 0;
}
