#include "MatriceCarree.h"

// ---------- Constructeurs de destructeur

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
CMatriceCarree<T>::CMatriceCarree() : CMatrice<T>() {}


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
CMatriceCarree<T>::CMatriceCarree(CMatriceCarree<T> & MACmatrice) : CMatrice<T>(MACmatrice) {}


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
CMatriceCarree<T>::CMatriceCarree(unsigned int uiDimension) : CMatrice<T>(uiDimension, uiDimension) {}

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
CMatriceCarree<T>::~CMatriceCarree() {}


// Operateurs 


/*****************************************
Constructeur par defaut
*****************************************
Entree : void
Necessite : Si iPuissance = 0 : (T est un type de base) OU (T est une classe qui surcharge l'operateur ^)
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
template <class T>
CMatriceCarree<T> CMatriceCarree<T>::operator^(int iPuissance)
{
	unsigned int uiBoucle;
	if (iPuissance == 0)
	{
		unsigned int uiDim = MACgetDimension();
		T tTab[uiDim];
		T tObjTmp;

		for (uiBoucle = 0; uiBoucle < uiDim; uiBoucle++)
		{
			tTab[uiBoucle] = tObjTmp ^ 0 ;
		}

		return CMatriceCarree<T>::MACdiag(uiDim)
	}
	else
	{
		bool bNegatif = false;

		// Si la puissance est negative, on prend sa valeur absolue 
		// car A^(-n) = A^(n^(-1))
		if (iPuissance < 0)
		{
			iPuissance *= -1;
			bNegatif = true;
		}

		CMatriceCarree<T> MATresultat(*this);
		for (uiBoucle = 1; uiBoucle < iPuissance; uiBoucle++)
		{
			MATresultat = MATresultat * *this;
		}

		// Puis on inverse le resultat si la puissance etait negative
		if (bNegatif)
		{
			MATresultat = MATresultat.MACinverse();
		}

		return MATresultat;
	}
}


// Getters

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
inline unsigned int CMatriceCarree<T>::MACgetDimension()
{
	return MATgetNbLignes();
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
inline void CMatriceCarree<T>::MACsetDimension(unsigned int uiDimension)
{
	MATsetNbLignes(uiDimension);
	MATsetNbColonnes(uiDimension);
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
T CMatriceCarree<T>::MACdet()
{
	if (MACgetDimension() == 1)
	{
		return ppMATmatrice[0][0];
	}
	else
	{
		unsigned int uiBoucleL;
		T tDeterminant = 0;
		for (uiBoucleL = 0; uiBoucleL < MACgetDimension(); uiBoucleL++)
		{
			CMatriceCarree<T> MACsousMatrice = MATsousMatrice(uiBoucleL, 0);
			int iSignature = -1;
			if ((uiBoucleL) % 2 == 0)
				iSignature = 1;

			dTeterminant += MATgetValeur(uiBoucleL, 0) * MACsousMatrice.MACdet() * iSignature;
		}

		return tDeterminant;
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
T CMatriceCarree<T>::MACtr()
{
	unsigned int uiBoucle;
	T trace;

	for (uiBoucle = 0; uiBoucle < MACgetDimension(); uiBoucle++)
	{
		trace += ppMATmatrice[uiBoucle][uiBoucle];
	}

	return trace;
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
CMatriceCarree<T> CMatriceCarree<T>::MACcommatrice()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MACgetDimension();
	CMatriceCarree<T> MACresultat(uiDim);

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			CMatriceCarree<T> MACsousMatrice = MATsousMatrice(uiBoucleL, uiBoucleC);
			int iSignature = -1;
			if ((uiBoucleL + uiBoucleC) % 2 == 0)
				iSignature = 1;

			MACresultat(uiBoucleL, uiBoucleC) = iSignature * MACsousMatrice.MACdet();
		}
	}

	return MACresultat;
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
CMatriceCarree<T> CMatriceCarree<T>::MACinverse()
{
	T det;
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MACgetDimension();
	CMatriceCarree<T> MACcomm, MACtransComm;

	CMatriceCarree<T> MACinv(uiDim);
	det = MACdet();
	MACcomm = MACcommatrice();
	MACtransComm = (CMatriceCarree) MATtransposee(MACcomm);

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			MACinv(uiBoucleL, uiBoucleC) = MACtransComm(uiBoucleL, uiBoucleC) / det;
		}
	}

	return MACinv;
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
bool CMatriceCarree<T>::MACestTriangulaire()
{
	return (MACestTriangulaireInferieure() || MACestTriangulaireSuperieure());
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
bool CMatriceCarree<T>::MACestTriangulaireSuperieure()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
	for (uiBoucleColonne= 1; uiBoucleColonne < MACgetDimension(); uiBoucleColonne++)
	{
		for (uiBoucleLigne = 0; uiBoucleLigne < uiBoucleColonne; uiBoucleLigne++)
		{
			if (MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
			{
				// Si l'element dans le triangle superiere est non nul
				// Alors la matrice c'est pas triangulaire superieurs
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
bool CMatriceCarree<T>::MACestTriangulaireInferieure()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
	for (uiBoucleLigne = 1; uiBoucleLigne < MACgetDimension(); uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonnee < uiBoucleLigne; uiBoucleColonne++)
		{
			if (MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
			{
				// Si l'element dans le triangle inferieure est non nul
				// Alors la matrice c'est pas triangulaire inferieure
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
bool CMatriceCarree<T>::MACestDiagonale()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MACgetDimension();

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
bool CMatriceCarree<T>::MACestInversible()
{
	return (MACdet() != 0);
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
bool CMatriceCarree<T>::MACestSymetrique()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MACgetDimension();

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
bool CMatriceCarree<T>::MACestAntiSymetrique()
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MACgetDimension();

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
static CMatriceCarree<T> CMatriceCarree<T>::MACdiag(unsigned int uiDim, T * ptDiag)
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MACgetDimension();
	CMatriceCarree<T> MACresultat(uiDim);

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			if (uiBoucleL == uiBoucleC)
			{
				// On est sur la diagonale ==> valeur de ptDiag
				MACresultat(uiBoucleL, uiBoucleC) = ptDiag[uiBoucleL];
			}
			else
			{
				// On est en dehors de la diagonale ==> 0
				MACresultat(uiBoucleL, uiBoucleC) = 0;
			}
		}
	}

	return MACresultat;
}