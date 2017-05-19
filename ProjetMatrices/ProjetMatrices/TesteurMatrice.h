#ifndef TESTEUR_MATRICE_H
#define TESTEUR_MATRICE_H

#include "Matrice.h"
#include "OperationMatrice.h"

template <class T>
class CTesteurMatrice
{
public:
	CTesteurMatrice();
	~CTesteurMatrice();


	/*****************************************
	Teste si la matrice est triangulaire.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
	Entra�ne : rien.
	******************************************/
	bool TESestTriangulaire(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est triangulaire sup�rieure.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire sup�rieure, False = la matrice n'est pas triangulaire sup�rieure.
	Entra�ne : rien
	******************************************/
	bool TESestTriangulaireSuperieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est triangulaire inf�rieure.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire inf�rieur, False = la matrice n'est pas triangulaire inf�rieure.
	Entra�ne : rien
	******************************************/
	bool TESestTriangulaireInferieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
	Entra�ne : rien.
	******************************************/
	bool TESestDiagonale(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est inversible.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est inversible, False = la matrice n'est pas inversible.
	Entra�ne : rien
	******************************************/
	bool TESestInversible(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est sym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est sym�trique, False = la matrice n'est pas sym�trique.
	Entra�ne : rien.
	******************************************/
	bool TESestSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est antisym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est antisym�trique, False = la matrice n'est pas antisym�trique.
	Entra�ne : rien.
	******************************************/
	bool TESestAntiSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Test si une ligne est nulle
	******************************************
	Entr�e : l'indice de la ligne
	N�cessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entra�ne : rien
	******************************************/
	bool TESligneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Test si une colonne est nulle
	******************************************
	Entr�e : l'indice de la colonne
	N�cessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entra�ne : rien
	******************************************/
	bool TEScolonneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Test de matrice nulle.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est nulle, False = la matrice n'est pas nulle.
	Entraine : rien
	******************************************/
	bool TESestNulle(const CMatrice<T> & MATmatrice) const;

	bool TESestCarree(const CMatrice<T> & MATmatrice) const;
};

#include "TesteurMatrice.cpp"

#endif
