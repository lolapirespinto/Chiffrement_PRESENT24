#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <math.h>

/*PIRES PINTO
LOLA
(m1,c1) = (94f4b8, bbd3cb) (m2,c2) = (111ef1,8773b3)*/

void remplir_liste_M(int message, int *Liste_LM);
void remplir_liste_C(int message, int *Liste_LC);
void tri_rapide(int *tableau, int taille);
void comparaison_tableau(int *tab1, int *tab2, int m1, int c1, int m2, int c2);
int double_chiffrement(int message, int clee1, int clee2);
void attaque(int m1, int c1, int m2, int c2);
void compare_tab(int *tab1, int *tab2,int *liste_indices,int taille);