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
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice();

	/*****************************************
	Constructeur a deux arguments
	*****************************************
	Entree : le nombre de lignes (unsigned int), le nombre de colonnes (unsigned int)
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	/*****************************************
	Destructeur
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : (Destruction de l'objet) et (desallocation du tableau 2D)
	*****************************************
	*/
	CMatrice(CMatrice<T> & MATmatrice);
	~CMatrice();


	// ----- Operateurs ----------------------------------------

	/*****************************************
	Operateur ()
	*****************************************
	Entree : indice de la ligne (unsigned int), indice de la colonne (unsigned int)
	Necessite : rien
	Sortie : Valeur a la position (i, j) dans la matrice
	Entraine : rien
	*****************************************
	*/
	T & operator()(unsigned int uiLigne, unsigned int uiColonne);

	/*****************************************
	Operateur =
	*****************************************
	Entree : Instance de la classe CMatrice
	Necessite : rien
	Sortie : Instance de la classe CMatrice par reference, copie de celle en parametre
	Entraine : Recopie de l'objet en parametre
	*****************************************
	*/
	CMatrice<T> & operator=(CMatrice<T> & MATmatrice);

	/*****************************************
	Operateur ==
	*****************************************
	Entree : Instance de la classe CMatrice
	Necessite : rien
	Sortie : booleen
	Entraine : (true : les matrices sont identiques) OU (false : les matrices sont differentes)
	*****************************************
	*/
	bool operator==(CMatrice<T> & MATmatrice);

	/*****************************************
	Operateur !=
	*****************************************
	Entree : Instance de la classe CMatrice
	Necessite : rien
	Sortie : booleen
	Entraine : (true : les matrices sont differentes) OU (false : les matrices sont identiques)
	*****************************************
	*/
	bool operator!=(CMatrice<T> & MATmatrice);

	/*****************************************
	Operateur + a parametre de type T : 
	Ajoute la valeur passee en parametre a toutes les cases de la matrice
	*****************************************
	Entree : valeur a ajouter (T)
	Necessite : rien
	Sortie : Instance de la classe CMatrice contenant le resultat de la somme
	Entraine : Allocation d'un nouvel objet CMatrice 
	*****************************************
	*/
	CMatrice<T> operator+(T tValeur);

	/*****************************************
	Operateur + a parametre de type CMatrice
	*****************************************
	Entree : CMatrice a ajouter
	Necessite : Matrices de meme dimension
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> operator+(CMatrice MATmatrice);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> operator*(T tValeur);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> operator*(CMatrice<T> MATmatrice);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> operator-(T tValeur);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> operator-(CMatrice<T> MATmatrice);

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatrice<T> operator/(T tValeur);

	// ----- Getters ----------------------------------------

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	void MATafficher();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	unsigned int MATgetNbColonnes();

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
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
