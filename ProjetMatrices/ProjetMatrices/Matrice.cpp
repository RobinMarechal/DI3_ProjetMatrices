#include "Matrice.h"
#include "Cexception.h"

#include <iostream>

using namespace std;

// ----- Constructeurs et destructeurs----------------------------------------

template <class T>
CMatrice<T>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMATmatrice = nullptr;
}

template <class T>
CMatrice<T>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATnbLignes = uiNbLignes;
	uiMATnbColonnes = uiNbColonnes;
	MATinitMatrice();
}

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

template <class T>
CMatrice<T>::~CMatrice()
{
	MATdesallouerMatrice();
}


// ----- Operateurs ----------------------------------------

template <class T>
inline T & CMatrice<T>::operator()(unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiLigne >= uiMATnbLignes || uiColonne >= uiMATnbColonnes)
		throw Cexception(0, "Operator () : Indice invalide");

	return ppMATmatrice[uiColonne][uiLigne];
}


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


template <class T>
bool CMatrice<T>::operator!=( CMatrice<T> & MATmatrice)
{
	return !(*this == MATmatrice);
}



template <class T>
CMatrice<T> CMatrice<T>::operator+(const T & tValeur)
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



template <class T>
CMatrice<T> CMatrice<T>::operator+( CMatrice<T> & MATmatrice)
{
	unsigned int uiBoucleL, uiBoucleC;

	if (MATmatrice.uiMATnbColonnes != uiMATnbColonnes || MATmatrice.uiMATnbLignes != uiMATnbLignes)
	{
		throw Cexception(0, "operator+ : Dimensions invalides");
	}

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



template <class T>
CMatrice<T> CMatrice<T>::operator*(const T & tValeur)
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



template <class T>
CMatrice<T> CMatrice<T>::operator*( CMatrice<T> & MATmatrice)
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



template <class T>
CMatrice<T> CMatrice<T>::operator-(const T & tValeur)
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



template <class T>
CMatrice<T> CMatrice<T>::operator-(CMatrice<T> & MATmatrice)
{
	unsigned int uiBoucleL, uiBoucleC;

	if (MATmatrice.uiMATnbColonnes != uiMATnbColonnes || MATmatrice.uiMATnbLignes != uiMATnbLignes)
	{
		throw Cexception(0, "operator- : Dimensions invalides");
	}

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



template <class T>
CMatrice<T> CMatrice<T>::operator/(const T & tValeur)
{
	if (tValeur == 0)
	{
		throw Cexception(0, "operator / : Division par 0");
	}

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


template<class T>
CMatrice<T> CMatrice<T>::operator^(int iPuissance)
{
	if (iPuissance == 0)
	{
		// Impossible dans certains cas...
		throw Cexception(0, "Cette librairie ne permet pas d'élever une matrice à la puissance 0.");
	}

	unsigned int uiBoucle;
	bool bNegatif = false;

	// Si la puissance est negative, on prend sa valeur absolue 
	// car A^(-n) = A^(n^(-1))
	if (iPuissance < 0)
	{
		iPuissance *= -1;
		bNegatif = true;
	}

	CMatrice<T> MATresultat(*this);
	for (uiBoucle = 1; uiBoucle < (unsigned int)iPuissance; uiBoucle++)
	{
		MATresultat = MATresultat * *this;
	}

	// Puis on inverse le resultat si la puissance etait negative
	if (bNegatif)
	{
		MATresultat = MATresultat.MATinverse();
	}

	return MATresultat;
}


// ----- Getters ----------------------------------------


template <class T>
void CMatrice<T>::MATafficher()
{
	/*
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
	*/

	// Pour la maintenanabilité du code :
	std::cout << *this;
}



template <class T>
inline unsigned int CMatrice<T>::MATgetNbColonnes()
{
	return uiMATnbColonnes;
}



template <class T>
inline unsigned int CMatrice<T>::MATgetNbLignes()
{
	return uiMATnbLignes;
}



template <class T>
inline T & CMatrice<T>::MATgetValeur(unsigned int uiLigne, unsigned int uiColonne)
{
	return (*this)(uiLigne, uiColonne);
}



template <class T>
T * CMatrice<T>::MATgetLigne(unsigned int uiLigne)
{
	unsigned int uiBoucleC;
	T * tTab = new T[uiMATnbColonnes];
	
	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		tTab[uiBoucleC] = MATgetValeur(uiLigne, uiBoucleC);
	}

	return tTab;
}



template <class T>
T * CMatrice<T>::MATgetColonne(unsigned int uiColonne)
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


template <class T>
inline void CMatrice<T>::MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur)
{
	(*this)(uiLigne, uiColonne) = tValeur;
}



template <class T>
inline void CMatrice<T>::MATsetNbLignes(unsigned int uiNbLignes)
{
	MATajouterLignes(uiNbLignes - uiMATnbLignes);
	uiMATnbLignes = uiNbLignes;
}



template <class T>
inline void CMatrice<T>::MATsetNbColonnes(unsigned int uiNbColonnes)
{
	MATajouterColonnes(uiNbColonnes - uiMATnbColonnes);
	uiMATnbColonnes = uiNbColonnes;
}


// ----- Calculs ----------------------------------------


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



template <class T>
CMatrice<T> CMatrice<T>::MATsousMatrice(unsigned int uiLigne, unsigned int uiColonne)
{
	unsigned int uiBoucleL, uiBoucleC;
	CMatrice<T> MATresultat(uiMATnbLignes - 1, uiMATnbColonnes - 1);

	for (uiBoucleL = 0; uiBoucleL < MATresultat.uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < MATresultat.uiMATnbColonnes; uiBoucleC++)
		{
			unsigned int uiIndiceL = uiBoucleL, uiIndiceC = uiBoucleC;

			if (uiBoucleL >= uiLigne)
			{
				uiIndiceL = uiBoucleL + 1;
			}

			if (uiBoucleC >= uiColonne)
			{
				uiIndiceC = uiBoucleC + 1;
			}

			MATresultat(uiBoucleL, uiBoucleC) = MATgetValeur(uiIndiceL, uiIndiceC);
		}
	}
	
	return MATresultat;
}



