#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

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

private:

	static const char * pcBalises[4];

	static void PARtoLowerString(char * pcStr);
	static void PARremplirMatrice(CMatrice<double> & MATmatrice, unsigned int uiNbLignes, unsigned int uiNbColonnes, char * pcStrMatrice);
	CParseur() {};
	~CParseur() {};
};

#endif