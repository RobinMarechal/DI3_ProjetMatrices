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
	Constructeur par défaut
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la création de l'objet.
	******************************************/
	CTestsUnitaires(); // privée pour empecher la création d'un objet CTestsUnitaires de l'extérieur.

	/*****************************************
	Teste les accesseurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestAccesseurs();


	/*****************************************
	Teste l'opérateur +.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurPlus();


	/*****************************************
	Teste l'opérateur -.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurMoins();


	/*****************************************
	Teste l'opérateur =.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurEgal();


	/*****************************************
	Teste les opérateur de comparaisons == et !=.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateursComparaison();


	/*****************************************
	Teste l'opérateur *.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurProduit();


	/*****************************************
	Teste l'opérateur /.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurDiviser();


	/*****************************************
	Teste l'opérateur ^.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurPuissance();


	/*****************************************
	Teste de tous les opérateurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les opérateurs.
	******************************************/
	void UNItestOperateurs();


	/*****************************************
	Teste le calcul du rang.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculRang();


	/*****************************************
	Teste l'échelonnement.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculEchelonnee();


	/*****************************************
	Teste le calcul de la transposée.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculTransposee();


	/*****************************************
	Teste le calcul de la sous-matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculSousMatrice();


	/*****************************************
	Teste le calcul du déterminant.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculDet();


	/*****************************************
	Teste le calcul de la matrice inverse.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculInverse();


	/*****************************************
	Teste le calcul de la commatrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculCommatrice();


	/*****************************************
	Teste le calcul de la trace.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculTrace();


	/*****************************************
	Teste tous les calculs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les calculs.
	******************************************/
	void UNItestCalculs();


	/*****************************************
	Teste le test de matrice nulle.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstNulle();


	/*****************************************
	Teste le test de matrice triangulaire.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstTriangulaire();


	/*****************************************
	Teste le test de matrice triangulaire supérieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstTriangulaireSuperieure();


	/*****************************************
	Teste le test de matrice triangulaire inférieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstTriangulaireInferieure();


	/*****************************************
	Teste le test de matrice diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstDiagonale();


	/*****************************************
	Teste le test de matrice inversible.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstInversible();


	/*****************************************
	Teste le test de matrice symétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstSymetrique();


	/*****************************************
	Teste le test de matrice antisymétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstAntiSymetrique();


	/*****************************************
	Teste le test de matrice carrée.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les méthodes de test.
	******************************************/
	void UNItestTestsMatriceCarree();
	

	/*****************************************
	Teste la création d'une matrice diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestDiag();


	/*****************************************
	Teste les exceptions.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestExceptions();



	/*****************************************
	Teste le fonctionnement global de CTableauAssociatif
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestsCTableauAssociatif();

public:

	/*****************************************
	Début des tests.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests.
	******************************************/
	static void UNIstart();
};

#endif // CTestsUnitaires_H