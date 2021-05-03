# include  <stdlib.h>
# include  <stdio.h>
# include  <string.h>
#include "present24.h"

int permutation_inverse(int etat); //Fonction pour la permutation inverse
int substitution_inverse(int etat); //Fonction pour la substitution inverse
int dechiffrement(int etat, CLES cles); //Fonction pour déchiffrement un message chiffré