#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include "TableauAssociatif.h"
#include "Cexception.h"
#include "helpers.h"
#include "constantes.h"

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
	Entrée : Une instance de CTableauAssociatif.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : une exception si le tableau de contient pas "NBColonnes", "NBLignes" et "Matrice", 
			et que les types correspondants sont incorrects (resp. Entier, Entier, Chaine)
	******************************************/
	static void MATverifierContenuTableau(CTableauAssociatif TABtab);

	/*****************************************
	Initialisation de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : initialisation de l'objet.
	******************************************/
	void MATinitMatrice();


	/*****************************************
	Test d'une ligne nulle
	******************************************
	Entrée : l'indice de la ligne
	Nécessite : rien
	Sortie : un booléen
	Entraîne : (true : la ligne est nulle)
			   OU (false : la ligne n'est pas nulle)
	******************************************/
	bool MATligneEstNulle(unsigned int uiLigne);


	/*****************************************
	Libère la mémoire rerservée par l'instance de CMatrice<T>
	******************************************
	Entrée : rien
	Nécessite : Nombres de 'colonnes' de pptMatrice = uiMATnbColonnes 
	Sortie : rien
	Entraîne : désalloue l'objet.
	******************************************/
	void MATdesallouerMatrice();


	/*****************************************
	Ajoute ou retire des colonnes
	******************************************
	Entrée : le nombre de colonnes à ajouter (par défaut = 1).
	Nécessite : rien
	Sortie : rien
	Entraîne : une réallocation du tableau 2D
	******************************************/
	void MATajouterColonnes(int iNb = 1);


	/*****************************************
	Ajoute ou retire des lignes
	******************************************
	Entrée : le nombre de lignes à ajouter (par défaut = 1).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : une réallocation du tableau 2D.
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
	CMatrice(CMatrice<T> & MATmatrice);


	/****************************************
	Destructeur.
	*****************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : Libération de la mémoire allouée pour pptMATmatrice
	****************************************/
	~CMatrice();


	// ----- Opérateurs ----------------------------------------

	/*****************************************
	Opérateur ().
	******************************************
	Entrée : indice de la ligne,
	Entrée : indice de la colonne.
	Nécessite : rien.
	Sortie : valeur de la position (i, j) dans la matrice.
	Entraîne : rien.
	*****************************************/
	T & operator()(unsigned int uiLigne, unsigned int uiColonne);


	/*****************************************
	Operateur =.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : instance de la classe CMatrice
	Entraîne : Copie des valeurs des attributs de l'objet en paramètre
	******************************************/
	CMatrice<T> & operator=(CMatrice<T> & MATmatrice);


	/*****************************************
	Operateur ==.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : booléen.
	Entraîne : (true : les matrices sont identiques)
			   OU (false : les matrices sont différentes).
	******************************************/
	bool operator==(CMatrice<T> & MATmatrice);


	/*****************************************
	Operateur !=.
	******************************************
	Entrée : instance de la classe CMatrice.
	Necessite : rien.
	Sortie : booléen.
	Entraîne : (true : les matrices sont différentes)
			   OU (false : les matrices sont identiques).
	******************************************/
	bool operator!=(CMatrice<T> & MATmatrice);


	/*****************************************
	Opérateur + à paramètre de type T. 
	******************************************
	Entrée : la valeur à ajouter.
	Nécessite : rien.
	Sortie : objet CMatrice<T>.
	Entraîne : création d'un nouvel objet CMatrice<T> résultant de la somme
	******************************************/
	CMatrice<T> operator+(const T & tValeur);


	/*****************************************
	Operateur + à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : les matrices sont de même dimension.
	Sortie : instance de la classe CMatrice contenant le résultat de la somme.
	Entraîne : Allocation d'un nouvel objet CMatrice.
	******************************************/

	CMatrice<T> operator+(CMatrice & MATmatrice);


	/*****************************************
	Opérateur * à paramètre de type T.
	*****************************************
	Entree : la valeur à multiplier (de type T).
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat du produit.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   multiplication de la valeur passée en paramètre avec toutes les cases de la matrice.
	******************************************/

	CMatrice<T> operator*(const T & tValeur);


	/*****************************************
	Operateur * à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : le nombre de colonnes de la première matrice
				et le nombre de lignes de la deuxième matrice sont identiques.
	Sortie : instance de la classe CMatrice contenant le résultat du produit.
	Entraîne : Allocation d'un nouvel objet CMatrice.
	******************************************/

	CMatrice<T> operator*(CMatrice<T> & MATmatrice);


	/*****************************************
	Opérateur - à paramètre de type T.
	******************************************
	Entree : la valeur à soustraire (de type T).
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   soustraction de la valeur passée en paramètre avec toutes les cases de la matrice.
	******************************************/

	CMatrice<T> operator-(const T & tValeur);
	

	/*****************************************
	Operateur - à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : les matrices sont de même dimension.
	Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
	Entraîne : Allocation d'un nouvel objet CMatrice.
	******************************************/

	CMatrice<T> operator-(CMatrice<T> & MATmatrice);


	/*****************************************
	Opérateur / à paramètre de type T.
	******************************************
	Entree : la valeur à diviser (de type T).
	Necessite : tValeur doit être différente de 0.
	Sortie : instance de la classe CMatrice contenant le résultat de la division.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   division de la valeur passée en paramètre avec toutes les cases de la matrice.
	******************************************/

	CMatrice<T> operator/(const T & tValeur);


	CMatrice<T> operator^(int iPuissance);


	// ----- Getters ----------------------------------------

	/*****************************************
	Affichage d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'affichage de la matrice.
	******************************************/

	void MATafficher();


	/*****************************************
	Lecture du nombre de colonnes.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de colonnes de la matrice (unsigned int).
	Entraîne : rien.
	******************************************/

	unsigned int MATgetNbColonnes();


	/*****************************************
	Lecture du nombre de lignes.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de lignes de la matrice (unsigned int).
	Entraîne : rien.
	******************************************/

	unsigned int MATgetNbLignes();


	/*****************************************
	Lecture de la valeur d'un coefficient.
	******************************************
	Entéee : l'indice de la ligne (unsigned int),
			 l'indice de la colonne (unsigned int).
	Nécessite : rien.
	Sortie : le coefficient à la position (uiLigne, uiColonne).
	Entraîne : rien.
	******************************************/
	T & MATgetValeur(unsigned int uiLigne, unsigned int uiColonne);


	/*****************************************
	Lecture d'une ligne.
	******************************************
	Entrée : l'indice de la ligne (unsigned int).
	Nécessite : rien.
	Sortie : la ligne à l'indice uiLigne.
	Entraîne : rien.
	******************************************/

	T * MATgetLigne(unsigned int uiLigne);

	
	/*****************************************
	Lecture d'une colonne.
	******************************************
	Entrée : l'indice de la colonne (unsigned int).
	Nécessite : rien.
	Sortie : la colonne à l'indice uiColonne.
	Entraîne : rien.
	******************************************/

	T * MATgetColonne(unsigned int uiColonne);


	// ----- Setters ----------------------------------------

	/*****************************************
	Mutateur pour la valeur.
	******************************************
	Entrée : l'indice de la ligne (unsigned int),
			 l'indice de la colonne (unsigned int),
			 la valeur définir (de type T).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : un changement de valeur du coefficient (uiLigne, uiColonne).
	******************************************/

	void MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur);


	/*****************************************
	Mutateur pour le nombre de lignes.
	******************************************
	Entrée : le nombre de lignes (unsigned int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : une initialisation ou modification du nombre de lignes de la matrice.
	******************************************/

	void MATsetNbLignes(unsigned int uiNbLignes);


	/*****************************************
	Mutateur pour le nombre de colonnes.
	******************************************
	Entrée : le nombre de colonnes (unsigned int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : une initialisation ou modification du nombre de colonnes de la matrice.
	******************************************/

	void MATsetNbColonnes(unsigned int uiNbColonnes);


	// ----- Calculs ----------------------------------------

	/*****************************************
	Le rang de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le rang de la matrice (unsigned int).
	Entraîne : rien.
	******************************************/

	unsigned int MATrang();


	/*****************************************
	Echelonnement de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : l'échelonnement de la matrice.
	******************************************/

	CMatrice<T> MATechelonnee();


	/*****************************************
	Transposée de la matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : une transposition de la matrice.
	******************************************/

	CMatrice<T> MATtransposee();


	/*****************************************
	Calcul d'une sous-matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : création d'une matrice de dimension 
	******************************************/

	CMatrice<T> MATsousMatrice(unsigned int uiLigne, unsigned int uiColonne);


	/*****************************************
	Calcul du déterminant d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : la valeur du déterminant (de type T).
	Entraîne : rien.
	******************************************/

	T MATdet();


	/*****************************************
	Calcul de la trace d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : la valeur de la trace (de type T).
	Entraîne : rien.
	******************************************/

	T MATtr();


	/*****************************************
	Calcul de la commatrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : la création d'une matrice.
	******************************************/

	CMatrice<T> MATcommatrice();


	/*****************************************
	Calcul de l'inverse d'une matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : la création de la matrice inverse.
	******************************************/

	CMatrice<T> MATinverse();


	/*****************************************
	Teste si la matrice est triangulaire.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est triangulaire)
			   OU (false : la matrice n'est pas triangulaire).
	******************************************/

	bool MATestTriangulaire();


	/*****************************************
	Teste si la matrice est triangulaire supérieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est triangulaire supérieur)
			   OU (false : la matrice n'est pas triangulaire supérieur).
	******************************************/

	bool MATestTriangulaireSuperieure();


	/*****************************************
	Teste si la matrice est triangulaire inférieur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est triangulaire inférieur)
			   OU (false : la matrice n'est pas triangulaire inférieur).
	******************************************/

	bool MATestTriangulaireInferieure();


	/*****************************************
	Teste si la matrice est diagonale.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est diagonale)
			   OU (false : la matrice n'est pas diagonale).
	******************************************/

	bool MATestDiagonale();


	/*****************************************
	Teste si la matrice est inversible.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est inversible)
			   OU (false : la matrice n'est pas inversible).
	******************************************/

	bool MATestInversible();


	/*****************************************
	Teste si la matrice est symétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est symétrique)
			   OU (false : la matrice n'est pas symétrique).
	******************************************/

	bool MATestSymetrique();


	/*****************************************
	Teste si la matrice est antisymétrique.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la matrice est antisymétrique)
			   OU (false : la matrice n'est pas antisymétrique).
	******************************************/

	bool MATestAntiSymetrique();

	// Factory

	/*****************************************
	Création d'une matrice diagonale.
	******************************************
	Entrée : la dimension (unsigned int),
			 un tableau de valeurs (de type T).
	Nécessite : la dimension du tableau est >= à la dimension souhaitée.
	Sortie : une instance de CMatrice.
	Entraîne : la création d'une matrice diagonale.
	******************************************/

	static CMatrice<T> MATdiag(unsigned int uiDim, const T ptDiag[]);


	/*****************************************
	Génération d'une matrice .
	******************************************
	Entrée : une instance de CTableauAssociatif.
	Nécessite : rien.
	Sortie : une instance de CMatrice.
	Entraîne : la création d'une matrice.
	******************************************/

	static CMatrice<T> MATgenerer(CTableauAssociatif TABtab);


	/*****************************************
	Test de matrice nulle.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un booléen.
	Entraine : (true : la matrice est nulle)
			   OU (false : la matrice n'est pas nulle).
	******************************************/

	bool MATestNulle();
};


// Opérateurs complémentaires

/*****************************************
Opérateur +.
******************************************
Entrée : la valeur à ajouter (de type T),
		 une instance de CMatrice.
Nécessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat de la somme.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   ajout de la valeur passée en paramètre à toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> operator+(const T & tValeur, const CMatrice<T> & MATmatrice);


/*****************************************
Opérateur -.
******************************************
Entrée : la valeur à soustraire (de type T),
		 une instance de CMatrice.
Nécessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   soustraction de la valeur passée en paramètre avec toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> operator-(const T & tValeur, const CMatrice<T> & MATmatrice);


/*****************************************
Opérateur *.
******************************************
Entrée : la valeur à multiplier (de type T),
		 une instance de CMatrice.
Nécessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat du produit.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   multiplication de la valeur passée en paramètre avec toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> operator*(const T & tValeur, const CMatrice<T> & MATmatrice);


/*****************************************
Opérateur <<.
******************************************
Entrée : un flux,
		 une instance de CMatrice.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage de la matrice.
******************************************/

template <class T>
std::ostream & operator<<(std::ostream & OSTflux, const CMatrice<T> & MATmatrice);

#include "Matrice.cpp"

#endif
