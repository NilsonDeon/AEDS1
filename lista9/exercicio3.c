#include <stdio.h>
#include <stdlib.h>

typedef struct data_
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct horario_
{
    int h;
    int m;
    int s;
} horario;

typedef struct compromisso_
{

    Data data;
    horario hora;
    char desc[100];

} compromisso;

void regComp(compromisso registro[], int cont)
{
    printf("Data do compromico: ");
    scanf("%i %i %i",
          &registro[cont].data.dia,
          &registro[cont].data.mes,
          &registro[cont].data.ano); // atribui a data

    printf("horario do compromico: ");
    scanf("%i %i %i",
          &registro[cont].hora.h,
          &registro[cont].hora.m,
          &registro[cont].hora.s); // atribui o horário

    printf("Descricao do compromico: ");
    scanf("%s", registro[cont].desc); // atribui a descrição
}

void listTComp(compromisso registro[], int cont)
{
    for (int i = 0; i <= cont; i++)
    { // printa todas os compromissos
        printf("\nDia: %i/%i/%i\n",
               registro[cont].data.dia,
               registro[cont].data.mes,
               registro[cont].data.ano);

        printf("Horario: %i/%i/%i\n",
               registro[cont].hora.h,
               registro[cont].hora.m,
               registro[cont].hora.s);

        printf("Compromico: %s", registro[cont].desc);

        printf("\n");
    }
}

void listMes(compromisso registro[], int cont, int val)
{
   
}

int main(void)
{
    int resp, cont = 0, val;
    compromisso registro[5];

    while (1)
    { // verifica o que o usuário quer fazer
        printf("\n0 - sair\n");
        printf("1 - Registrar compromisso\n");
        printf("2 - Listar todos os compromissos\n");
        printf("3 - Listar compromissos de um mês\n");
        printf("Opcao desejada: ");
        scanf("%d", &resp);

        if (resp == 0)
        {
            break;
        }
        else if (resp == 1)
        {
            regComp(registro, cont++);
        }
        else if (resp == 2)
        {
            listTComp(registro, cont);
        }
        else if (resp == 3)
        {
            printf("Mes: ");
            scanf("%i", &val);
            listMes(registro, cont, val);
        }
    }
    return 0;
}