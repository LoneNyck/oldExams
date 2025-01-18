/* Si vuole definire un programma in C che, data una matrice di interi di dimensione massima NxM (N ed M costanti
predefinite), individui quanti e quali elementi, di seguito detti minimoRC, sono il minimo sia della colonna sia
della riga in cui sono posizionati. */

#include <stdio.h>

#define N 10
#define M 10

typedef struct{
    int y;
    int x;
} Coord;

int creaMatrice(char *nomeFile, int mat[N][M], int *righe, int *colonne);
int trovaMinimi(int mat[N][M], int righe, int colonne, Coord *coordMin); 

int main(int argc, char *argv[]){
    Coord coordMin[N*M];
    int mat[N][M], righe, colonne;
    int numeroMin;
    int i;

    if(argc != 2){
        printf("Argomenti insufficienti durante la chiamata della funzione\n");
        return -1;
    }

    creaMatrice(argv[1], mat, &righe, &colonne);
    numeroMin = trovaMinimi(mat, righe, colonne, coordMin);

    printf("Trovati %d minimi:", numeroMin);
    for(i = 0; i < numeroMin; i++){
        printf(" (%d,%d)", coordMin[i].y, coordMin[i].x);
    }
    printf("\n");

    return 0 ;
}

int creaMatrice(char *nomeFile, int mat[N][M], int *righe, int *colonne){
    FILE *f = fopen(nomeFile, "r");
    int i, j;

    if(f == NULL){
        printf("Errore: non è stato possibile aprire il file\n");
        return -1;
    }

    fscanf(f, "%d %d", righe, colonne);

    for(i = 0; i < *righe; i++){
        for(j = 0; j < *colonne; j++){
            fscanf(f, "%d", &mat[i][j]);
        }
    }

    fclose(f);
    return 0;
}

int trovaMinimi(int mat[N][M], int righe, int colonne, Coord *coordMin){
    int numeroMin = 0;
    int i, j, k;
    int daSalvare;

    for(i = 0; i < righe; i++){
        for(j = 0; j < colonne; j++){
            daSalvare = 1;

            for(k = 0; k < righe; k++){
                if(k != i && mat[i][j] > mat[k][j]){
                    daSalvare = 0;
                }
            }

            for(k = 0; k < colonne; k++){
                if(k != j && mat[i][j] > mat[i][k]){
                    daSalvare = 0;
                }
            }

            if(daSalvare){
                coordMin[numeroMin].y = i;
                coordMin[numeroMin].x = j;
                numeroMin++;
            }
        }
    }

    return numeroMin;
}

