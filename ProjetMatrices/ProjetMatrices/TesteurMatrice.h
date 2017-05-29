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
	Constructeur par défaut
	******************************************
	Entrée : rien.
	Nécessite : rien
	Sortie : rien.
	Entraîne : La contruction de l'objet.
	******************************************/
	CTesteurMatrice();


	/*****************************************
	Destructeur
	******************************************
	Entrée : rien.
	Nécessite : rien
	Sortie : rien.
	Entraîne : La destruction de l'objet.
	******************************************/
	~CTesteurMatrice();


	/*****************************************
	Teste si une matrice est triangulaire.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
	Entraîne : rien.
	******************************************/
	bool TESestTriangulaire(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est triangulaire supérieure.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est triangulaire supérieure, False = la matrice n'est pas triangulaire supérieure.
	Entraîne : rien
	******************************************/
	bool TESestTriangulaireSuperieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est triangulaire inférieure.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est triangulaire inférieur, False = la matrice n'est pas triangulaire inférieure.
	Entraîne : rien
	******************************************/
	bool TESestTriangulaireInferieure(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est diagonale.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
	Entraîne : rien.
	******************************************/
	bool TESestDiagonale(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est inversible.
	******************************************
	Entrée : La matrice.
	Nécessite : rien.
	Sortie : un booléen : True = la matrice est inversible, False = la matrice n'est pas inversible.
	Entraîne : rien
	******************************************/
	bool TESestInversible(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est symétrique.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est symétrique, False = la matrice n'est pas symétrique.
	Entraîne : rien.
	******************************************/
	bool TESestSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est antisymétrique.
	******************************************
	Entrée : La matrice.
	Nécessite : La matrice est carrée.
	Sortie : un booléen : True = la matrice est antisymétrique, False = la matrice n'est pas antisymétrique.
	Entraîne : rien.
	******************************************/
	bool TESestAntiSymetrique(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une ligne est nulle
	******************************************
	Entrée : La matrice.
	Entrée : l'indice de la ligne
	Nécessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entraîne : rien
	******************************************/
	bool TESligneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Teste si une colonne est nulle
	******************************************
	Entrée : La matrice.
	Entrée : l'indice de la colonne
	Nécessite : rien
	Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
	Entraîne : rien
	******************************************/
	bool TEScolonneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const;


	/*****************************************
	Teste si une matrice est nulle.
	******************************************
	Entrée : La matrice.
	Nécessite : rien.
	Sortie : un booléen : True = la matrice est nulle, False = la matrice n'est pas nulle.
	Entraine : rien
	******************************************/
	bool TESestNulle(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Teste si une matrice est carrée.
	******************************************
	Entrée : La matrice.
	Nécessite : rien.
	Sortie : un booléen : True = la matrice est carrée, False = la matrice n'est pas carrée.
	Entraine : rien
	******************************************/
	bool TESestCarree(const CMatrice<T> & MATmatrice) const;
};

#include "TesteurMatrice.cpp"

#endif
