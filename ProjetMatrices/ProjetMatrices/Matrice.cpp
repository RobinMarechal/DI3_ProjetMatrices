#include "Matrice.h"
#include "Cexception.h"

#include <iostream>

using namespace std;

// ----- Constructeurs et destructeurs----------------------------------------

/*****************************************
Constructeur par défaut.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : initialisation de l'objet.
*****************************************/

template <class T>
CMatrice<T>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMATmatrice = nullptr;
}

/*****************************************
Constructeur à deux arguments.
******************************************
Entrée : le nombre de lignes (unsigned int)
		 le nombre de colonnes (unsigned in
Nécessite : rien.
Sortie : rien.
Entraîne : Initialisation de l'objet.
******************************************/

template <class T>
CMatrice<T>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATnbLignes = uiNbLignes;
	uiMATnbColonnes = uiNbColonnes;
	MATinitMatrice();
}

/****************************************
Constructeur de recopie.
*****************************************
Entrée : instance de la classe CMatrice.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation de l'objet.
*****************************************/

template <class T>
CMatrice<T>::CMatrice(CMatrice<T> & MATmatrice)
{
	unsigned int uiLigne, uiColonne;

	// Initialisation
	uiMATnbLignes = MATmatrice.uiMATnbLignes;
	uiMATnbColonnes = MATmatrice.uiMATnbColonnes;
	MATinitMatrice();

	// Copie
	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			MATsetValeur(uiLigne, uiColonne, MATmatrice.MATgetValeur(uiLigne, uiColonne));
		}
	}
}

/****************************************
Destructeur.
*****************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : destruction de l'objet,
		   désallocation du tableau 2D.
****************************************/

template <class T>
CMatrice<T>::~CMatrice()
{
	MATdesallouerMatrice();
}


// ----- Operateurs ----------------------------------------

/*****************************************
Opérateur ().
******************************************
Entrée : indice de la ligne (unsigned int)
		 indice de la colonne (unsigned in
Nécessite : rien.
Sortie : valeur de la position (i, j) dans
Entraîne : rien.
*****************************************/

template <class T>
inline T & CMatrice<T>::operator()(unsigned int uiLigne, unsigned int uiColonne) const
{
	if (uiLigne >= uiMATnbLignes || uiColonne >= uiMATnbColonnes)
		throw Cexception(0, "Operator () : Indice invalide");

	return ppMATmatrice[uiColonne][uiLigne];
}

/*****************************************
Operateur =.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : rien.
Sortie : instance de la classe CMatrice par référence,
		 copie de celle en paramètre
Entraîne : la recopie de l'objet en paramètre
******************************************/

template <class T>
CMatrice<T> & CMatrice<T>::operator=(CMatrice<T> & MATmatrice)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	// Initialisation
	uiMATnbLignes = MATmatrice.uiMATnbLignes;
	uiMATnbColonnes = MATmatrice.uiMATnbColonnes;
	MATinitMatrice();

	// Copie
	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			MATsetValeur(uiLigne, uiColonne, MATmatrice.MATgetValeur(uiLigne, uiColonne));
		}
	}
	
	return *this;
}

/*****************************************
Operateur ==.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : rien.
Sortie : booléen.
Entraîne : (true : les matrices sont identiques)
		   OU (false : les matrices sont différentes).
******************************************/

template <class T>
bool CMatrice<T>::operator==(CMatrice<T> & MATmatrice)
{
	if (uiMATnbColonnes != MATmatrice.uiMATnbColonnes || uiMATnbLignes != MATmatrice.uiMATnbLignes)
		return false;

	unsigned int uiLigne;
	unsigned int uiColonne;

	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			// Les coefficients sont diff�rents : les matrices sont diff�rentes.
			if (MATmatrice.ppMATmatrice[uiColonne][uiLigne] != ppMATmatrice[uiColonne][uiLigne])
				return false;
		}
	}		
	// Les matrices sont identiques.
	return true;
}

/*****************************************
Operateur !=.
******************************************
Entrée : instance de la classe CMatrice.
Necessite : rien.
Sortie : booléen.
Entraîne : (true : les matrices sont différentes)
		   OU (false : les matrices sont identiques).
******************************************/

