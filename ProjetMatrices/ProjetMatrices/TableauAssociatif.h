#ifndef TABLEAU_ASSOCIATIF_H
#define TABLEAU_ASSOCIATIF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cexception.h"
#include "helpers.h"
#include "constantes.h"

/**************************************************
Union permettant de stocker une valeur dans le 
tableau associatif en tant que reel, entier ou chaine.
***************************************************/
typedef union {
	double dReel;
	int iEntier;
	char * pcChaine;
} Valeur;

/**************************************************
Gestion de tableaux associatifs
***************************************************
Classe permettant de cr�er et de manipuler des 
tableaux associatifs Cl� => Valeur 
Les valeurs peuvent �tre de type Entier, R��l ou
Chaine gr�ce � l'utilisation d'unions.
***************************************************/
class CTableauAssociatif
{
	/********************************************************
		Tableau contenant les cl�s
	*********************************************************/
	char ** ppcTABcles;

	/********************************************************
		Tableau des unions 'Valeur' associ�s au cl�s
	*********************************************************/
	Valeur * pvTABvaleurs;

	/********************************************************
		Le nombre d'�lement du tableau
	*********************************************************/
	unsigned int uiTABnbElements;
	
	/********************************************************
		Tableau contenant le type de chaque valeur 
		pour faciliter l'utilisation de l'union 'Valeur'
	*********************************************************/
	unsigned int * puiTypes;


	/********************************************************
	Initialisation de l'objet
	*********************************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : rien
	Entra�ne : D�finition de la valeur des attributs : 
	les pointeurs � NULL et le nombre d'�l�ment � 0
	*********************************************************/
	void TABinit();


	/********************************************************
	Pr�-destruction de l'objet
	*********************************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : rien
	Entra�ne : Lib�ration de la m�moire allou�e pour les attributs
	*********************************************************/
	void TABdetruire();


	/********************************************************
	Ajout d'un union au tableau associatif
	*********************************************************
	Entr�e : la cl�,
	Entr�e : l'union contenant la valeur,
	Entr�e : Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
	N�cessite : rien
	Sortie : rien
	Entra�ne : La r�allocations des trois tableaux et l'insertion
	des �l�ments dans les tableaux respectifs.
	*********************************************************/
	void TABajouter( const char * pcCle, Valeur vValeur, unsigned int uiType);


public:


	/********************************************************
	Constructeur par d�faut
	*********************************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : rien
	Entra�ne : Cr�ation de l'objet
	*********************************************************/
	CTableauAssociatif();


	/********************************************************
	Constructeur de recopie
	*********************************************************
	Entr�e : l'instance de CTableauAssociatif � recopier
	N�cessite : rien
	Sortie : rien
	Entra�ne : Cr�ation de l'objet en recopiant TABobjet.
	=> La recopie des tableau se fait en recopiant les valeurs, 
	et non l'adresse des pointeurs
	*********************************************************/
	CTableauAssociatif(const CTableauAssociatif & TABobjet);


	/********************************************************
	Destructeur
	*********************************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : rien
	Entra�ne : La destruction de l'objet et la lib�ration
	de la m�moire allou�e pour les attributs
	*********************************************************/
	~CTableauAssociatif();


	/********************************************************
	Op�rateur =
	*********************************************************
	Entr�e : l'instance de CTableauAssociatif � affecter � l'objet
	N�cessite : rien
	Sortie : rien
	Entra�ne : La recopie des tableau en recopier les valeurs, 
	et non l'adresse des pointeurs
	*********************************************************/
	CTableauAssociatif & operator=(const CTableauAssociatif & TABobjet);


	/********************************************************
	Supprimer un �l�ment du tableau
	*********************************************************
	Entr�e : la cl� � retirer du tableau
	N�cessite : L'objet poss�de la cl� en attribut (Sinon la m�thode ne fait rien)
	Sortie : rien
	Entra�ne : R�duction de la m�moire allou�e aux tableaux en attribut
	Et suppression de la cl� pcCle et de l'�l�ment dans les autres tableaux
	*********************************************************/
	void TABsupprimer(const char * pcCle);


	/********************************************************
	Ajouter un �l�ment de type Entier
	*********************************************************
	Entr�e : la cl� de la valeur � ajouter
	Entr�e : la valeur de type Entier � ajouter
	N�cessite : rien
	Sortie : rien
	Entra�ne : R�allocation des tableaux en attribut
			et ajout des �l�ments dans leur tableau respectif
	*********************************************************/
	void TABajouterEntier(const char * pcCle, int iVal);



	/********************************************************
	Ajouter un �l�ment de type R�el
	*********************************************************
	Entr�e : la cl� de la valeur � ajouter
	Entr�e : la valeur de type R�el � ajouter
	N�cessite : rien
	Sortie : rien
	Entra�ne : R�allocation des tableaux en attribut
			et ajout des �l�ments dans leur tableau respectif
	*********************************************************/
	void TABajouterReel( const char * pcCle, double dVal);



