#include "present24.h"




void chiffrement(unsigned int message, unsigned int clee){
    int etat = message;
    //clee toujours a 0 ici
    for(int i=1; i<=10; i++){ 
        etat = etat ^ clee;
    }

}

