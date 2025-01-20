/* Si vuole definire un programma che verifichi l’occorrenza di alcune parole nelle righe e nelle colonne di una
matrice di caratteri */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *creaMatrice(FILE *f, int *righe, int *colonne);
int trova(char *mat, int righe, int colonne, char *s);

int confrontaRiga(char *s1, char* s2, int len);
int confrontaColonna(char *s1, char* s2, int len, int colonne);

int main(int argc, char *argv[]){
    FILE *matrice, *parole;
    int righe, colonne;
    char *mat, *parola;

    if(argc != 3){
        printf("Argomenti insufficienti in chiamata del programma\n");
        return -1;
    }

    matrice = fopen(argv[1], "r");
    parole = fopen(argv[2], "r");

    if(matrice == NULL || parole == NULL){
        printf("Errore nell'apertura dei file\n");
        return -1;
    }

    mat = creaMatrice(matrice, &righe, &colonne);

    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            printf("%c ", *(mat + i * colonne + j));
        }
        printf("\n");
    }
    printf("\n");

    parola = (righe > colonne ? malloc(sizeof(char) * righe) : malloc(sizeof(char) * colonne));

    while(!feof(parole)){
        fscanf(parole, "%s", parola);
        trova(mat, righe, colonne, parola);
    }

    return 0;
}

char *creaMatrice(FILE *f, int *righe, int *colonne){
    char *mat;
    char c;
    int i, j;

    fscanf(f, "%d %d", righe, colonne);
    mat = malloc(sizeof(char) * (*righe) * (*colonne));

    i = 0;
    while(i < (*righe) && !feof(f)){
        j = 0;
        while(j < (*colonne) && !feof(f)){
            fscanf(f, "%c", &c);
            if(c != '\n'){
                *(mat + i * (*colonne) + j) = c;
                j++;
            }
        }
        i++;
    }

    return mat;

}

int trova(char *mat, int righe, int colonne, char *s){
    int i, j;
    int trovati;

    trovati = 0;
    i = 0;
    while(i < righe){
        j = 0;
        while(j + strlen(s) <= colonne){
            if(confrontaRiga(mat + i * colonne + j, s, strlen(s))){
                trovati++;
                printf("\"%s\" trovata: RIGA - indice prima lettera [%d,%d]\n", s, i, j);
            }
            j++;
        }
        i++;
    }

    j = 0;
    while(j < colonne){
        i = 0;
        while(i + strlen(s) <= righe){
            if(confrontaColonna(mat + i * colonne + j, s, strlen(s), colonne)){
                trovati++;
                printf("\"%s\" trovata: COLONNA - indice prima lettera [%d,%d]\n", s, i, j);
            }
            i++;
        }
        j++;
    }

    if(!trovati){
        printf("\"%s\" non trovata\n", s);
    }

    return trovati;
}

int confrontaRiga(char *s1, char* s2, int len){
    int uguali;
    int i; 

    uguali = 1;
    i = 0;
    while(i < len && uguali){
        if(*(s1 + i) != *(s2 + i)){
            uguali = 0;
        }
        i++;
    }

    return uguali;
}

int confrontaColonna(char *s1, char* s2, int len, int colonne){
    int uguali;
    int i;

    uguali = 1;
    i = 0;
    while(i < len && uguali){
        if(*(s1 + i * colonne) != *(s2 + i)){
            uguali = 0;
        }
        i++;
    }
    
    return uguali;
}