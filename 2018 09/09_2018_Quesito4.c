/* Si scriva una funzione ricorsiva che permette di calcolare la somma degli elementi di una matrice */

#include <stdio.h>

#define N 5

int somma(int mat[N][N], int righe, int colonne);

int somma(int mat[N][N], int righe, int colonne){
    if(righe == 0){
        return 0;
    }
    if(colonne == 0){
        return somma(mat, righe - 1, N);
    }
    return mat[righe - 1][colonne - 1] + somma(mat, righe, colonne -1);
}
