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

		try
		{
			for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
			{
				CTableauAssociatif TABtab = CParseur::PARparserFichier(argv[uiBoucle]);

				// On vérifie que 'TypeMatrice' est bien précisé dans le fichier
				if (TABtab.TABgetIndiceCle("TypeMatrice") == -1)
				{
					char pcMsg[1024];
					sprintf_s(pcMsg, 1024, "Le champs 'TypeMatrice' n'est pas spécifié dans le fichier %s.", argv[uiBoucle]);

					throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
				}

				// On vérifie que la matrice est bien de type 'double'.
				if (strcmp(TABtab.TABgetValeurChaine("TypeMatrice"), "double") != 0 || strlen(TABtab.TABgetValeurChaine("TypeMatrice")) != strlen("double"))
				{
					char pcMsg[1024];
					sprintf_s(pcMsg, 1024, "La valeur de TypeMatrice n'est pas 'double' dans le fichier %s.", argv[uiBoucle]);

					throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
				}

				pcMATmatrices[uiBoucle - 1] = CMatrice<double>::MATgenerer(TABtab);
				std::cout << "Fichier " << uiBoucle << " lu." << std::endl;
			}
		} catch(Cexception EXCe)
		{
			std::cout << EXCe.EXCgetMessage() << std::endl;

			exit(EXIT_FAILURE);
		}

		std::cout << "Matrices construites : " << std::endl;
		 
		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			std::cout << pcMATmatrices[uiBoucle] << std::endl;
		}

		std::cout << "Veuillez entrer une valeur : ";

		std::cin >> iValeur;

		// Affichage de la multiplication.
		std::cout << "Matrice * Entier : " << std::endl;
		
		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			CMatrice<double> MATtmp = pcMATmatrices[uiBoucle] * iValeur;
			std::cout << MATtmp << std::endl;
		}

		// Affichage de la division.
		std::cout << "Matrice / Entier : " << std::endl;

		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			CMatrice<double> MATtmp = pcMATmatrices[uiBoucle] / iValeur;
			std::cout << MATtmp << std::endl;
		}

		// Affichage de l'addition de toutes les matrices entre elles.
		std::cout << "M1 + M2 + M3 +.... : " << std::endl;

		CMatrice <double> MATsomme = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			MATsomme = MATsomme + pcMATmatrices[uiBoucle];
		}

		std::cout << MATsomme << std::endl;

		// Affichage de l'opération M1 - M2 + M3 - M4...
		std::cout << "M1 - M2 + M3 - ... : " << std::endl;
		CMatrice <double> MATsommeSoustraction = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			// -1 si uiBoucle impair, 1 sinon
			double iCoeff = -1;
			if (uiBoucle % 2 == 0)
				iCoeff = 1;
			MATsommeSoustraction = MATsommeSoustraction + iCoeff * pcMATmatrices[uiBoucle];
		}

		std::cout << MATsommeSoustraction << std::endl;

		// Affichage de la multiplication de toutes les matrices entre elles.
		std::cout << "M1 * M2 * M3 *.... : " << std::endl;
		CMatrice <double> MATproduit = pcMATmatrices[0];

		try
		{
			for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
			{
				MATproduit = MATproduit * pcMATmatrices[uiBoucle];
			}
					
			std::cout << MATproduit << std::endl;

		} catch(Cexception EXCe)
		{
			std::cout << EXCe.EXCgetMessage() << std::endl;
		}

	}
	
	return 0;
}