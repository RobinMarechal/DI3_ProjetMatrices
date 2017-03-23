#ifndef CTESTCMATRICE_H
#define CTESTCMATRICE_H

#include <assert.h>
#include "Matrice.h"

class CTestCMatrice
{
private:

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
	void TMAtestCalculDet();
	void TMAtestCalculInverse();
	void TMAtestCalculCommatrice();
	void TMAtestCalculTrace();

	void TMAtestCalculs();

	void TMAtestEstNulle();
	void TMAtestEstTriangulaire();
	void TMAtestEstTriangulaireSuperieure();
	void TMAtestEstTriangulaireInferieure();
	void TMAtestEstDiagonale();
	void TMAtestEstInversible();
	void TMAtestEstSymetrique();
	void TMAtestEstAntiSymetrique();

	void TMAtestTestsMatriceCarree();

	void TMAtestDiag();

	void TMAtestExceptions();

public:

	static void TMAstart();
};

#endif // CTESTCMATRICE_H