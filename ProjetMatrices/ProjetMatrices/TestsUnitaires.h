#ifndef CTestsUnitaires_H
#define CTestsUnitaires_H

#include <assert.h>
#include "Matrice.h"
#include "helpers.h"

#include "TableauAssociatif.h"
#include "OperationMatrice.h"
#include "TesteurMatrice.h"

class CTestsUnitaires
{
public:


	/*****************************************
	Constructeur par d�faut
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la cr�ation de l'objet.
	******************************************/
	CTestsUnitaires(); 

	/*****************************************
	Teste les accesseurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestAccesseurs() const;


	/*****************************************
	Teste l'op�rateur +.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurPlus() const;


	/*****************************************
	Teste l'op�rateur -.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurMoins() const;


	/*****************************************
	Teste l'op�rateur =.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurEgal() const;


	/*****************************************
	Teste les op�rateur de comparaisons == et !=.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateursComparaison() const;


	/*****************************************
	Teste l'op�rateur *.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurProduit() const;


	/*****************************************
	Teste l'op�rateur /.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurDiviser() const;


	/*****************************************
	Teste l'op�rateur ^.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestOperateurPuissance() const;


	/*****************************************
	Teste de tous les op�rateurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les op�rateurs.
	******************************************/
	void UNItestOperateurs() const;


	/*****************************************
	Teste le calcul du rang.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculRang() const;


	/*****************************************
	Teste l'�chelonnement.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculEchelonnee() const;


	/*****************************************
	Teste le calcul de la transpos�e.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculTransposee() const;


	/*****************************************
	Teste le calcul de la sous-matrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculSousMatrice() const;


	/*****************************************
	Teste le calcul du d�terminant.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculDet() const;


	/*****************************************
	Teste le calcul de la matrice inverse.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculInverse() const;


	/*****************************************
	Teste le calcul de la commatrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculCommatrice() const;


	/*****************************************
	Teste le calcul de la trace.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCalculTrace() const;


	/*****************************************
	Teste tous les calculs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les calculs.
	******************************************/
	void UNItestCalculs() const;


	/*****************************************
	Teste le test de matrice nulle.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstNulle() const;


	/*****************************************
	Teste le test de matrice triangulaire.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstTriangulaire() const;


	/*****************************************
	Teste le test de matrice triangulaire sup�rieur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstTriangulaireSuperieure() const;


	/*****************************************
	Teste le test de matrice triangulaire inf�rieur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstTriangulaireInferieure() const;


	/*****************************************
	Teste le test de matrice diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstDiagonale() const;


	/*****************************************
	Teste le test de matrice inversible.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstInversible() const;


	/*****************************************
	Teste le test de matrice sym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstSymetrique() const;


	/*****************************************
	Teste le test de matrice antisym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestEstAntiSymetrique() const;


	/*****************************************
	Teste le test de matrice carr�e.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les m�thodes de test.
	******************************************/
	void UNItestTestsMatriceCarree() const;
	

	/*****************************************
	Teste la cr�ation d'une matrice diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestDiag() const;


	/*****************************************
	Teste les exceptions.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestExceptions() const;



	/*****************************************
	Teste le fonctionnement global de CTableauAssociatif
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestsCTableauAssociatif() const;



	/*****************************************
	Test du calcul de la factorisation de Choleski
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void UNItestCholeski() const;


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