#ifndef TABLEAU_ASSOCIATIF_H
#define TABLEAU_ASSOCIATIF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cexception.h"
#include "helpers.h"
#include "constantes.h"

typedef union {
	double dReel;
	int iEntier;
	char * pcChaine;
} Valeur;

class CTableauAssociatif
{
	char ** ppcTABcles;
	Valeur * pvTABvaleurs;
	unsigned int uiTABnbElements;
	unsigned int * puiTypes;


	void TABinit();
	void TABdetruire();
	void TABajouter(char * pcCle, Valeur vValeur, unsigned int uiType);


public:
	CTableauAssociatif();
	CTableauAssociatif(CTableauAssociatif & TABobjet);
	~CTableauAssociatif();

	CTableauAssociatif & operator=(CTableauAssociatif & TABobjet);
	Valeur & operator[](char * pcCle);

	void TABsupprimer(char * pcCle);
	void TABmodifier(char * pcCle, Valeur vValeur, unsigned int uiType);

	void TABajouterEntier(char * pcCle, int iVal);
	void TABajouterReel(char * pcCle, double dVal);
	void TABajouterChaine(char * pcCle, char * pcVal);
	void TABajouterAuto(char * pcCle, char * pcVal);

	unsigned int TABgetNbElements() const;
	int TABgetIndiceCle(char * pcCle) const;
	char * TABgetCle(unsigned int uiPos) const;
	Valeur TABgetValeur(char * pcCle) const;
	Valeur TABgetValeurPos(unsigned int uiPos);
	unsigned int TABgetValeurType(unsigned int uiPos);
	unsigned int TABgetValeurType(char * pcCle);

	int TABgetValeurEntier(char * pcCle) const;
	double TABgetValeurReel(char * pcCle) const;
	char * TABgetValeurChaine(char * pcCle) const;
};

int getType(char * pcCle);

#endif