template <class T>
bool CMatrice<T>::operator!=(CMatrice<T> & MATmatrice)
{
	return !(*this == MATmatrice);
}

/*****************************************
Opérateur + à paramètre de type T. 
******************************************
Entrée : la valeur à ajouter (de type T).
Nécessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat de la somme.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   ajout de la valeur passée en paramètre à toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator+(T tValeur)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<T> MATmatrice(uiMATnbLignes, uiMATnbColonnes);

	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			MATmatrice(uiLigne, uiColonne) = MATgetValeur(uiLigne, uiColonne) + tValeur;
		}
	}

	return MATmatrice;
}

/*****************************************
Operateur + à paramètre de type CMatrice.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : les matrices sont de même dimension.
Sortie : instance de la classe CMatrice contenant le résultat de la somme.
Entraîne : Allocation d'un nouvel objet CMatrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator+(CMatrice<T> MATmatrice)
{
	unsigned int uiBoucleL, uiBoucleC;
	CMatrice<T> MATresultat(uiMATnbLignes, uiMATnbColonnes);

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			MATresultat(uiBoucleL, uiBoucleC) = MATgetValeur(uiBoucleL, uiBoucleC) + MATmatrice(uiBoucleL, uiBoucleC);
		}
	}

	return MATresultat;
}

/*****************************************
Opérateur * à paramètre de type T.
*****************************************
Entree : la valeur à multiplier (de type T).
Necessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat du produit.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   multiplication de la valeur passée en paramètre avec toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator*(T tValeur)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<T> MATmatrice(uiMATnbLignes, uiMATnbColonnes);

	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			MATmatrice(uiLigne, uiColonne) = MATgetValeur(uiLigne, uiColonne) * tValeur;
		}
	}

	return MATmatrice;
}

/*****************************************
Operateur * à paramètre de type CMatrice.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : le nombre de colonnes de la première matrice
			et le nombre de lignes de la deuxième matrice sont identiques.
Sortie : instance de la classe CMatrice contenant le résultat du produit.
Entraîne : Allocation d'un nouvel objet CMatrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator*(CMatrice<T> MATmatrice)
{
	if(uiMATnbColonnes != MATmatrice.uiMATnbLignes)
	{
		throw Cexception(0, "Operator * : Dimensions invalides");
	}

	unsigned int uiBoucleL, uiBoucleC, uiBouclePdt;
	CMatrice<T> MATresultat(uiMATnbLignes, MATmatrice.uiMATnbColonnes);

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < MATmatrice.uiMATnbColonnes; uiBoucleC++)
		{
			// MATresultat(uiBoucleL, uiBoucleC) est egal 
			// au produit scalaire de la ligne uiBoucleL de *this
			// par la colonne uiBoucleC de MATmatrice.
			T tPdt = 0;
			for (uiBouclePdt = 0; uiBouclePdt < uiMATnbColonnes; uiBouclePdt++)
			{
				tPdt = tPdt + MATgetValeur(uiBoucleL, uiBouclePdt) * MATmatrice(uiBouclePdt, uiBoucleC);
			}
			
			MATresultat(uiBoucleL, uiBoucleC) = tPdt;
		}
	}

	return MATresultat;
}

/*****************************************
Opérateur - à paramètre de type T.
******************************************
Entree : la valeur à soustraire (de type T).
Necessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   soustraction de la valeur passée en paramètre avec toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator-(T tValeur)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<T> MATmatrice(*this);

	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			MATmatrice(uiLigne, uiColonne) = MATmatrice(uiLigne, uiColonne) - tValeur;
		}
	}

	return MATmatrice;
}

/*****************************************
Operateur - à paramètre de type CMatrice.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : les matrices sont de même dimension.
Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
Entraîne : Allocation d'un nouvel objet CMatrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator-(CMatrice<T> MATmatrice)
{
	unsigned int uiBoucleL, uiBoucleC;
	CMatrice<T> MATresultat(*this);

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			MATresultat(uiBoucleL, uiBoucleC) = MATgetValeur(uiBoucleL, uiBoucleC) - MATmatrice(uiBoucleL, uiBoucleC);
		}
	}

	return MATresultat;
}

/*****************************************
Opérateur / à paramètre de type T.
******************************************
Entree : la valeur à diviser (de type T).
Necessite : tValeur doit être différente de 0.
Sortie : instance de la classe CMatrice contenant le résultat de la division.
Entraîne : Allocation d'un nouvel objet CMatrice,
		   division de la valeur passée en paramètre avec toutes les cases de la matrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::operator/(T tValeur)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<T> MATmatrice(*this);

	for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
	{
		for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
		{
			MATmatrice(uiLigne, uiColonne) = MATmatrice(uiLigne, uiColonne) / tValeur;
		}
	}

	return MATmatrice;
}

// ----- Getters ----------------------------------------

/*****************************************
Affichage d'une matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'affichage de la matrice.
******************************************/

