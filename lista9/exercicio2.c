#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum dias_da_semana
{
    dom,
    seg,
    ter,
    qua,
    qui,
    sex,
    sab
};

int main(void)
{
    int index;
    char dias[7][4] = {"dom", "seg", "ter", "qua", "qui", "sex", "sab"}, dia[4];

    char **mat = (char **)malloc(7 * sizeof(char *)); // linhas da matriz

    for (int i = 0; i < 7; i++)
    {

        mat[i] = (char *)malloc(3 * sizeof(char)); // colunas da matriz

        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = dias[i][j]; // adiciona dias da semana
        }
    }

    printf("Digite um dia da semana(as tres primeiras letras): ");
    gets(dia); // recebe dia da semana

    for (int i = 0; i < 7; i++)
    { // transforma o dia em int
        if (strcmp(dia, mat[i]) == 0)
        {
            index = i;
        }
    }

    switch (index)
    { // verificação
    case dom:
        printf("Final de semana.\n");
        break;

    case sab:
        printf("Final de semana.\n");
        break;

    default:
        printf("Dia de semana.\n");
        break;
    }

    return 0;
}