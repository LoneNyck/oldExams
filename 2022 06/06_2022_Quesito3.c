/* Si scriva una funzione in C che, ricevuto come parametro l’array iniziale, crei e restituisca
all’ambiente chiamante un secondo array, finale, in cui a ogni sotto-sequenza delimitata da parentesi
tonde si sostituisca il carattere che nella sotto-sequenza compare più frequentemente.
Il nuovo array deve avere una dimensione strettamente necessaria a contenere i suoi elementi. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 128

void modifica(char *iniziale, char **finale);
char conta(char *s);

int main(){
    char *iniziale = "ciao(come)stai(bella)persona";
    char *finale;

    modifica(iniziale, &finale);

    printf("%s\n", finale);

    return 0;
}

void modifica(char *iniziale, char **finale){
    char s[N], t[N];
    char c;
    int i,j;

    strcpy(s, iniziale);

    i = 0;
    j = 0;
    while(s[i] != '\0'){
        if(s[i] == '('){
            t[j] = s[i]; // copia la parentesi

            i++; //avanza al carattere dopo la prima parentesi
            j++; 

            c = conta(&s[i]); //trova il carattere più frequente fino alla fine della parentesi
            t[j] = c; //copia il carattere più frequente
            j++; 

            while(s[i] != ')'){
                i++;
            }
            t[j] = s[i];

            i++; // avanza a dopo la parentesi chiusa
            j++;
        }
        else{
            t[j] = s[i];
            i++;
            j++;
        }
    }

    t[j] = '\0';

    *finale = malloc(sizeof(char) * (strlen(t) + 1));
    strcpy(*finale, t);
}

char conta(char *s){
    int occ[26] = {0};
    int posMax;
    int i;

    i = 0;
    while(s[i] != ')'){
        occ[s[i] - 'a']++;
        i++;
    }

    posMax = 0;
    for(i = 1; i < 26; i++){
        if(occ[i] > occ[posMax]){
            posMax = i;
        }
    }

    return 'a' + posMax;
}