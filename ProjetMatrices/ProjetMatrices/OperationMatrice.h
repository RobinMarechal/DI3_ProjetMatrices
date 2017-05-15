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
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le rang de la matrice.
	Entra�ne : rien.
	******************************************/
	unsigned int OPMrang(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Echelonnement de la matrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : une matrice �chelonn�es (non r�duite => change le d�terminant).
	Entra�ne : rien.
	******************************************/
	CMatrice<T> OPMechelonnee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Transpos�e de la matrice.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : la transpos�e de la matrice
	Entra�ne : rien.
	******************************************/
	CMatrice<T> OPMtransposee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul d'une sous-matrice.
	******************************************
	Entr�e : l'indice de la ligne.
	Entr�e : l'indice de la colonne.
	N�cessite : uiLigne >= 0 et est inferieur au nombre de lignes de la matrice.
	N�cessite : uiColonne >= 0 et est inferieur au nombre de de colonnes de la matrice.
	Sortie : une instance de CMatrice poss�dant une ligne et une colonne de moins
	contenant les valeurs de la matrice qui ne sont pas sur la lige uiLigne ou
	sur la colonne uiColonne.
	Entra�ne : rien.
	******************************************/
	CMatrice<T> OPMsousMatrice(const CMatrice<T> & MATmatrice, unsigned int uiLigne, unsigned int uiColonne) const;


	/*****************************************
	Calcul du d�terminant.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : la valeur du d�terminant.
	Entra�ne : rien.
	******************************************/
	T OPMdet(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la trace d'une matrice.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : la valeur de la trace.
	Entra�ne : rien.
	******************************************/
	T OPMtr(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la commatrice.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : une instance de CMatrice �gale a la commatrice de l'objet.
	Entra�ne : rien.
	******************************************/
	CMatrice<T> OPMcommatrice(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de l'inverse d'une matrice.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : une instance de CMatrice �gale � l'inverse de l'objet.
	Entra�ne : Une Cexception est lev�e si le determinant est nul.
	******************************************/
	CMatrice<T> OPMinverse(const CMatrice<T> & MATmatrice) const;



	/*****************************************
	Cr�ation d'une matrice diagonale.
	******************************************
	Entr�e : la dimension,
	Entr�e : un tableau de valeurs.
	N�cessite : la dimension du tableau est >= uiDim
	(si elle est sup�rieure, seules les uiDim premi�res
	valeurs seront prisent en compte).
	Sortie : un matrice diagonale contenant les valeurs de ptDiag sur la diagonale.
	Entra�ne : rien
	******************************************/
	CMatrice<T> OPMcreerMatriceDiagonale(unsigned int uiDim, const T ptDiag[]);

};

#include "OperationMatrice.cpp"

#endif