#ifndef CMATRICE_H
#define CMATRICE_H

template <class T>
class CMatrice
{
private:
	unsigned int uiMATnbColonnes;
	unsigned int uiMATnbLignes;
	T ** ppMATmatrice;

	void MATinitMatrice();

	bool MATligneEstNulle(unsigned int uiLigne);

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

	CMatrice<T> operator+(T tValeur);


	/*****************************************
	Operateur + à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : les matrices sont de même dimension.
	Sortie : instance de la classe CMatrice contenant le résultat de la somme.
	Entraîne : Allocation d'un nouvel objet CMatrice.
	******************************************/

	CMatrice<T> operator+(CMatrice MATmatrice);


	/*****************************************
	Opérateur * à paramètre de type T.
	*****************************************
	Entree : la valeur à multiplier (de type T).
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat du produit.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   multiplication de la valeur passée en paramètre avec toutes les cases de la matrice.
	******************************************/

	CMatrice<T> operator*(T tValeur);


	/*****************************************
	Operateur * à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : le nombre de colonnes de la première matrice
				et le nombre de lignes de la deuxième matrice sont identiques.
	Sortie : instance de la classe CMatrice contenant le résultat du produit.
	Entraîne : Allocation d'un nouvel objet CMatrice.
	******************************************/

	CMatrice<T> operator*(CMatrice<T> MATmatrice);


	/*****************************************
	Opérateur - à paramètre de type T.
	******************************************
	Entree : la valeur à soustraire (de type T).
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   soustraction de la valeur passée en paramètre avec toutes les cases de la matrice.
	******************************************/

	CMatrice<T> operator-(T tValeur);
	

	/*****************************************
	Operateur - à paramètre de type CMatrice.
	******************************************
	Entrée : instance de la classe CMatrice.
	Nécessite : les matrices sont de même dimension.
	Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
	Entraîne : Allocation d'un nouvel objet CMatrice.
	******************************************/

	CMatrice<T> operator-(CMatrice<T> MATmatrice);


	/*****************************************
	Opérateur / à paramètre de type T.
	******************************************
	Entree : la valeur à diviser (de type T).
	Necessite : rien.
	Sortie : instance de la classe CMatrice contenant le résultat de la division.
	Entraîne : Allocation d'un nouvel objet CMatrice,
			   division de la valeur passée en paramètre avec toutes les cases de la matrice.
	******************************************/

	CMatrice<T> operator/(T tValeur);


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
	*****************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de lignes de la matrice (unsigned int).
	Entraîne : rien.
	*****************************************
	*/
	unsigned int MATgetNbLignes();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	T MATgetValeur(unsigned int uiLigne, unsigned int uiColonne);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	T * MATgetLigne(unsigned int uiLigne);

	
	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	T * MATgetColonne(unsigned int uiColonne);


	// ----- Setters ----------------------------------------

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	void MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	void MATsetNbLignes(unsigned int uiNbLignes);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	void MATsetNbColonnes(unsigned int uiNbColonnes);

	// ----- Calculs ----------------------------------------

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	unsigned int MATrang();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> MATechelonnee();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> MATtransposee();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> MATsousMatrice();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MATestNulle();
};

// Opérateurs complémentaires

template <class T>
CMatrice<T> operator+(T tValeur, CMatrice<T> MATmatrice);

template <class T>
CMatrice<T> operator-(T tValeur, CMatrice<T> MATmatrice);

template <class T>
CMatrice<T> operator*(T tValeur, CMatrice<T> MATmatrice);


#include "Matrice.cpp"

#endif
