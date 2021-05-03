#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <math.h>

/*on a deux tableaux d'unsigned long long
avec le chiffré/clair et la clé
sur une case*/
/*PIRES PINTO
LOLA
(m1,c1) = (94f4b8, bbd3cb) (m2,c2) = (111ef1,8773b3)*/

typedef struct ListeM{
    unsigned long long int chiffre_obtenu;
    unsigned int cle;
}ListeM;

typedef struct ListeC{
    unsigned long long int clair_obtenu;
    unsigned int cle;
}ListeC;