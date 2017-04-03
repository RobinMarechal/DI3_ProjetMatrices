#include "TestsUnitaires.h"
#include "Matrice.h"
#include "Cexception.h"
#include <assert.h>
#include <iostream>
#include "helpers.h"
#include "constantes.h"
#include "TableauAssociatif.h"

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
CTestsUnitaires::CTestsUnitaires() {}


/*****************************************
Teste les accesseurs.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'arrêt du programme si une assertion n'est pas vérifiée.
******************************************/
void CTestsUnitaires::UNItestAccesseurs()
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

void CTestsUnitaires::UNItestOperateurPlus()
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

void CTestsUnitaires::UNItestOperateurMoins()
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

void CTestsUnitaires::UNItestOperateurEgal()
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

void CTestsUnitaires::UNItestOperateursComparaison()
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

void CTestsUnitaires::UNItestOperateurProduit()
{
	cout << "UNItestOperateurProduit()";

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

	assertionVraie((MATm2 * MATm3).MATestNulle());

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

void CTestsUnitaires::UNItestOperateurDiviser()
{
	cout << "UNItestOperateurDiviser()";

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
	assertionVraie((MATm / 10).MATestNulle());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestOperateurPuissance()
{
	cout << "UNItestOperateurPuissance()";

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
	assertionEgalite(MATm22 ^(-1), MATm22.MATinverse());
	assertionEgalite((MATm22 ^-1) ^ -1, MATm22);
	assertionEgalite((MATm22 ^ 2) ^ 3, MATm22 ^ 6);
	assertionEgalite(MATm22 ^ 2, MATm22 * MATm22);
	assertionEgalite(MATid22 ^ 3, MATid22);

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestOperateurs()
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

void CTestsUnitaires::UNItestCalculRang()
{
	cout << "UNItestCalculRang()";

	CMatrice<int> MATm(2, 2), MATm2(2, 3);

	assertionEgalite(MATm.MATrang(), 0);

	// | 1  2 |
	// | 3  4 |
	MATm(0, 0) = 1;
	MATm(0, 1) = 2;
	MATm(1, 0) = 3;
	MATm(1, 1) = 4;
	assertionEgalite(MATm.MATrang(), 2);

	// | 1  2 |
	// | 3  6 |
	MATm(1, 1) = 6;

	assertionEgalite(MATm.MATrang(), 1);

	
	// | 1  2  3 |
	// | 4  5  6 |
	MATm2(0, 0) = 1;
	MATm2(0, 1) = 2;
	MATm2(0, 2) = 3;
	MATm2(1, 0) = 4;
	MATm2(1, 1) = 5;
	MATm2(1, 2) = 6;

	assertionEgalite(MATm2.MATrang(), 2);
	assertionEgalite(MATm2.MATtransposee().MATrang(), MATm2.MATrang());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculEchelonnee()
{
	cout << "UNItestCalculEchelonnee()";

	CMatrice<double> MATm1(2, 2), MATm2(2, 2);

	assertionEgalite(MATm1, MATm1.MATechelonnee());

	// | 1  0 |
	// | 0  2 |
	MATm1(0, 0) = 1;
	MATm1(1, 1) = 2;

	assertionEgalite(MATm1, MATm1.MATechelonnee());

	// | 1  3 |
	// | 0  2 |
	MATm1(0, 1) = 3;

	assertionEgalite(MATm1, MATm1.MATechelonnee());

	// | 2  4 |
	// | 4  5 |
	MATm1(0, 0) = 2;
	MATm1(0, 1) = 4;
	MATm1(1, 0) = 4;
	MATm1(1, 1) = 5;

	// Tests independants de l'implementation des fonctions...
	assertionDifference(MATm1.MATechelonnee()(0, 0), 0);
	assertionDifference(MATm1.MATechelonnee()(0, 1), 0);
	assertionEgalite(MATm1.MATechelonnee()(1, 0), 0);
	assertionDifference(MATm1.MATechelonnee()(1, 1), 0);

	MATm1(1, 1) = 8;

	assertionDifference(MATm1.MATechelonnee()(0, 0), 0);
	assertionDifference(MATm1.MATechelonnee()(0, 1), 0);
	assertionEgalite(MATm1.MATechelonnee()(1, 0), 0);
	assertionEgalite(MATm1.MATechelonnee()(1, 1), 0);
	
	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculTransposee()
{
	cout << "UNItestCalculTransposee()";

	CMatrice<int> MATm22(2, 2), MATm23(2, 3), MATm32(3, 2);

	// | 1  0 |
	// | 0  1 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 1;

	assertionEgalite(MATm22.MATtransposee(), MATm22);

	// | 1  2 |
	// | 0  1 |
	MATm22(0, 1) = 2;

	assertionEgalite(MATm22.MATtransposee().MATtransposee(), MATm22);
	assertionEgalite(MATm22.MATtransposee()(1, 0), 2);

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

	assertionEgalite(MATm23.MATtransposee(), MATm32);

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculSousMatrice()
{
	cout << "UNItestCalculSousMatrice()";
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

	assertionEgalite(MATm22.MATsousMatrice(0, 0).MATgetNbLignes(), 1);
	assertionEgalite(MATm22.MATsousMatrice(0, 0).MATgetNbColonnes(), 2);
	assertionEgalite(MATm22.MATsousMatrice(1, 1), MATsousM11);

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculDet()
{
	cout << "UNItestCalculDet()";
	CMatrice<int> MATm22(2, 2);

	assertionEgalite(MATm22.MATdet(), 0);

	// | 1 0 |
	// | 0 4 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 4;

	assertionEgalite(MATm22.MATdet(), 4);

	// | 1 2 |
	// | 0 4 |
	MATm22(0, 1) = 2;

	assertionEgalite(MATm22.MATdet(), 4);

	// | 1 2 |
	// | 3 4 |
	MATm22(1, 0) = 3;
	
	assertionEgalite(MATm22.MATdet(), 1 * 4 - 2 * 3);

	CMatrice<int> MATm22_2 = MATm22 + 2;

	assertionEgalite((MATm22 * MATm22_2).MATdet(), MATm22.MATdet() * MATm22_2.MATdet());
	assertionEgalite((MATm22 * 3).MATdet(), MATm22.MATdet() * (3 * 3));
	assertionDifference((MATm22 + MATm22_2).MATdet(), MATm22.MATdet() + MATm22_2.MATdet());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculInverse()
{
	cout << "UNItestCalculInverse()";
	// Le cas du déterminant nul est testé dans UNItestExceptions()

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

	assertionEgalite(MATm22.MATinverse(), MATm22);

	// 1 0
	// 0 4
	MATm22(1, 1) = 4;

	assertionEgalite(MATm22.MATinverse(), MATinv22);

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

	assertionEgalite(MATm22.MATinverse().MATinverse(), MATm22);
	assertionEgalite(MATm22.MATinverse(), MATinv22);

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculCommatrice()
{
	cout << "UNItestCalculCommatrice()";
	CMatrice<int> MATm22(2, 2);
	CMatrice<int> MATcomm22(2, 2);

	assertionEgalite(MATm22.MATcommatrice(), MATm22);

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

	assertionEgalite(MATm22.MATcommatrice(), MATcomm22);

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculTrace()
{
	cout << "UNItestCalculTrace()";

	CMatrice<int> MATm22(2, 2);

	assertionEgalite(MATm22.MATtr(), 0);

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionEgalite(MATm22.MATtr(), 5);
	assertionEgalite(MATm22.MATtransposee().MATtr(), MATm22.MATtr());

	CMatrice<int> MATm22_2 = MATm22 * 2 - 1;

	assertionEgalite((MATm22 + MATm22_2).MATtr(), MATm22.MATtr() + MATm22_2.MATtr());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestCalculs()
{
	UNItestCalculSousMatrice();
	UNItestCalculEchelonnee();
	UNItestCalculTransposee();
	UNItestCalculRang();

	// Matrices carrees
	UNItestCalculDet();
	UNItestCalculInverse();
	UNItestCalculCommatrice();
	UNItestCalculTrace();
}

void CTestsUnitaires::UNItestEstNulle()
{
	cout << "UNItestEstNulle()";

	CMatrice<int> MATm(2, 2);
	MATm(0, 0) = 0;
	MATm(0, 1) = 0;
	MATm(1, 0) = 0;
	MATm(1, 1) = 0;

	assertionVraie(MATm.MATestNulle())

	MATm(0, 1) = 2;

	assertionFausse(MATm.MATestNulle());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestEstTriangulaire()
{
	UNItestEstTriangulaireSuperieure();
	UNItestEstTriangulaireInferieure();
}

void CTestsUnitaires::UNItestEstTriangulaireSuperieure()
{
	cout << "UNItestEstTriangulaireSuperieure()";
	// | 1 2 |
	// | 0 4 |
	CMatrice<int> MATm22(2, 2);
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 1) = 4;

	assertionVraie(MATm22.MATestTriangulaireSuperieure());
	assertionFausse(MATm22.MATestTriangulaireInferieure());

	// | 1 2 |
	// | 5 4 |
	MATm22(1, 0) = 5;

	assertionFausse(MATm22.MATestTriangulaireSuperieure());

	assertionVraie((CMatrice<int>(2, 2)).MATestTriangulaireSuperieure());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestEstTriangulaireInferieure()
{
	cout << "UNItestEstTriangulaireInferieure()";

	// | 1 0 |
	// | 3 4 |
	CMatrice<int> MATm22(2, 2);
	MATm22(0, 0) = 1;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionVraie(MATm22.MATestTriangulaireInferieure());
	assertionFausse(MATm22.MATestTriangulaireSuperieure());

	// | 1 5 |
	// | 3 4 |
	MATm22(0, 1) = 5;

	assertionFausse(MATm22.MATestTriangulaireInferieure());

	assertionVraie((CMatrice<int>(2, 2)).MATestTriangulaireInferieure());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestEstDiagonale()
{
	cout << "UNItestEstDiagonale()";

	CMatrice<int> MATm22(2, 2);
	assertionVraie(MATm22.MATestDiagonale());

	// | 1 0 |
	// | 0 4 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 4;

	assertionVraie(MATm22.MATestDiagonale());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;

	assertionFausse(MATm22.MATestDiagonale());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestEstInversible()
{
	cout << "UNItestEstInversible()";

	CMatrice<int> MATm22(2, 2);

	assertionFausse(MATm22.MATestInversible());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionVraie(MATm22.MATestInversible());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestEstSymetrique()
{
	cout << "UNItestEstSymetrique()";

	CMatrice<int> MATm22(2, 2);

	assertionVraie(MATm22.MATestSymetrique());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionFausse(MATm22.MATestSymetrique());

	// | 1 2 |
	// | 2 4 |
	MATm22(1, 0) = 2;

	assertionVraie(MATm22.MATestSymetrique());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestEstAntiSymetrique()
{
	cout << "UNItestEstAntiSymetrique()";

	CMatrice<int> MATm22(2, 2);

	assertionVraie(MATm22.MATestAntiSymetrique());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertionFausse(MATm22.MATestAntiSymetrique());

	// | 1  2 |
	// | -2 4 |
	MATm22(1, 0) = -2;

	assertionFausse(MATm22.MATestAntiSymetrique());

	// | 0  2 |
	// | -2 0 |
	MATm22(0, 0) = 0;
	MATm22(1, 1) = 0;

	assertionVraie(MATm22.MATestAntiSymetrique());

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestTestsMatriceCarree()
{
	UNItestEstTriangulaire();
	UNItestEstDiagonale();
	UNItestEstInversible();
	UNItestEstSymetrique();
	UNItestEstAntiSymetrique();
}

void CTestsUnitaires::UNItestDiag()
{
	cout << "UNItestDiag()";
	const int iTab[] = { 1, 2, 4 };

	CMatrice<int> MATm22 = CMatrice<int>::MATdiag(3, iTab);

	assertionEgalite(MATm22.MATdet(), 8);
	assertionEgalite(MATm22.MATtr(), 7);

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestExceptions()
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
	catch (Cexception EXCe) {
		cout << ".";
	}

	// Ne doit pas lever d'exception 
	try {
		MATm23 / 2;
		cout << ".";
	}
	catch (Cexception EXCe) {
		assertionExceptionNonSoulevee();
	}

	// operator ^

	// Doit lever une exception
	try
	{
		MATm33 ^ 0;
		assertionExceptionSoulevee();
	}
	catch (Cexception EXCe) {
		cout << ".";
	}

	// Ne doit pas lever d'exception 
	try {
		MATm33 ^ 2;
		cout << ".";
	}
	catch (Cexception EXCe) {
		assertionExceptionNonSoulevee();
	}

	cout << "OK" << endl;
}

void CTestsUnitaires::UNItestsCTableauAssociatif()
{
	cout << "UNItestsCTableauAssociatif()";
	CTableauAssociatif TABt;

	assertionEgalite(TABt.TABgetNbElements(), 0);

	double dReel = 5.2;
	int iEntier = 7;
	char * pcStr = "abc";
	// alocation dynamique car on va tester que le free ne modifie pas la valeur dans le tableau
	char * pcChaine = _strdup(pcStr);

	TABt.TABajouterReel("reel", dReel);
	TABt.TABajouterEntier("entier", iEntier);
	TABt.TABajouterChaine("chaine", _strdup(pcChaine));

	// Tests types
	assertionEgalite(TABt.TABgetNbElements(), 3);
	assertionEgalite(TABt.TABgetValeurType("reel"), TAB_TYPE_REEL);
	assertionEgalite(TABt.TABgetValeurType("entier"), TAB_TYPE_ENTIER);
	assertionEgalite(TABt.TABgetValeurType("chaine"), TAB_TYPE_CHAINE);

	// test indices
	assertionEgalite(TABt.TABgetIndiceCle("entier"), 1);
	assertionEgalite(TABt.TABgetIndiceCle("absent"), -1);

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

	assertionEgalite(TABt.TABgetValeurType("reel auto"), TAB_TYPE_REEL);
	assertionEgalite(TABt.TABgetValeurType("entier auto"), TAB_TYPE_ENTIER);
	assertionEgalite(TABt.TABgetValeurType("chaine auto"), TAB_TYPE_CHAINE);
	
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
