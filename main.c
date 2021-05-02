#include "present24.h"
#include "dechiffrement.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){

    /*____________________________CHIFFREMENT_____________________________________________________________________*/

    printf("DONNÉES QUE NOUS POSSÉDONS POUR CHIFFRER : \n(message, clee) : (0x%s,0x%s)",argv[1],argv[2]);

    CLES cles = cadencement(argv[2]);
    int message_chiffre = chiffrement(argv[1],cles);
    printf(" \n Le message chiffré obtenu est : %x",message_chiffre);


    /*____________________________DECHIFFREMENT_____________________________________________________________________*/

    //int message_clair = dechiffrement(message_chiffre,cles);
    ////printf(" \n Le message clair obtenu est : %x",message_chiffre);

    exit(0);
}