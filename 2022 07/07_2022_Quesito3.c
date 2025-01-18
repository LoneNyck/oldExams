/* restituisca al chiamante il numero di sottomatrici quadrate di dimensione dim_sm che hanno
somma degli elementi esattamente uguale a val. */

#include <stdio.h>

#define N 5

int sottomatrici(int mat[N][N], int dim, int dimSm, int val){
    int somma, numSott;
    int i, j, k, l;
    
    numSott = 0;
    for(i = 0; i <= dim - dimSm; i++){
        for(j = 0; j <= dim - dimSm; j++){
            somma = 0;
            for(k = i; k < i + dimSm; k++){
                for(l = j; l < j + dimSm; l++){
                    somma += mat[k][l];
                }
            }
            if(somma == val){
                numSott++;
            }
        }
    }

    return numSott;    
}