/* Si definisca una funzione che calcoli il numero di giorni che intercorrono tra due date
dell'anno 2024 */

#include <stdio.h>

const int Anno[12]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct {
    int giornoMese;
    int mese;
} Data;

int tempoTrascorso(Data data1, Data data2);
int verificaData(Data data);

int main(int argc, char *argv[]){
    FILE *f;
    Data data1, data2;
    int durataTot = 0, numSoggiorni = 0;
    float durataMedia = 0;

    if(argc != 2){
        printf("Errore\n");
        return -1;
    }

    f = fopen(argv[1], "r");
    while(!feof(f)){
        fscanf(f, "%d %d %d %d", &data1.giornoMese, &data1.mese, &data2.giornoMese, &data2.mese);
        if(tempoTrascorso(data1, data2) != -1){
            durataTot += tempoTrascorso(data1, data2);
        }

        numSoggiorni++;
    }
    
    durataMedia = (float) durataTot / numSoggiorni;

    printf("La durata media dei soggiorni è %.2f giorni\n", durataMedia);

    fclose(f);
    return 0;
}

int tempoTrascorso(Data data1, Data data2){
    int giorniPassati = 0;
    int isValid;
    int i;

    isValid = verificaData(data1);
    if(!isValid){
        return -1;
    }
    isValid = verificaData(data2);
    if(!isValid){
        return -1;
    }

    if(data1.mese > data2.mese){
        return -1;
    }
    if(data1.mese == data2.mese && data1.giornoMese > data2.giornoMese){
        return -1;
    }

    if(data1.mese == data2.mese){
        giorniPassati = data2.giornoMese - data1.giornoMese;
    }
    else{
        giorniPassati += Anno[data1.mese - 1] - data1.giornoMese;
        for(i = data1.mese; i < data2.mese - 1; i++){
            giorniPassati += Anno[i];
        }
        giorniPassati += data2.giornoMese;
    }

    return giorniPassati;
}

int verificaData(Data data){
    if(data.giornoMese > Anno[data.mese - 1]){
        return 0;
    }
    return 1;

}
