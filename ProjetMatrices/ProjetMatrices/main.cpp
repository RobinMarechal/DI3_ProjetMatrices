#include <iostream>
#include <signal.h>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"
#include "TableauAssociatif.h"

// pour desactiver les tests : #define NDEBUG
// #define NDEBUG

#ifndef NDEBUG

#include "TestCMatrice.h"

#endif

void handleSIGABRT(int iSignNb)
{
	cout << "TESTS ECHOUES !" << endl;
}


void gregoire()
{
	//CMatrice <double> m = CParseur::PARparserFichier("..\\JePasse\\fichier04.txt");
	//m.MATafficher();
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
	//robin();
	//gregoire();

	if (argc > 1)
	{
		int iValeur;

		CMatrice <double> * pcMATmatrices = (CMatrice <double> *) malloc(argc * sizeof(CMatrice <double>));

		unsigned int uiBoucle;

		for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
		{
			pcMATmatrices[uiBoucle - 1] = CParseur::PARparserFichier(argv[uiBoucle]);
		}

		cout << "Veuillez entrer une valeur : ";

		cin >> iValeur;

		// Affichage de la multiplication.

		for (uiBoucle = 0; uiBoucle < argc; uiBoucle++)
		{
			(pcMATmatrices[uiBoucle] * iValeur).MATafficher();
		}

		// Affichage de la division.

		for (uiBoucle = 0; uiBoucle < argc; uiBoucle++)
		{
			(pcMATmatrices[uiBoucle] / iValeur).MATafficher();
		}

		// Affichage de l'addition de toutes les matrices entre elles.

		CMatrice <double> MATmatrice1;

		for (uiBoucle = 0; uiBoucle < argc; uiBoucle++)
		{
			MATmatrice1 = MATmatrice1 + pcMATmatrices[uiBoucle];
		}

		MATmatrice1.MATafficher();

		// Affichage de l'opération M1 - M2 + M3 - M4...

		CMatrice <double> MATmatrice2;

		for (uiBoucle = 0; uiBoucle < argc; uiBoucle++)
		{
			if (uiBoucle % 2 == 0)
			{
				MATmatrice2 = MATmatrice2 + pcMATmatrices[uiBoucle];
			}

			else
			{
				MATmatrice2 = MATmatrice2 - pcMATmatrices[uiBoucle];
			}
		}

		(MATmatrice2).MATafficher();

		// Affichage de la multiplication de toutes les matrices entre elles.

		CMatrice <double> MATmatrice3;

		for (uiBoucle = 0; uiBoucle < argc; uiBoucle++)
		{
			MATmatrice3 = MATmatrice3 * pcMATmatrices[uiBoucle];
		}

		(MATmatrice3).MATafficher();
	}

	return 0;
}