template <class T>
void CMatrice<T>::MATafficher()
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	for (uiLigne = 0; uiLigne < uiMATnbLignes; uiLigne++)
	{
		for (uiColonne = 0; uiColonne < uiMATnbColonnes; uiColonne++)
		{
			cout << MATgetValeur(uiLigne, uiColonne) << " ";
		}

		cout << endl;
	}
}

/*****************************************
Lecture du nombre de colonnes.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le nombre de colonnes de la matrice (unsigned int).
Entraîne : rien.
******************************************/

template <class T>
inline unsigned int CMatrice<T>::MATgetNbColonnes() const
{
	return uiMATnbColonnes;
}

/*****************************************
Lecture du nombre de lignes.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le nombre de lignes de la matrice (unsigned int).
Entraîne : rien.
******************************************/

template <class T>
inline unsigned int CMatrice<T>::MATgetNbLignes() const
{
	return uiMATnbLignes;
}

/*****************************************
Lecture de la valeur d'un coefficient.
******************************************
Entéee : l'indice de la ligne (unsigned int),
		 l'indice de la colonne (unsigned int).
Nécessite : rien.
Sortie : le coefficient à la position (uiLigne, uiColonne).
Entraîne : rien.
******************************************/

template <class T>
inline T & CMatrice<T>::MATgetValeur(unsigned int uiLigne, unsigned int uiColonne) const
{
	return (*this)(uiLigne, uiColonne);
}

/*****************************************
Lecture d'une ligne.
******************************************
Entrée : l'indice de la ligne (unsigned int).
Nécessite : rien.
Sortie : la ligne à l'indice uiLigne.
Entraîne : rien.
******************************************/

template <class T>
T * CMatrice<T>::MATgetLigne(unsigned int uiLigne) const
{
	unsigned int uiBoucleC;
	T * tTab = new T[uiMATnbColonnes];
	
	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		tTab[uiBoucleC] = MATgetValeur(uiLigne, uiBoucleC);
	}

	return tTab;
}

/*****************************************
Lecture d'une colonne.
******************************************
Entrée : l'indice de la colonne (unsigned int).
Nécessite : rien.
Sortie : la colonne à l'indice uiColonne.
Entraîne : rien.
******************************************/

template <class T>
T * CMatrice<T>::MATgetColonne(unsigned int uiColonne) const
{
	unsigned int uiBoucleL;
	T * tTab = new T[uiMATnbLignes];

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		tTab[uiBoucleL] = MATgetValeur(uiBoucleL, uiColonne);
	}

	return tTab;
}

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

template <class T>
inline void CMatrice<T>::MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur)
{
	(*this)(uiLigne, uiColonne) = tValeur;
}

/*****************************************
Mutateur pour le nombre de lignes.
******************************************
Entrée : le nombre de lignes (unsigned int).
Nécessite : rien.
Sortie : rien.
Entraîne : une initialisation ou modification du nombre de lignes de la matrice.
******************************************/

template <class T>
inline void CMatrice<T>::MATsetNbLignes(unsigned int uiNbLignes)
{
	MATajouterLignes(uiNbLignes - uiMATnbLignes);
	uiMATnbLignes = uiNbLignes;
}

/*****************************************
Mutateur pour le nombre de colonnes.
******************************************
Entrée : le nombre de colonnes (unsigned int).
Nécessite : rien.
Sortie : rien.
Entraîne : une initialisation ou modification du nombre de colonnes de la matrice.
******************************************/

