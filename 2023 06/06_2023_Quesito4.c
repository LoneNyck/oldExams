/* Scrivere una funzione che, ricevendo in ingresso una matrice di N x M interi (con M > N) e i
soli parametri dimensionali necessari, verifichi la seguente condizione: per ogni k tra 1 e N-1, l’elemento di valore
massimo della riga di indice k della matrice si trovi in posizione più avanzata rispetto all’elemento di valore
massimo della riga precedente (di indice k-1). Si suppone che ciascuna riga della matrice contenga tutti valori
distinti. La funzione dovrà restituire 1 se la condizione è verificata, 0 altrimenti.  */

#include <stdio.h>

#define N 3
#define M 4

int verificaMatrice(int mat[N][M]);

int main(){
    int mat[N][M] = {{1,3,8,2}, {10,5,12,3}, {3,2,12,16}};
    int n;

    n = verificaMatrice(mat);

    printf("%d", n);
    return 0;
}

int verificaMatrice(int mat[N][M]){
    int indMaxPrec, indMaxRiga;
    int i, j;
    int valida;

    indMaxPrec = 0;
    for(j = 1; j < M; j++){
        if(mat[0][j] > mat[0][indMaxPrec]){
            indMaxPrec = j;
        }
    }

    valida = 1;
    i = 1;
    while(i < N && valida){
        indMaxRiga = 0;
        for(j = 1; j < M; j++){
            if(mat[i][j] > mat[i][indMaxRiga]){
                indMaxRiga = j;
            }
        }

        if(indMaxRiga <= indMaxPrec){
            valida = 0;
        }
        else{
            indMaxPrec = indMaxRiga;
            i++;
        }
    }
    return valida;
}