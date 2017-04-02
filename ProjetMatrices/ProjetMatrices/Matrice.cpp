#include "Matrice.h"

#include <iostream>

#include "Cexception.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"

using namespace std;

// ----- Constructeurs et destructeurs----------------------------------------


/*****************************************
Constructeur par défaut.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : initialisation d'un objet CMatrice de dimensions 0 * 0
*****************************************/
template <class T>
CMatrice<T>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	pptMATmatrice = nullptr;
}



/*****************************************
Constructeur à deux arguments.
******************************************
Entrée : le nombre de lignes
Entrée : le nombre de colonnes
Nécessite : rien.
Sortie : rien.
Entraîne : initialisation d'un objet CMatrice de dimensions uiNbLignes * uiNbColonnes
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
Entraîne : l'initialisation de l'objet par copie de MATmatrice
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
Entraîne : Destruction de l'objet et libération de la mémoire allouée
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
Entrée : indice de la ligne,
Entrée : indice de la colonne.
Nécessite : 0 <= uiLigne < nombre de lignes;
Nécessite : 0 <= uiColonnes < nombre de colonnes;
Sortie : Référence de la valeur à la position (i, j) dans la matrice.
Entraîne : rien.
*****************************************/
template <class T>
inline T & CMatrice<T>::operator()(unsigned int uiLigne, unsigned int uiColonne)
{
	return pptMATmatrice[uiColonne][uiLigne];
}



/*****************************************
Operateur =.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : rien.
Sortie : instance de la classe CMatrice
Entraîne : Copie des valeurs des attributs de l'objet en paramètre
******************************************/
template <class T>
CMatrice<T> & CMatrice<T>::operator=(CMatrice<T> & MATmatrice)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	// Initialisation

	MATdesallouerMatrice();

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
Sortie : booléen : true = les matrices sont identiques, false = les matrices sont différentes
Entraîne : rien
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
			if (MATmatrice.pptMATmatrice[uiColonne][uiLigne] != pptMATmatrice[uiColonne][uiLigne])
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
Nécessite : rien.
Sortie : booléen : true = les matrices sont différentes, false = les matrices sont identiques
Entraîne : rien
******************************************/
template <class T>
bool CMatrice<T>::operator!=( CMatrice<T> & MATmatrice)
{
	return !(*this == MATmatrice);
}


/*****************************************
Opérateur + à paramètre de type T.
******************************************
Entrée : la valeur à ajouter.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant de la somme.
Entraîne : rien
******************************************/
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


/*****************************************
Operateur + à paramètre de type CMatrice.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : les matrices sont de même dimension.
Sortie : instance de la classe CMatrice contenant le résultat de la somme.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> CMatrice<T>::operator+( CMatrice<T> & MATmatrice)
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
Entraîne : rien
******************************************/
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


