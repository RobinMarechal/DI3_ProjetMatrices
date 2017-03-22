#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

class CParseur
{
public:
	
	static CMatrice<double> PARparserFichier(char * pcFichier);

private:
	static void PARtoLowerString(char * pcStr);
	CParseur();
	~CParseur();
}

#endif