#ifndef CTESTCMATRICE_H
#define CTESTCMATRICE_H

#include <assert.h>
#include "Matrice.h"

class CTestCMatrice
{
private:

	/*****************************************
	Teste les accesseurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/
	void TMAtestAccesseurs();


	/*****************************************
	Teste l'op�rateur +.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateurPlus();


	/*****************************************
	Teste l'op�rateur -.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateurMoins();


	/*****************************************
	Teste l'op�rateur =.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateurEgal();


	/*****************************************
	Teste les op�rateur de comparaisons == et !=.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateursComparaison();


	/*****************************************
	Teste l'op�rateur *.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateurProduit();


	/*****************************************
	Teste l'op�rateur /.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateurDiviser();


	/*****************************************
	Teste l'op�rateur ^.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestOperateurPuissance();


	/*****************************************
	Teste de tous les op�rateurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les op�rateurs.
	******************************************/

	void TMAtestOperateurs();


	/*****************************************
	Teste le calcul du rang.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculRang();


	/*****************************************
	Teste l'�chelonnement.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculEchelonnee();


	/*****************************************
	Teste le calcul de la transpos�e.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculTransposee();


	/*****************************************
	Teste le calcul de la sous-matrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculSousMatrice();


	/*****************************************
	Teste le calcul du d�terminant.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculDet();


	/*****************************************
	Teste le calcul de la matrice inverse.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculInverse();


	/*****************************************
	Teste le calcul de la commatrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculCommatrice();


	/*****************************************
	Teste le calcul de la trace.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestCalculTrace();


	/*****************************************
	Teste tous les calculs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les calculs.
	******************************************/

	void TMAtestCalculs();


	/*****************************************
	Teste le test de matrice nulle.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstNulle();


	/*****************************************
	Teste le test de matrice triangulaire.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstTriangulaire();


	/*****************************************
	Teste le test de matrice triangulaire sup�rieur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstTriangulaireSuperieure();


	/*****************************************
	Teste le test de matrice triangulaire inf�rieur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstTriangulaireInferieure();


	/*****************************************
	Teste le test de matrice diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstDiagonale();


	/*****************************************
	Teste le test de matrice inversible.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstInversible();


	/*****************************************
	Teste le test de matrice sym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstSymetrique();


	/*****************************************
	Teste le test de matrice antisym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestEstAntiSymetrique();


	/*****************************************
	Teste le test de matrice carr�e.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests sur les m�thodes de test.
	******************************************/

	void TMAtestTestsMatriceCarree();
	

	/*****************************************
	Teste la cr�ation d'une matrice diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestDiag();


	/*****************************************
	Teste les exceptions.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'arr�t du programme si une assertion n'est pas v�rifi�e.
	******************************************/

	void TMAtestExceptions();

public:

	/*****************************************
	D�but des tests.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'appel de tous les tests.
	******************************************/

	static void TMAstart();
};

#endif // CTESTCMATRICE_H