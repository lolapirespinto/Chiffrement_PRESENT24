#include "dechiffrement.h"
#include <math.h>

static const unsigned int pbox_inverse[24] = {0,4,8,12,16,20,1,5,9,13,17,21,2,6,10,14,18,22,3,7,11,15,19,23};

static const unsigned int sbox_inverse[16] = {0x05, 0x0e, 0x0f, 0x08, 0x0c, 0x01, 0x02, 0x0d, 0x0b, 0x04, 0x06, 0x03, 0x00, 0x07, 0x09, 0x0a};

//Fonction permutation inverse
unsigned int permutation_inverse(unsigned int etat){
    int tmp, tmp2, decalage; 
    tmp = etat & 1;  //le bit 0 permute toujours en 0, on garde alors toujours le dernier bit bO
    for(int i=1; i<24; i++){  //on itére ensuite sur les bits de b1 à b23
        double p = pow(2,i); 
        int res = (int) p;  
        tmp2 = etat & res; //pour isoler le bit qu'on souhaite traiter
        decalage = i - pbox_inverse[i]; //on calcule le décalage entre le bit qu'on traite et sa permutation
        if(decalage > 0) tmp2 = tmp2 >> decalage; //si ce décalage est positif on décale vers la droite
        if(decalage < 0) tmp2 = tmp2 << -(decalage); // si ce décalage est négatif on décale vers la gauche
        tmp = tmp | tmp2; //on ajoute le résultat à tmp 
    }
    etat = tmp;
    return etat;
}

//Fonction substitution inverse
unsigned int substitution_inverse(unsigned int etat){
    int tmp,tmp2; 
    tmp = sbox_inverse[etat & 15]; //on substitue les 4 premiers bits 
    tmp2 = (sbox_inverse[(etat >> 4) & 15]) << 4; //on substitue les 4 suivants
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

//Algorithme de déchiffrement
unsigned int dechiffrement(unsigned int etat, CLES cles){
    etat ^= cles.K[10]; 
    for(int i=1;i<=10;i++){ 
        etat = permutation_inverse(etat);  
        etat = substitution_inverse(etat); 
        etat ^= cles.K[10-i]; 
    }
    return etat;
}
