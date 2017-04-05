#include <iostream>
#include <fstream>

#include "Matrice.h"
#include "Parseur.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"

// pour desactiver les tests : #define NDEBUG
//#define NDEBUG

#ifndef NDEBUG

#include "TestsUnitaires.h"

#endif

/************************************************
Recuperer la valeur entree par l'utilisateur dans la 
console, jusqu'a ce que ce soit un nombre (reel ou entier)
*************************************************
Entree : rien
Necessite : rien
Sortie : le nombre entre par l'utilisateur dans la console.
Entraine : Le reste du programme est en stand by tant que
l'utilisateur ne rentre pas un nombre (entier ou reel).
*************************************************/
double recupererEntreeConsole()
{
	char pcEntree[1024] = { 0 };
	int iType;

	cout << "Veuillez entrer une valeur (entier ou reel) : ";

	std::cin >> pcEntree;
	iType = analyserType(pcEntree);

	while (iType != TAB_TYPE_ENTIER && iType != TAB_TYPE_REEL) 
	{
		std::cout << "La valeur doit etre un entier ou un reel. Veuillez recommencer : ";

		std::cin >> pcEntree;
		iType = analyserType(pcEntree);
	} 

	return atof(pcEntree);
}


int main(unsigned int argc, char * argv[])
{
	#ifndef NDEBUG
		// Lancement des tests unitaires
		CTestsUnitaires::UNIstart();
	#endif

	if (argc > 1)
	{
		double dValeur;

		CMatrice <double> * pcMATmatrices = new CMatrice<double>[argc-1];
		CMatrice <double> MATsomme,
						  MATsommeSoustraction,
						  MATproduit;

		unsigned int uiBoucle;

		// On entoure tout le for dans un try/catch car il est necessaire que toutes
		// les matrices soient correctement creees.
		try
		{
			for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
			{
				CTableauAssociatif TABtab = CParseur::PARparserFichier(argv[uiBoucle]);

				// On verifie que 'TypeMatrice' est bien precise dans le fichier
				if (TABtab.TABgetIndiceCle("TypeMatrice") == -1)
				{
					char pcMsg[1024];
					sprintf_s(pcMsg, 1024, "Le champs 'TypeMatrice' n'est pas specifie dans le fichier %s.", argv[uiBoucle]);

					// On profite du try/catch autour du for
					throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
				}

				// On verifie que la matrice est bien de type 'double'.
				if (strcmp(TABtab.TABgetValeurChaine("TypeMatrice"), "double") != 0 || strlen(TABtab.TABgetValeurChaine("TypeMatrice")) != strlen("double"))
				{
					char pcMsg[1024];
					sprintf_s(pcMsg, 1024, "La valeur de TypeMatrice n'est pas 'double' dans le fichier %s.", argv[uiBoucle]);

					// On profite du try/catch autour du for
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


		/*******************************************************
		 Affichage des matrices construites
		********************************************************/
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Matrices construites : " << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;

		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			std::cout << pcMATmatrices[uiBoucle] << std::endl;
		}


		// Recuperation de la valeur entree dans la console
		dValeur = recupererEntreeConsole();


		/*******************************************************
		 Affichage de la multiplication.
		********************************************************/
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Multiplication de chaque matrices par la valeur entree" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		
		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			CMatrice<double> MATtmp = pcMATmatrices[uiBoucle] * dValeur;
			std::cout << MATtmp << std::endl;
		}

		/*******************************************************
		 Affichage de la division.
		********************************************************/
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Division de chaque matrice par la valeur entree : " << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;

		for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++)
		{
			CMatrice<double> MATtmp = pcMATmatrices[uiBoucle] / dValeur;
			std::cout << MATtmp << std::endl;
		}


		/*******************************************************
		Affichage de l'addition de toutes les matrices entre elles.
		********************************************************/
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Addition de toutes les matrices entre elles :" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;

		MATsomme = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			MATsomme = MATsomme + pcMATmatrices[uiBoucle];
		}

		std::cout << MATsomme << std::endl;


		/*******************************************************
		Affichage de l'addition/soustraction alternee de toutes les matrices entre elles.
		M1 + M2 - M3 +M4 - ...
		********************************************************/
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Addition alternee de toutes les matrices entre elles (M1 + M2 - M3 + ...) :" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;

		MATsommeSoustraction = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			// -1 si uiBoucle impair, 1 sinon
			double iCoeff = -1;
			if (uiBoucle % 2 == 0)
				iCoeff = 1;
			MATsommeSoustraction = MATsommeSoustraction + iCoeff * pcMATmatrices[uiBoucle];
		}

		std::cout << MATsommeSoustraction << std::endl;


		/*******************************************************
		Affichage de la multiplication de toutes les matrices entre elles.
		********************************************************/
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Multiplication de toutes les matrices entre elles :" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		MATproduit = pcMATmatrices[0];

		for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++)
		{
			MATproduit = MATproduit * pcMATmatrices[uiBoucle];
		}
					
		std::cout << MATproduit << std::endl;
	}
	
	return 0;
}