template <class T>
bool CMatrice<T>::MATestNulle()
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



template <class T>
T CMatrice<T>::MATdet()
{
	if (MATgetNbLignes() == 1)
	{
		return ppMATmatrice[0][0];
	}
	else
	{
		unsigned int uiBoucleL;
		T tDeterminant = 0;
		for (uiBoucleL = 0; uiBoucleL < MATgetNbLignes(); uiBoucleL++)
		{
			CMatrice<T> MATsousMat = MATsousMatrice(uiBoucleL, 0);
			int iSignature = -1;
			if ((uiBoucleL) % 2 == 0)
				iSignature = 1;

			tDeterminant += MATgetValeur(uiBoucleL, 0) * MATsousMat.MATdet() * iSignature;
		}

		return tDeterminant;
	}
}



template <class T>
T CMatrice<T>::MATtr()
{
	unsigned int uiBoucle;
	T trace = 0;

	for (uiBoucle = 0; uiBoucle < MATgetNbLignes(); uiBoucle++)
	{
		trace += ppMATmatrice[uiBoucle][uiBoucle];
	}

	return trace;
}



template <class T>
CMatrice<T> CMatrice<T>::MATcommatrice()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MATgetNbLignes();
	CMatrice<T> MATresultat(uiDim, uiDim);

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			CMatrice<T> MATsousMat = MATsousMatrice(uiBoucleL, uiBoucleC);
			int iSignature = -1;
			if ((uiBoucleL + uiBoucleC) % 2 == 0)
				iSignature = 1;

			MATresultat(uiBoucleL, uiBoucleC) = iSignature * MATsousMat.MATdet();
		}
	}

	return MATresultat;
}



template <class T>
CMatrice<T> CMatrice<T>::MATinverse()
{
	T det;
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MATgetNbLignes();
	CMatrice<T> MATcomm, MATtransComm;

	det = MATdet();

	if (det == 0)
	{
		throw Cexception(0, "Calcul de l'inverse impossible : Déterminant nul.");
	}

	CMatrice<T> MATinv(uiDim, uiDim);
	MATcomm = MATcommatrice();
	MATtransComm = MATcomm.MATtransposee();

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			MATinv(uiBoucleL, uiBoucleC) = MATtransComm(uiBoucleL, uiBoucleC) / det;
		}
	}

	return MATinv;
}


template <class T>
bool CMatrice<T>::MATestTriangulaire()
{
	return (MATestTriangulaireInferieure() || MATestTriangulaireSuperieure());
}



