#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include "TableauAssociatif.h"
#include "Cexception.h"
#include "helpers.h"

/*************************************
Classe permettant de gérer des matrices
**************************************
Permet la créations de matrices
et fournis un ensemble d'opérations
mathématiques courantes
**************************************/
template <class T>
class CMatrice
{
private:
	/*****************************
	Le nombre de colonnes de la matrice
	******************************/
	unsigned int uiMATnbColonnes;

	/*****************************
	Le nombre de lignes de la matrice
	******************************/
	unsigned int uiMATnbLignes;

	/*****************************
	le tableau 2D représentant la matrice
	******************************/
	T ** pptMATmatrice;


	/*****************************************
	Vérifie le contenu d'une instance de CTableauAssociatif
	pour créer un objet CMatrice
	******************************************
	Entrée : Un pointeur sur une instance de CTableauAssociatif.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : une Cexception  est levée si le tableau de contient pas "NBColonnes", "NBLignes" et "Matrice",
			ou que les types correspondants sont incorrects (resp. Entier, Entier, Chaine)
	******************************************/
	static void MATverifierContenuTableau(CTableauAssociatif * TABtab);

	/*****************************************
	Initialisation de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : Allocation sur le tas du tableau 2D contenant la matrice
	******************************************/
	void MATinitMatrice();


	/*****************************************
	Libère la mémoire rerservée par l'instance de CMatrice<T>
	******************************************
	Entrée : rien
	Nécessite : rien
	Sortie : rien
	Entraîne : libère la mémoire allouée au tableau 2D.
	******************************************/
	void MATdesallouerMatrice();


	/*****************************************
	Ajoute ou retire des colonnes
	******************************************
	Entrée : le nombre de colonnes à ajouter (par défaut = 1).
	Nécessite : rien
	Sortie : rien
	Entraîne : Réallocation du tableau 2D
	******************************************/
	void MATajouterColonnes(int iNb = 1);


	/*****************************************
	Ajoute ou retire des lignes
	******************************************
	Entrée : le nombre de lignes à ajouter (par défaut = 1).
	Nécessite : iNb > (-1) * le nombre de lignes.
	Sortie : rien.
	Entraîne : Réallocation du tableau 2D.
	******************************************/
	void MATajouterLignes(int iNb = 1);

public:

	// ----- Constructeurs et destructeurs----------------------------------------

