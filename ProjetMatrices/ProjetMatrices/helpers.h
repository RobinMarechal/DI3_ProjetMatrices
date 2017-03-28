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
Entra�ne : (0 = entier) || (1 = r�el) || (3 = chaine)
******************************************/
int getType(char * pcCle);


/*****************************************
Extraction d'une sous chaine
******************************************
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
Entr�e : un pointeur sur la fin de la sous-cha�ne.
N�cessite : 'end' >= 'start'.
Sortie : la sous-cha�ne souhait�e (de type char *).
Entra�ne : Allocation dynamique d'un char * (malloc)
******************************************/
char * subString(const char * start, const char * end);


/*****************************************
transformation d'une chaine de carat�res en minuscule.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : la chaine est en minuscule.
******************************************/
void toLowerString(char * pcStr);


/*****************************************
Suppression des espaces en d�but et fin de chaine.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : une cha�ne de caract�res.
Entra�ne : la suppression des espaces au d�but et � la fin de la cha�ne.
******************************************/
char * trim(char pcStr[]);

#endif;