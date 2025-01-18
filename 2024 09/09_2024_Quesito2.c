/* Scrivere una funzione ricorsiva in C che, ricevuto come parametro un numero intero positivo n, costruisce e
restituisce un nuovo numero ottenuto sostituendo a ciascuna cifra di n la sua successiva. N.B.: la cifra 9 viene
sostituita con 0. */

#include <stdio.h>

int aggiungi(int num){
    int cifra;
    switch (num % 10){
        case 9:
            cifra = 0;
            break;
        default:
            cifra = num % 10 + 1;
            break;
    }

    if(num > 9){
        return cifra + 10 * aggiungi(num / 10);
    }
    return cifra;
}

int main(){
    printf("%d\n", aggiungi(100));
    return 0;
}