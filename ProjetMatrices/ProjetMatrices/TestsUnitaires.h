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
	Constructeur par défaut
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la création de l'objet.
	******************************************/
	CTestsUnitaires(); 

	/*****************************************
	Teste les accesseurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestAccesseurs() const;


	/*****************************************
	Teste l'opérateur +.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurPlus() const;


	/*****************************************
	Teste l'opérateur -.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurMoins() const;


	/*****************************************
	Teste l'opérateur =.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurEgal() const;


	/*****************************************
	Teste les opérateur de comparaisons == et !=.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateursComparaison() const;


	/*****************************************
	Teste l'opérateur *.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurProduit() const;


	/*****************************************
	Teste l'opérateur /.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurDiviser() const;


	/*****************************************
	Teste l'opérateur ^.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestOperateurPuissance() const;


	/*****************************************
	Teste de tous les opérateurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les opérateurs.
	******************************************/
	void UNItestOperateurs() const;


	/*****************************************
	Teste le calcul du rang.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculRang() const;


	/*****************************************
	Teste l'échelonnement.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculEchelonnee() const;


	/*****************************************
	Teste le calcul de la transposée.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculTransposee() const;


	/*****************************************
	Teste le calcul de la sous-matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculSousMatrice() const;


	/*****************************************
	Teste le calcul du déterminant.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculDet() const;


	/*****************************************
	Teste le calcul de la matrice inverse.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculInverse() const;


	/*****************************************
	Teste le calcul de la commatrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculCommatrice() const;


	/*****************************************
	Teste le calcul de la trace.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCalculTrace() const;


	/*****************************************
	Teste tous les calculs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les calculs.
	******************************************/
	void UNItestCalculs() const;


	/*****************************************
	Teste le test de matrice nulle.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstNulle() const;


	/*****************************************
	Teste le test de matrice triangulaire.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstTriangulaire() const;


	/*****************************************
	Teste le test de matrice triangulaire supérieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstTriangulaireSuperieure() const;


	/*****************************************
	Teste le test de matrice triangulaire inférieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstTriangulaireInferieure() const;


	/*****************************************
	Teste le test de matrice diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstDiagonale() const;


	/*****************************************
	Teste le test de matrice inversible.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstInversible() const;


	/*****************************************
	Teste le test de matrice symétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstSymetrique() const;


	/*****************************************
	Teste le test de matrice antisymétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestEstAntiSymetrique() const;


	/*****************************************
	Teste le test de matrice carrée.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'appel de tous les tests sur les méthodes de test.
	******************************************/
	void UNItestTestsMatriceCarree() const;
	

	/*****************************************
	Teste la création d'une matrice diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestDiag() const;


	/*****************************************
	Teste les exceptions.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestExceptions() const;



	/*****************************************
	Teste le fonctionnement global de CTableauAssociatif
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestsCTableauAssociatif() const;



	/*****************************************
	Test du calcul de la factorisation de Choleski
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
	******************************************/
	void UNItestCholeski() const;


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