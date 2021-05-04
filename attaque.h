#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <math.h>

/*PIRES PINTO
LOLA
(m1,c1) = (94f4b8, bbd3cb) (m2,c2) = (111ef1,8773b3)*/
unsigned long long *Liste_LC;
unsigned long long *Liste_LM;

void remplir_liste_M(int message, unsigned long long int *Liste_LM);
void remplir_liste_C(int message, unsigned long long int *Liste_LC);
void quicksort(unsigned long long *number,int first,int last);
void comparaison_tableau(unsigned long long int *tab1, unsigned long long int *tab2, int m1, int c1, int m2, int c2);
int double_chiffrement(int message, int clee1, int clee2);
void attaque(unsigned int m1, unsigned int c1, unsigned int m2, unsigned int c2);
void compare_tab(int *tab1, int *tab2,int *liste_indices,int taille);