#include "TesteurMatrice.h"



template <class T>
CTesteurMatrice<T>::CTesteurMatrice()
{
}


template <class T>
CTesteurMatrice<T>::~CTesteurMatrice()
{
}



/*****************************************
Teste si la matrice est triangulaire.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : un bool�en : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
Entra�ne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestTriangulaire() const
{
	return (TESestTriangulaireInferieure() || TESestTriangulaireSuperieure());
}


/*****************************************
Teste si la matrice est triangulaire inf�rieure.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : un bool�en : True = la matrice est triangulaire inf�rieur, False = la matrice n'est pas triangulaire inf�rieure.
Entra�ne : rien
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestTriangulaireInferieure() const
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


/*****************************************
Teste si la matrice est triangulaire sup�rieure.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : un bool�en : True = la matrice est triangulaire sup�rieure, False = la matrice n'est pas triangulaire sup�rieure.
Entra�ne : rien
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestTriangulaireSuperieure() const
{
	// La transpos�e d'une matrice triangulaire sup�rieure est triangulaire inf�rieure
	CMatrice<T> MATtmp = MATtransposee();
	return MATtmp.TESestTriangulaireInferieure();
}


/*****************************************
Teste si la matrice est diagonale.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : un bool�en : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
Entra�ne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestDiagonale() const
{
	// Pour la compr�hension du code et la maintenabilit� :
	return (TESestTriangulaireInferieure() && TESestTriangulaireSuperieure());
}


/*****************************************
Teste si la matrice est inversible.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : un bool�en : True = la matrice est inversible, False = la matrice n'est pas inversible.
Entra�ne : rien
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestInversible() const
{
	return (uiMATnbColonnes == uiMATnbLignes && MATdet() != 0);
}


/*****************************************
Teste si la matrice est sym�trique.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : un bool�en : True = la matrice est sym�trique, False = la matrice n'est pas sym�trique.
Entra�ne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestSymetrique() const
{
	return (MATtransposee() == *this);
}


/*****************************************
Teste si la matrice est antisym�trique.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : un bool�en : True = la matrice est antisym�trique, False = la matrice n'est pas antisym�trique.
Entra�ne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestAntiSymetrique() const
{
	return (MATtransposee() == (*this * -1));
}


/*****************************************
Test de matrice nulle.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : un bool�en : True = la matrice est nulle, False = la matrice n'est pas nulle.
Entraine : rien
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestNulle() const
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
Test si une ligne est null
******************************************
Entr�e : l'indice de la ligne
N�cessite : rien
Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
Entra�ne : rien
******************************************/
template<class T>
bool CTesteurMatrice<T>::MATligneEstNulle(unsigned int uiLigne) const
{
	unsigned int uiBoucleC;

	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		// Si au moins une valeur est non nulle, alors la ligne n'est pas nulle
		if (MATgetValeur(uiLigne, uiBoucleC) != 0)
		{
			return false;
		}
	}

	return true;
}


/*****************************************
Test si une colonne est nulle
******************************************
Entr�e : l'indice de la colonne
N�cessite : rien
Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
Entra�ne : rien
******************************************/
template<class T>
bool CTesteurMatrice<T>::MATcolonneEstNulle(unsigned int uiLigne) const
{
	unsigned int uiBoucleC;

	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		// Si au moins une valeur est non nulle, alors la ligne n'est pas nulle
		if (MATgetValeur(uiLigne, uiBoucleC) != 0)
		{
			return false;
		}
	}

	return true;
}