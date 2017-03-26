#include <iostream>
#include <signal.h>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"
#include "TableauAssociatif.h"
#include <fstream>

// pour desactiver les tests : #define NDEBUG
 #define NDEBUG

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

	char * s2 = "..\\JePasse\\fichier01.txt";
	char * s3 = "..\\JePasse\\fichier02.txt";
	char * s4 = "..\\JePasse\\fichier03.txt";
	char * s5 = "..\\JePasse\\fichier04.txt";
	char * s6 = "..\\JePasse\\fichier05.txt";
	char * s7 = "..\\JePasse\\fichier06.txt";
	char * s8 = "..\\JePasse\\fichier07.txt";

	char * f1 = "..\\TestsSyntaxe\\s1.txt";
	char * f2 = "..\\TestsSyntaxe\\f2.txt";
/*
	try {
		CParseur::PARanalyseSyntaxique(f2);
		cout << "Succes" << endl;
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}

	cout << "fin" << endl;
	*/

	CMatrice<double> m;
	try {
		m = CParseur::PARparserFichier(f1);
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}

	cout << m << endl;


#ifndef NDEBUG

	// Permet d'éviter les messages de crash en cas d'appel a la fonction abort() par assert.h
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	// Récupère le signal SIGABRT envoyé par la fonction abort() et fait quelque chose... (un cout en l'occurrence)
	signal(SIGABRT, &handleSIGABRT);

	// Lancement des tests unitaires
	CTestCMatrice::TMAstart();

#endif
}


int main(unsigned int argc, char * argv[])
{
	robin();
	//gregoire();

	/*
		TODO :
		- automate pour les nombres dans CTableauAssociatif::TABestNumerique()
		- Vérifier les nombres négatifs
	*/

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