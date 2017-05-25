#include <iostream>
#include <fstream>

#include "Matrice.h"
#include "Parseur.h"
#include "TableauAssociatif.h"
#include "helpers.h"


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
	char pcEntree[1024] = {0};
	int iType;

	cout << "Veuillez entrer une valeur (entier ou reel) : ";

	std::cin >> pcEntree;
	iType = analyserType(pcEntree);

	while (iType != TYPE_ENTIER && iType != TYPE_REEL)
	{
		std::cout << "La valeur doit etre un entier ou un reel. Veuillez recommencer : ";

		std::cin >> pcEntree;
		iType = analyserType(pcEntree);
	}

	return atof(pcEntree);
}


int main(unsigned int argc, char* argv[])
{
#ifndef NDEBUG
	// Lancement des tests unitaires
	CTestsUnitaires::UNIstart();
#endif

	unsigned int uiBoucle;

	for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			CMatrice<double> MATmatrice;
			CMatrice<double> MATresultat;
			COperationMatrice<double> OPMoperation;
			CTableauAssociatif* TABtab = CParseur::PARparserFichier(argv[uiBoucle]);

			// On verifie que 'TypeMatrice' est bien precise dans le fichier
			if (TABtab->TABgetIndiceCle("TypeMatrice") == -1)
			{
				char pcMsg[1024];
				sprintf_s(pcMsg, 1024, "Le champs 'TypeMatrice' n'est pas specifie dans le fichier %s.", argv[uiBoucle]);

				// On profite du try/catch autour du for
				throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
			}

			// On verifie que la matrice est bien de type 'double'.
			if (strcmp(TABtab->TABgetValeurChaine("TypeMatrice"), "double") != 0 || strlen(TABtab->TABgetValeurChaine("TypeMatrice")) != strlen("double"))
			{
				char pcMsg[1024];
				sprintf_s(pcMsg, 1024, "La valeur de TypeMatrice n'est pas 'double' dans le fichier %s.", argv[uiBoucle]);

				// On profite du try/catch autour du for
				throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
			}

			MATmatrice = CMatrice<double>::MATgenerer(TABtab);

			delete TABtab;

			cout << "Fichier " << uiBoucle << " lu." << endl;

			// Calculs

			cout << "----------------------------------------------------------" << endl;
			cout << "Matrice construite : " << endl;
			cout << "----------------------------------------------------------" << endl;

			cout << MATmatrice << endl;

			try
			{
				MATresultat = OPMoperation.OPMfactorisationCholeski(MATmatrice);

				cout << "----------------------------------------------------------" << endl;
				cout << "Matrice L de la factorisation de Choleski : " << endl;
				cout << "----------------------------------------------------------" << endl;

				cout << MATresultat;
			}
			catch (Cexception EXCe)
			{
				cout << EXCe.EXCgetMessage();
			}
		}
		catch (Cexception EXCe)
		{
			cout << "Une erreur est survenue lors de la lecture du fichier num�ro " << uiBoucle << "." << endl;
			cout << EXCe.EXCgetMessage() << endl;
		}
	}

	return 0;
}
