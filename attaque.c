#include "attaque.h"
#include "dechiffrement.h"
#include <stdint.h>

//5841527,5855507

void tri_rapide (int *tableau, int taille){
    int mur, courant, pivot, tmp;
    if (taille < 2) return;
    // On prend comme pivot l element le plus a droite
    pivot = tableau[taille - 1];
    mur  = courant = 0;
    while (courant<taille) {
        if (tableau[courant] <= pivot) {
            if (mur != courant) {
                tmp=tableau[courant];
                tableau[courant]=tableau[mur];
                tableau[mur]=tmp;              
            }
            mur ++;
        }
        courant ++;
    }
    tri_rapide(tableau, mur - 1);
    tri_rapide(tableau + mur - 1, taille - mur + 1);
}

void comparaison_tableau(int *tab1, int *tab2, int message_clair, int message_chiffre){
    int message_obtenu, clee1, clee2;
    for(int i=0; i<16777216; i++){
        if((tab1[i] >> 24) == (tab2[i] >> 24)){
            clee1 = tab1[i] & 0x0ffffff;
            clee2 = tab2[i] & 0x0ffffff;
            message_obtenu = double_chiffrement(message_clair,clee1,clee2);
            if (message_obtenu == message_chiffre){
                printf("\n k1 = %d,K2 = %d",clee1,clee2);
                return;
            }
        } 
    }
}

int double_chiffrement(int message, int clee1, int clee2){
    CLES cles1 = cadencement(clee1);
    CLES cles2 = cadencement(clee2);
    int chiffre = chiffrement((chiffrement(message,cles1)),cles2);
    return chiffre;
}

int *remplir_liste_M(unsigned int message, int *Liste_LM){
    for(int i=0; i<16777216; i++){
        CLES K = cadencement(i); 
        int res = (chiffrement(message,K) << 24) | i;
        Liste_LM[i]=res; //On stocke le résultat du chiffrement du message clair avec la clee ki
    }
    return Liste_LM;
}

int *remplir_liste_C(unsigned int message, int *Liste_LC){
    for(int i=0; i<16777216; i++){
        CLES K = cadencement(i); 
        int res = (dechiffrement(message,K) << 24) | i;
        Liste_LC[i]=res; //On stocke le résultat du chiffrement du message clair avec la clee ki
    }
    return Liste_LC;
}