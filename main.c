#include "dechiffrement.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "attaque.h"
#include <time.h>

/*./chiffrer "fffffff" "000000"
	./chiffrer "000000" "ffffff"
	./chiffrer "f955b9" "d1bd2d"*/

    //a obtenir
    //bb57e6 739293 1b56ce 47a929


int main(int argc, char *argv[]){

    float temps;
    clock_t t1, t2;

    /*____________________________CHIFFREMENT_____________________________________________________________________*/

    /*printf("\n DONNÉES QUE NOUS POSSÉDONS POUR CHIFFRER : \n(message clair, clee) : (0x%s,0x%s)",argv[1],argv[2]);

    int message = hexa_to_dec(argv[1]);
    int clee = hexa_to_dec(argv[2]);
    CLES cles = cadencement(clee);
    int message_chiffre = chiffrement(message,cles);
    printf(" \n Le message chiffré obtenu est : %x \n",message_chiffre);*/

    /*____________________________DECHIFFREMENT_____________________________________________________________________*/

    /*printf("\n DONNÉES QUE NOUS POSSÉDONS POUR DECHIFFRER : \n(message chiffré, clee) : (0x%s,0x%s)",argv[1],argv[2]);

    int message = hexa_to_dec(argv[1]);
    CLES cles = cadencement(argv[2]);
    int message_clair = dechiffrement(message,cles);
    printf(" \n Le message clair obtenu est : %x",message_clair);*/


    /*____________________________ATTAQUE_____________________________________________________________________*/
    t1 = clock();
    printf("\n DONNÉES QUE NOUS POSSÉDONS POUR ATTAQUE : \n(message clair, message chiffré) : (0x%s,0x%s)",argv[1],argv[2]);
    int message_clair = hexa_to_dec(argv[1]);
    int message_chiffré = hexa_to_dec(argv[2]);

    int *Liste_LC = malloc(16777216*sizeof(int));
    int *Liste_LM = malloc(16777216*sizeof(int));

    Liste_LM = remplir_liste_M(message_clair,Liste_LM);
    Liste_LC  = remplir_liste_C(message_chiffré,Liste_LC);

    tri_rapide(Liste_LM, 16777216);
    tri_rapide(Liste_LC, 16777216);

    comparaison_tableau(Liste_LM, Liste_LC,message_clair,message_chiffré);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps pour remplir les listes = %f\n", temps);

    exit(0);
}