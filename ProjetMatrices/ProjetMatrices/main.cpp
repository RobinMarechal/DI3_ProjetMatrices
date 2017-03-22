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
	CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Desktop\\essai.txt");

	m.MATechelonnee().MATafficher();
}

void robin()
{
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\ProjetMatrices\\test.txt");
		cout << m << endl;
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}

#ifndef NDEBUG
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	signal(SIGABRT, &handleSIGABRT);
	CTestCMatrice::TMAstart();

#endif
}


int main(int argc, char * argv[])
{
	robin();
	//gregoire();

	return 0;
}