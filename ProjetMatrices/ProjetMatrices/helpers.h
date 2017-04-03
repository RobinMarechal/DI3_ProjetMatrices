#ifndef HERLPERS_H
#define HERLPERS_H

#include "helpers.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/*****************************************
Retourne le type correspondant � la chaine en param�tre
******************************************
Entr�e : la chaine � analyser
N�cessite : rien
Sortie : l'entier correspondant au type de la chaine
=> (0 = entier) || (1 = r�el) || (3 = chaine)
Entra�ne : rien
******************************************/
int analyserType(char * pcCle);


/*****************************************
Extraction d'une sous chaine
******************************************
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
Entr�e : un pointeur sur la fin de la sous-cha�ne.
N�cessite : pcStart >= pcEnd.
Sortie : la sous-cha�ne souhait�e (de type char *).
Entra�ne : Allocation dynamique d'un char * (malloc)
******************************************/
char * sousChaine(const char * pcStart, const char * pcEnd);


/*****************************************
transformation d'une chaine de carat�res en minuscule.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : Modification de la chaine point�e par pcStr
-> tous les caract�res sont en minuscule.
******************************************/
void transformerEnMinuscule(char * pcStr);


/*****************************************
Suppression des espaces en d�but et fin de chaine.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : Une copie de la chaine de caract�re sans les espaces de d�but et de fin.
Entra�ne : rien.
******************************************/
char * supprimerEspaces(char pcStr[]);

#endif;