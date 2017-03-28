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
#endif