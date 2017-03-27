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
	
	static CTableauAssociatif PARparserFichier(char * pcFichier);
	static void PARanalyseSyntaxique(char * pcFichier);

private:
	static void PARremplirMatrice(CMatrice<double> & MATmatrice, char * pcStrMatrice);
	CParseur() {};
	~CParseur() {};
};


char * subString(const char * start, const char * end);
void toLowerString(char * pcStr);
char * trim(char pcStr[]);

#endif