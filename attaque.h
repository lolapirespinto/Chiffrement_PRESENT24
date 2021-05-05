#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <math.h>

/*PIRES PINTO
LOLA
(m1,c1) = (94f4b8, bbd3cb) (m2,c2) = (111ef1,8773b3)*/
unsigned long long *Liste_LC;
unsigned long long *Liste_LM;

void remplir_liste_M(int message, unsigned long long int *Liste_LM); //Fonction qui remplit la liste LM
void remplir_liste_C(int message, unsigned long long int *Liste_LC); //Fonction qui remplit la liste LC
void quicksort(unsigned long long *tab, int premier, int dernier); //Fonction pour le tri rapide
void comparaison_tableau(unsigned long long int *tab1, unsigned long long int *tab2, int m1, int c1, int m2, int c2); //on cherche les clés k1 et k2 dans les listes LC et LM
int double_chiffrement(int message, int clee1, int clee2); //Fonction qui double chiffre un message clair avec deux cles k1 et k2
void attaque(unsigned int m1, unsigned int c1, unsigned int m2, unsigned int c2); //Fonction globale de l'attaque par le milieu