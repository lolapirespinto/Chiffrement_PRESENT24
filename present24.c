#include "present24.h"
#include <math.h>

static const int sbox[16] = { 0x0c, 0x05, 0x06, 0x0b, 0x09, 0x00, 0x0a, 0x0d, 0x03, 0x0e, 0x0f, 0x08, 0x04, 0x07, 0x01, 0x02};

int hexa_to_dec(char *mot){
    int x=0;
    for(int i=strlen(mot)-1;i>=0;i--){
        if (mot[i]>='0' && mot[i]<='9'){x=x+((mot[i]-48)*pow(16,strlen(mot)-1-i));}
        if (mot[i]>='a' && mot[i]<='f'){x=x+((mot[i]-87)*pow(16,strlen(mot)-1-i));}
    }
    return x;
}

int substitution(int etat){
    int tmp,tmp2;
    tmp = sbox[etat & 15];
    tmp2 = (sbox[(etat >> 4) & 15]) << 4; 
    tmp = tmp | tmp2; 
    tmp2 = (sbox[(etat >> 8) & 15]) << 8; 
    tmp = tmp | tmp2;
    tmp2 = (sbox[(etat >> 12) & 15]) << 12; 
    tmp = tmp | tmp2;
    tmp2 = (sbox[(etat >> 16) & 15]) << 16; 
    tmp = tmp | tmp2;
    tmp2 = (sbox[(etat >> 20) & 15]) << 20; 
    tmp = tmp | tmp2;
    etat = tmp;
    return etat;
}

int permutation(int etat){
    return etat;
}

//remplacer clee maitre par tableau de cadencmenet
void chiffrement(char *message, char *clee_maitre){
    //int etat = hexa_to_dec(message);
    //int clee = hexa_to_dec(clee_maitre);

    int etat = 11245686;
    int clee = 0;
    //for(int t=1; t<=10; t++){ // Pour les 10 tours de la fonction de chiffrement
        etat = etat ^ clee; 
        etat = substitution(etat);
        etat = permutation(etat);
    //}
    printf(" \n valeur de l'etat %d",etat);
    //etat = etat ^ k10
}

