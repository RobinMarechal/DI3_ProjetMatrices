#ifndef HERLPERS_H
#define HERLPERS_H

#include "constantes.h"

int getType(char * pcCle);

/*****************************************
Récupère une partie d'une chaîne de caractères.
******************************************
Entrée : un pointeur sur le début de la sous-chaîne,
un pointeur sur la fin de la sous-chaîne.
Nécessite : 'end' est située après 'start'.
Sortie : la sous-chaîne souhaitée (de type char *).
Entraîne : rien.
******************************************/

char * subString(const char * start, const char * end);


/*****************************************
Suppression de la casse.
******************************************
Entrée : une chaîne de caractères.
Nécessite : rien.
Sortie : rien.
Entraîne : la suppression de la casse sur la chaîne de caractères.
******************************************/

void toLowerString(char * pcStr);


/*****************************************
Suppression des espaces.
******************************************
Entrée : une chaîne de caractères.
Nécessite : rien.
Sortie : une chaîne de caractères.
Entraîne : la suppression des espaces au début et à la fin de la chaîne.
******************************************/

char * trim(char pcStr[]);

#endif;