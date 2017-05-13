#ifndef CTestsUnitaires_H
#define CTestsUnitaires_H

#include <assert.h>
#include "Matrice.h"
#include "helpers.h"
#include "constantes.h"
#include "TableauAssociatif.h"
#include "OperationMatrice.h"

class CTestsUnitaires
{
private:


	/*****************************************
	Constructeur par d�faut
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la cr�ation de l'objet.
	******************************************/
	CTestsUnitaires(); // priv�e pour empecher la cr�ation d'un objet CTestsUnitaires de l'ext�rieur.

	/*****************************************
	Teste les accesseurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestAccesseurs();


	/*****************************************
	Teste l'op�rateur +.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurPlus();


	/*****************************************
	Teste l'op�rateur -.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurMoins();


	/*****************************************
	Teste l'op�rateur =.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurEgal();


	/*****************************************
	Teste les op�rateur de comparaisons == et !=.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateursComparaison();


	/*****************************************
	Teste l'op�rateur *.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurProduit();


	/*****************************************
	Teste l'op�rateur /.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurDiviser();


	/*****************************************
	Teste l'op�rateur ^.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurPuissance();


	/*****************************************
	Teste de tous les op�rateurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les op�rateurs.
	******************************************/
	void UNItestOperateurs();


	/*****************************************
	Teste le calcul du rang.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculRang();


	/*****************************************
	Teste l'�chelonnement.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculEchelonnee();


	/*****************************************
	Teste le calcul de la transpos�e.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculTransposee();


	/*****************************************
	Teste le calcul de la sous-matrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculSousMatrice();


	/*****************************************
	Teste le calcul du d�terminant.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculDet();


	/*****************************************
	Teste le calcul de la matrice inverse.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculInverse();


	/*****************************************
	Teste le calcul de la commatrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculCommatrice();


	/*****************************************
	Teste le calcul de la trace.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculTrace();


	/*****************************************
	Teste tous les calculs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les calculs.
	******************************************/
	void UNItestCalculs();


	/*****************************************
	Teste le test de matrice nulle.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstNulle();


	/*****************************************
	Teste le test de matrice triangulaire.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstTriangulaire();


	/*****************************************
	Teste le test de matrice triangulaire sup�rieur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstTriangulaireSuperieure();


	/*****************************************
	Teste le test de matrice triangulaire inf�rieur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstTriangulaireInferieure();


	/*****************************************
	Teste le test de matrice diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstDiagonale();


	/*****************************************
	Teste le test de matrice inversible.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstInversible();


	/*****************************************
	Teste le test de matrice sym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstSymetrique();


	/*****************************************
	Teste le test de matrice antisym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstAntiSymetrique();


	/*****************************************
	Teste le test de matrice carr�e.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les m�thodes de test.
	******************************************/
	void UNItestTestsMatriceCarree();
	

	/*****************************************
	Teste la cr�ation d'une matrice diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestDiag();


	/*****************************************
	Teste les exceptions.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestExceptions();



	/*****************************************
	Teste le fonctionnement global de CTableauAssociatif
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestsCTableauAssociatif();

public:

	/*****************************************
	D�but des tests.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests.
	******************************************/
	static void UNIstart();
};

#endif // CTestsUnitaires_H