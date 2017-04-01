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

	argc = 2;
	argv[1] = "C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\ProjetMatrices\\JePassePas\\fichier123.txt";

	#ifndef NDEBUG
		// Lancement des tests unitaires
		CTestCMatrice::TMAstart();
	#endif


	if (argc > 1)
	{
		double iValeur;

		CMatrice <double> * pcMATmatrices = new CMatrice<double>[argc];

		unsigned int uiBoucle;

		try
		{

			for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
			{
				CTableauAssociatif TABtab = CParseur::PARparserFichier(argv[uiBoucle]);

				// On v�rifie que 'TypeMatrice' est bien pr�cis� dans le fichier
				if (TABtab.TABgetIndiceCle("TypeMatrice") == -1)
				{
					char pcMsg[1024];
					sprintf_s(pcMsg, 1024, "Le champs 'TypeMatrice' n'est pas sp�cifi� dans le fichier %s.", argv[uiBoucle]);

					throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
				}

				// On v�rifie que la matrice est bien de type 'double'.
				if (strcmp(TABtab.TABgetValeurChaine("TypeMatrice"), "double") != 0 || strlen(TABtab.TABgetValeurChaine("TypeMatrice")) != strlen("double"))
				{
					char pcMsg[1024];
					sprintf_s(pcMsg, 1024, "La valeur de TypeMatrice n'est pas 'double' dans le fichier %s.", argv[uiBoucle]);

					throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
				}

				pcMATmatrices[uiBoucle - 1] = CMatrice<double>::MATgenerer(TABtab);
			}
		} catch(Cexception EXCe)
		{
			cout << EXCe.EXCgetMessage() << endl;

			exit(EXIT_FAILURE);
		}

		cout << "Matrices construites : " << endl;
		 
		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			cout << pcMATmatrices[uiBoucle] << endl;
		}

		cout << "Veuillez entrer une valeur : ";

		cin >> iValeur;

		// Affichage de la multiplication.
		cout << "Matrice * Entier : " << endl;
		
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

		// Affichage de l'op�ration M1 - M2 + M3 - M4...
		cout << "M1 - M2 + M3 - ... : " << endl;
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

		try
		{
			for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
			{
				MATproduit = MATproduit * pcMATmatrices[uiBoucle];
			}
					
			cout << MATproduit << endl;

		} catch(Cexception EXCe)
		{
			cout << EXCe.EXCgetMessage() << endl;
		}

	}
	
	return 0;
}