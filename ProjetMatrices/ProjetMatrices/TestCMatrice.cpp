#include "TestCMatrice.h"
#include "Matrice.h"
#include "Cexception.h"
#include <assert.h>
#include <iostream>
#include "helpers.h"
#include "constantes.h"

using namespace std;

#define CUSTOM_ASSERT(expr) cout << "."; assert(expr);
#define assertTrue(expr) CUSTOM_ASSERT((expr) == true)
#define assertFalse(expr) CUSTOM_ASSERT((expr) == false)
#define assertEquals(param1, param2) CUSTOM_ASSERT((param1) == (param2))
#define assertNotEquals(param1, param2) CUSTOM_ASSERT((param1) != (param2))
#define assertNull(expr) CUSTOM_ASSERT((expr) == nullptr)
#define assertNotNull(expr) CUSTOM_ASSERT((expr) != nullptr)
#define assertExceptionHasBeenThrown() CUSTOM_ASSERT(true == false)
#define assertExceptionHasNotBeenThrown() CUSTOM_ASSERT(true == false)

void CTestCMatrice::TMAtestAccesseurs()
{
	cout << "TMAtestAccesseurs()";

	CMatrice<int> MATm1(2, 3);
	assertEquals(MATm1.MATgetNbLignes(), 2);
	assertEquals(MATm1.MATgetNbColonnes(), 3);

	assertEquals(MATm1(0, 0), 0);
	assertEquals(MATm1(0, 1), 0);
	assertEquals(MATm1(1, 0), 0);
	assertEquals(MATm1(1, 1), 0);

	// | 2  3  7 |
	// | 5  1  0 |
	MATm1(0, 0) = 2;
	MATm1(0, 1) = 3;
	MATm1(0, 2) = 7;
	MATm1.MATsetValeur(1, 0, 5);
	MATm1.MATgetValeur(1, 1) = 1;
	MATm1(1, 2) = 0;

	assertEquals(MATm1.MATgetValeur(0, 0), 2);
	assertEquals(MATm1.MATgetValeur(0, 1), 3);
	assertEquals(MATm1.MATgetValeur(1, 0), 5);
	assertEquals(MATm1.MATgetValeur(1, 1), 1);

	assertEquals(MATm1.MATgetLigne(0)[0], 2);
	assertEquals(MATm1.MATgetLigne(0)[1], 3);
	assertEquals(MATm1.MATgetLigne(0)[2], 7);
	assertEquals(MATm1.MATgetColonne(0)[0], 2);
	assertEquals(MATm1.MATgetColonne(1)[1], 1);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurPlus()
{
	cout << "TMAtestOperateurPlus()";
	CMatrice<int> MATm1(2, 2), MATm2(2, 2);

	assertEquals((MATm1 + MATm2)(0, 0), 0);
	assertEquals((MATm1 + MATm2)(1, 1), 0);

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

	assertEquals(MATm3(0, 0), 6);
	assertEquals(MATm3(0, 1), 8);
	assertEquals(MATm3(1, 0), 10);
	assertEquals(MATm3(1, 1), 12);

	assertEquals((MATm1 + 5)(0, 0), 6);
	assertEquals((MATm1 + 5)(0, 1), 7);
	assertEquals((MATm1 + 5)(1, 0), 8);
	assertEquals((MATm1 + 5)(1, 1), 9);

	// Commutativite
	assertEquals(MATm1 + 5, 5 + MATm1);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurMoins()
{
	cout << "TMAtestOperateurMoins()";
	CMatrice<int> MATm1(2, 2), MATm2(2, 2);

	assertEquals(MATm1 - MATm2, MATm1);

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

	assertEquals(MATm3(0, 0), -4);
	assertEquals(MATm3(0, 1), -4);
	assertEquals(MATm3(1, 0), -4);
	assertEquals(MATm3(1, 1), -5);

	assertEquals((MATm1 - 5)(0, 0), -4);
	assertEquals((MATm1 - 5)(0, 1), -3);
	assertEquals((MATm1 - 5)(1, 0), -2);
	assertEquals((MATm1 - 5)(1, 1), -1);

	assertEquals(5 - MATm1, MATm1 * (-1) + 5);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurEgal()
{
	cout << "TMAtestOperateurEgal()";

	CMatrice<int> MATm1(2, 2), MATm2(2, 2);

	// | 1  2 |
	// | 3  4 |
	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	MATm2 = MATm1;

	assertEquals(MATm1, MATm2);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateursComparaison()
{
	cout << "TMAtestOperateursComparaison()";

	CMatrice<int> MATm1(2, 2), MATm2(3, 3), MATm3(2, 2);

	assertTrue(MATm1 == MATm3);
	assertFalse(MATm1 != MATm3);
	assertFalse(MATm1 == MATm2);
	assertTrue(MATm1 != MATm2);

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

	assertFalse(MATm1 == MATm2);
	assertTrue(MATm1 != MATm2);

	// | 1  2 |
	// | 3  4 |
	MATm3(1, 1) = 4;

	assertTrue(MATm1 == MATm3);
	assertFalse(MATm1 != MATm3);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurProduit()
{
	cout << "TMAtestOperateurProduit()";

	CMatrice<int> MATid(2, 2), MATm1(2, 2), MATm2(2, 3), MATm3(3, 2);

	MATid(0, 0) = 1;
	MATid(0, 1) = 0;
	MATid(1, 0) = 0;
	MATid(1, 1) = 1;

	MATm1(0, 0) = 1;
	MATm1(0, 1) = 2;
	MATm1(1, 0) = 3;
	MATm1(1, 1) = 4;

	assertEquals((MATid * MATm1), MATm1);
	assertEquals((MATm1 * MATid), MATm1);


	assertEquals(5 * MATm1, MATm1 * 5);

	// | 1  2  3 |
	// | 4  5  6 |
	MATm2(0, 0) = 1;
	MATm2(0, 1) = 2;
	MATm2(0, 2) = 3;
	MATm2(1, 0) = 4;
	MATm2(1, 1) = 5;
	MATm2(1, 2) = 6;

	assertTrue((MATm2 * MATm3).MATestNulle());

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


	assertEquals(MATtest.MATgetNbLignes(), 2);
	assertEquals(MATtest.MATgetNbColonnes(), 2);

	assertEquals(MATtest, MATres);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurDiviser()
{
	cout << "TMAtestOperateurDiviser()";

	CMatrice<int> MATm(2, 2), MATm1(2, 2);

	MATm(0, 0) = 4;
	MATm(0, 1) = 4;
	MATm(1, 0) = 4;
	MATm(1, 1) = 4;

	MATm1(0, 0) = 1;
	MATm1(0, 1) = 1;
	MATm1(1, 0) = 1;
	MATm1(1, 1) = 1;

	assertEquals(MATm / 4, MATm1);
	assertTrue((MATm / 10).MATestNulle());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurPuissance()
{
	cout << "TMAtestOperateurPuissance()";

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

	assertEquals(MATnulle22 ^ 2, MATnulle22);
	assertEquals(MATm22 ^ 1, MATm22);
	assertEquals(MATm22 ^(-1), MATm22.MATinverse());
	assertEquals((MATm22 ^-1) ^ -1, MATm22);
	assertEquals((MATm22 ^ 2) ^ 3, MATm22 ^ 6);
	assertEquals(MATm22 ^ 2, MATm22 * MATm22);
	assertEquals(MATid22 ^ 3, MATid22);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestOperateurs()
{
	TMAtestOperateursComparaison();
	TMAtestOperateurEgal();
	TMAtestOperateurPlus();
	TMAtestOperateurMoins();
	TMAtestOperateurProduit();
	TMAtestOperateurDiviser();

	cout << "TMAtestOperateurs()";

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

	assertEquals(MATtest.MATgetNbLignes(), 2);
	assertEquals(MATtest.MATgetNbColonnes(), 2);

	// | 31  26 |
	// | 49  44 |
	MATres(0, 0) = 31;
	MATres(0, 1) = 26;
	MATres(1, 0) = 49;
	MATres(1, 1) = 44;

	assertEquals(MATtest, MATres);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculRang()
{
	cout << "TMAtestCalculRang()";

	CMatrice<int> MATm(2, 2), MATm2(2, 3);

	assertEquals(MATm.MATrang(), 0);

	// | 1  2 |
	// | 3  4 |
	MATm(0, 0) = 1;
	MATm(0, 1) = 2;
	MATm(1, 0) = 3;
	MATm(1, 1) = 4;
	assertEquals(MATm.MATrang(), 2);

	// | 1  2 |
	// | 3  6 |
	MATm(1, 1) = 6;

	assertEquals(MATm.MATrang(), 1);

	
	// | 1  2  3 |
	// | 4  5  6 |
	MATm2(0, 0) = 1;
	MATm2(0, 1) = 2;
	MATm2(0, 2) = 3;
	MATm2(1, 0) = 4;
	MATm2(1, 1) = 5;
	MATm2(1, 2) = 6;

	assertEquals(MATm2.MATrang(), 2);
	assertEquals(MATm2.MATtransposee().MATrang(), MATm2.MATrang());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculEchelonnee()
{
	cout << "TMAtestCalculEchelonnee()";

	CMatrice<double> MATm1(2, 2), MATm2(2, 2);

	assertEquals(MATm1, MATm1.MATechelonnee());

	// | 1  0 |
	// | 0  2 |
	MATm1(0, 0) = 1;
	MATm1(1, 1) = 2;

	assertEquals(MATm1, MATm1.MATechelonnee());

	// | 1  3 |
	// | 0  2 |
	MATm1(0, 1) = 3;

	assertEquals(MATm1, MATm1.MATechelonnee());

	// | 2  4 |
	// | 4  5 |
	MATm1(0, 0) = 2;
	MATm1(0, 1) = 4;
	MATm1(1, 0) = 4;
	MATm1(1, 1) = 5;

	// Tests independants de l'implementation des fonctions...
	assertNotEquals(MATm1.MATechelonnee()(0, 0), 0);
	assertNotEquals(MATm1.MATechelonnee()(0, 1), 0);
	assertEquals(MATm1.MATechelonnee()(1, 0), 0);
	assertNotEquals(MATm1.MATechelonnee()(1, 1), 0);

	MATm1(1, 1) = 8;

	assertNotEquals(MATm1.MATechelonnee()(0, 0), 0);
	assertNotEquals(MATm1.MATechelonnee()(0, 1), 0);
	assertEquals(MATm1.MATechelonnee()(1, 0), 0);
	assertEquals(MATm1.MATechelonnee()(1, 1), 0);
	
	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculTransposee()
{
	cout << "TMAtestCalculTransposee()";

	CMatrice<int> MATm22(2, 2), MATm23(2, 3), MATm32(3, 2);

	// | 1  0 |
	// | 0  1 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 1;

	assertEquals(MATm22.MATtransposee(), MATm22);

	// | 1  2 |
	// | 0  1 |
	MATm22(0, 1) = 2;

	assertEquals(MATm22.MATtransposee().MATtransposee(), MATm22);
	assertEquals(MATm22.MATtransposee()(1, 0), 2);

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

	assertEquals(MATm23.MATtransposee(), MATm32);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculSousMatrice()
{
	cout << "TMAtestCalculSousMatrice()";
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

	assertEquals(MATm22.MATsousMatrice(0, 0).MATgetNbLignes(), 1);
	assertEquals(MATm22.MATsousMatrice(0, 0).MATgetNbColonnes(), 2);
	assertEquals(MATm22.MATsousMatrice(1, 1), MATsousM11);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculDet()
{
	cout << "TMAtestCalculDet()";
	CMatrice<int> MATm22(2, 2);

	assertEquals(MATm22.MATdet(), 0);

	// | 1 0 |
	// | 0 4 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 4;

	assertEquals(MATm22.MATdet(), 4);

	// | 1 2 |
	// | 0 4 |
	MATm22(0, 1) = 2;

	assertEquals(MATm22.MATdet(), 4);

	// | 1 2 |
	// | 3 4 |
	MATm22(1, 0) = 3;
	
	assertEquals(MATm22.MATdet(), 1 * 4 - 2 * 3);

	CMatrice<int> MATm22_2 = MATm22 + 2;

	assertEquals((MATm22 * MATm22_2).MATdet(), MATm22.MATdet() * MATm22_2.MATdet());
	assertEquals((MATm22 * 3).MATdet(), MATm22.MATdet() * (3 * 3));
	assertNotEquals((MATm22 + MATm22_2).MATdet(), MATm22.MATdet() + MATm22_2.MATdet());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculInverse()
{
	cout << "TMAtestCalculInverse()";
	// Le cas du déterminant nul est testé dans TMAtestExceptions()

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

	assertEquals(MATm22.MATinverse(), MATm22);

	// 1 0
	// 0 4
	MATm22(1, 1) = 4;

	assertEquals(MATm22.MATinverse(), MATinv22);

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

	assertEquals(MATm22.MATinverse().MATinverse(), MATm22);
	assertEquals(MATm22.MATinverse(), MATinv22);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculCommatrice()
{
	cout << "TMAtestCalculCommatrice()";
	CMatrice<int> MATm22(2, 2);
	CMatrice<int> MATcomm22(2, 2);

	assertEquals(MATm22.MATcommatrice(), MATm22);

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

	assertEquals(MATm22.MATcommatrice(), MATcomm22);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculTrace()
{
	cout << "TMAtestCalculTrace()";

	CMatrice<int> MATm22(2, 2);

	assertEquals(MATm22.MATtr(), 0);

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertEquals(MATm22.MATtr(), 5);
	assertEquals(MATm22.MATtransposee().MATtr(), MATm22.MATtr());

	CMatrice<int> MATm22_2 = MATm22 * 2 - 1;

	assertEquals((MATm22 + MATm22_2).MATtr(), MATm22.MATtr() + MATm22_2.MATtr());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculs()
{
	TMAtestCalculSousMatrice();
	TMAtestCalculEchelonnee();
	TMAtestCalculTransposee();
	TMAtestCalculRang();

	// Matrices carrees
	TMAtestCalculDet();
	TMAtestCalculInverse();
	TMAtestCalculCommatrice();
	TMAtestCalculTrace();
}

void CTestCMatrice::TMAtestEstNulle()
{
	cout << "TMAtestEstNulle()";

	CMatrice<int> MATm(2, 2);
	MATm(0, 0) = 0;
	MATm(0, 1) = 0;
	MATm(1, 0) = 0;
	MATm(1, 1) = 0;

	assertTrue(MATm.MATestNulle())

	MATm(0, 1) = 2;

	assertFalse(MATm.MATestNulle());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestEstTriangulaire()
{
	TMAtestEstTriangulaireSuperieure();
	TMAtestEstTriangulaireInferieure();
}

void CTestCMatrice::TMAtestEstTriangulaireSuperieure()
{
	cout << "TMAtestEstTriangulaireSuperieure()";
	// | 1 2 |
	// | 0 4 |
	CMatrice<int> MATm22(2, 2);
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 1) = 4;

	assertTrue(MATm22.MATestTriangulaireSuperieure());
	assertFalse(MATm22.MATestTriangulaireInferieure());

	// | 1 2 |
	// | 5 4 |
	MATm22(1, 0) = 5;

	assertFalse(MATm22.MATestTriangulaireSuperieure());

	assertTrue((CMatrice<int>(2, 2)).MATestTriangulaireSuperieure());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestEstTriangulaireInferieure()
{
	cout << "TMAtestEstTriangulaireInferieure()";

	// | 1 0 |
	// | 3 4 |
	CMatrice<int> MATm22(2, 2);
	MATm22(0, 0) = 1;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertTrue(MATm22.MATestTriangulaireInferieure());
	assertFalse(MATm22.MATestTriangulaireSuperieure());

	// | 1 5 |
	// | 3 4 |
	MATm22(0, 1) = 5;

	assertFalse(MATm22.MATestTriangulaireInferieure());

	assertTrue((CMatrice<int>(2, 2)).MATestTriangulaireInferieure());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestEstDiagonale()
{
	cout << "TMAtestEstDiagonale()";

	CMatrice<int> MATm22(2, 2);
	assertTrue(MATm22.MATestDiagonale());

	// | 1 0 |
	// | 0 4 |
	MATm22(0, 0) = 1;
	MATm22(1, 1) = 4;

	assertTrue(MATm22.MATestDiagonale());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;

	assertFalse(MATm22.MATestDiagonale());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestEstInversible()
{
	cout << "TMAtestEstInversible()";

	CMatrice<int> MATm22(2, 2);

	assertFalse(MATm22.MATestInversible());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertTrue(MATm22.MATestInversible());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestEstSymetrique()
{
	cout << "TMAtestEstSymetrique()";

	CMatrice<int> MATm22(2, 2);

	assertTrue(MATm22.MATestSymetrique());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertFalse(MATm22.MATestSymetrique());

	// | 1 2 |
	// | 2 4 |
	MATm22(1, 0) = 2;

	assertTrue(MATm22.MATestSymetrique());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestEstAntiSymetrique()
{
	cout << "TMAtestEstAntiSymetrique()";

	CMatrice<int> MATm22(2, 2);

	assertTrue(MATm22.MATestAntiSymetrique());

	// | 1 2 |
	// | 3 4 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(1, 0) = 3;
	MATm22(1, 1) = 4;

	assertFalse(MATm22.MATestAntiSymetrique());

	// | 1  2 |
	// | -2 4 |
	MATm22(1, 0) = -2;

	assertFalse(MATm22.MATestAntiSymetrique());

	// | 0  2 |
	// | -2 0 |
	MATm22(0, 0) = 0;
	MATm22(1, 1) = 0;

	assertTrue(MATm22.MATestAntiSymetrique());

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestTestsMatriceCarree()
{
	TMAtestEstTriangulaire();
	TMAtestEstDiagonale();
	TMAtestEstInversible();
	TMAtestEstSymetrique();
	TMAtestEstAntiSymetrique();
}

void CTestCMatrice::TMAtestDiag()
{
	cout << "TMAtestDiag()";
	const int iTab[] = { 1, 2, 4 };

	CMatrice<int> MATm22 = CMatrice<int>::MATdiag(3, iTab);

	assertEquals(MATm22.MATdet(), 8);
	assertEquals(MATm22.MATtr(), 7);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestExceptions()
{
	cout << "TMAtestExceptions()";

	CMatrice<int> MATm23(2, 3);
	CMatrice<int> MATm33(3, 3);

	// operator/

	// Doit lever une exception
	try
	{
		MATm23 / 0;
		assertExceptionHasBeenThrown();
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
		assertExceptionHasNotBeenThrown();
	}

	// operator ^

	// Doit lever une exception
	try
	{
		MATm33 ^ 0;
		assertExceptionHasBeenThrown();
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
		assertExceptionHasNotBeenThrown();
	}

	cout << "OK" << endl;
}

void CTestCMatrice::TMAstart()
{
	cout << "------------------------------------------" << endl;
	cout << "DEBUT DES TESTS DE CMATRICE" << endl;
	cout << "------------------------------------------" << endl << endl;

	CTestCMatrice TMAtest;

	TMAtest.TMAtestEstNulle();
	TMAtest.TMAtestAccesseurs();
	TMAtest.TMAtestOperateurs();
	TMAtest.TMAtestExceptions();
	TMAtest.TMAtestTestsMatriceCarree();
	TMAtest.TMAtestDiag();
	TMAtest.TMAtestCalculs();
	TMAtest.TMAtestOperateurPuissance();

	cout << endl << "FIN DES TESTS DE CMATRICE" << endl;
	cout << "------------------------------------------" << endl;
}