/*****************************************
Operateur * à paramètre de type CMatrice.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : le nombre de colonnes de la première matrice
et le nombre de lignes de la deuxième matrice sont identiques.
Sortie : instance de la classe CMatrice contenant le résultat du produit.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> CMatrice<T>::operator*( CMatrice<T> & MATmatrice)
{
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
Entree : la valeur à soustraire.
Necessite : rien.
Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> CMatrice<T>::operator-(const T & tValeur)
{
	return operator+(-tValeur);
}


/*****************************************
Operateur - à paramètre de type CMatrice.
******************************************
Entrée : instance de la classe CMatrice.
Nécessite : les matrices sont de même dimension.
Sortie : instance de la classe CMatrice contenant le résultat de la soustraction.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> CMatrice<T>::operator-(CMatrice<T> & MATmatrice)
{
	return operator+(MATmatrice * -1);
}


/*****************************************
Opérateur / à paramètre de type T.
******************************************
Entree : la valeur à diviser (de type T).
Necessite : tValeur doit être différente de 0.
Sortie : instance de la classe CMatrice contenant le résultat de la division.
Entraîne : Une Cexception est levée si tValeur = 0
******************************************/
template <class T>
CMatrice<T> CMatrice<T>::operator/(const T & tValeur)
{
	// On ne peux pas utiliser l'operateur * car il pose problème pour les types entiers
	// Ex : M / 4 = M * 1/4, mais 1/4 = 0 en cas de type entier
	if (tValeur == 0)
	{
		throw Cexception(EXC_DIVISION_PAR_ZERO, "operator / : Division par 0");
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


/*****************************************
Opérateur ^
******************************************
Entree : la puissance
Necessite : iPuissance != 0
Sortie : instance de la classe CMatrice contenant le résultat de M^(iPuissance).
Entraîne : Une Cexception est levée si iPuissance = 0
******************************************/
template<class T>
CMatrice<T> CMatrice<T>::operator^(int iPuissance)
{
	if (iPuissance == 0)
	{
		// Impossible dans certains cas...
		throw Cexception(EXC_PUISSANCE_ZERO, "Cette librairie ne permet pas d'élever une matrice à la puissance 0.");
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


/*****************************************
Affichage d'une matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : rien
******************************************/
template <class T>
void CMatrice<T>::MATafficher()
{
	std::cout << *this;
}


/*****************************************
Lecture du nombre de colonnes.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le nombre de colonnes de la matrice
Entraîne : rien.
******************************************/
template <class T>
inline unsigned int CMatrice<T>::MATgetNbColonnes()
{
	return uiMATnbColonnes;
}


/*****************************************
Lecture du nombre de lignes.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le nombre de lignes de la matrice.
Entraîne : rien.
******************************************/
template <class T>
inline unsigned int CMatrice<T>::MATgetNbLignes()
{
	return uiMATnbLignes;
}


/*****************************************
Lecture de la valeur d'un coefficient.
******************************************
Entéee : l'indice de la ligne,
Entrée : l'indice de la colonne.
Nécessite : 0 <= uiLigne < nombre de lignes;
Nécessite : 0 <= uiColonnes < nombre de colonnes;
Sortie : le coefficient à la position (uiLigne, uiColonne) par référence.
Entraîne : rien.
******************************************/
template <class T>
inline T & CMatrice<T>::MATgetValeur(unsigned int uiLigne, unsigned int uiColonne)
{
	return (*this)(uiLigne, uiColonne);
}


/*****************************************
Lecture d'une ligne.
******************************************
Entrée : l'indice de la ligne (unsigned int).
Nécessite : 0 <= uiLigne < nombre de lignes;
Sortie : T * : un tableau contant la ligne uiLigne.
Entraîne : allocation (via l'operateur new) d'un tableau.
******************************************/
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


/*****************************************
Lecture d'une colonne.
******************************************
Entrée : l'indice de la colonne.
Nécessite : 0 <= uiColonnes < nombre de colonnes;
Sortie : un tableau contant la colonnes uiColonne.
Entraîne : allocation (via l'operateur new) d'un tableau.
******************************************/
template <class T>
T * CMatrice<T>::MATgetColonne(unsigned int uiColonne)
{
	return MATtransposee().MATgetLigne(uiColonne);
}



// ----- Setters ----------------------------------------


/*****************************************
Mutateur pour la valeur.
******************************************
Entrée : l'indice de la ligne.
Entrée : l'indice de la colonne.
Entrée : la valeur définir.
Nécessite : 0 <= uiLigne < nombre de lignes;
Nécessite : 0 <= uiColonnes < nombre de colonnes;
Sortie : rien.
Entraîne : un changement de valeur du coefficient à la position (uiLigne, uiColonne).
******************************************/
template <class T>
inline void CMatrice<T>::MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur)
{
	(*this)(uiLigne, uiColonne) = tValeur;
}


/*****************************************
Mutateur pour le nombre de lignes.
******************************************
Entrée : le nombre de lignes.
Nécessite : uiNbLignes > 0.
Sortie : rien.
Entraîne : une réallocation du tableau 2D.
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
Entrée : le nombre de colonnes.
Nécessite : uiNbColonnes > 0.
Sortie : rien.
Entraîne : une réallocation du tableau 2D.
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
Sortie : le rang de la matrice.
Entraîne : rien.
******************************************/
template <class T>
unsigned int CMatrice<T>::MATrang()
{
	CMatrice<T> MATech = MATechelonnee();
	unsigned int uiBoucleL = 0;

	// On échelonne la matrice et compte le nombre de lignes non nulles
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
Sortie : une matrice échelonnées (non réduite => change le déterminant).
Entraîne : rien.
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
Sortie : la transposée de la matrice
Entraîne : rien.
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
Entrée : l'indice de la ligne.
Entrée : l'indice de la colonne.
Nécessite : uiLigne >= 0 et est inferieur au nombre de lignes de la matrice.
Nécessite : uiColonne >= 0 et est inferieur au nombre de de colonnes de la matrice.
Sortie : une instance de CMatrice possédant une ligne et une colonne de moins
contenant les valeurs de la matrice qui ne sont pas sur la lige uiLigne ou
sur la colonne uiColonne.
Entraîne : rien.
******************************************/
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


/*****************************************
Test de matrice nulle.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un booléen : True = la matrice est nulle, False = la matrice n'est pas nulle.
Entraine : rien
******************************************/
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


/*****************************************
Vérifie le contenu d'une instance de CTableauAssociatif
pour créer un objet CMatrice
******************************************
Entrée : Une instance de CTableauAssociatif.
Nécessite : rien.
Sortie : rien.
Entraîne : une Cexception  est levée si le tableau de contient pas "NBColonnes", "NBLignes" et "Matrice",
		ou que les types correspondants sont incorrects (resp. Entier, Entier, Chaine)
******************************************/
template<class T>
void CMatrice<T>::MATverifierContenuTableau(CTableauAssociatif TABtab)
{
	if (TABtab.TABgetIndiceCle("TypeMatrice") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'TypeMatrice' non renseigné.");

	if (TABtab.TABgetIndiceCle("NBLignes") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'NBLignes' non renseigné.");

	if (TABtab.TABgetIndiceCle("NBColonnes") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'NBColonnes' non renseigné.");

	if (TABtab.TABgetIndiceCle("Matrice") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'Matrice' non renseigné.");

	if (TABtab.TABgetValeurType("NBLignes") != TAB_TYPE_ENTIER  || TABtab.TABgetValeurEntier("NBLignes") < 1)
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation de la matrice : La valeur de 'NBLignes' doit etre un nombre entier strictement positif.");

	if (TABtab.TABgetValeurType("NBColonnes") != TAB_TYPE_ENTIER || TABtab.TABgetValeurEntier("NBColonnes") < 1)
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation de la matrice : La valeur de 'NBColonnes' doit etre un nombre entier strictement positif.");

	if (TABtab.TABgetValeurType("Matrice") != TAB_TYPE_CHAINE)
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation de la matrice : La valeur de 'Matrice' doit etre une liste ('[....]')");
}



/*****************************************
Initialisation de la matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien
Entraîne : Allocation sur le tas du tableau 2D contenant la matrice
******************************************/
template <class T>
void CMatrice<T>::MATinitMatrice()
{
	unsigned int uiBoucle;
	// On alloue uiMATnbColonnes colonnes
	pptMATmatrice = (T **) malloc(sizeof(T *) * uiMATnbColonnes);

	if (pptMATmatrice == nullptr)
	{
		cout << "Erreur d'allocation dans MATinitMatrice(). Le programme s'est arrêté." << endl;
		exit(EXIT_FAILURE);
	}

	// Dans chaque colonne, on alloue uiMATnbLignes 'cases'
	for (uiBoucle = 0; uiBoucle < uiMATnbColonnes; uiBoucle++)
	{
		// permet d'obtenir la matrice null directement
		pptMATmatrice[uiBoucle] = (T *) calloc(uiMATnbLignes, sizeof(T));

		if (pptMATmatrice[uiBoucle] == nullptr)
		{
			cout << "Erreur d'allocation dans MATinitMatrice(). Le programme s'est arrêté." << endl;
			exit(EXIT_FAILURE);
		}
	}
}



/*****************************************
Test d'une ligne nulle
******************************************
Entrée : l'indice de la ligne
Nécessite : rien
Sortie : un booléen. True : ligne nulle, False : la ligne n'est pas nulle.
Entraîne : rien
******************************************/
template<class T>
bool CMatrice<T>::MATligneEstNulle(unsigned int uiLigne)
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
Libère la mémoire rerservée par l'instance de CMatrice<T>
******************************************
Entrée : rien
Nécessite : rien
Sortie : rien
Entraîne : libère la mémoire allouée au tableau 2D.
******************************************/
template <class T>
void CMatrice<T>::MATdesallouerMatrice()
{
	unsigned int uiBoucleC;

	// On desalloue toutes les colonnes
	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		free(pptMATmatrice[uiBoucleC]);
	}

	// Puis on desalloue le pointeur
	free(pptMATmatrice);
	pptMATmatrice = nullptr;
}


/*****************************************
Ajoute ou retire des colonnes
******************************************
Entrée : le nombre de colonnes à ajouter (par défaut = 1).
Nécessite : rien
Sortie : rien
Entraîne : Réallocation du tableau 2D
******************************************/
template<class T>
void CMatrice<T>::MATajouterColonnes(int iNb)
{
	// Ajouter une colonne revient a ajouter une ligne à la transposee
	CMatrice<T> MATtmp = MATtransposee();
	MATtmp.MATsetNbLignes(iNb + MATtmp.uiMATnbLignes);
	
	*this = MATtmp.MATtransposee();
}


/*****************************************
Ajoute ou retire des lignes
******************************************
Entrée : le nombre de lignes à ajouter (par défaut = 1).
Nécessite : iNb > (-1) * le nombre de lignes.
Sortie : rien.
Entraîne : Réallocation du tableau 2D.
******************************************/
template<class T>
void CMatrice<T>::MATajouterLignes(int iNb)
{
	unsigned int uiBoucleC, uiBoucleL;

	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		pptMATmatrice[uiBoucleC] = (T *) realloc(pptMATmatrice[uiBoucleC], (uiMATnbLignes + iNb) * sizeof(T));

		if (pptMATmatrice[uiBoucleC] == nullptr)
		{
			cout << "Erreur d'allocation dans MATajouterLignes(). Le programme s'est arrêté." << endl;
			exit(EXIT_FAILURE);
		}

		for (uiBoucleL = uiMATnbLignes; uiBoucleL < uiMATnbLignes + iNb; uiBoucleL++)
		{
			pptMATmatrice[uiBoucleC][uiBoucleL] = 0;
		}
	}
}


/*****************************************
Calcul du déterminant.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : la valeur du déterminant.
Entraîne : rien.
******************************************/
template <class T>
T CMatrice<T>::MATdet()
{
	if (uiMATnbLignes == 1)
	{
		return pptMATmatrice[0][0];
	}
	else
	{
		T tDeterminant = 0;

		// Le determinant d'une matrice triangulaire est le produit des élements de la diagonale
		if (MATestTriangulaire())
		{
			tDeterminant = MATgetValeur(0, 0);
			unsigned int uiBoucle;
			// Si a un moment donné tDeterminant = 0, on peut stopper la boucle et retourner 0
			for (uiBoucle = 1; uiBoucle < uiMATnbColonnes && tDeterminant != 0; uiBoucle++)
			{
				tDeterminant = tDeterminant * MATgetValeur(uiBoucle, uiBoucle);
			}

			return tDeterminant;
		}
		else
		{
			unsigned int uiBoucleL;
			// Formule de Leibniz
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
}


/*****************************************
Calcul de la trace d'une matrice.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : la valeur de la trace.
Entraîne : rien.
******************************************/
template <class T>
T CMatrice<T>::MATtr()
{
	unsigned int uiBoucle;
	T trace = 0;

	for (uiBoucle = 0; uiBoucle < MATgetNbLignes(); uiBoucle++)
	{
		trace += pptMATmatrice[uiBoucle][uiBoucle];
	}

	return trace;
}


/*****************************************
Calcul de la commatrice.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : une instance de CMatrice égale a la commatrice de l'objet.
Entraîne : rien.
******************************************/
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



/*****************************************
Calcul de l'inverse d'une matrice.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : une instance de CMatrice égale à l'inverse de l'objet.
Entraîne : Une Cexception est levée si le determinant est nul.
******************************************/
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
		throw Cexception(EXC_DIVISION_PAR_ZERO, "Calcul de l'inverse impossible : Déterminant nul.");
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


/*****************************************
Teste si la matrice est triangulaire.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est triangulaire, False = la matrice n'est pas triangulaire.
Entraîne : rien.
******************************************/
template <class T>
bool CMatrice<T>::MATestTriangulaire()
{
	return (MATestTriangulaireInferieure() || MATestTriangulaireSuperieure());
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


/*****************************************
Teste si la matrice est triangulaire supérieure.
******************************************
Entrée : rien.
Nécessite : La matrice est carrée.
Sortie : un booléen : True = la matrice est triangulaire supérieure, False = la matrice n'est pas triangulaire supérieure.
Entraîne : rien
******************************************/
template <class T>
bool CMatrice<T>::MATestTriangulaireSuperieure()
{
	// La transposée d'une matrice triangulaire supérieure est triangulaire inférieure
	CMatrice<T> MATtmp = MATtransposee();
	return MATtmp.MATestTriangulaireInferieure();
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
bool CMatrice<T>::MATestDiagonale()
{
	// Pour la compréhension du code et la maintenabilité :
	return (MATestTriangulaireInferieure() && MATestTriangulaireSuperieure());
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
bool CMatrice<T>::MATestInversible()
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
bool CMatrice<T>::MATestSymetrique()
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
bool CMatrice<T>::MATestAntiSymetrique()
{
	return (MATtransposee() == (*this * -1));
}



/*****************************************
Création d'une matrice diagonale.
******************************************
Entrée : la dimension,
Entrée : un tableau de valeurs.
Nécessite : la dimension du tableau est >= uiDim
(si elle est supérieure, seules les uiDim premières
valeurs seront prisent en compte).
Sortie : un matrice diagonale contenant les valeurs de ptDiag sur la diagonale.
Entraîne : rien
******************************************/
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


/*****************************************
Génération d'une matrice .
******************************************
Entrée : une instance de CTableauAssociatif.
Nécessite : rien.
Sortie : une instance de CMatrice.
Entraîne : la création d'une matrice à partir des valeurs du tableau.
******************************************/
template<class T>
CMatrice<T> CMatrice<T>::MATgenerer(CTableauAssociatif & TABtab)
{
	char * pcStrMatrice;
	unsigned int uiBoucleL, uiBoucleC, uiIndiceCaractere;
	double dValeur;

	// soulève une exception en cas de contenu non conforme
	CMatrice<T>::MATverifierContenuTableau(TABtab);
	CMatrice<T> MATmatrice(TABtab.TABgetValeurEntier("NBLignes"), TABtab.TABgetValeurEntier("NBColonnes"));

	pcStrMatrice = TABtab.TABgetValeurChaine("Matrice");

	if (strlen(pcStrMatrice) == 0)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Format invalide : la valeur de 'Matrice' est vide.");
	}

	for (uiBoucleL = 0; uiBoucleL < MATmatrice.MATgetNbLignes(); uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < MATmatrice.MATgetNbColonnes(); uiBoucleC++)
		{

			char pcCoefficient[64] = { 0 };

			// On gère le cas ou le coefficient est un double à virgule.
			uiIndiceCaractere = 0;

			while (isspace(*pcStrMatrice) || *pcStrMatrice == '\n' || *pcStrMatrice == '\0')
			{
				// Si on trouve '\n' ici alors qu'on a pas passé la dernière colonnes
				if ((*pcStrMatrice == '\n' || *pcStrMatrice == '\0') && uiBoucleC > 0)
					throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Format invalide : Au moins une ligne contient moins de valeurs que la valeur de 'NBColonnes'.");
				pcStrMatrice++;
			}

			pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;

			while (*pcStrMatrice != '\0' && !isspace(*pcStrMatrice) && *pcStrMatrice != '\n')
			{
				pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;
				// On remplace les potentielles ',' par '.'
				if (pcCoefficient[uiIndiceCaractere] == ',')
				{
					pcCoefficient[uiIndiceCaractere] = '.';
				}

				pcStrMatrice++;
				uiIndiceCaractere++;
			}

			// Si le dernier caractère est un '.', on réduit la chaine d'un caractère
			if (pcCoefficient[strlen(pcCoefficient) - 1] == '.')
			{
				pcCoefficient[strlen(pcCoefficient) - 1] = '\0';
			}

			if (getType(pcCoefficient) != TAB_TYPE_REEL && getType(pcCoefficient) != TAB_TYPE_ENTIER)
			{
				throw Cexception(EXC_ERREUR_LEXICALE, "La valeur de 'Matrice' ne doit être composée que de nombres.");
			}

			dValeur = atof(pcCoefficient);

			MATmatrice(uiBoucleL, uiBoucleC) = dValeur;
		}

		//  On vérifie qu'il ne reste rien après la dernière colonne.
		// Si c'est le cas, alors le format est invalide.

		if (*pcStrMatrice != '\n' && *pcStrMatrice != '\0')
		{
			while (*pcStrMatrice != '\n' && *pcStrMatrice != '\0')
			{
				if (*pcStrMatrice != ' ' && *pcStrMatrice != '\t')
				{
					throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Format invalide : Une ligne de la matrice contient plus de valeurs que la valeur de 'NBColonnes'.");
				}

				pcStrMatrice++;
			}
		}
	}

	// Si le reste (sans les espaces, tabulations et retours à la ligne)
	// n'est pas vide, il y a une (des) ligne(s) en trop
	if (trim(pcStrMatrice)[0] != 0)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Format invalide : la matrice contient plus de lignes que la valeur de 'NBLignes'.");
	}

	return MATmatrice;
}


// Operateurs complémentaires



/*****************************************
Opérateur + à paramètre de type CMatrice<T> et T.
******************************************
Entrée : la valeur à ajouter (de type T),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant de la somme.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> operator+(const T & tValeur, CMatrice<T> & MATmatrice)
{
	return MATmatrice + tValeur;
}



/*****************************************
Opérateur - à paramètre de type CMatrice<T> et T.
******************************************
Entrée : la valeur à retirer (de type T),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant de la différence.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> operator-(const T & tValeur, CMatrice<T> & MATmatrice)
{
	return (MATmatrice - tValeur) * (-1);
}



/*****************************************
Opérateur * à paramètre de type CMatrice<T> et T.
******************************************
Entrée : le coefficient de multiplication (de type T),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : objet CMatrice<T> résultant du produit.
Entraîne : rien
******************************************/
template <class T>
CMatrice<T> operator*(const T & tValeur, CMatrice<T> & MATmatrice)
{
	return MATmatrice * tValeur;
}


/*****************************************
Opérateur <<.
******************************************
Entrée : un flux (std::cout),
Entrée : une instance de CMatrice.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage de la matrice.
******************************************/
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
			OSTflux << MATmatrice.MATgetValeur(uiLigne, uiColonne) << "\t";
		}

		OSTflux << '|' << endl;
	}

	OSTflux << endl;

	return OSTflux;
}