#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int vrfcDiscp (int x, char y[10][50]){
    setlocale (LC_ALL, "");
    for (int i=1; i<x; i++){
        if (strcmp(y[i], y[x])==0) {
            return 1;
        break;
        }
    }
    return 0;
}
void listaDisc (int x, char nome [10] [50]) {
    setlocale (LC_ALL, "");
    for (int j=1; j<x; j++) {
        printf ("[%d]%s\n", j, nome[j]);
    }
}
