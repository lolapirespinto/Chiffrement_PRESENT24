#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int hexa_to_dec(char *mot); //Fonction pour convertir un héxa en décimale
int permutation(int etat); //Fonction pour la permutation
int substitution(int etat); //Fonction pour la substitution
void chiffrement(char *message, char *clee); //Fonction pour le chiffrement