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

int *remplir_liste_M(unsigned int message, int *Liste_LM);
int *remplir_liste_C(unsigned int message, int *Liste_LC);
void tri_rapide(int *tableau, int taille);
void comparaison_tableau(int *tab1, int *tab2, int message_clair, int message_chiffre);
int double_chiffrement(int message, int clee1, int clee2);