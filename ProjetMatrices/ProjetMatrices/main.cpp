#include <iostream>
#include <signal.h>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"
#include "TableauAssociatif.h"
#include <fstream>
#include "helpers.h"
#include "constantes.h"

// pour desactiver les tests : #define NDEBUG
 //#define NDEBUG

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

	/*CMatrice<double> m;
	try {
		m = CParseur::PARparserFichier(f1);
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}

	cout << m << endl;*/
	try {
		CTableauAssociatif TABtab = CParseur::PARparserFichier(f1);
		cout << TABtab.TABgetValeurChaine("Matrice") << endl;
		if (strcmp(TABtab.TABgetValeurChaine("TypeMatrice"), "double") != 0)
		{
			throw Cexception(0, "TypeMatrice != 'double'.");
		}

		CMatrice<double> m = CMatrice<double>::MATparser(TABtab);

		cout << m << endl;
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}


#ifndef NDEBUG

	// Permet d'éviter les messages de crash en cas d'appel a la fonction abort() par assert.h
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	// Récupère le signal SIGABRT envoyé par la fonction abort() et fait quelque chose... (un cout en l'occurrence)
	signal(SIGABRT, &handleSIGABRT);

	// Lancement des tests unitaires
	CTestCMatrice::TMAstart();

#endif
}


int main(unsigned int argc, char * argv2[])
{
	//robin();
	//gregoire();

	cout << "1\t=>\t" << getType("1") << endl;
	cout << "1.50\t=>\t" << getType("1.50") << endl;
	cout << "1.\t=>\t" << getType("1.") << endl;
	cout << ".1\t=>\t" << getType(".1") << endl;
	cout << "-50.23\t=>\t" << getType("-50.23") << endl;
	cout << "-50\t=>\t" << getType("-50") << endl;
	cout << "-0.23\t=>\t" << getType("-0.23") << endl;
	cout << "-0.23\t=>\t" << getType("-0.23") << endl;
	cout << "27e+23\t=>\t" << getType("27e+23") << endl;
	cout << "32e-23\t=>\t" << getType("32e-23") << endl;
	cout << "32e-23\t=>\t" << getType("abc") << endl;

	/*
		TODO :
		- automate pour les nombres dans CTableauAssociatif::TABestNumerique()
		- Vérifier les nombres négatifs
	*/
	/*
	argc = 4;
	char * argv[4] = { "", "..\\01.txt", "..\\02.txt", "..\\03.txt" };
	
	cout << argc << endl;
	for (unsigned int i = 1; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	
	
	if (argc > 1)
	{
		double iValeur;

		CMatrice <double> * pcMATmatrices = new CMatrice<double>[argc];

		unsigned int uiBoucle;

		for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
		{
			CTableauAssociatif TABtab = CParseur::PARparserFichier(argv[uiBoucle]);
			pcMATmatrices[uiBoucle - 1] = CMatrice<double>();
			pcMATmatrices[uiBoucle - 1] = CMatrice<double>::MATparser(TABtab);
		}

		cout << "Matrices construites : " << endl;

		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			cout << pcMATmatrices[uiBoucle] << endl;
		}

		cout << "Veuillez entrer une valeur : ";

		cin >> iValeur;

		// Affichage de la multiplication.
		cout << "Matrice + Entier : " << endl;
		
		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			CMatrice<double> MATtmp = pcMATmatrices[uiBoucle] * iValeur;
			cout << MATtmp << endl;
		}

		// Affichage de la division.
		cout << "Matrice / Entier : " << endl;

		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			CMatrice<double> MATtmp = pcMATmatrices[uiBoucle] / iValeur;
			cout << MATtmp << endl;
		}

		// Affichage de l'addition de toutes les matrices entre elles.
		cout << "M1 + M2 + M3 +.... : " << endl;

		CMatrice <double> MATsomme = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			MATsomme = MATsomme + pcMATmatrices[uiBoucle];
		}

		cout << MATsomme << endl;

		// Affichage de l'opération M1 - M2 + M3 - M4...
		cout << "M1 + M2 - M3 +.... : " << endl;
		CMatrice <double> MATsommeSoustraction = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			// -1 si uiBoucle impair, 1 sinon
			double iCoeff = -1;
			if (uiBoucle % 2 == 0)
				iCoeff = 1;
			MATsommeSoustraction = MATsommeSoustraction + iCoeff * pcMATmatrices[uiBoucle];
		}

		cout << MATsommeSoustraction << endl;

		// Affichage de la multiplication de toutes les matrices entre elles.
		cout << "M1 * M2 * M3 *.... : " << endl;
		CMatrice <double> MATproduit = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			MATproduit = MATproduit * pcMATmatrices[uiBoucle];
		}

		cout << MATproduit << endl;
	}
	*/
	return 0;
}