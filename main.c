#include "present24.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    //____________________________CHIFFREMENT_____________________________________________________________________//

    printf("DONNÉES QUE NOUS POSSÉDONS POUR CHIFFRER : \n(message, clee) : (0x%s,0x%s)",argv[1],argv[2]);

    //cadencement des clées
    chiffrement(argv[1],argv[2]);

    
    exit(0);
}