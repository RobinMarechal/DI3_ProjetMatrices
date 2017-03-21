#include "Matrice.h"
#include "Cexception.h"

#include <iostream>

using namespace std;

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
template <class T>
CMatrice<T>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMATmatrice = nullptr;
}

/*****************************************
Constructeur a deux arguments
*****************************************
Entree : le nombre de lignes (unsigned int), le nombre de colonnes (unsigned int)
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
CMatrice<T>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATnbLignes = uiNbLignes;
	uiMATnbColonnes = uiNbColonnes;
	MATinitMatrice();
}

/*****************************************
Constructeur de recopie
*****************************************
Entree : une instance de la classe CMatrice
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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

/*****************************************
Destructeur
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : (Destruction de l'objet) et (desallocation du tableau 2D)
*****************************************
*/
template <class T>
CMatrice<T>::~CMatrice()
{
	MATdesallouerMatrice();
}


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

template <class T>
inline T & CMatrice<T>::operator()(unsigned int uiLigne, unsigned int uiColonne) const
{
	if (uiLigne >= uiMATnbLignes || uiColonne >= uiMATnbColonnes)
		throw Cexception(0, "Operator () : Indice invalide");

	return ppMATmatrice[uiColonne][uiLigne];
}

/*****************************************
Operateur =
*****************************************
Entree : Instance de la classe CMatrice
Necessite : rien
Sortie : Instance de la classe CMatrice par reference, copie de celle en parametre
Entraine : Recopie de l'objet en parametre
*****************************************
*/
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
Operateur ==
*****************************************
Entree : Instance de la classe CMatrice
Necessite : rien
Sortie : booleen
Entraine : (true : les matrices sont identiques) OU (false : les matrices sont differentes)
*****************************************
*/
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
Operateur !=
*****************************************
Entree : Instance de la classe CMatrice
Necessite : rien
Sortie : booleen
Entraine : (true : les matrices sont differentes) OU (false : les matrices sont identiques)
*****************************************
*/
template <class T>
bool CMatrice<T>::operator!=(CMatrice<T> & MATmatrice)
{
	return !(*this == MATmatrice);
}

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
Operateur + a parametre de type CMatrice
*****************************************
Entree : CMatrice a ajouter
Necessite : Matrices de meme dimension
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
inline unsigned int CMatrice<T>::MATgetNbColonnes() const
{
	return uiMATnbColonnes;
}

/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
inline unsigned int CMatrice<T>::MATgetNbLignes() const
{
	return uiMATnbLignes;
}

/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
inline T & CMatrice<T>::MATgetValeur(unsigned int uiLigne, unsigned int uiColonne) const
{
	return (*this)(uiLigne, uiColonne);
}

/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
inline void CMatrice<T>::MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur)
{
	(*this)(uiLigne, uiColonne) = tValeur;
}

/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
inline void CMatrice<T>::MATsetNbLignes(unsigned int uiNbLignes)
{
	MATajouterLignes(uiNbLignes - uiMATnbLignes);
	uiMATnbLignes = uiNbLignes;
}

/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
inline void CMatrice<T>::MATsetNbColonnes(unsigned int uiNbColonnes)
{
	MATajouterColonnes(uiNbColonnes - uiMATnbColonnes);
	uiMATnbColonnes = uiNbColonnes;
}

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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
CMatrice<T> CMatrice<T>::MATsousMatrice(unsigned int uiLigne, unsigned int uiColonne) const
{
	CMatrice<T> m(uiMATnbLignes - 1, uiMATnbColonnes - 1);

	return m;
}

/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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
Constructeur par defaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
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