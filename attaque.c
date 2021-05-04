#include "attaque.h"
#include "dechiffrement.h"
#include <stdint.h>
#include <time.h>

//5841527,5855507

float temps;
    clock_t t1, t2;


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

int double_chiffrement(int message, int cle1, int cle2){
    CLES cles1 = cadencement(cle1);
    CLES cles2 = cadencement(cle2);
    int chiffre = chiffrement((chiffrement(message,cles1)),cles2);
    return chiffre;
}

void remplir_liste_M(int message, int *Liste_LM){
    for(int i=0; i<16777216; i++){
        CLES K = cadencement(i); 
        Liste_LM[i] = chiffrement(message,K);
        Liste_LM[i] = Liste_LM[i] << 24 | i;
    }
}

void remplir_liste_C(int message, int *Liste_LC){
    for(int i=0; i<16777216; i++){
        CLES K = cadencement(i); 
        Liste_LC[i] = dechiffrement(message,K); 
        Liste_LC[i] = (Liste_LC[i] << 24) | i; //On stocke le résultat du chiffrement du message clair avec la clee ki
    }
}

void attaque(int message_clair, int message_chiffre){
    t1 = clock();
    int *Liste_LC = malloc(16777216*sizeof(unsigned long));
    int *Liste_LM = malloc(16777216*sizeof(unsigned long));

    remplir_liste_M(message_clair,Liste_LM);
    remplir_liste_C(message_chiffre,Liste_LC);

    tri_rapide(Liste_LM, 16777216);
    tri_rapide(Liste_LC, 16777216);

    /*comparaison_tableau(Liste_LM, Liste_LC,message_clair,message_chiffre);*/






    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps pour remplir les listes = %f\n", temps);
}