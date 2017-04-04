#include "TableauAssociatif.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

#include "Cexception.h"
#include "constantes.h"


/********************************************************
Initialisation de l'objet
*********************************************************
Entr�e : rien
N�cessite : rien
Sortie : rien
Entra�ne : D�finition de la valeur des attributs :
les pointeurs � NULL et le nombre d'�l�ment � 0
*********************************************************/
void CTableauAssociatif::TABinit() 
{
	ppcTABcles = NULL;
	pvTABvaleurs = NULL;
	puiTypes = NULL;
	uiTABnbElements = 0;
}



/********************************************************
Pr�-destruction de l'objet
*********************************************************
Entr�e : rien
N�cessite : rien
Sortie : rien
Entra�ne : Lib�ration de la m�moire allou�e pour les attributs
*********************************************************/
void CTableauAssociatif::TABdetruire() 
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTABnbElements; uiBoucle++)
	{
		free(ppcTABcles[uiBoucle]);
		if(puiTypes[uiBoucle] == TAB_TYPE_CHAINE)
			free(pvTABvaleurs[uiBoucle].pcChaine);
	}

	free(ppcTABcles);
	free(pvTABvaleurs);
	free(puiTypes);
}


/********************************************************
Constructeur par d�faut
*********************************************************
Entr�e : rien
N�cessite : rien
Sortie : rien
Entra�ne : Cr�ation de l'objet
*********************************************************/
CTableauAssociatif::CTableauAssociatif() 
{
	TABinit();
}


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
CTableauAssociatif::CTableauAssociatif(const CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		if (TABobjet.puiTypes[uiBoucle] == TAB_TYPE_CHAINE)
		{
			TABajouterChaine(TABobjet.ppcTABcles[uiBoucle], _strdup(TABobjet.pvTABvaleurs[uiBoucle].pcChaine));
		}
		else
		{
			TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
		}
	}
}


/********************************************************
Destructeur
*********************************************************
Entr�e : rien
N�cessite : rien
Sortie : rien
Entra�ne : La destruction de l'objet et la lib�ration
de la m�moire allou�e pour les attributs
*********************************************************/
CTableauAssociatif::~CTableauAssociatif() 
{
	TABdetruire();
}


/********************************************************
Op�rateur =
*********************************************************
Entr�e : l'instance de CTableauAssociatif � affecter � l'objet
N�cessite : rien
Sortie : rien
Entra�ne : La recopie des tableau en recopier les valeurs,
et non l'adresse des pointeurs
*********************************************************/
CTableauAssociatif & CTableauAssociatif::operator=(const CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABdetruire();
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		if (TABobjet.puiTypes[uiBoucle] == TAB_TYPE_CHAINE)
		{
			TABajouterChaine(TABobjet.ppcTABcles[uiBoucle], _strdup(TABobjet.pvTABvaleurs[uiBoucle].pcChaine));
		}
		else
		{
			TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
		}
	}

	return *this;
}


