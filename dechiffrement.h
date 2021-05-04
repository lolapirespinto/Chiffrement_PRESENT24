# include  <stdlib.h>
# include  <stdio.h>
# include  <string.h>
#include "present24.h"

unsigned int permutation_inverse(unsigned int etat); //Fonction pour la permutation inverse
unsigned int substitution_inverse(unsigned int etat); //Fonction pour la substitution inverse
unsigned int dechiffrement(unsigned int etat, CLES cles); //Fonction pour déchiffrement un message chiffré