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
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
	Entraîne : rien.
	******************************************/
	bool TESestTriangulaire(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est triangulaire supérieure.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est triangulaire supérieure, False = la matrice n'est pas triangulaire supérieure.
	Entraîne : rien
	******************************************/
	bool TESestTriangulaireSuperieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est triangulaire inférieure.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est triangulaire inférieur, False = la matrice n'est pas triangulaire inférieure.
	Entraîne : rien
	******************************************/
	bool TESestTriangulaireInferieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est diagonale.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
	Entraîne : rien.
	******************************************/
	bool TESestDiagonale(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est inversible.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen : True = la matrice est inversible, False = la matrice n'est pas inversible.
	Entraîne : rien
	******************************************/
	bool TESestInversible(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est symétrique.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est symétrique, False = la matrice n'est pas symétrique.
	Entraîne : rien.
	******************************************/
	bool TESestSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si la matrice est antisymétrique.
	******************************************
	Entrée : rien.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est antisymétrique, False = la matrice n'est pas antisymétrique.
	Entraîne : rien.
	******************************************/
	bool TESestAntiSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Test si une ligne est nulle
	******************************************
	Entrée : l'indice de la ligne
	Nécessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entraîne : rien
	******************************************/
	bool TESligneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Test si une colonne est nulle
	******************************************
	Entrée : l'indice de la colonne
	Nécessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entraîne : rien
	******************************************/
	bool TEScolonneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Test de matrice nulle.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen : True = la matrice est nulle, False = la matrice n'est pas nulle.
	Entraine : rien
	******************************************/
	bool TESestNulle(const CMatrice<T> & MATmatrice) const;

	bool TESestCarree(const CMatrice<T> & MATmatrice) const;
};

#include "TesteurMatrice.cpp"

#endif
