#include "attaque.h"
#include "dechiffrement.h"
#include <stdint.h>
#include <time.h>

#define TAILLE 16777216

float temps;
    clock_t t1, t2;


//Fonction tri_rapide qui trie les élémenents d'une liste dans l'ordre croissant
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

//on cherche les cles k1 et k2 en comparant les valeurs dans les deux listes LM et LC
void comparaison_tableau(unsigned long long *tab1, unsigned long long int *tab2, int m1, int c1, int m2, int c2){
    int n1 = TAILLE;
    int message_obtenu1,message_obtenu2, cle1, cle2;
  
    int  i = 0 ,  j = 0; 
  
    while(i < n1 & j < n1){
        
        if((tab1[i] & 0xffffff000000) < (tab2[j] & 0xffffff000000)) i++; //si la valeur i est inférieur à la valeur j on incrémente i 
        else if((tab1[i] & 0xffffff000000) > (tab2[j] & 0xffffff000000)) j++; //si la valeur i est supérieur à la valeur j on incrémente j
        else{ //les deux valeurs dans les deux listes sont égales
            cle1 = tab1[i] & 0x0ffffff; //on récupère la clee k1
            cle2 = tab2[j] & 0x0ffffff; //on récupère la clee k2
            message_obtenu1 = double_chiffrement(m1,cle1,cle2); //on regarde si on obtient c1 en chiffrant m1 avec k1 et K2
            message_obtenu2 = double_chiffrement(m2,cle1,cle2); //on regarde si on obtient c2 en chiffrant m2 avec k1 et K2
            if ((message_obtenu1 == c1) && (message_obtenu2 == c2)){ //on a touvé les deux clés k1 et K2 qui chiffrent m1 et m2
                printf("\n(k1, k2) : (%d,%d)\n",cle1,cle2);
                return;
            }
            i++;
            j++;
        }   
    } 
}
    
//Fonction qui double chiffre un message clair avec deux cles k1 et k2
int double_chiffrement(int message, int cle1, int cle2){
    CLES cles1 = cadencement(cle1);
    CLES cles2 = cadencement(cle2);
    int chiffre = chiffrement((chiffrement(message,cles1)),cles2);
    return chiffre;
}

//Fonction qui remplit la liste LM
void remplir_liste_M(int message, unsigned long long *Liste_LM){
    for(unsigned int i=0; i<TAILLE; i++){
        CLES K = cadencement(i); //cadencement de la cle maitre i 
        Liste_LM[i] = chiffrement(message,K); //chiffre le message avec la cle ki
        Liste_LM[i] = Liste_LM[i] << 24 | i; // stock la concaténation du message chiffré avec la cle ki 
    }
}

void remplir_liste_C(int message, unsigned long long *Liste_LC){
    for(unsigned int i=0; i<TAILLE; i++){
        CLES K = cadencement(i); //cadencement de la cle maitre i 
        Liste_LC[i] = dechiffrement(message,K); //chiffre le message avec la cle ki
        Liste_LC[i] = (Liste_LC[i] << 24) | i; // stcok la concaténation du message chiffré avec la cle ki
    }
}

void attaque(unsigned int m1, unsigned int c1, unsigned int m2, unsigned int c2){
    
    t1 = clock();
    unsigned long long *Liste_LC = malloc(TAILLE*sizeof(unsigned long long));
    unsigned long long *Liste_LM = malloc(TAILLE*sizeof(unsigned long long));

    remplir_liste_M(m1,Liste_LM); //remplit liste LM
    remplir_liste_C(c1,Liste_LC); //remplit la liste LC

    quicksort(Liste_LC,0,TAILLE-1); //tri rapide sur la liste LC
    quicksort(Liste_LM,0,TAILLE-1); //tri rapidfe sur la liste LM
  
    comparaison_tableau(Liste_LM,Liste_LC,m1,c1,m2,c2); //cherche les cles dans les deux listes

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps final = %f\n", temps);
}