template <class T>
inline void CMatrice<T>::MATsetNbColonnes(unsigned int uiNbColonnes)
{
	MATajouterColonnes(uiNbColonnes - uiMATnbColonnes);
	uiMATnbColonnes = uiNbColonnes;
}

// ----- Calculs ----------------------------------------

/*****************************************
Le rang de la matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le rang de la matrice (unsigned int).
Entraîne : rien.
******************************************/

template <class T>
unsigned int CMatrice<T>::MATrang()
{
	CMatrice<T> MATech = MATechelonnee();
	unsigned int uiBoucleL = 0;

	while (uiBoucleL < uiMATnbLignes && !MATech.MATligneEstNulle(uiBoucleL))
	{
		uiBoucleL++;
	}

	return uiBoucleL;
}

/*****************************************
Echelonnement de la matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : une instance de CMatrice.
Entraîne : l'échelonnement de la matrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::MATechelonnee()
{
	unsigned int uiLignes,
				 uiColonnes,
				 uiIndicePivot;
    
    T iPivot,
		iCoefficientLigne;

	CMatrice <T> MATmatrice(*this);
    
    for (uiIndicePivot = 0; uiIndicePivot < uiMATnbColonnes; uiIndicePivot++)
    {
        for (uiLignes = 1 + uiIndicePivot; uiLignes < uiMATnbLignes; uiLignes++)
        {
            iPivot = MATmatrice.MATgetValeur(uiIndicePivot, uiIndicePivot);
            
            iCoefficientLigne = MATmatrice.MATgetValeur(uiLignes, uiIndicePivot);
            
            for (uiColonnes = 0; uiColonnes < uiMATnbColonnes; uiColonnes++)
            {
                MATmatrice.MATsetValeur(uiLignes, uiColonnes, iPivot * MATmatrice.MATgetValeur(uiLignes, uiColonnes)
                                        - iCoefficientLigne * MATmatrice.MATgetValeur(uiIndicePivot, uiColonnes));
            }
        }
    }
    
    return MATmatrice;
}

/*****************************************
Transposée de la matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : une instance de CMatrice.
Entraîne : une transposition de la matrice.
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::MATtransposee()
{
	unsigned int uiBoucleL, uiBoucleC;
	CMatrice<T> MATresultat(uiMATnbColonnes, uiMATnbLignes);


	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			MATresultat(uiBoucleC, uiBoucleL) = MATgetValeur(uiBoucleL, uiBoucleC);
		}
	}

	return MATresultat;
}

/*****************************************
Calcul d'une sous-matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : une instance de CMatrice.
Entraîne : //
******************************************/

template <class T>
CMatrice<T> CMatrice<T>::MATsousMatrice(unsigned int uiLigne, unsigned int uiColonne) const
{
	CMatrice<T> m(uiMATnbLignes - 1, uiMATnbColonnes - 1);

	return m;
}

/*****************************************
Test de matrice nulle.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un booléen.
Entraine : (true : la matrice est nulle)
		   OU (false : la matrice n'est pas nulle).
******************************************/

template <class T>
bool CMatrice<T>::MATestNulle() const
{
	unsigned int uiBoucleL, uiBoucleC;

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			if (MATgetValeur(uiBoucleL, uiBoucleC) != 0)
			{
				return false;
			}
		}
	}

	return true;
}

/*****************************************
Initialisation de la matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : initialisation de l'objet.
******************************************/

template <class T>
void CMatrice<T>::MATinitMatrice()
{
	unsigned int uiBoucle;
	ppMATmatrice = (T **) malloc(sizeof(T *) * uiMATnbColonnes);

	if (ppMATmatrice == nullptr)
	{
		throw Cexception(0, "MATinitMatrice() : Mallocation failed");
	}

	for (uiBoucle = 0; uiBoucle < uiMATnbColonnes; uiBoucle++)
	{
		ppMATmatrice[uiBoucle] = (T *) calloc(uiMATnbLignes, sizeof(T));

		if (ppMATmatrice[uiBoucle] == nullptr)
		{
			throw Cexception(0, "MATinitMatrice() : Callocation failed");
		}
	}
}

/*****************************************
Test d'une ligne nulle.
******************************************
Entrée : l'indice de la ligne (unsigned int).
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : la ligne est nulle)
		   OU (false : la ligne n'est pas nulle).
******************************************/

