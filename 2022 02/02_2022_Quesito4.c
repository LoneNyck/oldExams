/* Un file contiene una sequenza di interi che in modo compatto codificano i valori di una matrice di
dimensione MxN (M ed N costanti predefinite). Per decodificare la sequenza, i valori nel file devono
essere interpretati a coppie: ogni coppia è del tipo <x = valore, y = ripetizioni>, dove y rappresenta il
numero di volte in cui il valore x deve essere inserito in celle adiacenti della matrice. */

#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 5

void decodifica(int mat[N][M], FILE *f);
void codifica(int mat[N][M], FILE *f);

int main(int argc, char *argv[]){
    FILE *f;
    char nome[258];
    int mat[N][M];

    if(argc != 2){
        printf("Parametri insufficienti in chiamata di funzione\n");
        return -1;
    }

    if(argv[1] == "codifica"){
        printf("Inserire il nome del file su cui salvare la matrice: \n");
        fscanf("%s", nome);
        f = fopen(nome, "w");

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%d ", &mat[i][j]);
            }
        }

        codifica(mat, f);
    }
    else if(argv[1] == "decodifica"){
        printf("Inserire il nome del file da cui salvare la matrice: \n");
        fscanf("%s", nome);
        f = fopen(nome, "r");

        decodifica(mat, f);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

void decodifica(int mat[N][M], FILE *f){
    int i, j;
    int num, rip;

    i = 0;
    j = 0;

    while(!feof(f)){
        fscanf(f, "%d %d", &num, &rip);

        while(rip > 0 && i < N){
            mat[i][j] = num;
            rip--;

            if(j < M - 1){
                j++;
            }
            else{
                j = 0;
                i++;
            }
        }
    }
}

void codifica(int mat[N][M], FILE *f){
    int i, j;
    int num, rip;

    i = 0;
    j = 0;

    while(i < N){
        num = mat[i][j];
        rip = 1;

        if(j < M - 1){
            j++;
        }
        else if(j == M - 1 && i < N - 1){
            j = 0;
            i++;
        }

        while(i < N && mat[i][j] == num){
            rip++;

            if(j < M - 1){
                j++;
            }
            else if(j == M - 1 && i < N){
                j = 0;
                i++;
            }
        }

        fprintf(f, "%d %d ", num, rip);
    }
}