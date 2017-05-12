#ifndef TESTEUR_MATRICE_H
#define TESTEUR_MATRICE_H

#include "Matrice.h"
#include "OperationMatrice.h"

class COperationMatrice;

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
	template <class T>
	bool TESestTriangulaire(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est triangulaire sup�rieure.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire sup�rieure, False = la matrice n'est pas triangulaire sup�rieure.
	Entra�ne : rien
	******************************************/
	template <class T>
	bool TESestTriangulaireSuperieure(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est triangulaire inf�rieure.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est triangulaire inf�rieur, False = la matrice n'est pas triangulaire inf�rieure.
	Entra�ne : rien
	******************************************/
	template <class T>
	bool TESestTriangulaireInferieure(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est diagonale.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
	Entra�ne : rien.
	******************************************/
	template <class T>
	bool TESestDiagonale(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est inversible.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est inversible, False = la matrice n'est pas inversible.
	Entra�ne : rien
	******************************************/
	template <class T>
	bool TESestInversible(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est sym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est sym�trique, False = la matrice n'est pas sym�trique.
	Entra�ne : rien.
	******************************************/
	template <class T>
	bool TESestSymetrique(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est antisym�trique.
	******************************************
	Entr�e : rien.
	N�cessite : La matrice est carr�e.
	Sortie : un bool�en : True = la matrice est antisym�trique, False = la matrice n'est pas antisym�trique.
	Entra�ne : rien.
	******************************************/
	template <class T>
	bool TESestAntiSymetrique(const CMAtrice<T> & MATmatrice) const;


	/*****************************************
	Test si une ligne est null
	******************************************
	Entr�e : l'indice de la ligne
	N�cessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entra�ne : rien
	******************************************/
	template <class T>
	bool TESligneEstNulle(const CMAtrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Test si une colonne est nulle
	******************************************
	Entr�e : l'indice de la colonne
	N�cessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entra�ne : rien
	******************************************/
	template <class T>
	bool TEScolonneEstNulle(const CMAtrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Test de matrice nulle.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un bool�en : True = la matrice est nulle, False = la matrice n'est pas nulle.
	Entraine : rien
	******************************************/
	template <class T>
	bool TESestNulle(const CMAtrice<T> & MATmatrice) const;
};

#include "TesteurMatrice.cpp"

#endif
