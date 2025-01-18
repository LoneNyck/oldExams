/* Data una matrice di interi mat, di dimensione NxM (N e M costanti), si scriva una funzione per individuare se Mat
contiene almeno una sottomatrice, di dimensioni r e c, i cui elementi abbiano somma uguale a 0. La funzione
riceve come parametro la matrice mat, le dimensioni r e c della sottomatrice e ogni altro parametro ritenuto
necessario. Quindi, restituisce all’ambiente chiamante gli indici dell’angolo superiore sinistro della prima
sottomatrice individuata. Se mat non contiene una sottomatrice di somma 0, la funzione restituisce indici di
valore -1, -1. */

#include <stdio.h>

#define M 5
#define N 5

void sottomatriceNulla(int mat[N][M], int r, int c, int *x, int *y){
    int trovato;
    int somma;
    int i, j, k, l;
    
    *x = -1;
    *y = -1;

    if(r <= N && c <= M){
        trovato = 0;
        somma = 0;

        for(i = 0; i <= N - r; i++){
            for(j = 0; j <= M - c; j++){
                somma = 0;
                for(k = i; k < r + i; k++){
                    for(l = j; l < c + j; l++){
                        somma += mat[k][l];
                    }
                }
                if(somma == 0){
                    *x = j;
                    *y = i;
                    return;
                }
            }
        }
    }
}