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
	
	static CTableauAssociatif PARparserFichier(char * pcFichier);
	static void PARanalyseSyntaxique(char * pcFichier);

private:
	static void PARremplirMatrice(CMatrice<double> & MATmatrice, char * pcStrMatrice);
	CParseur() {};
	~CParseur() {};
};

#endif