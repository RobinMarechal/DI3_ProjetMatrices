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

	CMatrice<double> m(4, 4);

	m(0, 0) = 1;
	m(0, 1) = 1;
	m(0, 2) = 1;
	m(0, 3) = 1;

	m(1, 0) = 1;
	m(1, 1) = 5;
	m(1, 2) = 5;
	m(1, 3) = 5;

	m(2, 0) = 1;
	m(2, 1) = 5;
	m(2, 2) = 14;
	m(2, 3) = 14;

	m(3, 0) = 1;
	m(3, 1) = 5;
	m(3, 2) = 14;
	m(3, 3) = 15;

	cout << "Matrice M :" << endl;
	cout << m << endl;

	COperationMatrice<double> t;
	CMatrice<double> m2 = t.OPMfactorisationCholeski(m);

	cout << "Choleski : " << endl;
	cout << m2 << endl;

	return 0;
}
