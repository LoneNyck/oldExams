/* Si consideri una matrice di dimensioni MxN che contiene valori binari 0 e 1. La matrice rappresenta una griglia
di possibili percorsi, in cui 0 indica un varco attraversabile e 1 rappresenta un muro invalicabile. I movimenti
all'interno di questa griglia avvengono in orizzontale e verticale, e possono essere rappresentati da coppie di
valori (±i, 0), per gli spostamenti verticali (verso l'alto o il basso), e (0, ±j) per gli spostamenti orizzontali (a destra
o a sinistra). i e j rappresentano cioè scostamenti di riga e di colonna, rispettivamente. */

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 5
#define K 10

typedef struct{
    int vert;
    int oriz;
} Mossa;

int verificaPercorso(int mat[M][N], Mossa mosse[K], int numMosse);

int main(){
    int mat[M][N] = {{0, 1, 0, 1, 1},
                    {0, 0, 1, 1, 0},
                    {1, 0, 0, 0, 0},
                    {1, 1, 0, 1, 0},
                    {1, 1, 1, 1, 0}};
    int numMosse = 3;
    Mossa mosse[K] = {{1,0},{0,1},{5,0}};

    verificaPercorso(mat, mosse, numMosse);

    return 0;
}

int verificaPercorso(int mat[M][N], Mossa *mosse, int numMosse){
    int ultimaY, ultimaX;
    int valida;
    int dir;
    int i, j;

    ultimaY = 0;
    ultimaX = 0;

    valida = 1;
    i = 0;

    while(i < numMosse && valida){
        if(ultimaY + mosse[i].vert >= M || ultimaX + mosse[i].oriz >= N){
            valida = 0;
        }
        else{
            dir = mosse[i].oriz / abs(mosse[i].oriz);
            for(j = 1; j <= abs(mosse[i].oriz); j++){
                if(mat[ultimaY][ultimaX + j * dir] == 1){
                    valida = 0;
                }
            }

            dir = mosse[i].vert / abs(mosse[i].vert );
            for(j = 1; j <= abs(mosse[i].vert); j++){
                if(mat[ultimaY + j * dir][ultimaX] == 1){
                    valida = 0;
                    printf("wall");
                }
            }
        }
        if(valida){
            ultimaY += mosse[i].vert;
            ultimaX += mosse[i].oriz;
        }
        i++;
    }

    if(valida){
        printf("Il precorso è stato completato con successo\n");
        return 1;
    }
    else{
        printf("Il percorso si è interrotto in [%d][%d]\n", ultimaY, ultimaX);
        return 0;
    }
}