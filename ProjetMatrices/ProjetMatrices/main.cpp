#include <iostream>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"
#include <signal.h>

// pour desactiver les tests : #define NDEBUG
// #define NDEBUG

#ifndef DEBUG

#include "TestCMatrice.h"

#endif


void handleSIGABRT(int iSignNb)
{
	cout << "TESTS ECHOUES !" << endl;
	exit(-1);
}


void gregoire()
{
	/*CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Desktop\\essai.txt");

	m.MATechelonnee().MATafficher();*/
}

void robin()
{
#ifndef NDEBUG

	CTestCMatrice::TMAstart();

#endif
}


int main(int argc, char * argv[])
{
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	signal(SIGABRT, &handleSIGABRT);

	robin();
	gregoire();

	return 0;
}