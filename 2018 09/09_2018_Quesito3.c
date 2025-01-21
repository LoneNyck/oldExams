#include <stdio.h>
#include <stdlib.h>

#define N 128

void leggiMatrice(FILE *f, int mat[N][N], int *dim);
int quadratoMagico(int mat[N][N], int dim);

int main(int argc, char *argv[]){
    FILE *f;
    int mat[N][N];
    int dim;

    if(argc != 2){
        printf("Argomenti insufficienti in chiamata\n");
    }
    else{
        f = fopen(argv[1], "r");
        if(f == NULL){
            printf("Errore nell'apertura del file\n");
        }
        else{
            leggiMatrice(f, mat, &dim);
            if(quadratoMagico(mat, dim)){
                printf("La matrice è un quadrato magico\n");
            }
            else{
                printf("La matrice NON è un quadrato magico\n");
            }
        }
    }

    return 0;
}

void leggiMatrice(FILE *f, int mat[N][N], int *dim){
    int i,j;

    fscanf(f, "%d", dim);
    for(i = 0; i < *dim; i++){
        for(j = 0; j < *dim; j++){
            fscanf(f, "%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int quadratoMagico(int mat[N][N], int dim){
    int trovato;
    int somma, somma1, somma2;
    int i, j, n;

    for(n = 1; n <= dim*dim; n++){
        trovato = 0;
        i = 0;
        while(i < dim && !trovato){
            j = 0;
            while(j < dim && !trovato){
                if(mat[i][j] == n){
                    trovato = 1;
                }
                j++;
            }
            i++;
        }
        if(!trovato){
            return 0;
        }
    }

    somma = 0;
    for(j = 0; j < dim; j++){
        somma += mat[0][j];
    }

    for(i = 0; i < dim; i++){
        somma1 = 0;
        somma2 = 0;
        for(j = 0; j < dim; j++){
            somma1 += mat[i][j];
            somma2 += mat[j][i];
        }
        
        if(somma1 != somma || somma2 != somma){
            return 0;
        }
    }

    somma1 = 0;
    somma2 = 0;
    for(i = 0; i < dim; i++){
        somma1 += mat[i][i];
        somma2 += mat[i][dim - 1 - i];
    }

    if(somma1 != somma || somma2 != somma){
        return 0;
    }
    return 1;
}