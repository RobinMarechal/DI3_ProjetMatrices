#ifndef OPERATION_MATRICE_H
#define OPERATION_MATRICE_H

#include "Matrice.h"
#include "TesteurMatrice.h"

template <class T>
class CTesteurMatrice;

template <class T>
class COperationMatrice
{
public:
	COperationMatrice();
	~COperationMatrice();


	/*****************************************
	Le rang de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le rang de la matrice.
	Entraîne : rien.
	******************************************/
	unsigned int OPMrang(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Echelonnement de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : une matrice échelonnées (non réduite => change le déterminant).
	Entraîne : rien.
	******************************************/
	CMatrice<T> OPMechelonnee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Transposée de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : la transposée de la matrice
	Entraîne : rien.
	******************************************/
	CMatrice<T> OPMtransposee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul d'une sous-matrice.
	******************************************
	Entrée : l'indice de la ligne.
	Entrée : l'indice de la colonne.
	Nécessite : uiLigne >= 0 et est inferieur au nombre de lignes de la matrice.
	Nécessite : uiColonne >= 0 et est inferieur au nombre de de colonnes de la matrice.
	Sortie : une instance de CMatrice possédant une ligne et une colonne de moins
	contenant les valeurs de la matrice qui ne sont pas sur la lige uiLigne ou
	sur la colonne uiColonne.
	Entraîne : rien.
	******************************************/
	CMatrice<T> OPMsousMatrice(const CMatrice<T> & MATmatrice, unsigned int uiLigne, unsigned int uiColonne) const;


	/*****************************************
	Calcul du déterminant.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : la valeur du déterminant.
	Entraîne : rien.
	******************************************/
	T OPMdet(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la trace d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : la valeur de la trace.
	Entraîne : rien.
	******************************************/
	T OPMtr(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la commatrice.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : une instance de CMatrice égale a la commatrice de l'objet.
	Entraîne : rien.
	******************************************/
	CMatrice<T> OPMcommatrice(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de l'inverse d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : une instance de CMatrice égale à l'inverse de l'objet.
	Entraîne : Une Cexception est levée si le determinant est nul.
	******************************************/
	CMatrice<T> OPMinverse(const CMatrice<T> & MATmatrice) const;



	/*****************************************
	Création d'une matrice diagonale.
	******************************************
	Entrée : la dimension,
	Entrée : un tableau de valeurs.
	Nécessite : la dimension du tableau est >= uiDim
	(si elle est supérieure, seules les uiDim premières
	valeurs seront prisent en compte).
	Sortie : un matrice diagonale contenant les valeurs de ptDiag sur la diagonale.
	Entraîne : rien
	******************************************/
	CMatrice<T> OPMcreerMatriceDiagonale(unsigned int uiDim, const T ptDiag[]);

};

#include "OperationMatrice.cpp"

#endif