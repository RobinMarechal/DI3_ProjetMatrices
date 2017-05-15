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
bool CTesteurMatrice<T>::TESestTriangulaire(const CMatrice<T> & MATmatrice) const
{
	return (TESestTriangulaireInferieure(MATmatrice) || TESestTriangulaireSuperieure(MATmatrice));
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
bool CTesteurMatrice<T>::TESestTriangulaireInferieure(const CMatrice<T> & MATmatrice) const
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();

	for (uiBoucleColonne = 1; uiBoucleColonne < uiNbLignes; uiBoucleColonne++)
	{
		for (uiBoucleLigne = 0; uiBoucleLigne < uiBoucleColonne; uiBoucleLigne++)
		{
			if (MATmatrice.MATgetValeur(uiBoucleLigne, uiBoucleColonne) != 0)
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
bool CTesteurMatrice<T>::TESestTriangulaireSuperieure(const CMatrice<T> & MATmatrice) const
{
	// La transposée d'une matrice triangulaire supérieure est triangulaire inférieure
	COperationMatrice<T> OPMoperation;
	CTesteurMatrice<T> TESt;
	CMatrice<T> MATtmp = OPMoperation.OPMtransposee(MATmatrice);
	return TESt.TESestTriangulaireInferieure(MATtmp);
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
bool CTesteurMatrice<T>::TESestDiagonale(const CMatrice<T> & MATmatrice) const
{
	// Pour la compréhension du code et la maintenabilité :
	return (TESestTriangulaireInferieure(MATmatrice) && TESestTriangulaireSuperieure(MATmatrice));
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
bool CTesteurMatrice<T>::TESestInversible(const CMatrice<T> & MATmatrice) const
{
	COperationMatrice<T> OPMoperation;
	return (MATmatrice.MATgetNbLignes() == MATmatrice.MATgetNbColonnes() && OPMoperation.OPMdet(MATmatrice) != 0);
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
bool CTesteurMatrice<T>::TESestSymetrique(const CMatrice<T> & MATmatrice) const
{
	COperationMatrice<T> OPMoperation;
	return (OPMoperation.OPMtransposee(MATmatrice) == MATmatrice);
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
bool CTesteurMatrice<T>::TESestAntiSymetrique(const CMatrice<T> & MATmatrice) const
{
	COperationMatrice<T> OPMoperation;
	return (OPMoperation.OPMtransposee(MATmatrice) == (MATmatrice * -1));
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
bool CTesteurMatrice<T>::TESestNulle(const CMatrice<T> & MATmatrice) const
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();
	unsigned int uiNbColonnes = MATmatrice.MATgetNbColonnes();

	for (uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			if (MATmatrice.MATgetValeur(uiBoucleL, uiBoucleC) != 0)
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
bool CTesteurMatrice<T>::TESligneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const
{
	unsigned int uiBoucleC;
	unsigned int uiNbColonnes = MATmatrice.MATgetNbColonnes();

	for (uiBoucleC = 0; uiBoucleC <uiNbColonnes; uiBoucleC++)
	{
		// Si au moins une valeur est non nulle, alors la ligne n'est pas nulle
		if (MATmatrice(uiLigne, uiBoucleC) != 0)
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
template <class T>
bool CTesteurMatrice<T>::TEScolonneEstNulle(const CMatrice<T> & MATmatrice, unsigned int uiLigne) const
{
	unsigned int uiBoucleC;

	for (uiBoucleC = 0; uiBoucleC < MATmatrice.uiMATnbColonnes; uiBoucleC++)
	{
		// Si au moins une valeur est non nulle, alors la ligne n'est pas nulle
		if (MATmatrice.MATgetValeur(uiLigne, uiBoucleC) != 0)
		{
			return false;
		}
	}

	return true;
}