/********************************************************
Supprimer un �l�ment du tableau
*********************************************************
Entr�e : la cl� � retirer du tableau
N�cessite : L'objet poss�de la cl� en attribut (Sinon la m�thode ne fait rien)
Sortie : rien
Entra�ne : R�duction de la m�moire allou�e aux tableaux en attribut
Et suppression de la cl� pcCle et de l'�l�ment dans les autres tableaux
*********************************************************/
void CTableauAssociatif::TABsupprimer(const char * pcCle)
{
	unsigned int uiBoucle;
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	// Si l'�l�ment n'est pas dans le tableau, on ne fait rien
	if (uiPos == -1)
		return;

	// On free la cl�
	free(ppcTABcles[uiPos]);

	// Si c'est une chaine qu'on supprime, on la free
	if (puiTypes[uiPos] == TAB_TYPE_CHAINE)
	{
		free(pvTABvaleurs[uiPos].pcChaine);
	}

	// On d�cale tout ce qui est � droite de uiPos d'une case vers la gauche
	for (uiBoucle = uiPos; uiBoucle < uiTABnbElements - 1; uiBoucle++)
	{
		ppcTABcles[uiBoucle] = ppcTABcles[uiBoucle + 1];
		pvTABvaleurs[uiBoucle] = pvTABvaleurs[uiBoucle + 1];
		puiTypes[uiBoucle] = puiTypes[uiBoucle + 1];
	}

	// On met le pointeur de la derni�re case de ppcTABcles � NULL
	// Pas de fuite de m�moire car le pointeur a �t� copi� dans l'avant derni�re case
	ppcTABcles[uiTABnbElements - 1] = NULL;

	// Si le dernier �l�ment du tableau est une chaine, on met le pointeur � null
	// On ne la free pas car on a coppi� le pointeur dans l'avant derni�re 'case'
	if (puiTypes[uiTABnbElements - 1] == TAB_TYPE_CHAINE)
	{
		pvTABvaleurs[uiTABnbElements - 1].pcChaine = NULL;
	}

	uiTABnbElements--;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char *));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, sizeof(unsigned int) * uiTABnbElements);

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		std::cout << "TABsupprimer() : Une r�allocation a �chou�, le programme s'est arr�t�." << std::endl;
		exit(EXIT_FAILURE);
	}

}



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
void CTableauAssociatif::TABajouter(const char * pcCle, Valeur vValeur, unsigned int uiType) 
{
	uiTABnbElements++;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char*));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, uiTABnbElements * sizeof(unsigned int));

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		std::cout << "TABajouter() : Une r�allocation a �chou�, le programme s'est arr�t�." << std::endl;
		exit(EXIT_FAILURE);
	}


	ppcTABcles[uiTABnbElements - 1] = _strdup(pcCle);
	pvTABvaleurs[uiTABnbElements - 1] = vValeur;
	puiTypes[uiTABnbElements - 1] = uiType;
}


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
void CTableauAssociatif::TABajouterEntier(const char * pcCle, int iVal) 
{
	Valeur vVal;
	vVal.iEntier = iVal;
	TABajouter(pcCle, vVal, TAB_TYPE_ENTIER);
}



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
void CTableauAssociatif::TABajouterReel(const char * pcCle, double dVal) 
{
	Valeur vVal;
	vVal.dReel = dVal;
	TABajouter(pcCle, vVal, TAB_TYPE_REEL);
}



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
void CTableauAssociatif::TABajouterChaine(const char * pcCle, char * pcVal) 
{
	Valeur vVal;
	vVal.pcChaine = pcVal;
	TABajouter(pcCle, vVal, TAB_TYPE_CHAINE);
}



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
void CTableauAssociatif::TABajouterAuto(const char * pcCle, char * pcVal)
{
	// Format : XX
	int iType = analyserType(pcVal);
	if (iType == TAB_TYPE_ENTIER)
	{
		// On parse la chaine en int
		int iVal = atoi(pcVal);

		// on l'ajoute au tableau
		TABajouterEntier(pcCle, iVal);
	}
	// Format : XX.XX || XX,XX
	else if(iType == TAB_TYPE_REEL)
	{
		// On rajoute un 0 au d�but et � la fin pour etre sur d'�viter les probl�mes pour convertir
		unsigned int uiBoucle;
		unsigned int iTaille = strlen(pcVal);
		char * pcStr = new char[iTaille + 3];

		for (uiBoucle = 0; uiBoucle < iTaille + 2; uiBoucle++)
		{
			pcStr[uiBoucle] = '0';
		}
		pcStr[iTaille + 2] = '\0';

		strcpy_s(pcStr + 1, strlen(pcVal)+1, pcVal);
		*strchr(pcStr, '\0') = '0';

		// On remplace ',' par '.' s'il faut
		if (strchr(pcStr, ',') != NULL)
			pcStr[strchr(pcStr, ',') - pcStr] = '.';

		// On parse la chaine en double;
		double dVal = atof(pcStr);
		// on l'ajoute au tableau
		TABajouterReel(pcCle, dVal);

		delete[] pcStr;
	}
	else
	{
		// on ajoute simplement la chaine
		TABajouterChaine(pcCle, _strdup(pcVal));
	}
}



