#include "attaque.h"
#include "dechiffrement.h"
#include <stdint.h>
#include <time.h>

#define TAILLE 16777216

float temps;
    clock_t t1, t2, t3, t4, t5;


void quicksort(unsigned long long *number,int first,int last){
   int i, j, pivot;
   unsigned long long temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while((number[i]>>24 & 0xffffff) <= (number[pivot]>>24 & 0xffffff) && i<last)
            i++;
         while((number[j]>>24 & 0xffffff) > (number[pivot]>>24 & 0xffffff))
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

void comparaison_tableau(unsigned long long *tab1, unsigned long long int *tab2, int m1, int c1, int m2, int c2){
    printf("\n entrer dans comparaison");
    int n1 = TAILLE;
    int message_obtenu1,message_obtenu2, clee1, clee2;
  
    int  i = 0 ,  j = 0; 
  
    while(i < n1 & j < n1){
        
        if((tab1[i] & 0xffffff000000) < (tab2[j] & 0xffffff000000)) i++;
        else if((tab1[i] & 0xffffff000000) > (tab2[j] & 0xffffff000000)) j++;
        else{
            clee1 = tab1[i] & 0x0ffffff;
            clee2 = tab2[j] & 0x0ffffff;
            message_obtenu1 = double_chiffrement(m1,clee1,clee2);
            message_obtenu2 = double_chiffrement(m2,clee1,clee2);
            if ((message_obtenu1 == c1) && (message_obtenu2 == c2)){
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

void remplir_liste_M(int message, unsigned long long *Liste_LM){
    for(unsigned int i=0; i<TAILLE; i++){
        CLES K = cadencement(i); 
        Liste_LM[i] = chiffrement(message,K);
        Liste_LM[i] = Liste_LM[i] << 24 | i;
    }
}

void remplir_liste_C(int message, unsigned long long *Liste_LC){
    for(unsigned int i=0; i<TAILLE; i++){
        CLES K = cadencement(i); 
        Liste_LC[i] = dechiffrement(message,K); 
        Liste_LC[i] = (Liste_LC[i] << 24) | i; //On stocke le résultat du chiffrement du message clair avec la clee ki
    }
}

void attaque(unsigned int m1, unsigned int c1, unsigned int m2, unsigned int c2){
    t1 = clock();
    unsigned long long *Liste_LC = malloc(TAILLE*sizeof(unsigned long long));
    unsigned long long *Liste_LM = malloc(TAILLE*sizeof(unsigned long long));

    remplir_liste_M(m1,Liste_LM);
    remplir_liste_C(c1,Liste_LC);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps pour remplir les listes = %f\n", temps);

    t3 = clock();
 
    quicksort(Liste_LC,0,TAILLE-1);
    quicksort(Liste_LM,0,TAILLE-1);

    t4 = clock();
    temps = (float)(t4-t3)/CLOCKS_PER_SEC;
    printf("temps pour trier = %f\n", temps);

    comparaison_tableau(Liste_LM,Liste_LC,m1,c1,m2,c2);

    /*t5 = clock();
    temps = (float)(t5-t4)/CLOCKS_PER_SEC;
    printf("temps pour remplir les listes = %f\n", temps);*/
}