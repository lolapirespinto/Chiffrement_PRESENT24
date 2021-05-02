#include "present24.h"
#include "dechiffrement.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*./chiffrer "fffffff" "000000"
	./chiffrer "000000" "ffffff"
	./chiffrer "f955b9" "d1bd2d"*/


int main(int argc, char *argv[]){

    /*____________________________CHIFFREMENT_____________________________________________________________________*/

    //printf("\n DONNÉES QUE NOUS POSSÉDONS POUR CHIFFRER : \n(message clair, clee) : (0x%s,0x%s)",argv[1],argv[2]);

    //int message_chiffre = chiffrement(argv[1],argv[2]);
    //printf(" \n Le message chiffré obtenu est : %x",message_chiffre);
    //12277734

    /*____________________________DECHIFFREMENT_____________________________________________________________________*/

    printf("\n DONNÉES QUE NOUS POSSÉDONS POUR DECHIFFRER : \n(message chiffré, clee) : (0x%s,0x%s)",argv[1],argv[2]);

    int message_clair = dechiffrement(argv[1],argv[2]);
    printf(" \n Le message clair obtenu est : %x",message_clair);

    exit(0);
}