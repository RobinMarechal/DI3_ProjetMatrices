#include <iostream>
#include <fstream>

#include "Matrice.h"
#include "Parseur.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"

using namespace std;

// pour desactiver les tests : #define NDEBUG
//#define NDEBUG

#ifndef NDEBUG

#include "TestCMatrice.h"

#endif


int main(unsigned int argc, char * argv[])
{
	#ifndef NDEBUG
		// Lancement des tests unitaires
		CTestCMatrice::TMAstart();
	#endif

	if (argc > 1)
	{
		double iValeur;

		CMatrice <double> * pcMATmatrices = new CMatrice<double>[argc];

		unsigned int uiBoucle;

		for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
		{
			CTableauAssociatif TABtab = CParseur::PARparserFichier(argv[uiBoucle]);
			pcMATmatrices[uiBoucle - 1] = CMatrice<double>();
			pcMATmatrices[uiBoucle - 1] = CMatrice<double>::MATgenerer(TABtab);
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
	
	return 0;
}