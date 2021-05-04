#include "dechiffrement.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "attaque.h"
#include <time.h>

/*./chiffrer "fffffff" "000000"
	./chiffrer "000000" "ffffff"
	./chiffrer "f955b9" "d1bd2d"*/



int main(int argc, char *argv[]){


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
    //printf("\n DONNÉES QUE NOUS POSSÉDONS POUR ATTAQUE : \n(message clair, message chiffré) : (0x%s,0x%s)",argv[1],argv[2]);
    int m1 = 0x94f4b8; int c1 = 0xbbd3cb;
    attaque(m1,c1);


    exit(0);
}