#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void headerzin () {
    setlocale (LC_ALL, "");
    printf("=================================\n");
    printf("ESCOLA RONALDINHO GAÚCHO O BRUXO \n");
    printf("=================================\n");
}
void login (char user[6], char pass[8]){
    printf("\nInsira seu usuário: ");
    scanf("%s", user);
    printf("Insira sua senha: ");
    scanf("%s", pass);
}
void menu (){
    system ("cls");
    setlocale (LC_ALL, "");
    printf("===========");
    printf("     MENU    ");
    printf(" =============");
    printf("\nSelecione \n");
    printf("[1] Cadastrar disciplinas \n");
    printf("[2] Exibir disciplinas \n");
    printf("[3] Matricular alunos \n");
    printf("[4] Exibir alunos matriculados \n");
    printf("[5] Atribuir notas \n");
    printf("[6] Consultar notas \n");
    printf("[7] Sair \n");
    printf("======================================\n");
}
void cadastroDisciplinas (){
    setlocale (LC_ALL, "");
    printf("================================\n");
    printf("     CADASTRO DE DISCIPLINAS    \n");
    printf("================================\n");
}
void disciplinas () {
    setlocale (LC_ALL, "");
    printf("=========================\n");
    printf("        DISCIPLINAS      \n");
    printf("=========================\n");
}
void matriculaAlunos () {
    setlocale (LC_ALL, "");
    printf("=========================\n");
    printf("   MATRÍCULA DE ALUNOS   \n");
    printf("=========================\n");
}
void alunosMatriculados () {
    setlocale (LC_ALL, "");
    printf("=================================\n");
    printf("        ALUNOS MATRICULADOS      \n");
    printf("=================================\n");
}

void notasAlunos () {
    setlocale (LC_ALL, "");
    printf("============================\n");
    printf("        ATRIBUIR NOTAS      \n");
    printf("============================\n");
}
void centralAluno (char x [10][50][50], int y, int z) {
    setlocale (LC_ALL, "");
    printf("=====================\n");
    printf("       %s      \n", x[y][z-1]);
    printf("=====================\n");
}
void consultaNotas (){
    setlocale (LC_ALL, "");
    printf("=============================\n");
    printf("      CONSULTA DE NOTAS      \n");
    printf("=============================\n");
}


