#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[9];
    char sobrenome[8];
    int mat;
    int notas[4];

}aluno;


int main(){   
    aluno alunos[5]; // criando vetor/struct de alunos
    int matnota, media;

    FILE *pfile = fopen("alunos.txt", "r"); // lendo alunos.txt
    if (pfile == NULL){ // verificando se o arquivo foi aberto
        printf("Erro ao abrir arquivo"); 
    }
    
    for (int i = 0; i < 5; i++){ // atribuindo os alunos ao vetor/struct alunos
        fscanf(pfile,"%s %s %i", &alunos[i].nome, &alunos[i].sobrenome, &alunos[i].mat);
    }
    fclose(pfile); // fechando arquivo

    pfile = fopen("notas.txt", "r"); // lendo alunos.txt
    if (pfile == NULL){ // verificando se o arquivo foi aberto
        printf("Erro ao abrir arquivo");
    }

    for (int i = 0; i < 5; i++){

        int j = 0;

        fscanf(pfile,"%i", &matnota);

        while (1){ // loop infinito
           if (matnota == alunos[j].mat){ // verificando se matriculas são iguais
                // recebendo notas
                fscanf(pfile,"%i %i %i %i", &alunos[j].notas[0], &alunos[j].notas[1], &alunos[j].notas[2], &alunos[j].notas[3]);
                break;
            } 
            j++;        
        }
        printf("%s %i %i %i %i %i\n", alunos[i].nome, alunos[i].mat, alunos[i].notas[0], alunos[i].notas[1],alunos[i].notas[2], alunos[i].notas[3]);
    }
    fclose(pfile); // fechando arquivo

    /* 
    Erro ao receber notas do:
    - Alberto
    - Bernado
    */

    pfile = fopen("medias.txt", "a"); // criando arquivo (func tipo append)
    if (pfile == NULL){ // verificando se o arquivo foi aberto
        printf("Erro ao abrir arquivo");
    }

    for (int i = 0; i < 5; i++)
    {
        media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3])/4; // calculando média

        fprintf(pfile,"%s %s %i\n", alunos[i].nome, alunos[i].sobrenome, media);// adicionando nome, sobrenome e media ao arquivo
    }
    fclose(pfile); // fechando arquivo
    



    return 0;
}
