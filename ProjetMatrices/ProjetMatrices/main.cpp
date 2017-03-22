#include <iostream>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"

// pour desactiver les tests : #define NDEBUG
 #define NDEBUG

#ifndef DEBUG

#include "TestCMatrice.h"

#endif


void gregoire()
{
	CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Desktop\\essai.txt");

	m.MATechelonnee().MATafficher();
}

void robin()
{
#ifndef NDEBUG

	CTestCMatrice::TMAstart();

#endif
}


int main(int argc, char * argv[])
{
	robin();
	gregoire();

	return 0;
}