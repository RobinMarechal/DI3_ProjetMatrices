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
CMatrice<T>::CMatrice(const CMatrice<T> & MATmatrice)
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
inline T & CMatrice<T>::operator()(unsigned int uiLigne, unsigned int uiColonne) const
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
CMatrice<T> & CMatrice<T>::operator=(const CMatrice<T> & MATmatrice)
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
bool CMatrice<T>::operator==(const CMatrice<T> & MATmatrice) const
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
bool CMatrice<T>::operator!=(const CMatrice<T> & MATmatrice) const
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
CMatrice<T> CMatrice<T>::operator+(const T & tValeur) const
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
CMatrice<T> CMatrice<T>::operator+(const CMatrice<T> & MATmatrice) const
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
CMatrice<T> CMatrice<T>::operator*(const T & tValeur) const
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
CMatrice<T> CMatrice<T>::operator*(const CMatrice<T> & MATmatrice) const
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
CMatrice<T> CMatrice<T>::operator-(const T & tValeur) const
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
CMatrice<T> CMatrice<T>::operator-(const CMatrice<T> & MATmatrice) const
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
CMatrice<T> CMatrice<T>::operator/(const T & tValeur) const
{
	// On ne peux pas utiliser l'operateur * car il pose problème pour les types entiers
	// Ex : M / 4 = M * 1/4, mais 1/4 = 0 en cas de type entier
	if (tValeur == 0)
	{
		throw Cexception(EXC_DIVISION_PAR_ZERO, "operator / : Division par 0");
	}

	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<T> MATmatrice = *this;

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
CMatrice<T> CMatrice<T>::operator^(int iPuissance) const
{
	COperationMatrice <T> OPMoperation;

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
void CMatrice<T>::MATafficher() const
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
inline unsigned int CMatrice<T>::MATgetNbColonnes() const
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
inline unsigned int CMatrice<T>::MATgetNbLignes() const
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
inline T & CMatrice<T>::MATgetValeur(unsigned int uiLigne, unsigned int uiColonne) const
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
Entrée : l'indice de la colonne.
Nécessite : 0 <= uiColonnes < nombre de colonnes;
Sortie : un tableau contant la colonnes uiColonne.
Entraîne : allocation (via l'operateur new) d'un tableau.
******************************************/
template <class T>
T * CMatrice<T>::MATgetColonne(unsigned int uiColonne) const
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


/*****************************************
Vérifie le contenu d'une instance de CTableauAssociatif
pour créer un objet CMatrice
******************************************
Entrée : Un pointeur sur une instance de CTableauAssociatif.
Nécessite : rien.
Sortie : rien.
Entraîne : une Cexception  est levée si le tableau de contient pas "NBColonnes", "NBLignes" et "Matrice",
		ou que les types correspondants sont incorrects (resp. Entier, Entier, Chaine)
******************************************/
template<class T>
void CMatrice<T>::MATverifierContenuTableau(CTableauAssociatif * TABtab)
{
	if (TABtab->TABgetIndiceCle("TypeMatrice") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'TypeMatrice' non renseigné.");

	if (TABtab->TABgetIndiceCle("NBLignes") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'NBLignes' non renseigné.");

	if (TABtab->TABgetIndiceCle("NBColonnes") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'NBColonnes' non renseigné.");

	if (TABtab->TABgetIndiceCle("Matrice") == -1)
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs 'Matrice' non renseigné.");

	if (TABtab->TABgetValeurType("NBLignes") != TAB_TYPE_ENTIER  || TABtab->TABgetValeurEntier("NBLignes") < 1)
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation de la matrice : La valeur de 'NBLignes' doit etre un nombre entier strictement positif.");

	if (TABtab->TABgetValeurType("NBColonnes") != TAB_TYPE_ENTIER || TABtab->TABgetValeurEntier("NBColonnes") < 1)
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation de la matrice : La valeur de 'NBColonnes' doit etre un nombre entier strictement positif.");

	if (TABtab->TABgetValeurType("Matrice") != TAB_TYPE_CHAINE)
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
Génération d'une matrice .
******************************************
Entrée : Un pointeur sur une instance de CTableauAssociatif.
Nécessite : rien.
Sortie : une instance de CMatrice.
Entraîne : la création d'une matrice à partir des valeurs du tableau.
******************************************/
template<class T>
CMatrice<T> CMatrice<T>::MATgenerer(CTableauAssociatif * TABtab)
{
	char * pcStrMatrice;
	unsigned int uiBoucleL, uiBoucleC, uiIndiceCaractere;
	double dValeur;

	// soulève une exception en cas de contenu non conforme
	CMatrice<T>::MATverifierContenuTableau(TABtab);
	CMatrice<T> MATmatrice(TABtab->TABgetValeurEntier("NBLignes"), TABtab->TABgetValeurEntier("NBColonnes"));

	pcStrMatrice = TABtab->TABgetValeurChaine("Matrice");

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

			while (*pcStrMatrice == '\t' || *pcStrMatrice == ' ' || *pcStrMatrice == '\n' || *pcStrMatrice == '\0')
			{
				// Si on trouve '\n' ici alors qu'on a pas passé la dernière colonnes
				if ((*pcStrMatrice == '\n' || *pcStrMatrice == '\0') && uiBoucleC > 0)
					throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Format invalide : Au moins une ligne contient moins de valeurs que la valeur de 'NBColonnes'.");
				pcStrMatrice++;
			}

			pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;

			while (*pcStrMatrice != '\0' && *pcStrMatrice != '\t' && *pcStrMatrice != ' ' && *pcStrMatrice != '\n')
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

			if (analyserType(pcCoefficient) != TAB_TYPE_REEL && analyserType(pcCoefficient) != TAB_TYPE_ENTIER)
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
	if (supprimerEspaces(pcStrMatrice)[0] != 0)
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