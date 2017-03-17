#include "Matrice.h"
#include "Cexception.h"

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
CMatrice<T>::CMatrice(CMatrice & MATmatrice)
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
			MATsetValeur(uiLigne, uiColonne, MATmatrice.getValeu(uiLigne, uiColonne));
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
	unsigned int uiBoucleC;

	// On desalloue toutes les colonnes
	for (uiBoucleC = 0; uiBoucleC < uiMATnbColonnes; uiBoucleC++)
	{
		free(ppMATmatrice[uiBoucleC]);
	}

	// Puis on desalloue le pointeur
	free(ppMATmatrice);
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
inline T & CMatrice<T>::operator()(unsigned int uiLigne, unsigned int uiColonne)
{
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
CMatrice & CMatrice<T>::operator=(CMatrice & MATmatrice)
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
			MATsetValeur(uiLigne, uiColonne, MATmatrice.getValeur(uiLigne, uiColonne));
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
bool CMatrice<T>::operator==(CMatrice & MATmatrice)
{
	if (uiMATnbColonnes != MATmatrice.uiMATnbColonnes || uiMATnbLignes != MATmatrice.uiMATnbLignes)
		return false;
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
bool CMatrice<T>::operator!=(CMatrice & MATmatrice);

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
CMatrice CMatrice<T>::CMatrice operator+(T tValeur);

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
CMatrice CMatrice<T>::operator+(CMatrice MATmatrice);

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
CMatrice CMatrice<T>::operator*(T tValeur);

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
CMatrice CMatrice<T>::operator*(CMatrice MATmatrice);

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
CMatrice CMatrice<T>::operator-(T tValeur);

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
CMatrice CMatrice<T>::operator-(CMatrice MATmatrice);

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
CMatrice CMatrice<T>::operator/(T tValeur);

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
CMatrice CMatrice<T>::operator^(int iPuissance);

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
void CMatrice<T>::MATafficher();

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
unsigned int CMatrice<T>::MATgetNbColonnes();

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
unsigned int CMatrice<T>::MATgetNbLignes();

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
T CMatrice<T>::MATgetValeur(unsigned int uiLigne, unsigned int uiColonne);

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
T * CMatrice<T>::MATgetLigne(unsigned int uiLigne);

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
T * CMatrice<T>::MATgetColonne(unsigned int uiColonne);

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
void CMatrice<T>::MATsetValeur(unsigned int uiLigne, unsigned int uiColonne, T tValeur);

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
void CMatrice<T>::MATsetNbLignes(unsigned int uiNbLignes);

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
void CMatrice<T>::MATsetNbColonnes(unsigned int uiNbColonnes);

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
unsigned int CMatrice<T>::MATrang();

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
CMatrice CMatrice<T>::MATechelonnee();

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
CMatrice CMatrice<T>::MATtransposee();

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
CMatrice CMatrice<T>::MATsousMatrice();

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
bool CMatrice<T>::MATestNulle();

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
	ppMATmatrice = (T **)malloc(sizeof(T *) * uiMATnbColonnes);

	if (ppMATmatrice == nullptr)
	{
		throw Cexception(0, "Allocation failed");
	}

	for (uiBoucle = 0; uiBoucle < uiMATnbColonnes; uiBoucle++)
	{
		ppMATmatrice[uiBoucle] = (T *)calloc(uiMATnbLignes, sizeof(T));

		if (ppMATmatrice[uiBoucle] == nullptr)
		{
			throw Cexception(0, "Allocation failed");
		}
	}
}


