#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "TableauAssociatif.h"

class CParseur
{
public:
	
	/*****************************************
	Parse un fichier.
	******************************************
	Entr�e : le chemin du fichier (char *).
	N�cessite : rien.
	Sortie : une instance de CTableauAssociatif.
	Entra�ne : la r�cup�ration des informations contenues dans le fichier.
	******************************************/

	static CTableauAssociatif PARparserFichier(char * pcFichier);


	/*****************************************
	Analyseur syntaxique.
	******************************************
	Entr�e : le chemin du fichier (char *).
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'analyse des informations contenues dans le fichier,
			   soul�ve des exceptions si le format est incorrect.
	******************************************/

	static void PARanalyseSyntaxique(char * pcFichier);

private:

	/*****************************************
	Constructeur par d�faut.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : initialisation de l'objet.
	******************************************/

	CParseur() {};


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : rien.
	******************************************/

	~CParseur() {};
};


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

#endif