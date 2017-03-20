#ifndef CTESTCMATRICE_H
#define CTESTCMATRICE_H

#include <assert.h>
#include "Matrice.h"

class CTestCMatrice
{
private:
	CTestCMatrice();
	~CTestCMatrice();

	void TMAtestAccesseurs();

	void TMAtestOperateurPlus();
	void TMAtestOperateurMoins();
	void TMAtestOperateurEgal();
	void TMAtestOperateursComparaison();
	void TMAtestOperateurProduit();
	void TMAtestOperateurDiviser();
	void TMAtestOperateurPuissance();

	void TMAtestOperateurs();

	void TMAtestCalculRang();
	void TMAtestCalculEchelonnee();
	void TMAtestCalculTransposee();
	void TMAtestCalculSousMatrice();

	void TMAtestCalculs();

	void TMAtestEstNulle();

	void TMAtestExceptions();

public:

	static void TMAstart();
};

#endif // CTESTCMATRICE_H