	/********************************************************
	Ajouter un �l�ment de type Chaine
	*********************************************************
	Entr�e : la cl� de la valeur � ajouter
	Entr�e : la valeur de type Chaine � ajouter
	N�cessite : pcVal a �t� allou�e sur le tas.
	Sortie : rien
	Entra�ne : R�allocation des tableaux en attribut
	et ajout des �l�ments dans leur tableau respectif
	*********************************************************/
	void TABajouterChaine( const char * pcCle, char * pcVal);



	/********************************************************
	Ajouter un �l�ment sans sp�cifier le type
	*********************************************************
	Entr�e : la cl� de la valeur � ajouter
	Entr�e : la valeur � ajouter sous faire d'une chaine de caract�re
	N�cessite : rien
	Sortie : rien
	Entra�ne : D�duction du type potentiel de pcVal gr�ce � un automate,
			et l'ajoute au tableau avec le bon type
	Exemples : "1.12" => Reel, "5" => Entier, "a12" => Chaine
	Exemples : "7." => Entier, ".27" => Reel, "" => Chaine
	*********************************************************/
	void TABajouterAuto( const char * pcCle, char * pcVal);



	/********************************************************
	Lecture du nombre d'�lements du tableau
	*********************************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : le nombre d'�lements du tableau associatif
	Entra�ne : rien
	*********************************************************/
	unsigned int TABgetNbElements() const;



	/********************************************************
	Lecture du nombre d'�lements du tableau
	*********************************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : La position de la cl�. 
	>= 0 : La cl� est dans le tableau,
	== -1 : La cl� n'est pas dans le tableau.
	Entra�ne : rien
	*********************************************************/
	int TABgetIndiceCle( const char * pcCle) const;



	/********************************************************
	Lecture de la cl� � une position
	*********************************************************
	Entr�e : la position dans le tableau
	N�cessite : rien.
	Sortie : un pointeur sur la cl�, ou NULL si aucune cl� ne correspond � uiPos
	Entra�ne : rien
	Attention ! Une modification de la chaine retourn�e par la
	m�thode entrainerait la modification de l'�lement dans 
	le tableaux des cl�s, il ne s'agit pas d'une copie.
	*********************************************************/
	char * TABgetCle(unsigned int uiPos) const;



	/********************************************************
	Lecture de l'union Valeur associ� � une cl�
	*********************************************************
	Entr�e : la cl�
	N�cessite : pcCle est dans le tableau des cl�s
	Sortie : un union Valeur
	Entra�ne : rien
	*********************************************************/
	Valeur TABgetValeur( const char * pcCle) const;



	/********************************************************
	Lecture de l'union Valeur � une position
	*********************************************************
	Entr�e : la position
	N�cessite : 0 <= uiPos < Nombre d'�l�ments
	Sortie : un union Valeur
	Entra�ne : rien
	*********************************************************/
	Valeur TABgetValeurPos(unsigned int uiPos) const;



	/********************************************************
	Lecture du type de la valeur � une position
	*********************************************************
	Entr�e : la position
	N�cessite : 0 <= uiPos < Nombre d'�l�ments
	Sortie: Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
	Entra�ne : rien
	*********************************************************/
	unsigned int TABgetValeurType(unsigned int uiPos) const;



	/********************************************************
	Lecture du type de la valeur associ�e � une cl�
	*********************************************************
	Entr�e : la cl�
	N�cessite : pcCle est dans le tableau des cl�s
	Sortie : Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
	Entra�ne : rien
	*********************************************************/
	unsigned int TABgetValeurType( const char * pcCle) const;




	/********************************************************
	Lecture de la valeur au type Entier
	*********************************************************
	Entr�e : la cl�
	N�cessite : pcCle est dans le tableau des cl�s
	N�cessite : La valeur a �t� stock�e en tant qu'Entier
	Sortie : La valeur de type Entier de l'union Valeur associ� � la cl�.
	Entra�ne : rien
	Attention ! Si la valeur a �t� stock�e en tant qu'Entier,
	la valeur sera tronqu�e.
	Attention ! Si la valeur a �t� stock�e en tant que Chaine,
	la valeur sera fauss�e.
	*********************************************************/
	int TABgetValeurEntier( const char * pcCle) const;




	/********************************************************
	Lecture de la valeur au type Reel
	*********************************************************
	Entr�e : la cl�
	N�cessite : pcCle est dans le tableau des cl�s
	N�cessite : La valeur a �t� stock�e en tant qu'Reel
	Sortie : La valeur de type Reel de l'union Valeur associ� � la cl�.
	Entra�ne : rien
	Attention ! Si la valeur a �t� stock�e en tant que Chaine,
	la valeur sera fauss�e.
	*********************************************************/
	double TABgetValeurReel( const char * pcCle) const;




	/********************************************************
	Lecture de la valeur au type Chaine
	*********************************************************
	Entr�e : la cl�
	N�cessite : pcCle est dans le tableau des cl�s
	N�cessite : La valeur a �t� stock�e en tant qu'Entier
	Sortie : La valeur de type Entier de l'union Valeur associ� � la cl�.
	Entra�ne : rien
	Attention ! Si la valeur n'a pas �t� stock�e en tant qu'Entier,
	La valeur sera fauss�e.
	*********************************************************/
	char * TABgetValeurChaine( const char * pcCle) const;


};

#endif