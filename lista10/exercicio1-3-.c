#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct{
	int h;
	int m;
	int s;
} horario;

typedef struct{

	Data data;
	horario hora;
	char desc[100];

} compromisso;

void regComp(compromisso registro[], int cont){
	printf("Data do compromisso: ");
	scanf("%i %i %i",
		&registro[cont].data.dia,
		&registro[cont].data.mes,
		&registro[cont].data.ano
	); // atribui a data

	printf("horario do compromisso: ");
	scanf("%i %i %i",
		&registro[cont].hora.h,
		&registro[cont].hora.m,
		&registro[cont].hora.s
	); // atribui o horário

	printf("Descricao do compromisso: ");
	scanf("%s", registro[cont].desc); // atribui a descrição
}

void listTComp(compromisso registro[], int cont)
{
  for (int i = 0; i < cont; i++){ // printa todas os compromissos
		printf("\nCompromisso: %s\n", registro[i].desc);
		printf("Dia: %i/%i/%i\n",
		 registro[i].data.dia,
		 registro[i].data.mes,
		 registro[i].data.ano
		);

		printf("Horario: %i/%i/%i\n",
		 registro[i].hora.h,
		 registro[i].hora.m,
		 registro[i].hora.s
		);

		printf("\n");
	}
}

void listMes(compromisso registro[], int cont, int mes){

 for(int i = 0; i < cont; i++){
	 	if(registro[i].data.mes == mes){ // verifica compromissos com mesmo mes
				printf("\nCompromisso: %s\n", registro[i].desc);
			 
				printf("Dia: %i/%i/%i\n",
				 registro[i].data.dia,
				 registro[i].data.mes,
				 registro[i].data.ano
				);
			
				printf("Horario: %i/%i/%i\n",
				 registro[i].hora.h,
				 registro[i].hora.m,
				 registro[i].hora.s
				);
				printf("\n");
		}
	 
	}
   
}

void salvar(FILE *agenda, compromisso registro[], int cont){
	agenda = fopen("agenda.bin", "ab"); // cria arquivo
	if (agenda == NULL){
		printf("Erro ao criar o arquivo");
		exit(1);
	}
	
	for (int i = 0; i < cont; i++){ // adiciona ao arquivo
		fwrite(&registro[i].desc, sizeof(char), 1 ,agenda);
		fwrite(&registro[i].data.dia, sizeof(int), 1 ,agenda);
		fwrite(&registro[i].data.mes, sizeof(int), 1 ,agenda);
		fwrite(&registro[i].data.ano, sizeof(int), 1 ,agenda);
		fwrite(&registro[i].hora.h, sizeof(int), 1 ,agenda);
		fwrite(&registro[i].hora.m, sizeof(int), 1 ,agenda);
		fwrite(&registro[i].hora.s, sizeof(int), 1 ,agenda);
	}
    
    printf("\nArquivo salvo com sucesso\n");
	fclose(agenda); // fecha o arquivo
}

void carregar(FILE *agenda, compromisso registro[], int cont){
	int i = 0;
	cont = 0;
	agenda = fopen("agenda.bin", "rb"); // lê o arquivo
	if (agenda == NULL){ // verifica se abriu
		printf("Erro ao abrir o arquivo");
		exit(1);
	}
	
	while(!feof(agenda)){
		fread(&registro[i].desc, sizeof(char), 1 ,agenda);
		fread(&registro[i].data.dia, sizeof(int), 1 ,agenda);
		fread(&registro[i].data.mes, sizeof(int), 1 ,agenda);
		fread(&registro[i].data.ano, sizeof(int), 1 ,agenda);
		fread(&registro[i].hora.h, sizeof(int), 1 ,agenda);
		fread(&registro[i].hora.m, sizeof(int), 1 ,agenda);
		fread(&registro[i].hora.s, sizeof(int), 1 ,agenda);
		i++;
	}
	
	
	printf("\nArquivo carregado com sucesso\n");

	fclose(agenda); // fecha o arquivo
}

int main(){
	int resp, cont = 0, val;
	FILE *agenda;
	compromisso registro[5];

	while(1){ // verifica o que o usuário quer fazer
			
			printf("\n1 - Registrar compromisso\n");
			printf("2 - Listar todos os compromissos\n");
			printf("3 - Listar compromissos de um mês\n");
			printf("4 - Salvar agenda\n");
			printf("5 - Carregar agenda salva\n");
			printf("6 - sair\n");
			printf("Opcao desejada: ");
			scanf("%d", &resp);

			if (resp == 6){
				break;
			}
			else if (resp == 1){
				regComp(registro, cont++);
			}
			else if (resp == 2){
				listTComp(registro, cont);
			}
			else if (resp == 3){
				printf("Mes: ");
				scanf("%i", &val);
				listMes(registro, cont, val);
			}
			else if(resp == 4){
				salvar(agenda, registro, cont);
			}
			else if(resp == 5){
				carregar(agenda, registro, cont);
			}
			
	}
	return 0;
}