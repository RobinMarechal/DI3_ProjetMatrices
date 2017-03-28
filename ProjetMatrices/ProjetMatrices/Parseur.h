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
	Entrée : le chemin du fichier (char *).
	Nécessite : rien.
	Sortie : une instance de CTableauAssociatif.
	Entraîne : la récupération des informations contenues dans le fichier.
	******************************************/

	static CTableauAssociatif PARparserFichier(char * pcFichier);


	/*****************************************
	Analyseur syntaxique.
	******************************************
	Entrée : le chemin du fichier (char *).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'analyse des informations contenues dans le fichier,
			   soulève des exceptions si le format est incorrect.
	******************************************/

	static void PARanalyseSyntaxique(char * pcFichier);

private:

	/*****************************************
	Constructeur par défaut.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : initialisation de l'objet.
	******************************************/

	CParseur() {};


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien.
	******************************************/

	~CParseur() {};
};


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

#endif