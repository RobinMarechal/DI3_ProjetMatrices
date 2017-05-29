#ifndef TESTEUR_MATRICE_H
#define TESTEUR_MATRICE_H

#include "Matrice.h"
#include "OperationMatrice.h"

/****************************** 
 Patron de classe permettant d'effectuer un certain
 nombre de tests sur des CMatrice<T>
 ******************************/
template <class T>
class CTesteurMatrice
{
public:
	/*****************************************
	Constructeur par d�faut
	******************************************
	Entr�e : rien.
	N�cessite : rien
	Sortie : rien.
	Entra�ne : La contruction de l'objet.
	******************************************/
	CTesteurMatrice();


	/*****************************************
	Destructeur
	******************************************
	Entr�e : rien.
	N�cessite : rien
	Sortie : rien.
	Entra�ne : La destruction de l'objet.
	******************************************/
	~CTesteurMatrice();


	/*****************************************
	Teste si une matrice est triangulaire.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
	Entra�ne : rien.
	******************************************/
	bool TESestTriangulaire(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est triangulaire sup�rieure.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire sup�rieure, False = la matrice n'est pas triangulaire sup�rieure.
	Entra�ne : rien
	******************************************/
	bool TESestTriangulaireSuperieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est triangulaire inf�rieure.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire inf�rieur, False = la matrice n'est pas triangulaire inf�rieure.
	Entra�ne : rien
	******************************************/
	bool TESestTriangulaireInferieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est diagonale.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
	Entra�ne : rien.
	******************************************/
	bool TESestDiagonale(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est inversible.
	******************************************
	Entr�e : La matrice.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est inversible, False = la matrice n'est pas inversible.
	Entra�ne : rien
	******************************************/
	bool TESestInversible(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est sym�trique.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est sym�trique, False = la matrice n'est pas sym�trique.
	Entra�ne : rien.
	******************************************/
	bool TESestSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est antisym�trique.
	******************************************
	Entr�e : La matrice.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est antisym�trique, False = la matrice n'est pas antisym�trique.
	Entra�ne : rien.
	******************************************/
	bool TESestAntiSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une ligne est nulle
	******************************************
	Entr�e : La matrice.
	Entr�e : l'indice de la ligne
	N�cessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entra�ne : rien
	******************************************/
	bool TESligneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Teste si une colonne est nulle
	******************************************
	Entr�e : La matrice.
	Entr�e : l'indice de la colonne
	N�cessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entra�ne : rien
	******************************************/
	bool TEScolonneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Teste si une matrice est nulle.
	******************************************
	Entr�e : La matrice.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est nulle, False = la matrice n'est pas nulle.
	Entraine : rien
	******************************************/
	bool TESestNulle(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est carr�e.
	******************************************
	Entr�e : La matrice.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est carr�e, False = la matrice n'est pas carr�e.
	Entraine : rien
	******************************************/
	bool TESestCarree(const CMatrice<T> & MATmatrice) const;
};

#include "TesteurMatrice.cpp"

#endif
