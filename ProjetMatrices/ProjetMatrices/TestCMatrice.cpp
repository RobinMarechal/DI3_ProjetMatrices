#include "TestCMatrice.h"
#include "Matrice.h"
#include "Cexception.h"
#include <assert.h>
#include <iostream>

using namespace std;

#define CUSTOM_ASSERT(expr) cout << "."; assert(expr);
#define assertTrue(expr) CUSTOM_ASSERT((expr) == true)
#define assertFalse(expr) CUSTOM_ASSERT((expr) == false)
#define assertEquals(param1, param2) CUSTOM_ASSERT((param1) == (param2))
#define assertNotEquals(param1, param2) CUSTOM_ASSERT((param1) != (param2))
#define assertNull(expr) CUSTOM_ASSERT((expr) == nullptr)
#define assertNotNull(expr) CUSTOM_ASSERT((expr) != nullptr)

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

	assertEquals((MATm1 - MATm2)(0, 0), 0);
	assertEquals((MATm1 - MATm2)(1, 1), 0);

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

	//assertEquals(5 - MATm1, MATm1 * (-1) + 5);

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
	CMatrice<int> MATm22(2, 3);

	// | 1  2  3 |
	// | 4  5  6 |
	MATm22(0, 0) = 1;
	MATm22(0, 1) = 2;
	MATm22(0, 2) = 3;
	MATm22(1, 0) = 4;
	MATm22(1, 1) = 5;
	MATm22(1, 2) = 6;

	assertEquals(MATm22.MATsousMatrice(0, 0).MATgetNbLignes(), 1);
	assertEquals(MATm22.MATsousMatrice(0, 0).MATgetNbColonnes(), 2);
	assertEquals(MATm22.MATsousMatrice(0, 0)(0, 0), 5);
	assertEquals(MATm22.MATsousMatrice(0, 0)(0, 1), 6);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAtestCalculs()
{
	//TMAtestCalculSousMatrice();
	TMAtestCalculEchelonnee();
	TMAtestCalculTransposee();
	TMAtestCalculRang();
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

void CTestCMatrice::TMAtestExceptions()
{
	cout << "TMAtestExceptions()";

	bool bException = false;

	CMatrice<int> MATm1(2, 3);
	CMatrice<int> MATm2(3, 3);
	CMatrice<int> MATm3(3, 2);

	// operator()

	// Doit lever une exception
	try {
		MATm1(3, 3);
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	try {
		MATm1(2, 1);
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	// operator*

	// Doit lever une exception
	try
	{
		MATm2 * MATm1;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	// Ne doit pas lever d'exception
	try
	{
		MATm1 * MATm2;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertTrue(bException);

	bException = false;

	// operator+

	// Doit lever une exception
	try
	{
		MATm1 + MATm2;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	//assertTrue(bException);

	// Ne doit pas lever d'exception
	try
	{
		MATm1 + MATm1;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	//assertTrue(bException);

	bException = false;

	// operator-

	// Doit lever une exception
	try
	{
		MATm1 - MATm2;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	//assertTrue(bException);

	// Ne doit pas lever d'exception
	try
	{
		MATm1 - MATm1;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	//assertTrue(bException);

	bException = false;

	// operator/

	// Doit lever une exception
	/*try
	{
		MATm1 / 0;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}*/

	//assertTrue(bException);

	// Ne doit pas lever d'exception

	bException = true;
	try
	{
		MATm1 / 2;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertTrue(bException);

	bException = false;

	// MATgetValeur

	// Doit lever une exception
	try
	{
		MATm1.MATgetValeur(3, 3);
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	// Ne doit pas lever d'exception
	try
	{
		MATm1.MATgetValeur(1, 2);
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertTrue(bException);

	bException = false;

	// MATsetValeur

	// Doit lever une exception
	try
	{
		MATm1.MATsetValeur(3, 3, 5);
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	// Ne doit pas lever d'exception
	try
	{
		MATm1.MATsetValeur(1, 2, 5);
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertTrue(bException);

	cout << "OK" << endl;
}

void CTestCMatrice::TMAstart()
{
	cout << "---------------------" << endl;
	cout << "DEBUT DES TESTS DE CMATRICE" << endl;
	cout << "---------------------" << endl << endl;

	CTestCMatrice TMAtest;

	TMAtest.TMAtestEstNulle();
	TMAtest.TMAtestAccesseurs();
	TMAtest.TMAtestOperateurs();
	TMAtest.TMAtestExceptions();
	TMAtest.TMAtestCalculs();

	cout << endl << "FIN DES TESTS DE CMATRICE" << endl;
	cout << "---------------------" << endl;
}
