#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

class CParseur
{
public:
	
	static CMatrice<double> PARparserFichier(char * pcFichier);

private:
	static void PARtoLowerString(char * pcStr);
	static void PARremplirMatrice(CMatrice<double> & MATmatrice, unsigned int uiNbLignes, unsigned int uiNbColonnes, char * pcStrMatrice);
	CParseur();
	~CParseur();
};

#endif