	/*****************************************
	Constructeur par défaut.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : initialisation d'un objet CMatrice de dimensions 0 * 0
	*****************************************/
	CMatrice();
	

	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : le nombre de lignes
	Entrée : le nombre de colonnes
	Nécessite : rien.
	Sortie : rien.
	Entraîne : initialisation d'un objet CMatrice de dimensions uiNbLignes * uiNbColonnes
	******************************************/
	CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);


	/****************************************
	Constructeur de recopie.
	*****************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet par copie de MATmatrice
	*****************************************/
	CMatrice(const CMatrice<T> & MATmatrice);


	/****************************************
	Destructeur.
	*****************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : Destruction de l'objet et libération de la mémoire allouée
	****************************************/
	~CMatrice();


	// ----- Opérateurs ----------------------------------------

	/*****************************************
	Opérateur ().
	******************************************
	Entrée : indice de la ligne,
	Entrée : indice de la colonne.
	Nécessite : 0 <= uiLigne < nombre de lignes;
	Nécessite : 0 <= uiColonnes < nombre de colonnes;
	Sortie : Référence de la valeur à la position (i, j) dans la matrice.
	Entraîne : rien.
	*****************************************/
	T & operator()(unsigned int uiLigne, unsigned int uiColonne) const;


	/*****************************************
	Operateur =.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : instance de la classe CMatrice
	Entraîne : Copie des valeurs des attributs de l'objet en paramètre
	******************************************/
	CMatrice<T> & operator=(const CMatrice<T> & MATmatrice);


	/*****************************************
	Operateur ==.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : booléen : true = les matrices sont identiques, false = les matrices sont différentes
	Entraîne : rien
	******************************************/
	bool operator==(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Operateur !=.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : booléen : true = les matrices sont différentes, false = les matrices sont identiques
	Entraîne : rien
	******************************************/
	bool operator!=(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Opérateur + à paramètre de type T. 
	******************************************
	Entrée : la valeur à ajouter.
	Nécessite : les matrices sont de même dimension.
	Sortie : objet CMatrice<T> résultant de la somme.
	Entraîne : rien
	******************************************/
	CMatrice<T> operator+(const T & tValeur) const;


	/*****************************************
	Operateur + à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : les matrices sont de même dimension.
	Sortie : instance de la classe CMatrice contenant le résultat de la somme.
	Entraîne : rien
	******************************************/
	CMatrice<T> operator+(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Opérateur * à paramètre de type T.
	*****************************************
	Entree : la valeur à multiplier (de type T).
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat du produit.
	Entraîne : rien
	******************************************/
	CMatrice<T> operator*(const T & tValeur) const;


	/*****************************************
	Operateur * à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : le nombre de colonnes de la première matrice
				et le nombre de lignes de la deuxième matrice sont identiques.
	Sortie : instance de la classe CMatrice contenant le résultat du produit.
	Entraîne : rien
	******************************************/
	CMatrice<T> operator*(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Opérateur - à paramètre de type T.
	******************************************
	Entree : la valeur à soustraire.
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
	Entraîne : rien
	******************************************/
	CMatrice<T> operator-(const T & tValeur) const;
	

	/*****************************************
	Operateur - à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : les matrices sont de même dimension.
	Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
	Entraîne : rien
	******************************************/
	CMatrice<T> operator-(const CMatrice<T> & MATmatrice) const;


	/*****************************************
	Opérateur / à paramètre de type T.
	******************************************
	Entree : la valeur à diviser (de type T).
	Necessite : tValeur doit être différente de 0.
	Sortie : instance de la classe CMatrice contenant le résultat de la division.
	Entraîne : Une Cexception est levée si tValeur = 0
	******************************************/
	CMatrice<T> operator/(const T & tValeur) const;


	/*****************************************
	Opérateur ^ 
	******************************************
	Entree : la puissance
	Necessite : iPuissance != 0
	Sortie : instance de la classe CMatrice contenant le résultat de M^(iPuissance).
	Entraîne : Une Cexception est levée si iPuissance = 0
	******************************************/
	CMatrice<T> operator^(int iPuissance) const;


	// ----- Getters ----------------------------------------

	/*****************************************
	Affichage d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien
	******************************************/
	void MATafficher() const;


	/*****************************************
	Lecture du nombre de colonnes.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de colonnes de la matrice.
	Entraîne : rien.
	******************************************/
	unsigned int MATgetNbColonnes() const ;


	/*****************************************
	Lecture du nombre de lignes.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de lignes de la matrice.
	Entraîne : rien.
	******************************************/
	unsigned int MATgetNbLignes() const;


	/*****************************************
	Lecture de la valeur d'un coefficient.
	******************************************
	Entéee : l'indice de la ligne,
	Entrée : l'indice de la colonne.
	Nécessite : 0 <= uiLigne < nombre de lignes;
	Nécessite : 0 <= uiColonnes < nombre de colonnes;
	Sortie : le coefficient à la position (uiLigne, uiColonne) par référence.
	Entraîne : rien.
	******************************************/
	T & MATgetValeur(unsigned int uiLigne, unsigned int uiColonne) const;


	/*****************************************
	Lecture d'une ligne.
	******************************************
	Entrée : l'indice de la ligne.
	Nécessite : 0 <= uiLigne < nombre de lignes;
	Sortie : un tableau contant la ligne uiLigne.
	Entraîne : allocation (via l'operateur new) d'un tableau.
	******************************************/
	T * MATgetLigne(unsigned int uiLigne) const;

	
	/*****************************************
	Lecture d'une colonne.
	******************************************
	Entrée : l'indice de la colonne.
	Nécessite : 0 <= uiColonnes < nombre de colonnes;
	Sortie : un tableau contant la colonnes uiColonne.
	Entraîne : allocation (via l'operateur new) d'un tableau.
	******************************************/
	T * MATgetColonne(unsigned int uiColonne) const;


	// ----- Setters ----------------------------------------

	/*****************************************
	Mutateur pour la valeur.
	******************************************
	Entrée : l'indice de la ligne.
	Entrée : l'indice de la colonne.
	Entrée : la valeur définir.
	Nécessite : 0 <= uiLigne < nombre de lignes;
	Nécessite : 0 <= uiColonnes < nombre de colonnes;
	Sortie : rien.
	Entraîne : un changement de valeur du coefficient à la position (uiLigne, uiColonne).
	******************************************/
	void MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur);


	/*****************************************
	Mutateur pour le nombre de lignes.
	******************************************
	Entrée : le nombre de lignes.
	Nécessite : uiNbLignes > 0.
	Sortie : rien.
	Entraîne : une réallocation du tableau 2D.
	******************************************/
	void MATsetNbLignes(unsigned int uiNbLignes);


	/*****************************************
	Mutateur pour le nombre de colonnes.
	******************************************
	Entrée : le nombre de colonnes.
	Nécessite : uiNbColonnes > 0.
	Sortie : rien.
	Entraîne : une réallocation du tableau 2D.
	******************************************/
	void MATsetNbColonnes(unsigned int uiNbColonnes);


	/*****************************************
	Génération d'une matrice .
	******************************************
	Entrée : Un pointeur sur une instance de CTableauAssociatif.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : la création d'une matrice à partir des valeurs du tableau.
	******************************************/
	static CMatrice<T> MATgenerer(CTableauAssociatif * TABtab);
};


// Opérateurs complémentaires

/*****************************************
Opérateur + à paramètre de type CMatrice<T> et T.
******************************************
Entrée : la valeur à ajouter (de type T),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant de la somme.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> operator+(const T & tValeur, const CMatrice<T> & MATmatrice);



/*****************************************
Opérateur - à paramètre de type CMatrice<T> et T.
******************************************
Entrée : la valeur à retirer (de type T),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant de la différence.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> operator-(const T & tValeur, const CMatrice<T> & MATmatrice);



/*****************************************
Opérateur * à paramètre de type CMatrice<T> et T.
******************************************
Entrée : le coefficient de multiplication (de type T),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant du produit.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> operator*(const T & tValeur, const CMatrice<T> & MATmatrice);


/*****************************************
Opérateur <<.
******************************************
Entrée : un flux (std::cout),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage de la matrice.
******************************************/
template <class T>
std::ostream & operator<<(std::ostream & OSTflux, const CMatrice<T> & MATmatrice);

#include "Matrice.cpp"

#endif
