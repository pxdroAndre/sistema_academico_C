#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
void listaAlunos (int x[50], int y, char z [10][50][50], int w [50]) {
    setlocale (LC_ALL, "");
    for (int j=0;j<x[y];j++) {
        printf("\nNome: %s\n", z[y][j]);
        printf("Matrícula: %d\n", w[j]);
    }
}
float atribuirNotas (float n1[50][50], float n2 [50][50], int x, int y, float md [50][50], char z [10][50][50]){
    setlocale (LC_ALL, "");
    printf("\n\n");
    printf("Insira a primeira nota: ");
    scanf("%f", &n1[y][x]);
    printf("Insira a segunda nota: ");
    scanf("%f", &n2[y][x]);
    md[y][x]=(n1[y][x]+n2[y][x])/2;
    printf("As notas de %s foram cadastradas com sucesso!", z[x][y-1]);
    printf("\n\n");
    return md[y][x];
}
void asNotas (float n1 [50][50], int x, int y, float n2 [50][50], float md[50][50]){
    setlocale (LC_ALL, "");
    printf("Nota 1: %.1f \n", n1[y][x]);
    printf("Nota 2: %.1f \n", n2[y][x]);
    printf("Media: %.2f \n", md[y][x]);
    if (md[y][x]>=7){
        printf("\nAPROVADO(A), PODE CURTIR AS FÉRIAS\n");
    } else if (md[y][x]<=5){
        printf("\nREPROVADO(A), TENTE A SORTE NO FUTSAL\n");
    } else {
        printf("\nPRECISA TREINAR MAIS\n");
    }
}
