/* Si scriva una funzione che riceve in ingresso un array binario di dimensione nota N (N costante predefinita) e 
restituisca l’array (di dimensione non nota a priori) che ne rappresenti la codifica RLC. */

#include <stdio.h>
#include <stdlib.h>

#define N 19

int codificaRLC(int *arrayBin, int **arrayRLC);

// main al fine di testing
int main(){
    int arrayBin[N] = {0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0};
    int *arrayRLC;
    int len;

    len = codificaRLC(arrayBin, &arrayRLC);

    for(int i = 0; i < len; i++){
        printf("%d ", arrayRLC[i]);
    }

    return 0;
}

int codificaRLC(int *arrayBin, int **arrayRLC){
    int i, j, n;

    // l'array codificato potrà avere al massimo dimensione N + 1
    (*arrayRLC) = malloc(sizeof(int) * (N + 1));

    if(arrayBin[0] == 1){
        n = 1;
    }
    else{
        n = 0;
    }

    i = 0;
    while(i < N){
        j = 0;
        while(i + j < N && arrayBin[i + j] == arrayBin[i]){
            j++;
        }
        (*arrayRLC)[n] = j;
        n++;
        i += j;
    }

    (*arrayRLC) = realloc((*arrayRLC), sizeof(int) * n);
    return n;
}