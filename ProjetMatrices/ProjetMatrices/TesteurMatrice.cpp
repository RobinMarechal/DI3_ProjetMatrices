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
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
Entraîne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestTriangulaire() const
{
	return (TESestTriangulaireInferieure() || TESestTriangulaireSuperieure());
}


/*****************************************
Teste si la matrice est triangulaire inférieure.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est triangulaire inférieur, False = la matrice n'est pas triangulaire inférieure.
Entraîne : rien
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
Teste si la matrice est triangulaire supérieure.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est triangulaire supérieure, False = la matrice n'est pas triangulaire supérieure.
Entraîne : rien
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestTriangulaireSuperieure() const
{
	// La transposée d'une matrice triangulaire supérieure est triangulaire inférieure
	CMatrice<T> MATtmp = MATtransposee();
	return MATtmp.TESestTriangulaireInferieure();
}


/*****************************************
Teste si la matrice est diagonale.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est diagonale, False = la matrice n'est pas diagonale.
Entraîne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestDiagonale() const
{
	// Pour la compréhension du code et la maintenabilité :
	return (TESestTriangulaireInferieure() && TESestTriangulaireSuperieure());
}


/*****************************************
Teste si la matrice est inversible.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un booléen : True = la matrice est inversible, False = la matrice n'est pas inversible.
Entraîne : rien
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestInversible() const
{
	return (uiMATnbColonnes == uiMATnbLignes && MATdet() != 0);
}


/*****************************************
Teste si la matrice est symétrique.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est symétrique, False = la matrice n'est pas symétrique.
Entraîne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestSymetrique() const
{
	return (MATtransposee() == *this);
}


/*****************************************
Teste si la matrice est antisymétrique.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est antisymétrique, False = la matrice n'est pas antisymétrique.
Entraîne : rien.
******************************************/
template <class T>
bool CTesteurMatrice<T>::TESestAntiSymetrique() const
{
	return (MATtransposee() == (*this * -1));
}


/*****************************************
Test de matrice nulle.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un booléen : True = la matrice est nulle, False = la matrice n'est pas nulle.
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
Entrée : l'indice de la ligne
Nécessite : rien
Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
Entraîne : rien
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
Entrée : l'indice de la colonne
Nécessite : rien
Sortie : True : ligne nulle, False : la ligne n'est pas nulle.
Entraîne : rien
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