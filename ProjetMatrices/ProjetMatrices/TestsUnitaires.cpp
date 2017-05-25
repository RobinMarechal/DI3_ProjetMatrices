#include "TestsUnitaires.h"
//#include "Matrice.h"
#include "Cexception.h"
#include <assert.h>
#include <iostream>
#include "helpers.h"

#include "TableauAssociatif.h"
#include "TesteurMatrice.h"
#include "OperationMatrice.h"

using namespace std;

#define assertionBasique(expr) cout << "."; assert(expr);
#define assertionVraie(expr) assertionBasique((expr) == true)
#define assertionFausse(expr) assertionBasique((expr) == false)
#define assertionEgalite(param1, param2) assertionBasique((param1) == (param2))
#define assertionDifference(param1, param2) assertionBasique((param1) != (param2))
#define assertionPointeurNull(expr) assertionBasique((expr) == nullptr)
#define assertNotNull(expr) assertionBasique((expr) != nullptr)
#define assertionExceptionSoulevee() assertionBasique(true == false)
#define assertionExceptionNonSoulevee() assertionBasique(true == false)


/*****************************************
Constructeur par défaut
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la création de l'objet.
******************************************/
CTestsUnitaires::CTestsUnitaires()
{
}


/*****************************************
Teste les accesseurs.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestAccesseurs() const
{
	cout << "UNItestAccesseurs()";

	CMatrice<int> MATm1(2, 3);
	assertionEgalite(MATm1.MATgetNbLignes(), 2);
	assertionEgalite(MATm1.MATgetNbColonnes(), 3);

	assertionEgalite(MATm1(0, 0), 0);
	assertionEgalite(MATm1(0, 1), 0);
	assertionEgalite(MATm1(1, 0), 0);
	assertionEgalite(MATm1(1, 1), 0);

	// | 2  3  7 |
	// | 5  1  0 |
	MATm1(0, 0) = 2;
	MATm1(0, 1) = 3;
	MATm1(0, 2) = 7;
	MATm1.MATsetValeur(1, 0, 5);
	MATm1.MATgetValeur(1, 1) = 1;
	MATm1(1, 2) = 0;

	assertionEgalite(MATm1.MATgetValeur(0, 0), 2);
	assertionEgalite(MATm1.MATgetValeur(0, 1), 3);
	assertionEgalite(MATm1.MATgetValeur(1, 0), 5);
	assertionEgalite(MATm1.MATgetValeur(1, 1), 1);

	assertionEgalite(MATm1.MATgetLigne(0)[0], 2);
	assertionEgalite(MATm1.MATgetLigne(0)[1], 3);
	assertionEgalite(MATm1.MATgetLigne(0)[2], 7);
	assertionEgalite(MATm1.MATgetColonne(0)[0], 2);
	assertionEgalite(MATm1.MATgetColonne(1)[1], 1);

	cout << "OK" << endl;
}


/*****************************************
Teste l'opérateur +.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateurPlus() const
{
	cout << "UNItestOperateurPlus()";
	CMatrice<int> MATm1(2, 2), MATm2(2, 2);

	assertionEgalite((MATm1 + MATm2)(0, 0), 0);
	assertionEgalite((MATm1 + MATm2)(1, 1), 0);

	// | 1  2 |
	// | 3  4 |
	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	// | 5  6 |
	// | 7  8 |
	MATm2(0, 0) = 5;
	MATm2(0, 1) = 6;
	MATm2(1, 0) = 7;
	MATm2(1, 1) = 8;

	// | 6  8 |
	// | 10  12 |
	CMatrice<int> MATm3 = MATm1 + MATm2;

	assertionEgalite(MATm3(0, 0), 6);
	assertionEgalite(MATm3(0, 1), 8);
	assertionEgalite(MATm3(1, 0), 10);
	assertionEgalite(MATm3(1, 1), 12);

	assertionEgalite((MATm1 + 5)(0, 0), 6);
	assertionEgalite((MATm1 + 5)(0, 1), 7);
	assertionEgalite((MATm1 + 5)(1, 0), 8);
	assertionEgalite((MATm1 + 5)(1, 1), 9);

	// Commutativite
	assertionEgalite(MATm1 + 5, 5 + MATm1);

	cout << "OK" << endl;
}


/*****************************************
Teste l'opérateur -.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateurMoins() const
{
	cout << "UNItestOperateurMoins()";
	CMatrice<int> MATm1(2, 2), MATm2(2, 2);

	assertionEgalite(MATm1 - MATm2, MATm1);

	// | 1  2 |
	// | 3  4 |
	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	// | 5  6 |
	// | 7  9 |
	MATm2(0, 0) = 5;
	MATm2(0, 1) = 6;
	MATm2(1, 0) = 7;
	MATm2(1, 1) = 9;

	// | -4  -4 |
	// | -4  -5 |
	CMatrice<int> MATm3 = MATm1 - MATm2;

	assertionEgalite(MATm3(0, 0), -4);
	assertionEgalite(MATm3(0, 1), -4);
	assertionEgalite(MATm3(1, 0), -4);
	assertionEgalite(MATm3(1, 1), -5);

	assertionEgalite((MATm1 - 5)(0, 0), -4);
	assertionEgalite((MATm1 - 5)(0, 1), -3);
	assertionEgalite((MATm1 - 5)(1, 0), -2);
	assertionEgalite((MATm1 - 5)(1, 1), -1);

	assertionEgalite(5 - MATm1, MATm1 * (-1) + 5);

	cout << "OK" << endl;
}


/*****************************************
Teste l'opérateur =.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateurEgal() const
{
	cout << "UNItestOperateurEgal()";

	CMatrice<int> MATm1(2, 2), MATm2(2, 2);

	// | 1  2 |
	// | 3  4 |
	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	MATm2 = MATm1;

	assertionEgalite(MATm1, MATm2);

	cout << "OK" << endl;
}


/*****************************************
Teste les opérateur de comparaisons == et !=.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateursComparaison() const
{
	cout << "UNItestOperateursComparaison()";

	CMatrice<int> MATm1(2, 2), MATm2(3, 3), MATm3(2, 2);

	assertionVraie(MATm1 == MATm3);
	assertionFausse(MATm1 != MATm3);
	assertionFausse(MATm1 == MATm2);
	assertionVraie(MATm1 != MATm2);

	// | 1  2 |
	// | 3  4 |
	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	// | 1  2 |
	// | 3  0 |
	MATm3(0, 0) = 1;
	MATm3(0, 1) = 2;
	MATm3(1, 0) = 3;

	assertionFausse(MATm1 == MATm2);
	assertionVraie(MATm1 != MATm2);

	// | 1  2 |
	// | 3  4 |
	MATm3(1, 1) = 4;

	assertionVraie(MATm1 == MATm3);
	assertionFausse(MATm1 != MATm3);

	cout << "OK" << endl;
}


/*****************************************
Teste l'opérateur *.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateurProduit() const
{
	cout << "UNItestOperateurProduit()";

	CTesteurMatrice<int> TESt;
	CMatrice<int> MATid(2, 2), MATm1(2, 2), MATm2(2, 3), MATm3(3, 2);

	MATid(0, 0) = 1;
	MATid(0, 1) = 0;
	MATid(1, 0) = 0;
	MATid(1, 1) = 1;

	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	assertionEgalite((MATid * MATm1), MATm1);
	assertionEgalite((MATm1 * MATid), MATm1);


	assertionEgalite(5 * MATm1, MATm1 * 5);

	// | 1  2  3 |
	// | 4  5  6 |
	MATm2(0, 0) = 1;
	MATm2(0, 1) = 2;
	MATm2(0, 2) = 3;
	MATm2(1, 0) = 4;
	MATm2(1, 1) = 5;
	MATm2(1, 2) = 6;

	assertionVraie(TESt.TESestNulle(MATm2 * MATm3));

	// | 7  8  |
	// | 9  10 |
	// | 11 12 |
	MATm3(0, 0) = 7;
	MATm3(0, 1) = 8;
	MATm3(1, 0) = 9;
	MATm3(1, 1) = 10;
	MATm3(2, 0) = 11;
	MATm3(2, 1) = 12;
	CMatrice<int> MATtest = MATm2 * MATm3;
	CMatrice<int> MATres(2, 2);

	MATres(0, 0) = 58;
	MATres(0, 1) = 64;
	MATres(1, 0) = 139;
	MATres(1, 1) = 154;


	assertionEgalite(MATtest.MATgetNbLignes(), 2);
	assertionEgalite(MATtest.MATgetNbColonnes(), 2);

	assertionEgalite(MATtest, MATres);

	cout << "OK" << endl;
}


/*****************************************
Teste l'opérateur /.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateurDiviser() const
{
	cout << "UNItestOperateurDiviser()";

	CTesteurMatrice<int> TESt;

	CMatrice<int> MATm(2, 2), MATm1(2, 2);

	MATm(0, 0) = 4;
	MATm(0, 1) = 4;
	MATm(1, 0) = 4;
	MATm(1, 1) = 4;

	MATm1(0, 0) = 1;
	MATm1(0, 1) = 1;
	MATm1(1, 0) = 1;
	MATm1(1, 1) = 1;

	assertionEgalite(MATm / 4, MATm1);
	assertionVraie(TESt.TESestNulle(MATm / 10));

	cout << "OK" << endl;
}


/*****************************************
Teste l'opérateur ^.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestOperateurPuissance() const
{
	cout << "UNItestOperateurPuissance()";

	COperationMatrice<double> OPMo;

	// | 0 0 |
	// | 0 0 |
	CMatrice<double> MATnulle22(2, 2);

	// | 1 2 |
	// | 3 4 |
	CMatrice<double> MATm22(2, 2);
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	// | 1 0 |
	// | 0 1 |
	CMatrice<double> MATid22(2, 2);
	MATid22(0, 0) = 1;
	MATid22(1, 1) = 1;

	assertionEgalite(MATnulle22 ^ 2, MATnulle22);
	assertionEgalite(MATm22 ^ 1, MATm22);
	assertionEgalite(MATm22 ^ (-1), OPMo.OPMinverse(MATm22));
	assertionEgalite((MATm22 ^-1) ^ -1, MATm22);
	assertionEgalite((MATm22 ^ 2) ^ 3, MATm22 ^ 6);
	assertionEgalite(MATm22 ^ 2, MATm22 * MATm22);
	assertionEgalite(MATid22 ^ 3, MATid22);

	cout << "OK" << endl;
}


/*****************************************
Teste de tous les opérateurs.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'appel de tous les tests sur les opérateurs.
******************************************/
void CTestsUnitaires::UNItestOperateurs() const
{
	UNItestOperateursComparaison();
	UNItestOperateurEgal();
	UNItestOperateurPlus();
	UNItestOperateurMoins();
	UNItestOperateurProduit();
	UNItestOperateurDiviser();

	cout << "UNItestOperateurs()";

	CMatrice<int> MATm231(2, 3), MATm232(2, 3), MATm32(3, 2), MATtest(2, 2), MATres(2, 2);

	// | 1  2  3 |
	// | 4  5  6 |
	MATm231(0, 0) = 1;
	MATm231(0, 1) = 2;
	MATm231(0, 2) = 3;
	MATm231(1, 0) = 4;
	MATm231(1, 1) = 5;
	MATm231(1, 2) = 6;

	// |-1  0  2 |
	// | 5 -2  3 |
	MATm232(0, 0) = -1;
	MATm232(0, 1) = 0;
	MATm232(0, 2) = 2;
	MATm232(1, 0) = 5;
	MATm232(1, 1) = -2;
	MATm232(1, 2) = 3;

	// | 3  4 |
	// | 0  2 |
	// | 1 -2 |
	MATm32(0, 0) = 3;
	MATm32(0, 1) = 4;
	MATm32(1, 0) = 0;
	MATm32(1, 1) = 2;
	MATm32(2, 0) = 1;
	MATm32(2, 1) = -2;

	MATtest = (2 * MATm231 + 5 - MATm232 / 2) * MATm32;

	assertionEgalite(MATtest.MATgetNbLignes(), 2);
	assertionEgalite(MATtest.MATgetNbColonnes(), 2);

	// | 31  26 |
	// | 49  44 |
	MATres(0, 0) = 31;
	MATres(0, 1) = 26;
	MATres(1, 0) = 49;
	MATres(1, 1) = 44;

	assertionEgalite(MATtest, MATres);

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul du rang.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculRang() const
{
	cout << "UNItestCalculRang()";

	COperationMatrice<int> OPMo;
	CMatrice<int> MATm(2, 2), MATm2(2, 3);

	assertionEgalite(OPMo.OPMrang(MATm), 0);

	// | 1  2 |
	// | 3  4 |
	MATm(0, 0) = 1;
	MATm(0, 1) = 2;
	MATm(1, 0) = 3;
	MATm(1, 1) = 4;
	assertionEgalite(OPMo.OPMrang(MATm), 2);

	// | 1  2 |
	// | 3  6 |
	MATm(1, 1) = 6;

	assertionEgalite(OPMo.OPMrang(MATm), 1);


	// | 1  2  3 |
	// | 4  5  6 |
	MATm2(0, 0) = 1;
	MATm2(0, 1) = 2;
	MATm2(0, 2) = 3;
	MATm2(1, 0) = 4;
	MATm2(1, 1) = 5;
	MATm2(1, 2) = 6;

	assertionEgalite(OPMo.OPMrang(MATm2), 2);
	assertionEgalite(OPMo.OPMrang(OPMo.OPMtransposee(MATm2)), OPMo.OPMrang(MATm2));

	cout << "OK" << endl;
}


/*****************************************
Teste l'échelonnement.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculEchelonnee() const
{
	cout << "UNItestCalculEchelonnee()";

	COperationMatrice<double> OPMo;
	CMatrice<double> MATm1(2, 2), MATm2(2, 2);

	assertionEgalite(MATm1, OPMo.OPMechelonnee(MATm1));

	// | 1  0 |
	// | 0  2 |
	MATm1(0, 0) = 1;
	MATm1(1, 1) = 2;

	assertionEgalite(MATm1, OPMo.OPMechelonnee(MATm1));

	// | 1  3 |
	// | 0  2 |
	MATm1(0, 1) = 3;

	assertionEgalite(MATm1, OPMo.OPMechelonnee(MATm1));

	// | 2  4 |
	// | 4  5 |
	MATm1(0, 0) = 2;
	MATm1(0, 1) = 4;
	MATm1(1, 0) = 4;
	MATm1(1, 1) = 5;

	// Tests independants de l'implementation des fonctions...
	assertionDifference(OPMo.OPMechelonnee(MATm1)(0, 0), 0);
	assertionDifference(OPMo.OPMechelonnee(MATm1)(0, 1), 0);
	assertionEgalite(OPMo.OPMechelonnee(MATm1)(1, 0), 0);
	assertionDifference(OPMo.OPMechelonnee(MATm1)(1, 1), 0);

	MATm1(1, 1) = 8;

	assertionDifference(OPMo.OPMechelonnee(MATm1)(0, 0), 0);
	assertionDifference(OPMo.OPMechelonnee(MATm1)(0, 1), 0);
	assertionEgalite(OPMo.OPMechelonnee(MATm1)(1, 0), 0);
	assertionEgalite(OPMo.OPMechelonnee(MATm1)(1, 1), 0);

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul de la transposée.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculTransposee() const
{
	cout << "UNItestCalculTransposee()";

	COperationMatrice<int> OPMo;
	CMatrice<int> MATm22(2, 2), MATm23(2, 3), MATm32(3, 2);

	// | 1  0 |
	// | 0  1 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 1;

	assertionEgalite(OPMo.OPMtransposee(MATm22), MATm22);

	// | 1  2 |
	// | 0  1 |
	MATm22(0, 1) = 2;

	assertionEgalite(OPMo.OPMtransposee(OPMo.OPMtransposee(MATm22)), MATm22);
	assertionEgalite(OPMo.OPMtransposee(MATm22)(1, 0), 2);

	// | 1  2  3 |
	// | 4  5  6 |
	MATm23(0, 0) = 1;
	MATm23(0, 1) = 2;
	MATm23(0, 2) = 3;
	MATm23(1, 0) = 4;
	MATm23(1, 1) = 5;
	MATm23(1, 2) = 6;

	// | 1  4 |
	// | 2  5 |
	// | 3  6 |
	MATm32(0, 0) = 1;
	MATm32(0, 1) = 4;
	MATm32(1, 0) = 2;
	MATm32(1, 1) = 5;
	MATm32(2, 0) = 3;
	MATm32(2, 1) = 6;

	assertionEgalite(OPMo.OPMtransposee(MATm23), MATm32);

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul de la sous-matrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculSousMatrice() const
{
	cout << "UNItestCalculSousMatrice()";
	COperationMatrice<int> OPMo;
	CMatrice<int> MATm22(2, 3), MATsousM11(1, 2);

	// | 1  2  3 |
	// | 4  5  6 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(0, 2) = 3;
	MATm22(1, 0) = 4;
	MATm22(1, 1) = 5;
	MATm22(1, 2) = 6;

	// | 1  3 |
	MATsousM11(0, 0) = 1;
	MATsousM11(0, 1) = 3;

	assertionEgalite(OPMo.OPMsousMatrice(MATm22, 0, 0).MATgetNbLignes(), 1);
	assertionEgalite(OPMo.OPMsousMatrice(MATm22, 0, 0).MATgetNbColonnes(), 2);
	assertionEgalite(OPMo.OPMsousMatrice(MATm22, 1, 1), MATsousM11);

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul du déterminant.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculDet() const
{
	cout << "UNItestCalculDet()";
	COperationMatrice<int> OPMo;
	CMatrice<int> MATm22(2, 2);

	assertionEgalite(OPMo.OPMdet(MATm22), 0);

	// | 1 0 |
	// | 0 4 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 4;

	assertionEgalite(OPMo.OPMdet(MATm22), 4);

	// | 1 2 |
	// | 0 4 |
	MATm22(0, 1) = 2;

	assertionEgalite(OPMo.OPMdet(MATm22), 4);

	// | 1 2 |
	// | 3 4 |
	MATm22(1, 0) = 3;

	assertionEgalite(OPMo.OPMdet(MATm22), 1 * 4 - 2 * 3);

	CMatrice<int> MATm22_2 = MATm22 + 2;

	assertionEgalite(OPMo.OPMdet(MATm22 * MATm22_2), OPMo.OPMdet(MATm22) * OPMo.OPMdet(MATm22_2));
	assertionEgalite(OPMo.OPMdet(MATm22 * 3), OPMo.OPMdet(MATm22) * 9)
	assertionDifference(OPMo.OPMdet(MATm22 + MATm22_2), OPMo.OPMdet(MATm22) + OPMo.OPMdet(MATm22_2));

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul de la matrice inverse.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculInverse() const
{
	cout << "UNItestCalculInverse()";
	// Le cas du déterminant nul est testé dans UNItestExceptions()

	COperationMatrice<double> OPMo;
	CMatrice<double> MATm22(2, 2);
	CMatrice<double> MATinv22(2, 2);

	// 1  0
	// 0  0.25
	MATinv22(0, 0) = 1;
	MATinv22(1, 1) = 0.25;

	// 1 0
	// 0 1
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 1;

	assertionEgalite(OPMo.OPMinverse(MATm22), MATm22);

	// 1 0
	// 0 4
	MATm22(1, 1) = 4;

	assertionEgalite(OPMo.OPMinverse(MATm22), MATinv22);

	// 1 2
	// 3 4
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;

	// -2    1
	// -1.5 -0.5
	MATinv22(0, 0) = -2;
	MATinv22(0, 1) = 1;
	MATinv22(1, 0) = 1.5;
	MATinv22(1, 1) = -0.5;

	assertionEgalite(OPMo.OPMinverse(OPMo.OPMinverse(MATm22)), MATm22);
	assertionEgalite(OPMo.OPMinverse(MATm22), MATinv22);

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul de la commatrice.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculCommatrice() const
{
	cout << "UNItestCalculCommatrice()";

	COperationMatrice<int> OPMo;
	CMatrice<int> MATm22(2, 2);
	CMatrice<int> MATcomm22(2, 2);

	assertionEgalite(OPMo.OPMcommatrice(MATm22), MATm22);

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	// 4 -3
	// -2 1
	MATcomm22(0, 0) = 4;
	MATcomm22(0, 1) = -3;
	MATcomm22(1, 0) = -2;
	MATcomm22(1, 1) = 1;

	assertionEgalite(OPMo.OPMcommatrice(MATm22), MATcomm22);

	cout << "OK" << endl;
}


/*****************************************
Teste le calcul de la trace.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCalculTrace() const
{
	cout << "UNItestCalculTrace()";

	COperationMatrice<int> OPMo;
	CMatrice<int> MATm22(2, 2);

	assertionEgalite(OPMo.OPMtr(MATm22), 0);

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionEgalite(OPMo.OPMtr(MATm22), 5);
	assertionEgalite(OPMo.OPMtr(OPMo.OPMtransposee(MATm22)) , OPMo.OPMtr(MATm22));

	CMatrice<int> MATm22_2 = MATm22 * 2 - 1;

	assertionEgalite(OPMo.OPMtr(MATm22 + MATm22_2), OPMo.OPMtr(MATm22) + OPMo.OPMtr(MATm22_2));

	cout << "OK" << endl;
}


/*****************************************
Teste tous les calculs.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'appel de tous les tests sur les calculs.
******************************************/
void CTestsUnitaires::UNItestCalculs() const
{
	UNItestCalculSousMatrice();
	UNItestCalculEchelonnee();
	UNItestCalculTransposee();
	UNItestCalculRang();
	UNItestCholeski();

	// Matrices carrees
	UNItestCalculDet();
	UNItestCalculInverse();
	UNItestCalculCommatrice();
	UNItestCalculTrace();
}


/*****************************************
Teste le test de matrice nulle.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstNulle() const
{
	cout << "UNItestEstNulle()";

	CTesteurMatrice<int> TESt;
	CMatrice<int> MATm(2, 2);

	MATm(0, 0) = 0;
	MATm(0, 1) = 0;
	MATm(1, 0) = 0;
	MATm(1, 1) = 0;

	assertionVraie(TESt.TESestNulle(MATm));

	MATm(0, 1) = 2;

	assertionFausse(TESt.TESestNulle(MATm));

	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice triangulaire.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstTriangulaire() const
{
	UNItestEstTriangulaireSuperieure();
	UNItestEstTriangulaireInferieure();
}


/*****************************************
Teste le test de matrice triangulaire supérieur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstTriangulaireSuperieure() const
{
	cout << "UNItestEstTriangulaireSuperieure()";

	CTesteurMatrice<int> TESt;

	// | 1 2 |
	// | 0 4 |
	CMatrice<int> MATm22(2, 2);

	assertionVraie(TESt.TESestTriangulaireSuperieure(MATm22));
	assertionVraie(TESt.TESestTriangulaireInferieure(MATm22));

	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 1) = 4;

	assertionVraie(TESt.TESestTriangulaireSuperieure(MATm22));
	assertionFausse(TESt.TESestTriangulaireInferieure(MATm22));

	// | 1 2 |
	// | 5 4 |
	MATm22(1, 0) = 5;

	assertionFausse(TESt.TESestTriangulaireSuperieure(MATm22));


	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice triangulaire inférieur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstTriangulaireInferieure() const
{
	cout << "UNItestEstTriangulaireInferieure()";

	CTesteurMatrice<int> TESt;

	// | 1 0 |
	// | 3 4 |
	CMatrice<int> MATm22(2, 2);

	assertionVraie(TESt.TESestTriangulaireSuperieure(MATm22));
	assertionVraie(TESt.TESestTriangulaireInferieure(MATm22));

	MATm22(0, 0) = 1;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionVraie(TESt.TESestTriangulaireInferieure(MATm22));
	assertionFausse(TESt.TESestTriangulaireSuperieure(MATm22));

	// | 1 5 |
	// | 3 4 |
	MATm22(0, 1) = 5;

	assertionFausse(TESt.TESestTriangulaireInferieure(MATm22));


	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice diagonale.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstDiagonale() const
{
	cout << "UNItestEstDiagonale()";

	CTesteurMatrice<int> TESt;

	CMatrice<int> MATm22(2, 2);
	assertionVraie(TESt.TESestDiagonale(MATm22));

	// | 1 0 |
	// | 0 4 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 4;

	assertionVraie(TESt.TESestDiagonale(MATm22));

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;

	assertionFausse(TESt.TESestDiagonale(MATm22));

	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice inversible.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstInversible() const
{
	cout << "UNItestEstInversible()";

	CTesteurMatrice<int> TESt;
	CMatrice<int> MATm22(2, 2);

	assertionFausse(TESt.TESestInversible(MATm22));

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionVraie(TESt.TESestInversible(MATm22));

	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice symétrique.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstSymetrique() const
{
	cout << "UNItestEstSymetrique()";

	CTesteurMatrice<int> TESt;
	CMatrice<int> MATm22(2, 2);

	assertionVraie(TESt.TESestSymetrique(MATm22));

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionFausse(TESt.TESestSymetrique(MATm22));

	// | 1 2 |
	// | 2 4 |
	MATm22(1, 0) = 2;

	assertionVraie(TESt.TESestSymetrique(MATm22));

	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice antisymétrique.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestEstAntiSymetrique() const
{
	cout << "UNItestEstAntiSymetrique()";

	CTesteurMatrice<int> TESt;
	CMatrice<int> MATm22(2, 2);

	assertionVraie(TESt.TESestAntiSymetrique(MATm22));

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionFausse(TESt.TESestAntiSymetrique(MATm22));

	// | 1  2 |
	// | -2 4 |
	MATm22(1, 0) = -2;

	assertionFausse(TESt.TESestAntiSymetrique(MATm22));

	// | 0  2 |
	// | -2 0 |
	MATm22(0, 0) = 0;
	MATm22(1, 1) = 0;

	assertionVraie(TESt.TESestAntiSymetrique(MATm22));

	cout << "OK" << endl;
}


/*****************************************
Teste le test de matrice carrée.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'appel de tous les tests sur les méthodes de test.
******************************************/
void CTestsUnitaires::UNItestTestsMatriceCarree() const
{
	UNItestEstTriangulaire();
	UNItestEstDiagonale();
	UNItestEstInversible();
	UNItestEstSymetrique();
	UNItestEstAntiSymetrique();
}


/*****************************************
Teste la création d'une matrice diagonale.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestDiag() const
{
	COperationMatrice<int> OPMo;

	cout << "UNItestDiag()";
	const int iTab[] = {1, 2, 4};

	CMatrice<int> MATm22 = OPMo.OPMcreerMatriceDiagonale(3, iTab);

	assertionEgalite(OPMo.OPMdet(MATm22), 8);
	assertionEgalite(OPMo.OPMtr(MATm22), 7);

	cout << "OK" << endl;
}


/*****************************************
Teste les exceptions.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestExceptions() const
{
	cout << "UNItestExceptions()";

	CMatrice<int> MATm23(2, 3);
	CMatrice<int> MATm33(3, 3);

	// operator/

	// Doit lever une exception
	try
	{
		MATm23 / 0;
		assertionExceptionSoulevee();
	}
	catch (Cexception EXCe)
	{
		cout << ".";
	}

	// Ne doit pas lever d'exception 
	try
	{
		MATm23 / 2;
		cout << ".";
	}
	catch (Cexception EXCe)
	{
		assertionExceptionNonSoulevee();
	}

	// operator ^

	// Doit lever une exception
	try
	{
		MATm33 ^ 0;
		assertionExceptionSoulevee();
	}
	catch (Cexception EXCe)
	{
		cout << ".";
	}

	// Ne doit pas lever d'exception 
	try
	{
		MATm33 ^ 2;
		cout << ".";
	}
	catch (Cexception EXCe)
	{
		assertionExceptionNonSoulevee();
	}

	cout << "OK" << endl;
}


/*****************************************
Teste le fonctionnement global de CTableauAssociatif
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestsCTableauAssociatif() const
{
	cout << "UNItestsCTableauAssociatif()";
	CTableauAssociatif TABt;

	assertionEgalite(TABt.TABgetNbElements(), 0);

	unsigned int uiPos;
	double dReel = 5.2;
	int iEntier = 7;
	char* pcStr = "abc";
	// alocation dynamique car on va tester que le free ne modifie pas la valeur dans le tableau
	char* pcChaine = _strdup(pcStr);

	TABt.TABajouterReel("reel", dReel);
	TABt.TABajouterEntier("entier", iEntier);
	TABt.TABajouterChaine("chaine", _strdup(pcChaine));

	// Tests types
	assertionEgalite(TABt.TABgetNbElements(), 3);
	assertionEgalite(TABt.TABgetValeurType("reel"), TYPE_REEL);
	assertionEgalite(TABt.TABgetValeurType("entier"), TYPE_ENTIER);
	assertionEgalite(TABt.TABgetValeurType("chaine"), TYPE_CHAINE);

	// test indices
	assertionEgalite(TABt.TABgetIndiceCle("entier"), 1);
	assertionEgalite(TABt.TABgetIndiceCle("absent"), -1);

	// test suppression
	TABt.TABajouterChaine("chaine2", _strdup("def"));
	TABt.TABajouterChaine("chaine3", _strdup("ijk"));
	uiPos = TABt.TABgetIndiceCle("chaine2");
	TABt.TABsupprimer("chaine2");
	assertionEgalite(TABt.TABgetIndiceCle("chaine3"), uiPos);
	assertionVraie(strcmp(TABt.TABgetValeurChaine("chaine3"), "ijk") == 0);

	// Test valeurs
	assertionEgalite(TABt.TABgetValeurReel("reel"), dReel);
	assertionEgalite(TABt.TABgetValeurEntier("entier"), iEntier);
	assertionVraie(strcmp(TABt.TABgetValeurChaine("chaine"), pcChaine) == 0);
	assertionEgalite(TABt.TABgetValeurPos(0).dReel, TABt.TABgetValeurReel("reel"));

	// tests tronquages
	assertionEgalite(TABt.TABgetValeurEntier("reel"), (int)dReel);
	assertionEgalite(TABt.TABgetValeurReel("entier"), (double)iEntier);

	// Tests ajout auto
	TABt.TABajouterAuto("reel auto", "5.2");
	TABt.TABajouterAuto("entier auto", "7");
	TABt.TABajouterAuto("chaine auto", pcChaine);

	assertionEgalite(TABt.TABgetValeurType("reel auto"), TYPE_REEL);
	assertionEgalite(TABt.TABgetValeurType("entier auto"), TYPE_ENTIER);
	assertionEgalite(TABt.TABgetValeurType("chaine auto"), TYPE_CHAINE);

	free(pcChaine);
	assertionVraie(strcmp(TABt.TABgetValeurChaine("chaine auto"), pcStr) == 0);

	// Tests recopie

	CTableauAssociatif TABt2(TABt);

	assertionEgalite(TABt2.TABgetNbElements(), TABt.TABgetNbElements());
	assertionEgalite(TABt2.TABgetValeurReel("reel"), dReel);
	assertionEgalite(TABt2.TABgetValeurEntier("entier"), iEntier);
	assertionVraie(strcmp(TABt.TABgetValeurChaine("chaine auto"), TABt2.TABgetValeurChaine("chaine auto")) == 0);

	// Tests operateur = (doit tout écraser)
	CTableauAssociatif TABt3;

	TABt3.TABajouterEntier("supprimé", -2);

	TABt3 = TABt;

	assertionEgalite(TABt2.TABgetIndiceCle("supprimé"), -1);

	assertionEgalite(TABt3.TABgetNbElements(), TABt.TABgetNbElements());
	assertionEgalite(TABt3.TABgetValeurReel("reel"), dReel);
	assertionEgalite(TABt3.TABgetValeurEntier("entier"), iEntier);
	assertionVraie(strcmp(TABt.TABgetValeurChaine("chaine auto"), TABt3.TABgetValeurChaine("chaine auto")) == 0);

	cout << "OK" << endl;
}


/*****************************************
Test du calcul de la factorisation de Choleski
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestCholeski() const
{
	cout << "UNItestCholeski()";

	COperationMatrice<double> OPMoperation;

	// | 1  1  1  1  |
	// | 1  5  5  5  |
	// | 1  5  14 14 |
	// | 1  5  14 15 |
	CMatrice<double> MATdefPos(4, 4);

	// | 0  1  1  1  |
	// | 1  5  5  5  |
	// | 1  5  14 14 |
	// | 1  5  14 15 |
	CMatrice<double> MATnonDefPos(4, 4);

	// | 1  12 1  1  |
	// | 1  5  5  5  |
	// | 1  5  14 14 |
	// | 1  5  14 15 |
	CMatrice<double> MATnonSym(4, 4);

	// | 0 0 |
	CMatrice<double> MATnonCarree(1, 2);

	MATdefPos(0, 0) = 1;
	MATdefPos(0, 1) = 1;
	MATdefPos(0, 2) = 1;
	MATdefPos(0, 3) = 1;

	MATdefPos(1, 0) = 1;
	MATdefPos(1, 1) = 5;
	MATdefPos(1, 2) = 5;
	MATdefPos(1, 3) = 5;

	MATdefPos(2, 0) = 1;
	MATdefPos(2, 1) = 5;
	MATdefPos(2, 2) = 14;
	MATdefPos(2, 3) = 14;

	MATdefPos(3, 0) = 1;
	MATdefPos(3, 1) = 5;
	MATdefPos(3, 2) = 14;
	MATdefPos(3, 3) = 15;

	MATnonDefPos = MATdefPos;
	MATnonDefPos(0, 0) = 0;

	MATnonSym = MATdefPos;
	MATnonSym(0, 1) = 12;
	

	try
	{
		CMatrice<double> MATresult = OPMoperation.OPMfactorisationCholeski(MATdefPos);
		assertionEgalite(MATdefPos, MATresult * OPMoperation.OPMtransposee(MATresult));
		cout << "." << endl;
	}
	catch (Cexception EXCe)
	{
		// Ne doit pas lever d'exception
		assertionExceptionNonSoulevee();
	}


	try
	{
		OPMoperation.OPMfactorisationCholeski(MATnonDefPos);
		// doit lever une exception
		assertionExceptionSoulevee();
	}
	catch (Cexception EXCe)
	{
		assertionEgalite(EXCe.EXCgetValeur(), EXC_CALCUL_IMPOSSIBLE);
	}


	try
	{
		OPMoperation.OPMfactorisationCholeski(MATnonSym);
		// doit lever une exception
		assertionExceptionSoulevee();
	}
	catch (Cexception EXCe)
	{
		assertionEgalite(EXCe.EXCgetValeur(), EXC_CALCUL_IMPOSSIBLE);
	}


	try
	{
		OPMoperation.OPMfactorisationCholeski(MATnonCarree);
		// doit lever une exception
		assertionExceptionSoulevee();
	}
	catch (Cexception EXCe)
	{
		assertionEgalite(EXCe.EXCgetValeur(), EXC_DIMENSIONS_INVALIDES);
	}

	cout << "OK" << endl;
}


/*****************************************
Début des tests.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'appel de tous les tests.
******************************************/
void CTestsUnitaires::UNIstart()
{
	cout << "------------------------------------------" << endl;
	cout << "DEBUT DES TESTS UNITAIRES" << endl;
	cout << "------------------------------------------" << endl << endl;

	CTestsUnitaires UNItest;

	UNItest.UNItestEstNulle();
	UNItest.UNItestAccesseurs();
	UNItest.UNItestOperateurs();
	UNItest.UNItestExceptions();
	UNItest.UNItestTestsMatriceCarree();
	UNItest.UNItestDiag();
	UNItest.UNItestCalculs();
	UNItest.UNItestOperateurPuissance();
	UNItest.UNItestsCTableauAssociatif();

	cout << endl << "FIN DES TESTS UNITAIRES" << endl;
	cout << "------------------------------------------" << endl;
}
