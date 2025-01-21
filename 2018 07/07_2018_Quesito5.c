/* Realizzare la funzione pangramma che accetta in input una stringa s (e qualsiasi altro parametro ritenuto 
necessario), e restituisce 1 se e solo se s è un pangramma (cioè ognuna delle 26 lettere minuscole dell'alfabeto 
inglese compare almeno una volta), 0 altrimenti. */

#include <stdio.h>
#include <stdlib.h>

int pangramma(char *s);

// main al fine di testing
int main(){

    printf("%d\n", pangramma("the five boxing wizards jump quickly"));

    return 0;
}


int pangramma(char *s){
    int trovate[26] = {0};
    int i;

    for(i = 0; i < 26; i++){
        trovate[i] = 0;
    }

    i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <= 'z'){
            trovate[s[i] - 'a']++;
        }
        i++;
    }

    for(i = 0; i < 26; i++){
        if(trovate[i] == 0){
            printf("First letter missing: %c\n", 'a' + i);
            return 0;
        }
    }

    return 1;
}