template<class T>
bool CMatrice<T>::MATligneEstNulle(unsigned int uiLigne)
{
	unsigned int uiBoucleC;

	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		if (MATgetValeur(uiLigne, uiBoucleC) != 0)
		{
			return false;
		}
	}

	return true;
}

/*****************************************
Désalloue une matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : désalloue l'objet.
******************************************/

template <class T>
void CMatrice<T>::MATdesallouerMatrice()
{
	unsigned int uiBoucleC;

	// On desalloue toutes les colonnes
	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		free(ppMATmatrice[uiBoucleC]);
	}

	// Puis on desalloue le pointeur
	free(ppMATmatrice);
	ppMATmatrice = nullptr;
}

/*****************************************
Ajoute une ou des colonnes.
******************************************
Entrée : le nombre de colonnes (int).
Nécessite : rien.
Sortie : rien.
Entraîne : une réallocation du tableau 2D.
******************************************/

template<class T>
void CMatrice<T>::MATajouterColonnes(int iNb)
{
	if (iNb < 0 && (unsigned int) (-iNb) >= uiMATnbColonnes)
	{
		throw Cexception(0, "MATajouterColonnes() : Argument invalide");
	}

	ppMATmatrice = (T **)realloc(ppMATmatrice, (uiMATnbColonnes + iNb) * sizeof(T *));

	if (ppMATmatrice == nullptr)
	{
		throw Cexception(0, "MATajouterColonnes() : Echec de reallocation");
	}

	if (iNb > 0)
	{
		unsigned int uiBoucleC;

		for (uiBoucleC = uiMATnbColonnes; uiBoucleC < uiMATnbColonnes + iNb; uiBoucleC++)
		{
			ppMATmatrice[uiBoucleC] = (T *)calloc(uiMATnbLignes, sizeof(T));

			if (ppMATmatrice[uiBoucleC] == nullptr)
			{
				throw Cexception(0, "MATajouterColonnes() : Callocation failed");
			}
		}
	}
}

/*****************************************
Ajoute une ou plusieurs lignes.
******************************************
Entrée : le nombre de lignes (int).
Nécessite : rien.
Sortie : rien.
Entraîne : une réallocation du tableau 2D.
******************************************/

template<class T>
void CMatrice<T>::MATajouterLignes(int iNb)
{
	if (iNb < 0 && (unsigned int)(-iNb) >= uiMATnbLignes)
	{
		throw Cexception(0, "MATajouterLignes() : Argument invalide");
	}

	unsigned int uiBoucleC, uiBoucleL;

	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		ppMATmatrice[uiBoucleC] = (T *) realloc(ppMATmatrice[uiBoucleC], (uiMATnbLignes + iNb) * sizeof(T));

		if (ppMATmatrice[uiBoucleC] == nullptr)
		{
			throw Cexception(0, "MATajouterColonnes() : Reallocation failed");
		}

		for (uiBoucleL = uiMATnbLignes; uiBoucleL < uiMATnbLignes + iNb; uiBoucleL++)
		{
			ppMATmatrice[uiBoucleC][uiBoucleL] = 0;
		}
	}
}



// Operateurs complémentaires

template <class T>
CMatrice<T> operator+(const T tValeur, CMatrice<T> & MATmatrice)
{
	return MATmatrice + tValeur;
}

template <class T>
CMatrice<T> operator-(const T tValeur, CMatrice<T> & MATmatrice)
{
	return (MATmatrice - tValeur) * (-1);
}

template <class T>
CMatrice<T> operator*(const T tValeur, CMatrice<T> & MATmatrice)
{
	return MATmatrice * tValeur;
}

template<class T>
std::ostream & operator<<(std::ostream & OSTflux, const CMatrice<T>& MATmatrice)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	for (uiLigne = 0; uiLigne < MATmatrice.MATgetNbLignes(); uiLigne++)
	{
		for (uiColonne = 0; uiColonne < MATmatrice.MATgetNbColonnes(); uiColonne++)
		{
			OSTflux << MATmatrice(uiLigne, uiColonne) << " ";
		}

		OSTflux << endl;
	}

	return OSTflux;
}