/********************************************************
Lecture du nombre d'�lements du tableau
*********************************************************
Entr�e : rien
N�cessite : rien
Sortie : le nombre d'�lements du tableau associatif
Entra�ne : rien
*********************************************************/
unsigned int CTableauAssociatif::TABgetNbElements() const 
{
	return uiTABnbElements;
}



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
int CTableauAssociatif::TABgetIndiceCle(const char * pcCle) const 
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTABnbElements; uiBoucle++)
	{
		if (strcmp(ppcTABcles[uiBoucle], pcCle) == 0)
		{
			return uiBoucle;
		}
	}

	return -1;
}



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
char * CTableauAssociatif::TABgetCle(unsigned int uiPos) const 
{
	if (uiPos < 0 || uiPos >= uiTABnbElements)
		return NULL;

	return ppcTABcles[uiPos];
}



/********************************************************
Lecture de l'union Valeur associ� � une cl�
*********************************************************
Entr�e : la cl�
N�cessite : pcCle est dans le tableau des cl�s
Sortie : un union Valeur
Entra�ne : rien
*********************************************************/
Valeur CTableauAssociatif::TABgetValeur(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos];
}



/********************************************************
Lecture de l'union Valeur � une position
*********************************************************
Entr�e : la position
N�cessite : 0 <= uiPos < Nombre d'�l�ments
Sortie : un union Valeur
Entra�ne : rien
*********************************************************/
Valeur CTableauAssociatif::TABgetValeurPos(unsigned int uiPos) const
{
	return pvTABvaleurs[uiPos];
}



/********************************************************
Lecture du type de la valeur � une position
*********************************************************
Entr�e : la position
N�cessite : 0 <= uiPos < Nombre d'�l�ments
Sortie: Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
Entra�ne : rien
*********************************************************/
unsigned int CTableauAssociatif::TABgetValeurType(unsigned int uiPos) const
{
	return puiTypes[uiPos];
}



/********************************************************
Lecture du type de la valeur associ�e � une cl�
*********************************************************
Entr�e : la cl�
N�cessite : pcCle est dans le tableau des cl�s
Sortie : Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
Entra�ne : rien
*********************************************************/
unsigned int CTableauAssociatif::TABgetValeurType(const char * pcCle) const
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return TABgetValeurType(uiPos);
}



/********************************************************
Lecture de la valeur au type Entier
*********************************************************
Entr�e : la cl�
N�cessite : pcCle est dans le tableau des cl�s
N�cessite : La valeur a �t� stock�e en tant qu'Entier
Sortie : La valeur de type Entier de l'union Valeur associ� � la cl�.
Entra�ne : rien
Attention ! Si la valeur n'a pas �t� stock�e en tant qu'Entier,
La valeur sera fauss�e.
*********************************************************/
int CTableauAssociatif::TABgetValeurEntier(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	if (puiTypes[uiPos] == TAB_TYPE_REEL)
	{
		return (int) pvTABvaleurs[uiPos].dReel;
	}
	else
	{
		return pvTABvaleurs[uiPos].iEntier;
	}
}



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
double CTableauAssociatif::TABgetValeurReel(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	if (puiTypes[uiPos] == TAB_TYPE_ENTIER)
	{
		return (double) pvTABvaleurs[uiPos].iEntier;
	}
	else
	{
		return pvTABvaleurs[uiPos].dReel;
	}
}



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
char * CTableauAssociatif::TABgetValeurChaine(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].pcChaine;
}
