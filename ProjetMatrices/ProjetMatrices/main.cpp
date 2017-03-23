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
}


void gregoire()
{
	CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Desktop\\essai.txt");

	m.MATechelonnee().MATafficher();
}

void robin()
{

#ifndef NDEBUG

	// Permet d'éviter les messages de crash en cas d'appel a la fonction abort() par assert.h
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	// Récupère le signal SIGABRT envoyé par la fonction abort() et fait quelque chose... (un cout en l'occurrence)
	signal(SIGABRT, &handleSIGABRT);

	// Lancement des tests unitaires
	CTestCMatrice::TMAstart();

#endif
}


int main(int argc, char * argv[])
{
	robin();
	//gregoire();

	return 0;
}