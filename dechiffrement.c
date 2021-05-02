#include "dechiffrement.h"
#include "present24.h"

static const int pbox_inverse[24] = {0,4,8,12,16,20,1,5,9,13,17,21,2,6,10,14,18,22,3,7,11,15,19,23};

static const int sbox_inverse[16] = {0x05, 0x0e, 0x0f, 0x08, 0x0c, 0x01, 0x02, 0x0d, 0x0b, 0x04, 0x06, 0x03, 0x00, 0x07, 0x09, 0x0a};

int permutation_inverse(int etat){
    int tmp, tmp2, decalage; 
    tmp = etat & 1; 
    for(int i=1; i<24; i++){ 
        double p = pow(2,i);
        int res = (int) p;  
        tmp2 = etat & res; 
        decalage = i - pbox_inverse[i]; 
        if(decalage > 0) tmp2 = tmp2 >> decalage; 
        if(decalage < 0) tmp2 = tmp2 << -(decalage); 
        tmp = tmp | tmp2; 
    }
    etat = tmp;
    return etat;
}

int substitution_inverse(int etat){
    int tmp,tmp2;
    tmp = sbox_inverse[etat & 15];
    tmp2 = (sbox_inverse[(etat >> 4) & 15]) << 4; 
    tmp = tmp | tmp2; 
    tmp2 = (sbox_inverse[(etat >> 8) & 15]) << 8; 
    tmp = tmp | tmp2;
    tmp2 = (sbox_inverse[(etat >> 12) & 15]) << 12; 
    tmp = tmp | tmp2;
    tmp2 = (sbox_inverse[(etat >> 16) & 15]) << 16; 
    tmp = tmp | tmp2;
    tmp2 = (sbox_inverse[(etat >> 20) & 15]) << 20; 
    tmp = tmp | tmp2;
    etat = tmp;
    return etat;
}

/*nt dechiffrement(int message_chiffre, CLES K){
    int etat = etat ^ K[10]; 
    for(int i=1;i<=10;i++){ 
        permutation_inverse(etat);  
        substitution_inverse(etat); 
        etat = etat ^ K[10-i]; 
    }
    return etat;
}*/