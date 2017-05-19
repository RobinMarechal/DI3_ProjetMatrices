#include "OperationMatrice.h"


template <class T>
COperationMatrice<T>::COperationMatrice()
{
}


template <class T>
COperationMatrice<T>::~COperationMatrice()
{
}




/*****************************************
Le rang de la matrice.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : le rang de la matrice.
Entra�ne : rien.
******************************************/
template <class T>
unsigned int COperationMatrice<T>::OPMrang(const CMatrice<T> & MATmatrice) const
{
	CTesteurMatrice<T> TEStesteur;
	COperationMatrice<T> OPMop;
	const CMatrice<T> MATech = OPMop.OPMechelonnee(MATmatrice);
	unsigned int uiBoucleL = 0;
	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();

	// On �chelonne la matrice et compte le nombre de lignes non nulles
	while (uiBoucleL < uiNbLignes && !TEStesteur.TESligneEstNulle(MATech, uiBoucleL))
	{
		uiBoucleL++;
	}

	return uiBoucleL;
}


/*****************************************
Echelonnement de la matrice.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : une matrice �chelonn�es (non r�duite => change le d�terminant).
Entra�ne : rien.
******************************************/
template <class T>
CMatrice<T> COperationMatrice<T>::OPMechelonnee(const CMatrice<T> & MATmatrice) const
{
	unsigned int uiLignes,
		uiColonnes,
		uiIndicePivot;

	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();
	unsigned int uiNbColonnes = MATmatrice.MATgetNbColonnes();

	T iPivot, iCoefficientLigne;

	CMatrice <T> MATresult(MATmatrice);

	for (uiIndicePivot = 0; uiIndicePivot < uiNbColonnes; uiIndicePivot++)
	{
		for (uiLignes = 1 + uiIndicePivot; uiLignes < uiNbLignes; uiLignes++)
		{
			iPivot = MATresult.MATgetValeur(uiIndicePivot, uiIndicePivot);
			iCoefficientLigne = MATresult.MATgetValeur(uiLignes, uiIndicePivot);

			for (uiColonnes = 0; uiColonnes < uiNbColonnes; uiColonnes++)
			{
				MATresult.MATsetValeur(uiLignes, uiColonnes, iPivot * MATresult.MATgetValeur(uiLignes, uiColonnes)
					- iCoefficientLigne * MATresult.MATgetValeur(uiIndicePivot, uiColonnes));
			}
		}
	}

	return MATresult;
}


/*****************************************
Transpos�e de la matrice.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : la transpos�e de la matrice
Entra�ne : rien.
******************************************/
template <class T>
CMatrice<T> COperationMatrice<T>::OPMtransposee(const CMatrice<T> & MATmatrice) const
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();
	unsigned int uiNbColonnes = MATmatrice.MATgetNbColonnes();

	CMatrice<T> MATresult(uiNbColonnes, uiNbLignes);

	for (uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			MATresult(uiBoucleC, uiBoucleL) = MATmatrice(uiBoucleL, uiBoucleC);
		}
	}

	return MATresult;
}



/*****************************************
Calcul d'une sous-matrice.
******************************************
Entr�e : l'indice de la ligne.
Entr�e : l'indice de la colonne.
N�cessite : uiLigne >= 0 et est inferieur au nombre de lignes de la matrice.
N�cessite : uiColonne >= 0 et est inferieur au nombre de de colonnes de la matrice.
Sortie : une instance de CMatrice poss�dant une ligne et une colonne de moins
contenant les valeurs de la matrice qui ne sont pas sur la lige uiLigne ou
sur la colonne uiColonne.
Entra�ne : rien.
******************************************/
template <class T>
CMatrice<T> COperationMatrice<T>::OPMsousMatrice(const CMatrice<T> & MATmatrice, unsigned int uiLigne, unsigned int uiColonne) const
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();
	unsigned int uiNbColonnes = MATmatrice.MATgetNbColonnes();

	CMatrice<T> MATresultat(uiNbLignes - 1, uiNbColonnes - 1);

	for (uiBoucleL = 0; uiBoucleL < uiNbLignes - 1; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiNbColonnes - 1; uiBoucleC++)
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

			MATresultat(uiBoucleL, uiBoucleC) = MATmatrice(uiIndiceL, uiIndiceC);
		}
	}

	return MATresultat;
}


