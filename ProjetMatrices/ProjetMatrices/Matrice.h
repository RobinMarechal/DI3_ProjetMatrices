#ifndef CMATRICE_H
#define CMATRICE_H

#define TAB_TYPE_NON_DEFINI 0
#define TAB_TYPE_ENTIER 1
#define TAB_TYPE_REEL 2
#define TAB_TYPE_CHAINE 3

#include <iostream>
#include "TableauAssociatif.h"
#include "Cexception.h"
#include "helpers.h"
#include "constantes.h"

template <class T>
class CMatrice
{
private:
	unsigned int uiMATnbColonnes;
	unsigned int uiMATnbLignes;
	T ** ppMATmatrice;

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
	Test d'une ligne nulle.
	******************************************
	Entrée : l'indice de la ligne (unsigned int).
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : la ligne est nulle)
			   OU (false : la ligne n'est pas nulle).
	******************************************/

	bool MATligneEstNulle(unsigned int uiLigne);


	/*****************************************
	Désalloue une matrice.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : désalloue l'objet.
	******************************************/

	void MATdesallouerMatrice();

	//void MATactualiserMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);


	/*****************************************
	Ajoute une ou des colonnes.
	******************************************
	Entrée : le nombre de colonnes (int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : une réallocation du tableau 2D.
	******************************************/

	void MATajouterColonnes(int iNb = 1);


	/*****************************************
	Ajoute une ou plusieurs lignes.
	******************************************
	Entrée : le nombre de lignes (int).
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
	Entraîne : initialisation de l'objet.
	*****************************************/

	CMatrice();
	

	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : le nombre de lignes (unsigned int),
			 le nombre de colonnes (unsigned int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : Initialisation de l'objet.
	******************************************/

	CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);


	/****************************************
	Constructeur de recopie.
	*****************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	*****************************************/

	CMatrice(CMatrice<T> & MATmatrice);


	/****************************************
	Destructeur.
	*****************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : destruction de l'objet,
			   désallocation du tableau 2D.
	****************************************/

	~CMatrice();


	// ----- Opérateurs ----------------------------------------

	/*****************************************
	Opérateur ().
	******************************************
	Entrée : indice de la ligne (unsigned int),
			 indice de la colonne (unsigned int).
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
	Sortie : instance de la classe CMatrice par référence,
			 copie de celle en paramètre
	Entraîne : la recopie de l'objet en paramètre
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
	Entrée : la valeur à ajouter (de type T).
	Nécessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat de la somme.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   ajout de la valeur passée en paramètre à toutes les cases de la matrice.
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
	Entraîne : //
	******************************************/

	CMatrice<T> MATsousMatrice(unsigned int uiLigne, unsigned int uiColonne);

	T MATdet();
	T MATtr();
	CMatrice<T> MATcommatrice();
	CMatrice<T> MATinverse();
	bool MATestTriangulaire();
	bool MATestTriangulaireSuperieure();
	bool MATestTriangulaireInferieure();
	bool MATestDiagonale();
	bool MATestInversible();
	bool MATestSymetrique();
	bool MATestAntiSymetrique();

	// Factory

	static CMatrice<T> MATdiag(unsigned int uiDim, const T ptDiag[]);

	static CMatrice<T> MATparser(CTableauAssociatif TABtab);

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
