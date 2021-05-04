#include "attaque.h"
#include "dechiffrement.h"
#include <stdint.h>
#include <time.h>

//5841527,5855507
float temps;
    clock_t t1, t2, t3, t4, t5;

/*void tri_rapide (int *tableau, int taille){
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
}*/

void tri_rapide(int *tableau, int taille){
    int mur, courant, pivot, tmp;
    pivot = (tableau[taille - 1] & 0xffffff000000);
    mur  = courant = 0;
    while (courant<taille) {
        if ((tableau[courant] & 0xffffff000000) <= pivot) {
            if (mur != courant) {
                tmp=(tableau[courant]& 0xffffff000000);
                tableau[courant] = tableau[courant] & 0xffffff000000;
                tableau[mur] = tableau[mur] & 0xffffff000000;
                tableau[courant] = tableau[mur];
                tableau[mur] = tmp;              
            }
            mur ++;
        }
        courant ++;
    }
    tri_rapide(tableau, mur - 1);
    tri_rapide(tableau + mur - 1, taille - mur + 1);
}

void comparaison_tableau(int *tab1, int *tab2, int m1, int c1, int m2, int c2){
    printf("\n entrer dans comparaison");
    //int n1 = 16777216/sizeof(tab1[0]);
    //int n2 = 16777216/sizeof(tab2[0]);
    int n1 = 16777216;
    int message_obtenu1,message_obtenu2, clee1, clee2;
  
    int  i = 0 ,  j = 0; 
  
    while(i < n1 & j < n1){
        
        if((tab1[i] & 0xffffff000000) < (tab2[j] & 0xffffff000000)) i++;
        else if((tab1[i] & 0xffffff000000) > (tab2[j] & 0xffffff000000)) j++;
        else{
            clee1 = tab1[i] & 0x0ffffff;
            clee2 = tab2[i] & 0x0ffffff;
            message_obtenu1 = double_chiffrement(m1,clee1,clee2);
            message_obtenu2 = double_chiffrement(m2,clee1,clee2);
            if ((message_obtenu1 == c1)&(message_obtenu2 == c2)){
                printf("\n k1 = %d,K2 = %d",clee1,clee2);
                return;
            }
            i++;
            j++;
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
    printf("ok\n");
}

void attaque(int m1, int c1, int m2, int c2){
    t1 = clock();
    int *Liste_LC = malloc(16777216*sizeof(unsigned long));
    int *Liste_LM = malloc(16777216*sizeof(unsigned long));

    printf("\n avant remplissage");

    remplir_liste_M(m1,Liste_LM);
    remplir_liste_C(c1,Liste_LC);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps pour remplir les listes = %f\n", temps);

    printf("\n apres liste");

    t3 = clock();
    //potentiel probleme avec i a la fin
    tri_rapide(Liste_LM, 16777216);
    tri_rapide(Liste_LC, 16777216);

    printf("\n apres tri_rapide");

    t4 = clock();
    temps = (float)(t4-t3)/CLOCKS_PER_SEC;
    printf("temps pour trier = %f\n", temps);

    //comparaison_tableau(Liste_LM,Liste_LC,m1,c1,m2,c2);

    /*t5 = clock();
    temps = (float)(t5-t4)/CLOCKS_PER_SEC;
    printf("temps pour remplir les listes = %f\n", temps);*/

   
}