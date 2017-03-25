#ifndef TABLEAU_ASSOCIATIF_H
#define TABLEAU_ASSOCIATIF_H

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

	void TABinit();
	void TABdetruire();
	void TABajouter(char * pcCle, Valeur vValeur);

	bool TABestNumerique(char * pcCle);
	bool TABestEntier(char * pcCle);

public:
	CTableauAssociatif();
	CTableauAssociatif(CTableauAssociatif & TABobjet);
	~CTableauAssociatif();

	CTableauAssociatif & operator=(CTableauAssociatif & TABobjet);
	Valeur & operator[](char * pcCle);

	void TABsupprimer(char * pcCle);
	void TABmodifier(char * pcCle, Valeur vValeur);

	void TABajouterEntier(char * pcCle, int iVal);
	void TABajouterReel(char * pcCle, double dVal);
	void TABajouterChaine(char * pcCle, char * pcVal);
	void TABajouterAuto(char * pcCle, char * pcVal);

	unsigned int TABgetNbElements() const;
	int TABgetIndiceCle(char * pcCle) const;
	const char const * TABgetCle(unsigned int uiPos) const;
	Valeur TABgetValeur(char * pcCle) const;
	Valeur TABgetValeurPos(unsigned int uiPos);

	int TABgetValeurEntier(char * pcCle) const;
	double TABgetValeurReel(char * pcCle) const;
	const char const * TABgetValeurChaine(char * pcCle) const;
};

#endif