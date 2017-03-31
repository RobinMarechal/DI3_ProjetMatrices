#include "TableauAssociatif.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

#include "Cexception.h"
#include "constantes.h"

#define TAB_TYPE_NON_DEFINI 0
#define TAB_TYPE_ENTIER 1
#define TAB_TYPE_REEL 2
#define TAB_TYPE_CHAINE 3


void CTableauAssociatif::TABinit() 
{
	ppcTABcles = NULL;
	pvTABvaleurs = NULL;
	puiTypes = NULL;
	uiTABnbElements = 0;
}

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

CTableauAssociatif::CTableauAssociatif() 
{
	TABinit();
}

CTableauAssociatif::CTableauAssociatif(CTableauAssociatif & TABobjet) 
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

CTableauAssociatif::~CTableauAssociatif() 
{
	TABdetruire();
}

CTableauAssociatif & CTableauAssociatif::operator=(CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABdetruire();
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
	}

	return *this;
}

// precond : pcCle est bien dans le tableau
Valeur & CTableauAssociatif::operator[](char * pcCle) 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos];
}

void CTableauAssociatif::TABajouter(char * pcCle, Valeur vValeur, unsigned int uiType) 
{
	uiTABnbElements++;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char*));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, uiTABnbElements * sizeof(unsigned int));

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		throw Cexception(EXC_ECHEC_ALLOCATION, "TABsupprimerElement() : Echec de reallocation");
	}


	ppcTABcles[uiTABnbElements - 1] = _strdup(pcCle);
	pvTABvaleurs[uiTABnbElements - 1] = vValeur;
	puiTypes[uiTABnbElements - 1] = uiType;
}


void CTableauAssociatif::TABsupprimer(char * pcCle) 
{
	unsigned int uiBoucle;
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	// On décale tout ce qui est à droite de uiPos d'une case vers la gauche
	for (uiBoucle = uiPos; uiBoucle < uiTABnbElements - 1; uiBoucle++)
	{
		free(ppcTABcles[uiBoucle]);
		ppcTABcles[uiBoucle] = _strdup(ppcTABcles[uiBoucle + 1]);
		pvTABvaleurs[uiBoucle] = pvTABvaleurs[uiBoucle + 1];
		puiTypes[uiBoucle] = puiTypes[uiBoucle + 1];
	}

	uiTABnbElements--;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char *));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, sizeof(unsigned int) * uiTABnbElements);

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		throw Cexception(EXC_ECHEC_ALLOCATION, "TABsupprimerElement() : Echec de reallocation");
	}

}

// precond : pcCle est bien dans le tableau
void CTableauAssociatif::TABmodifier(char * pcCle, Valeur vValeur, unsigned int uiType) 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	pvTABvaleurs[uiPos] = vValeur;
	puiTypes[uiPos] = uiType;
}

void CTableauAssociatif::TABajouterEntier(char * pcCle, int iVal) 
{
	Valeur vVal;
	vVal.iEntier = iVal;
	TABajouter(pcCle, vVal, TAB_TYPE_ENTIER);
}

void CTableauAssociatif::TABajouterReel(char * pcCle, double dVal) 
{
	Valeur vVal;
	vVal.dReel = dVal;
	TABajouter(pcCle, vVal, TAB_TYPE_REEL);
}

void CTableauAssociatif::TABajouterChaine(char * pcCle, char * pcVal) 
{
	Valeur vVal;
	vVal.pcChaine = pcVal;
	TABajouter(pcCle, vVal, TAB_TYPE_CHAINE);
}
#include <iostream>
using namespace std;
void CTableauAssociatif::TABajouterAuto(char * pcCle, char * pcVal)
{
	// Format : XX
	int iType = getType(pcVal);
	if (iType == TAB_TYPE_ENTIER)
	{
		// On parse la chaine en int
		char * pcBuffer = nullptr;

		int iVal = strtod(pcVal, &pcBuffer);

		if (strlen(pcBuffer) > 0)
		{
			char pcMsg[256];
			sprintf(pcMsg, "La valeur de %s doit être un entier positif.", pcCle);

			throw Cexception(EXC_ERREUR_LEXICALE, pcMsg);
		}
		// on l'ajoute au tableau
		TABajouterEntier(pcCle, iVal);
	}
	// Format : XX.XX || XX,XX
	else if(iType == TAB_TYPE_REEL)
	{
		// On rajoute un 0 au début et à la fin pour etre sur d'éviter les problèmes pour convertir
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

unsigned int CTableauAssociatif::TABgetNbElements() const 
{
	return uiTABnbElements;
}

int CTableauAssociatif::TABgetIndiceCle(char * pcCle) const 
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

// precond : 0 < uiPos < uiTABnbElements
char * CTableauAssociatif::TABgetCle(unsigned int uiPos) const 
{
	return ppcTABcles[uiPos];
}

// precond : pcCle est bien dans le tableau
Valeur CTableauAssociatif::TABgetValeur(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos];
}

// precond : 0 < uiPos < uiTABnbElements
Valeur CTableauAssociatif::TABgetValeurPos(unsigned int uiPos)
{
	return pvTABvaleurs[uiPos];
}

// precond : 0 < uiPos < uiMATnbElements
unsigned int CTableauAssociatif::TABgetValeurType(unsigned int uiPos)
{
	return puiTypes[uiPos];
}

// precond :pcCle est dans le tableau
unsigned int CTableauAssociatif::TABgetValeurType(char * pcCle)
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return TABgetValeurType(uiPos);
}

// precond :pcCle est dans le tableau
int CTableauAssociatif::TABgetValeurEntier(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].iEntier;
}

// precond :pcCle est dans le tableau
double CTableauAssociatif::TABgetValeurReel(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].dReel;
}

// precond :pcCle est dans le tableau
char * CTableauAssociatif::TABgetValeurChaine(char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].pcChaine;
}
