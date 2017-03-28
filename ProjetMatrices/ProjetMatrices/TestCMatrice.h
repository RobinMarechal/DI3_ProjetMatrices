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
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void TMAtestAccesseurs();


	/*****************************************
	Teste l'opérateur +.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateurPlus();


	/*****************************************
	Teste l'opérateur -.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateurMoins();


	/*****************************************
	Teste l'opérateur =.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateurEgal();


	/*****************************************
	Teste les opérateur de comparaisons == et !=.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateursComparaison();


	/*****************************************
	Teste l'opérateur *.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateurProduit();


	/*****************************************
	Teste l'opérateur /.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateurDiviser();


	/*****************************************
	Teste l'opérateur ^.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestOperateurPuissance();


	/*****************************************
	Teste de tous les opérateurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les opérateurs.
	******************************************/

	void TMAtestOperateurs();


	/*****************************************
	Teste le calcul du rang.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculRang();


	/*****************************************
	Teste l'échelonnement.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculEchelonnee();


	/*****************************************
	Teste le calcul de la transposée.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculTransposee();


	/*****************************************
	Teste le calcul de la sous-matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculSousMatrice();


	/*****************************************
	Teste le calcul du déterminant.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculDet();


	/*****************************************
	Teste le calcul de la matrice inverse.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculInverse();


	/*****************************************
	Teste le calcul de la commatrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculCommatrice();


	/*****************************************
	Teste le calcul de la trace.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestCalculTrace();


	/*****************************************
	Teste tous les calculs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les calculs.
	******************************************/

	void TMAtestCalculs();


	/*****************************************
	Teste le test de matrice nulle.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstNulle();


	/*****************************************
	Teste le test de matrice triangulaire.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstTriangulaire();


	/*****************************************
	Teste le test de matrice triangulaire supérieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstTriangulaireSuperieure();


	/*****************************************
	Teste le test de matrice triangulaire inférieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstTriangulaireInferieure();


	/*****************************************
	Teste le test de matrice diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstDiagonale();


	/*****************************************
	Teste le test de matrice inversible.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstInversible();


	/*****************************************
	Teste le test de matrice symétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstSymetrique();


	/*****************************************
	Teste le test de matrice antisymétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestEstAntiSymetrique();


	/*****************************************
	Teste le test de matrice carrée.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les méthodes de test.
	******************************************/

	void TMAtestTestsMatriceCarree();
	

	/*****************************************
	Teste la création d'une matrice diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestDiag();


	/*****************************************
	Teste les exceptions.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/

	void TMAtestExceptions();

public:

	/*****************************************
	Début des tests.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests.
	******************************************/

	static void TMAstart();
};

#endif // CTESTCMATRICE_H