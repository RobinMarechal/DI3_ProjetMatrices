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



/*************************************************
Classe permettant de cr�er un CTableau associatif
� partir d'un fichier texte contenant des donn�es.
***************************************************/
class CParseur
{
public:

	/*****************************************
	Parse un fichier.
	******************************************
	Entr�e : le chemin du fichier � parser.
	N�cessite : rien.
	Sortie : une instance de CTableauAssociatif contenant les donn�es du fichier allou�e sur le tas.
	Entra�ne : soul�ve une Cexception en cas d'erreur de syntaxe dans le fichier
	Entra�ne : Allocation d'une chaine de caract�re (via new).
	******************************************/
	static CTableauAssociatif * PARparserFichier(char * pcFichier);


	/*****************************************
	Analyseur syntaxique.
	******************************************
	Entr�e : le chemin du fichier.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : soul�ve une Cexception en cas d'erreur de syntaxe dans le fichier
	******************************************/
	static void PARanalyseSyntaxique(char * pcFichier);


	/*****************************************
	Extraire la partie gauche d'une ligne du fichier
	******************************************
	Entr�e : la ligne du fichier � analyser
	N�cessite : la ligne contient un (et un seul) '='.
	Sortie : la partie gauche de la ligne allou�e sur le tas.
	Entra�ne : Allocation d'une chaine de caract�re (via new).
	******************************************/
	static char * PARextraireBalise(char * pcLigne);


	/*****************************************
	Extraire la partie droite d'une ligne du fichier
	******************************************
	Entr�e : la ligne du fichier � analyser
	N�cessite : la ligne contient un (et un seul) '='.
	Sortie : la partie droite de la ligne allou�e sur le tas.
	Entra�ne : Allocation d'une chaine de caract�re (via new).
	******************************************/
	static char *  PARextraireValeur(char * pcLigne);
};
#endif