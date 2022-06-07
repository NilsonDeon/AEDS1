#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int conta_linhas(FILE *pfile){

	char cha;
	int num = 1;

	while (!feof(pfile)){ // loop até o final do arquivo que conta o num de linhas
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

	for (int i = 0; i < quant; i++){ // loop até quantidade de linhas que verifica maior linha

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

	for (int i = 0; i < quant; i++){ // loop até quantidade de linhas que verifica menor linha

		fgets(frase, 100, pfile);
		len = strlen(frase);

		if (len < menorLen){
			menorLen = len;
			menor = i;
		}
	}

	return menor;
}

void conta_vogais(FILE *pfile, int quant, int* vogais){

	for (int i = 0; !feof(pfile); i++){ // loop até o final do arquivo que conta as vogais

		switch(toupper(fgetc(pfile))){
			case 'A':
				vogais[0] += 1;
				break;
			case 'E':
				vogais[1] += 1;
				break;
			case 'I':
				vogais[2] += 1;
				break;
			case 'O':
				vogais[3] += 1;
				break;
			case 'U':
				vogais[4] += 1;
				break;
		}
	}

} 

int main(){

	int quant = 0, maior = 0, menor = 0; 
	int *vogais = (int*) calloc(5, sizeof(int)); // [0] = a, [1] = e, [2] = i, [3] = o, [4] = u
	char caminho[100];
	FILE *pfile; 

	printf("Caminho do arquivo: ");
	scanf("%s", caminho);

	pfile = fopen(caminho, "r"); // criando arquivo
	if (pfile == NULL){
			printf("Erro\n");
			return 1;
	}

	quant = conta_linhas(pfile);
	rewind(pfile);
	maior = maior_linha(pfile, quant);
	rewind(pfile);
	menor = menor_linha(pfile, quant);
	rewind(pfile);
	conta_vogais(pfile, quant, vogais);
	
	printf("%d\n", quant);
	printf("%d\n", maior);
	printf("%d\n", menor);
	printf("a: %d | e: %d | i: %d | o: %d | u: %d", vogais[0], vogais[1], vogais[2], vogais[3], vogais[4]);

	free(vogais);
	return 0;
}
