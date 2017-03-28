#ifndef HERLPERS_H
#define HERLPERS_H

#include "constantes.h"

int getType(char * pcCle);

/*****************************************
R�cup�re une partie d'une cha�ne de caract�res.
******************************************
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
un pointeur sur la fin de la sous-cha�ne.
N�cessite : 'end' est situ�e apr�s 'start'.
Sortie : la sous-cha�ne souhait�e (de type char *).
Entra�ne : rien.
******************************************/

char * subString(const char * start, const char * end);


/*****************************************
Suppression de la casse.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : la suppression de la casse sur la cha�ne de caract�res.
******************************************/

void toLowerString(char * pcStr);


/*****************************************
Suppression des espaces.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : une cha�ne de caract�res.
Entra�ne : la suppression des espaces au d�but et � la fin de la cha�ne.
******************************************/

char * trim(char pcStr[]);

#endif;