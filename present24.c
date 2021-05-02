#include "present24.h"
#include <math.h>

static const int sbox[16] = {0x0c, 0x05, 0x06, 0x0b, 0x09, 0x00, 0x0a, 0x0d, 0x03, 0x0e, 0x0f, 0x08, 0x04, 0x07, 0x01, 0x02};

static const int permutation_tab[24] = {0,6,12,18,1,7,13,19,2,8,14,20,3,9,15,21,4,10,16,22,5,11,17,23};

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

//remplacer direct décalage par zéro ??
    /*decalage = tmp - permutation_tab[tmp]; 
    if(decalage > 0) tmp = tmp << decalage;
    else tmp = tmp >> decalage; //OK*/
    /*for(int i=1; i<23; i++){ 
        printf(" \n valeur de tmp ta capte %d",tmp);
        double p = pow(2,23-1);
        int res = (int) p; 
        tmp2 = etat & res;  //probleme
        printf(" \n valeur de tmp2 ta capte %d",tmp);
        decalage = 1 - permutation_tab[1];
        if(decalage > 0) tmp2 = tmp2 << decalage;
        else tmp2 = tmp2 >> decalage; 
        tmp = tmp | tmp2;
        //printf(" \n valeur de tmp ta capte %d",tmp);
    }*/

int permutation(int etat){
    int tmp, tmp2, decalage; 
    //printf(" \n valeur de l'etat AU DEBUT %d",etat);

    tmp = etat & 8388608; // ETAPE 1
    for(int i=0; i<23; i++){ 
        //printf(" \n valeur de tmp ta capte %d",tmp);
        double p = pow(2,i);
        int res = (int) p;  //ETAPE 2
        tmp2 = etat & res; //ETAPE 3
        decalage = (23-i) - (permutation_tab[23-i]); //etape 4
        if(decalage > 0) tmp2 = tmp2 << decalage; //etape 5
        if(decalage < 0) tmp2 = tmp2 >> decalage; 
        tmp = tmp | tmp2; //etape 6
        //printf(" \n valeur de tmp ta capte petit decakage %d",decalage);
    }
    etat = tmp;
    //printf(" \n valeur de tmp ta capte petit decakage %d",etat);
    return etat;
}

//remplacer clee maitre par tableau de cadencmenet
void chiffrement(char *message, char *clee_maitre){
    //int etat = hexa_to_dec(message);
    //int clee = hexa_to_dec(clee_maitre);

    int etat = 0;
    int K[11] = {0,0,1,1,4194402,8388650,12582963,4194395,1612,8389252,4195157};
    for(int t=1; t<=10; t++){ 
        etat = etat ^ K[t-1]; 
        etat = substitution(etat);
        etat = permutation(etat);
    }
    etat = etat ^ K[10]; 
    printf(" \n valeur de l'etat %d",etat);
    //valeur attendue = 12277734
}

