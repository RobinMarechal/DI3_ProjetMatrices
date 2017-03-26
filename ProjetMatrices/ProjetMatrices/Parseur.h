#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"

#define NB_BALISES 4
#define NB_VALEURS_NUMERIQUES 2
#define INDICE_PREMIERE_LIGNE_A_VALEUR_NUMERIQUE 1
#define VALEURS_NUMERIQUES_INDICE_NB_LIGNES 0
#define VALEURS_NUMERIQUES_INDICE_NB_COLONNES 1
#define VALEURS_BALISES_INDICE_MATRICE 3

class CParseur
{
public:
	
	static CMatrice<double> PARparserFichier(char * pcFichier);
	static void PARanalyseSyntaxique(char * pcFichier);

private:

	static const char * ppcBalises[4];

	static void PARremplirMatrice(CMatrice<double> & MATmatrice, char * pcStrMatrice);
	CParseur() {};
	~CParseur() {};
};


char * subString(const char * start, const char * end);
char * trim(char * pcStr);
void toLowerString(char * pcStr);

#endif