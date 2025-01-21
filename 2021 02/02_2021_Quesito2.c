/* Scrivere una funzione ricorsiva che, data una stringa, restituisce il numero di caratteri che
nella stringa rappresentano un cifra (‘0’,…, ‘9’). */

#include <stdio.h>

int numeri(char *s);

int main(){
    printf("%d\n", numeri("C1a0 c0m3 st4i p4r50n4"));

    return 0;
}

int numeri(char *s){
    if(*s == '\0'){
        return 0;
    }
    if(*s >= '0' && *s <= '9'){
        return 1 + numeri(s + 1);
    }
    return numeri(s + 1);
}