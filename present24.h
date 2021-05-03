#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*structure pour le cadencement des 11 clés*/
typedef struct cles{
    unsigned long long K[11];
}CLES;

/*___________FONCTIONS POUR LE CHIFFREMENT___________________*/
CLES cadencement(char *cle_maitre); //Fonction pour obtenir les 11 sous-clés à partir de la clée maître
int permutation(int etat); //Fonction pour la permutation
int substitution(int etat); //Fonction pour la substitution
int chiffrement(int etat, CLES cles); //Fonction qui chiffre un message 

/*_______________FONCTIONS DE CONVERSION___________________*/
int hexa_to_dec(char *mot); //Fonction pour convertir un héxa en décimale