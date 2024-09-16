#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "header.h"
#include "disc.h"
#include "alunos.h"

int main()
{
    setlocale (LC_ALL, "");
    char senha[8], usuario[6], disc[10][50], nomeAluno [50][50], alunosDisciplina [10][50][50];
    char resp2;
    int resp1, resp3, resp4=1, numDisc=1, numAlunos=1, discExistente=0;
    int numeroMatricula[50], numAlunosDisc[50];
    float nota1[50][50], nota2[50][50], media[50][50];

    //HEADER
    headerzin();

    //LOGIN
    login(usuario, senha);

    //VERIFICA SE O LOGIN EST� CORRETO
    if(strcmp(usuario, "obruxo") != 0 && strcmp (senha, "obruxo10") !=0) {
        printf("Acesso negado!\n");
    } else {

        //MENU
        do {
            menu();
            scanf("%d", &resp1);
            switch (resp1){
                case 1:
                    //CADASTRAR DISCIPLINAS
                    do {
                        system ("cls");
                        cadastroDisciplinas();
                        printf("Digite o nome da disciplina: ");
                        scanf("%s", disc[numDisc]);

                        //VERIFICA SE A DISCIPLINA J� FOI CADASTRADA
                        discExistente=vrfcDiscp (numDisc, disc);
                        if (discExistente==1) {
                            printf("Essa disciplina já foi cadastrada!");
                        }else {
                            printf("A disciplina %s foi cadastrada com sucesso!\n", disc[numDisc]);
                            numDisc++;
                        }
                        //PERGUNTA SE QUER CONTINUAR CADASTRANDO
                        printf("\nDeseja cadastrar outra disciplina? [S/N]\n");
                        scanf (" %c", &resp2);

                    } while (resp2 == 's' || resp2 == 'S');

                    //EXIBE AS DISCIPLINAS CADASTRADAS
                    printf ("\nAs disciplinas cadastradas foram: \n");
                    listaDisc(numDisc, disc);
                    printf("\n\n");
                    system ("pause");
                    break;
                    //FIM DO CASE 1


                case 2:
                    //EXIBIR DISCIPLINAS CADASTRADAS
                    system ("cls");
                    disciplinas();
                    printf("\n\n");
                    listaDisc(numDisc, disc);
                    printf("\n\n");
                    system ("pause");
                    break;
                    //FIM DO CASE 2

                case 3:
                //MATRICULAR ALUNO NA DISCIPLINA
                do {
                    system ("cls");
                    matriculaAlunos ();

                    //ESCOLHE A DISCIPLINA QUE QUER MATRICULAR O ALUNO
                    printf ("Em qual disciplina deseja matricular o aluno(a)?\n");
                    listaDisc(numDisc, disc);
                    scanf ("%d", &resp3);

                    //RECEBE O NOME E N� DE MATR�CULA DO ALUNO
                    printf("Digite o nome do aluno(a): ");
                    scanf("%s", nomeAluno[numAlunos]);
                    printf("Matrícula do aluno(a): ");
                    scanf("%d", &numeroMatricula[numAlunosDisc[resp3]]);

                    //MATRICULA O ALUNO
                    strcpy(alunosDisciplina[resp3][numAlunosDisc[resp3]], nomeAluno[numAlunos]);
                    printf("\nO aluno(a) %s (%d) foi matriculado(a) na disciplina %s com sucesso!\n", nomeAluno[numAlunos], numeroMatricula[numAlunosDisc[resp3]], disc[resp3]);
                    printf("\n\n");
                    numAlunosDisc[resp3]++;
                    numAlunos++;
                    system ("pause");

                    //PERGUNTA SE QUER MATRICULAR OUTRO
                    printf("\nDeseja matricular outro aluno? [S/N]\n");
                    scanf (" %c", &resp2);

                }while (resp2 == 's' || resp2 == 'S');
                break;
                //FIM DO CASE 3

                case 4:

                    //EXIBE ALUNOS MATRICULADOS NA DISCIPLINA
                    system ("cls");
                    alunosMatriculados();

                    //SELECIONA A DISCIPLINA
                    printf("Você deseja ver alunos de qual disciplina?");
                    printf("\n\n");
                    listaDisc(numDisc, disc);
                    scanf ("%d", &resp3);
                    system ("cls");
                    printf("\n");

                    //VERIFICA SE H� ALUNO NA TURMA SELECIONADA
                    if (numAlunosDisc[resp3]==0) {
                        printf("Nenhum aluno foi matriculado nessa disciplina.\n");
                        printf("\n");
                    } else {
                        //EXIBE OS ALUNOS MATRICULADOS COM SEUS RESPECTIVOS N� DE MATRICULA
                        printf ("Alunos matriculados na disciplina %s: ", disc[resp3]);
                        listaAlunos(numAlunosDisc, resp3, alunosDisciplina, numeroMatricula);
                        printf("\n\n");
                    }
                    system ("pause");
                    break;
                    //FIM DO CASE 4

                case 5:

                    //ATRIBUIR NOTAS PRO ALUNO NA DISCIPLINA
                    system ("cls");
                    notasAlunos ();

                    //SELECIONAR A DISCIPLINA
                    printf("Em que disciplina está cadastrado o aluno?");
                    printf("\n\n");
                    listaDisc(numDisc, disc);
                    scanf ("%d", &resp3);

                    //VERIFICA SE H� ALUNOS NAQUELA DISCIPLINA
                    if (numAlunosDisc[resp3]==0){
                        printf("Nenhum aluno foi cadastrado nesta disciplina!");
                        printf("\n\n");
                    } else {

                        //ESCOLHE O ALUNO
                        printf("Deseja atribuir nota para qual aluno?(Escolha pelo número de matrícula)\n");
                        printf("\n");
                        listaAlunos(numAlunosDisc, resp3, alunosDisciplina, numeroMatricula);
                        scanf("%d", &resp4);

                        //MENU DE ATRIBUI��O DE NOTA
                        system ("cls");
                        centralAluno (alunosDisciplina, resp3, resp4);
                        media[resp4][resp3] = atribuirNotas(nota1, nota2, resp3, resp4, media, alunosDisciplina);
                    }
                    system ("pause");
                    break;
                    //FIM DO CASE 5

                case 6:
                    //CONSULTAR NOTAS DOS ALUNOS
                    system ("cls");
                    consultaNotas();
                    //ESCOLHE A DISCIPLINA
                    printf("Selecione a disciplina do aluno: \n");
                    listaDisc (numDisc, disc);
                    scanf("%d", &resp3);
                    //VERIFICA SE H� ALUNOS NESTA DISCIPLINA
                    if (numAlunosDisc[resp3]==0) {
                        printf("Não há alunos cadastrados nesta disciplina!\n");
                    } else {
                        //ESCOLHE O ALUNO
                        printf("Selecione o aluno pelo seu número de matrícula: \n");
                        listaAlunos(numAlunosDisc, resp3, alunosDisciplina, numeroMatricula);
                        scanf("%d", &resp4);
                        system ("cls");
                        //EXIBE AS NOTAS
                        centralAluno (alunosDisciplina, resp3, resp4);
                        asNotas(nota1,resp3, resp4, nota2, media);
                    }
                    system ("pause");
                    break;
                    //FIM DO CASE 6


                case 7:
                //SAIR DO PROGRAMA
                system ("cls");
                printf("\nObrigado por utilizar o programa :)\n");
                resp4=0;
                break;
                //FIM DO CASE 7

                default:
                    printf("Opção inválida!");
                    printf("\n\n");
                    system ("pause");
                    break;
                }
            } while (resp1 != 7);
            //FIM DO PROGRAMA
        }
    return 0;
}