template <class T>
bool CMatrice<T>::MATestTriangulaireInferieure()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
	for (uiBoucleColonne = 1; uiBoucleColonne < MATgetNbLignes(); uiBoucleColonne++)
	{
		for (uiBoucleLigne = 0; uiBoucleLigne < uiBoucleColonne; uiBoucleLigne++)
		{
			if (MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
			{
				// Si l'element dans le triangle inferieure est non nul
				// Alors la matrice n'est pas triangulaire inferieure
				return false;
			}
		}
	}

	return true;
}


template <class T>
bool CMatrice<T>::MATestTriangulaireSuperieure()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
	for (uiBoucleLigne = 1; uiBoucleLigne < MATgetNbLignes(); uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiBoucleLigne; uiBoucleColonne++)
		{
			if (MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
			{
				// Si l'element dans le triangle superiere est non nul
				// Alors la matrice n'est pas triangulaire superieure
				return false;
			}
		}
	}

	return true;
}



template <class T>
bool CMatrice<T>::MATestDiagonale()
{
	/*
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MATgetNbLignes();

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC)
		{
			if (uiBoucleL != uiBoucleC && MATgetValeur(uiBoucleL, uiBoucleC) != 0)
			{
				// Si l'element n'est pas sur la diagonale 
				// ET qu'il n'est pas nul
				return false;
			}
		}
	}

	return true;
	*/

	// Pour la compréhension du code et la maintenabilité :
	return (MATestTriangulaireInferieure() && MATestTriangulaireSuperieure());
}


template <class T>
bool CMatrice<T>::MATestInversible()
{
	return (MATdet() != 0);
}



template <class T>
bool CMatrice<T>::MATestSymetrique()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MATgetNbLignes();

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			if (uiBoucleL != uiBoucleC && MATgetValeur(uiBoucleL, uiBoucleC) != MATgetValeur(uiBoucleC, uiBoucleL))
			{
				// L'element a l'indice (uiBoucleL, uiBoucleC) n'est pas sur la diagonale
				// et (*this)(uiBoucleL, uiBoucleC) != (*this)(uiBoucleC, uiBoucleL)
				return false;
			}
		}
	}

	return true;
}


template <class T>
bool CMatrice<T>::MATestAntiSymetrique()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MATgetNbLignes();

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			if (MATgetValeur(uiBoucleL, uiBoucleC) != (-1) * MATgetValeur(uiBoucleC, uiBoucleL))
			{
				// L'element a l'indice (uiBoucleL, uiBoucleC) n'est pas sur la diagonale
				// et (*this)(uiBoucleL, uiBoucleC) != (-1) * (*this)(uiBoucleC, uiBoucleL)
				return false;
			}
		}
	}

	return true;
}

// preconditions : ^0 défini
template <class T>
CMatrice<T> CMatrice<T>::MATdiag(unsigned int uiDim, const T ptDiag[])
{
	unsigned int uiBoucleL, uiBoucleC;
	CMatrice<T> MATresultat(uiDim, uiDim);

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			if (uiBoucleL == uiBoucleC)
			{
				// On est sur la diagonale ==> valeur de ptDiag
				MATresultat(uiBoucleL, uiBoucleC) = ptDiag[uiBoucleL];
			}
			else
			{
				// On est en dehors de la diagonale ==> 0
				MATresultat(uiBoucleL, uiBoucleC) = 0;
			}
		}
	}
	return MATresultat;
}


// Operateurs complémentaires


template <class T>
CMatrice<T> operator+(const T & tValeur, CMatrice<T> & MATmatrice)
{
	return MATmatrice + tValeur;
}



template <class T>
CMatrice<T> operator-(const T & tValeur, CMatrice<T> & MATmatrice)
{
	return (MATmatrice - tValeur) * (-1);
}



template <class T>
CMatrice<T> operator*(const T & tValeur, CMatrice<T> & MATmatrice)
{
	return MATmatrice * tValeur;
}



template<class T>
std::ostream & operator<<(std::ostream & OSTflux, CMatrice<T>& MATmatrice)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	OSTflux << " Matrice " << MATmatrice.MATgetNbLignes() << " x " << MATmatrice.MATgetNbColonnes() << " : ";
	OSTflux << endl;
	for (uiLigne = 0; uiLigne < MATmatrice.MATgetNbLignes(); uiLigne++)
	{
		OSTflux << " |\t";
		for (uiColonne = 0; uiColonne < MATmatrice.MATgetNbColonnes(); uiColonne++)
		{
			OSTflux << MATmatrice(uiLigne, uiColonne) << "\t";
		}

		OSTflux << '|' << endl;
	}

	OSTflux << endl;

	return OSTflux;
}