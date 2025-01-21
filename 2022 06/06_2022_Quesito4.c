/* Si definisca una funzione in grado di individuare e segnalare eventuali picchi, cioè
elementi con valori che superano quelli degli 8 elementi che li circondano di almeno 10 unità. 
Si escludano i bordi. */

#include <stdio.h>
#include <stdlib.h>

#define N 5

void picchi(int mat[N][N], FILE *f);

int main(int argc, char *argv[]){
    FILE *f;
    int mat[N][N];
    int i, j;

    if(argc != 2){
        printf("Argomenti insufficienti in chiamata\n");
        return -1;
    }
    
    f = fopen(argv[1], "w");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    printf("Inserire i valori della matrice\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    picchi(mat, f);

    return 0;
}

void picchi(int mat[N][N], FILE *f){
    int max;
    int i, j, k, l;

    for(i = 1; i < N - 1; i++){
        for(j = 1; j < N - 1; j++){
            max = mat[i - 1][j - 1];
            for(k = -1; k <= 1; k++){
                for(l = -1; l <= 1; l++){
                    if((k != 0 || l != 0) && mat[i + k][j + l] > max){
                        max = mat[i+ k][j + l];
                    }
                }
            }
            if(mat[i][j] - max >= 10){
                fprintf(f, "%d %d\n", i, j);
            }
        }
    }
}