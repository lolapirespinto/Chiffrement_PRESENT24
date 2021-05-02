#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*structure pour le cadencement des 11 clés*/
typedef struct cles{
    unsigned long long K[11];
}CLES;

/*___________FONCTIONS POUR LE CHIFFREMENT___________________*/
int permutation(int etat); //Fonction pour la permutation
int substitution(int etat); //Fonction pour la substitution
int chiffrement(char *message, char *clee_maitre); //Fonction qui chiffre un message 
CLES cadencement(char *cle_maitre);

/*_______________FONCTIONS DE CONVERSION___________________*/
int hexa_to_dec(char *mot); //Fonction pour convertir un héxa en décimale