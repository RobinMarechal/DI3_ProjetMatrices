#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

class CParseur
{
	public:
	
	/*static*/ CMatrice <double> PARparserFichier(char * pcFichier);

	private:

	CParseur();
	~CParseur();

	unsigned int uiPARnombreLignes;
	unsigned int uiPARnombreColonnes;
};

#endif