/*****************************************
Calcul du d�terminant.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : la valeur du d�terminant.
Entra�ne : rien.
******************************************/
template <class T>
T COperationMatrice<T>::OPMdet(const CMatrice<T> & MATmatrice) const
{
	if (MATmatrice.MATgetNbLignes() == 1)
	{
		return MATmatrice(0, 0);
	}
	else
	{
		T tDeterminant = 0;
		CTesteurMatrice<T> TEStesteur;
		unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();
		unsigned int uiNbColonnes = MATmatrice.MATgetNbColonnes();

		// Le determinant d'une matrice triangulaire est le produit des �lements de la diagonale
		if (TEStesteur.TESestTriangulaire(MATmatrice))
		{
			tDeterminant = MATmatrice(0, 0);
			unsigned int uiBoucle;
			// Si a un moment donn� tDeterminant = 0, on peut stopper la boucle et retourner 0
			for (uiBoucle = 1; uiBoucle < uiNbColonnes && tDeterminant != 0; uiBoucle++)
			{
				tDeterminant = tDeterminant * MATmatrice(uiBoucle, uiBoucle);
			}

			return tDeterminant;
		}
		else
		{
			unsigned int uiBoucleL;
			// Formule de Leibniz
			for (uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
			{
				CMatrice<T> MATsousMat = OPMsousMatrice(MATmatrice, uiBoucleL, 0);
				int iSignature = -1;
				if ((uiBoucleL) % 2 == 0)
					iSignature = 1;

				tDeterminant += MATmatrice(uiBoucleL, 0) * OPMdet(MATsousMat) * iSignature;
			}

			return tDeterminant;
		}
	}
}


/*****************************************
Calcul de la trace d'une matrice.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : la valeur de la trace.
Entra�ne : rien.
******************************************/
template <class T>
T COperationMatrice<T>::OPMtr(const CMatrice<T> & MATmatrice) const
{
	unsigned int uiBoucle;
	unsigned int uiNbLignes = MATmatrice.MATgetNbLignes();
	T tTrace = 0;

	for (uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		tTrace += MATmatrice(uiBoucle, uiBoucle);
	}

	return tTrace;
}


/*****************************************
Calcul de la commatrice.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : une instance de CMatrice �gale a la commatrice de l'objet.
Entra�ne : rien.
******************************************/
template <class T>
CMatrice<T> COperationMatrice<T>::OPMcommatrice(const CMatrice<T> & MATmatrice) const
{
	unsigned int uiBoucleL, uiBoucleC;
	unsigned int uiDim = MATmatrice.MATgetNbLignes();
	CMatrice<T> MATresultat(uiDim, uiDim);

	for (uiBoucleL = 0; uiBoucleL < uiDim; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiDim; uiBoucleC++)
		{
			CMatrice<T> MATsousMat = OPMsousMatrice(MATmatrice, uiBoucleL, uiBoucleC);
			int iSignature = -1;
			if ((uiBoucleL + uiBoucleC) % 2 == 0)
				iSignature = 1;

			MATresultat(uiBoucleL, uiBoucleC) = iSignature * OPMdet(MATsousMat);
		}
	}

	return MATresultat;
}



/*****************************************
Calcul de l'inverse d'une matrice.
******************************************
Entr�e : rien.
N�cessite : La matrice est carr�e.
Sortie : une instance de CMatrice �gale � l'inverse de l'objet.
Entra�ne : Une Cexception est lev�e si le determinant est nul.
******************************************/
template <class T>
CMatrice<T> COperationMatrice<T>::OPMinverse(const CMatrice<T> & MATmatrice) const
{
	T tDet;
	CMatrice<T> MATcomm, MATtransComm;

	tDet = OPMdet(MATmatrice);

	if (tDet == 0)
	{
		throw Cexception(EXC_DIVISION_PAR_ZERO, "Calcul de l'inverse impossible : D�terminant nul.");
	}

	MATcomm = OPMcommatrice(MATmatrice);
	MATtransComm = OPMtransposee(MATcomm);

	return MATtransComm / tDet;
}



/*****************************************
Cr�ation d'une matrice diagonale.
******************************************
Entr�e : la dimension,
Entr�e : un tableau de valeurs.
N�cessite : la dimension du tableau est >= uiDim
(si elle est sup�rieure, seules les uiDim premi�res
valeurs seront prisent en compte).
Sortie : un matrice diagonale contenant les valeurs de ptDiag sur la diagonale.
Entra�ne : rien
******************************************/
template <class T>
CMatrice<T> COperationMatrice<T>::OPMcreerMatriceDiagonale(unsigned int uiDim, const T ptDiag[])
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


template <class T>
CMatrice<T> COperationMatrice<T>::OPMfactorisationCholeski(CMatrice<T>& MATmatrice)
{
	CTesteurMatrice<T> TEStesteur;

	if (!TEStesteur.TESestCarree(MATmatrice))
		throw Cexception(EXC_DIMENSIONS_INVALIDES, "La matrice n'est pas carree.");
	
	T tSomme;
	unsigned int uiBoucleI, uiBoucleJ, uiBoucleK;
	unsigned int uiDim = MATmatrice.MATgetNbLignes();

	// Matrice L de la factorisation de choleski
	CMatrice<T> MATresult(uiDim, uiDim);
	MATresult(0, 0) = sqrt(MATmatrice(0, 0));


	for(uiBoucleI = 1; uiBoucleI < uiDim; uiBoucleI++)
	{
		for(uiBoucleJ = 0; uiBoucleJ < uiBoucleI; uiBoucleJ++)
		{
			tSomme = 0;
			for(uiBoucleK = 0; uiBoucleK < uiBoucleJ; uiBoucleK++)
			{
				tSomme = tSomme + MATresult(uiBoucleI, uiBoucleK) * MATresult(uiBoucleI, uiBoucleK);
			}

			MATresult(uiBoucleI, uiBoucleJ) = (MATmatrice(uiBoucleI, uiBoucleJ) - tSomme) / MATresult(uiBoucleJ, uiBoucleJ);
		}

		tSomme = 0;
		for(uiBoucleK = 0; uiBoucleK < uiBoucleI; uiBoucleK++)
		{
			tSomme = tSomme + MATresult(uiBoucleI, uiBoucleK) * MATresult(uiBoucleI, uiBoucleK);
		}

		if (tSomme <= 0)
			throw Cexception(EXC_CALCUL_IMPOSSIBLE, "La matrice n'est pas definie positive, le calcul de la factorisation de Choleski est impossible.");
	
		MATresult(uiBoucleI, uiBoucleI) = sqrt(MATmatrice(uiBoucleJ, uiBoucleJ) - tSomme);
	}

	return MATresult;

}
