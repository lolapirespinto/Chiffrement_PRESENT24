#include "present24.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    //____________________________CHIFFREMENT_____________________________________________________________________//

    unsigned int message = 000000; unsigned int clee = 000000;
    printf("DONNÉES QUE NOUS POSSÉDONS POUR CHIFFRER : \n(message, clee) : (0x%X,0x%X)",message,clee);
    chiffrement(message,clee);

    
    exit(0);
}