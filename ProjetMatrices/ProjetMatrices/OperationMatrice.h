#ifndef OPERATION_MATRICE_H
#define OPERATION_MATRICE_H

#include "Matrice.h"
#include "TesteurMatrice.h"
#include "Cexception.h"

template <class T>
class CTesteurMatrice;

/****************************
 Patron de classe permettant de r�aliser des 
 op�rations sur des objets de type CMatrice<T>
 ****************************/
template <class T>
class COperationMatrice
{
public:

	/****************************************
	 Constructeur par d�faut
	*****************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : La cr�ation de l'objet
	 ****************************************/
	COperationMatrice();

	/****************************************
	Destructeur
	*****************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : La destruction de l'objet
	****************************************/
	~COperationMatrice();


	/*****************************************
	Calcul du rang d'une matrice
	******************************************
	Entr�e : La matrice.
	N�cessite : rien.
	Sortie : le rang de la matrice.
	Entra�ne : La cr�ation d'un nouvel objet CMatrice<T>.
	******************************************/
	unsigned int OPMrang(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Echelonnement d'une matrice
	******************************************
	Entr�e : La matrice.
	N�cessite : rien.
	Sortie : une matrice �chelonn�es (non r�duite => change le d�terminant).
	Entra�ne : La cr�ation d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMechelonnee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Transpos�e d'une matrice.
	******************************************
	Entr�e : La matrice.
	N�cessite : rien.
	Sortie : la transpos�e de la matrice
	Entra�ne : La cr�ation d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMtransposee(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul d'une sous-matrice.
	******************************************
	Entr�e : La matrice
	Entr�e : l'indice de la ligne.
	Entr�e : l'indice de la colonne.
	N�cessite : uiLigne >= 0 et est inferieur au nombre de lignes de la matrice.
	N�cessite : uiColonne >= 0 et est inferieur au nombre de de colonnes de la matrice.
	Sortie : une instance de CMatrice poss�dant une ligne et une colonne de moins
	contenant les valeurs de la matrice qui ne sont pas sur la lige uiLigne ou
	sur la colonne uiColonne.
	Entra�ne : La cr�ation d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMsousMatrice(const CMatrice<T> & MATmatrice, unsigned int uiLigne, unsigned int uiColonne) const;


	/*****************************************
	Calcul du d�terminant d'une matrice.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : la valeur du d�terminant.
	Entra�ne : rien.
	******************************************/
	T OPMdet(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la trace d'une matrice.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : la valeur de la trace.
	Entra�ne : rien.
	******************************************/
	T OPMtr(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de la commatrice d'une matrice.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : une instance de CMatrice �gale a la commatrice de l'objet.
	Entra�ne : La cr�ation d'un nouvel objet CMatrice<T>.
	******************************************/
	CMatrice<T> OPMcommatrice(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Calcul de l'inverse d'une matrice.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : une instance de CMatrice �gale � l'inverse de l'objet.
	Entra�ne : La cr�ation d'un objet CMatrice<T>
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
	Entra�ne : La cr�ation d'un objet CMatrice<T>
	******************************************/
	CMatrice<T> OPMcreerMatriceDiagonale(unsigned int uiDim, const T ptDiag[]);



	/*****************************************
	Calcul de la matrice triangulaire inf�rieure (L)
	de la factorisation de Choleski
	******************************************
	Entr�e : la matrice,
	N�cessite : rien.
	Sortie : La matrice triangulaire inf�rieur de la factorisation de Choleski
	Entra�ne : La cr�ation d'un objet CMatrice<T>
	Entra�ne : Une Cexception si :
		- La matrice n'est pas carr�e,
		- La matrice n'est pas sym�trique
		- La matrice n'est pas d�finie positive
	******************************************/
	CMatrice<T> OPMfactorisationCholeski(CMatrice<T>& MATmatrice);
};

#include "OperationMatrice.cpp"

#endif