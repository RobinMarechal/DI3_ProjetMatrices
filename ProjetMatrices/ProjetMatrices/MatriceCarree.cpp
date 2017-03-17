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
unsigned int CMatriceCarree<T>::MACgetDimension()
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
void CMatriceCarree<T>::MACsetDimension(unsigned int uiDimension)
{
	uiMATnbLignes = uiDimension;
	uiMATnbColonnes = uiDimension;
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
	if (uiMATnbLignes == 1)
	{
		return ppMATmatrice[0][0];
	}
	else
	{
		unsigned int uiBoucleL;
		T tDeterminant = 0;
		for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
		{
			CMatriceCarree MACsousMatrice = MATsousMatrice(uiBoucleL, 0);
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

	for (uiBoucle = 0; uiBoucle < uiMATnbLignes; uiBoucle++)
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
CMatrice<T> CMatriceCarree<T>::MACcommatrice()
{
	unsigned int uiBoucleL, uiBoucleC;
	CMatriceCarree MACresultat(uiMATnbLignes);

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			CMatriceCarree MACsousMatrice = MATsousMatrice(uiBoucleL, uiBoucleC);
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
CMatrice<T> CMatriceCarree<T>::MACinverse()
{
	unsigned int uiBoucleL, uiBoucleC;
	T det;
	CMatriceCarree MACcomm, MACtransComm;

	CMatriceCarree MACinv(uiMATnbLignes);
	det = MACdet();
	MACcomm = MACcommatrice();
	MACtransComm = (CMatriceCarree) MATtransposee(MACcomm);

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
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
	for (uiBoucleColonne= 1; uiBoucleColonne < uiMATnbColonnes; uiBoucleColonne++)
	{
		for (uiBoucleLigne = 0; uiBoucleLigne < uiBoucleColonne; uiBoucleLigne++)
		{
			if (MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
				retur false;
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
	for (uiBoucleLigne = 1; uiBoucleLigne < uiMATnbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonnee < uiBoucleLigne; uiBoucleColonne++)
		{
			if (MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
				retur false;
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

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC)
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

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			if (uiBoucleL != uiBoucleC && MATgetValeur(uiBoucleL, uiBoucleC) != MATgetValeur(uiBoucleC, uiBoucleL))
			{
				// L'element a l'indice (uiBoucleL, uiBoucleC) n'est pas sur la diagonale
				// et il est different de l'element a l'indice (uiBoucleC, uiBoucleL)
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

	for (uiBoucleL = 0; uiBoucleL < uiMATnbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
		{
			if (MATgetValeur(uiBoucleL, uiBoucleC) != (-1) * MATgetValeur(uiBoucleC, uiBoucleL))
			{
				// L'element a l'indice (uiBoucleL, uiBoucleC)
				// n'est pas l'opposé de l'element a l'indice (uiBoucleC, uiBoucleL)
				return false;
			}
		}
	}

	return true;
}