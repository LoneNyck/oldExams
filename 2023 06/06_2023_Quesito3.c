/* L’app “hotel da incubo” individua i peggiori hotel di una città. L’app si basa sulle recensioni
che i clienti rilasciano online, su una scala da 1 a 10, per tre parametri: servizi (s), pulizia (pu), posizione (po). Si
vogliono definire quindi le funzioni che permettono di ritrovare l'hotel peggiore. Si tenga conto che per ogni hotel
della città, è disponibile un file di testo che memorizza le recensioni dei clienti. La prima riga del file riporta il
nome dell’hotel, le righe successive riportano ognuna, in modo anonimo, triple di voti assegnati da un cliente
ai 3 criteri s, pu e po.  */

#include <stdio.h>
#include <string.h>

#define SIZE 30
#define NUM_HOTEL 50

typedef struct{
    char nome[SIZE];
    float voto;
} Hotel;

float votoHotel(char *nomeFile, Hotel *hotel);
Hotel incubo(char *nomeFile);

int main(int argc, char *argv[]){
    Hotel hotelPeggiore;

    if(argc != 2){
        printf("Parametri insufficienti in chiamata\n");
        return -1;
    }

    hotelPeggiore = incubo(argv[1]);

    printf("L'hotel peggiore è %s con una media di %.2f/30.\n", hotelPeggiore.nome, hotelPeggiore.voto);
    
    return 0;
}

float votoHotel(char *nomeFile, Hotel *hotel){
    FILE *f = fopen(nomeFile, "r");

    int sommaS = 0, sommaPu = 0, sommaPo = 0, numeroVoti = 0;
    int s, pu, po;
    float mediaS, mediaPu, mediaPo;
    int i;

    if(f == NULL){
        printf("Errore: non è stato possibile aprire il file\n");
        return -1;
    }

    fgets(hotel->nome, SIZE, f);
    for(i = 0; i < strlen(hotel->nome); i++){
        if(hotel->nome[i] == '\n'){
            hotel->nome[i] = '\0';
        }
    }

    while(!feof(f)){
        fscanf(f, "%d %d %d", &s, &pu, &po);
        sommaS += s;
        sommaPu += pu;
        sommaPo += po;
        numeroVoti++;
    }

    mediaS = (float) sommaS/numeroVoti;
    mediaPu = (float) sommaPu/numeroVoti;
    mediaPo = (float) sommaPo/numeroVoti;

    fclose(f);

    return (mediaS + mediaPu + mediaPo);
}

Hotel incubo(char *nomeFile){
    FILE *f = fopen(nomeFile, "r");
    char nomeFileHotel[SIZE];
    Hotel hotel[NUM_HOTEL], hotelPeggiore = {" ", 0};
    int numeroHotel;
    int i;

    if(f == NULL){
        printf("Errore: non è stato possibile aprire il file\n");
    }
    else{
        numeroHotel = 0;

        while(!feof(f)){
            fscanf(f, "%s", nomeFileHotel);
            hotel[numeroHotel].voto = votoHotel(nomeFileHotel, &hotel[numeroHotel]);
            numeroHotel++;
        }

        hotelPeggiore = hotel[0];
        for(i = 1; i < numeroHotel; i++){
            if(hotel[i].voto < hotelPeggiore.voto){
                hotelPeggiore = hotel[i];
            }   
        }

        fclose(f);
    }
    
    return hotelPeggiore;
}