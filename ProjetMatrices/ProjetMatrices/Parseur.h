#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"

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
#endif