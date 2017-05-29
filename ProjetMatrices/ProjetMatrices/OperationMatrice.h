#ifndef OPERATION_MATRICE_H
#define OPERATION_MATRICE_H

#include "Matrice.h"
#include "TesteurMatrice.h"
#include "Cexception.h"

template <class T>
class CTesteurMatrice;

/****************************
 Patron de classe permettant de réaliser des 
 opérations sur des objets de type CMatrice<T>
 ****************************/
template <class T>
class COperationMatrice
{
public:

	/****************************************
	 Constructeur par défaut
	*****************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : La création de l'objet
	 ****************************************/
	COperationMatrice();

	/****************************************
	Destructeur
	*****************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : La destruction de l'objet
	****************************************/
	~COperationMatrice();


	/*****************************************
	Calcul du rang d'une matrice
	******************************************
	Entrée : La matrice.
	Nécessite : rien.
	Sortie : le rang de la matrice.
	Entraîne : La création d'un nouvel objet CMatrice<T>.
	******************************************/
	unsigned int OPMrang(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Echelonnement d'une matrice
	******************************************
	Entrée : La matrice.
	Nécessite : rien.
	Sortie : une matrice échelonnées (non réduite => change le déterminant).
	Entraîne : La création d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMechelonnee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Transposée d'une matrice.
	******************************************
	Entrée : La matrice.
	Nécessite : rien.
	Sortie : la transposée de la matrice
	Entraîne : La création d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMtransposee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul d'une sous-matrice.
	******************************************
	Entrée : La matrice
	Entrée : l'indice de la ligne.
	Entrée : l'indice de la colonne.
	Nécessite : uiLigne >= 0 et est inferieur au nombre de lignes de la matrice.
	Nécessite : uiColonne >= 0 et est inferieur au nombre de de colonnes de la matrice.
	Sortie : une instance de CMatrice possédant une ligne et une colonne de moins
	contenant les valeurs de la matrice qui ne sont pas sur la lige uiLigne ou
	sur la colonne uiColonne.
	Entraîne : La création d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMsousMatrice(const CMatrice<T> & MATmatrice, unsigned int uiLigne, unsigned int uiColonne) const;


	/*****************************************
	Calcul du déterminant d'une matrice.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : la valeur du déterminant.
	Entraîne : rien.
	******************************************/
	T OPMdet(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la trace d'une matrice.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : la valeur de la trace.
	Entraîne : rien.
	******************************************/
	T OPMtr(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la commatrice d'une matrice.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : une instance de CMatrice égale a la commatrice de l'objet.
	Entraîne : La création d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMcommatrice(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de l'inverse d'une matrice.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : une instance de CMatrice égale à l'inverse de l'objet.
	Entraîne : La création d'un objet CMatrice<T>
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
	Entraîne : La création d'un objet CMatrice<T>
	******************************************/
	CMatrice<T> OPMcreerMatriceDiagonale(unsigned int uiDim, const T ptDiag[]);



	/*****************************************
	Calcul de la matrice triangulaire inférieure (L)
	de la factorisation de Choleski
	******************************************
	Entrée : la matrice,
	Nécessite : rien.
	Sortie : La matrice triangulaire inférieur de la factorisation de Choleski
	Entraîne : La création d'un objet CMatrice<T>
	Entraîne : Une Cexception si :
		- La matrice n'est pas carrée,
		- La matrice n'est pas symétrique
		- La matrice n'est pas définie positive
	******************************************/
	CMatrice<T> OPMfactorisationCholeski(CMatrice<T>& MATmatrice);
};

#include "OperationMatrice.cpp"

#endif