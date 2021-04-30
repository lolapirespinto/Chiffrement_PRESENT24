#include "present24.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    //____________________________CHIFFREMENT_____________________________________________________________________//

    //printf("DONNÉES QUE NOUS POSSÉDONS POUR CHIFFRER : \n(message,clee) : (%d,%d)\n",argv[1],argv[2]);
    
    unsigned int message = 000000; unsigned int clee = 000000;
    chiffrement(message,clee);

    
    exit(0);
}