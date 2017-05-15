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
	
	return 0;
}