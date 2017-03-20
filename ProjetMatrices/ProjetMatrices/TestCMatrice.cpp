#include "TestCMatrice.h"
#include "Matrice.h"
#include "Cexception.h"

#define CUSTOM_ASSERT(expr) cout << "."; assert(expr);
#define assertTrue(expr) CUSTOM_ASSERT(expr == true)
#define assertFalse(expr) CUSTOM_ASSERT(expr == false)
#define assertEquals(param1, param2) CUSTOM_ASSERT(param1 == param2)
#define assertNotEquals(param1, param2) CUSTOM_ASSERT(param1 != param2)
#define assertNull(param) CUSTOM_ASSERT(param == nullptr)
#define assertNotNull(param) CUSTOM_ASSERT(param != nullptr)

CTestCMatrice::CTestCMatrice()
{
}


CTestCMatrice::~CTestCMatrice()
{
}

void CTestCMatrice::TMAtestAccesseurs()
{
}

void CTestCMatrice::TMAtestOperateurPlus()
{
}

void CTestCMatrice::TMAtestOperateurMoins()
{
}

void CTestCMatrice::TMAtestOperateurEgal()
{
}

void CTestCMatrice::TMAtestOperateursComparaison()
{
}

void CTestCMatrice::TMAtestOperateurProduit()
{
}

void CTestCMatrice::TMAtestOperateurDiviser()
{
}

void CTestCMatrice::TMAtestOperateurPuissance()
{
}

void CTestCMatrice::TMAtestOperateurs()
{
}

void CTestCMatrice::TMAtestCalculRang()
{
}

void CTestCMatrice::TMAtestCalculEchelonnee()
{
}

void CTestCMatrice::TMAtestCalculTransposee()
{
}

void CTestCMatrice::TMAtestCalculSousMatrice()
{
}

void CTestCMatrice::TMAtestCalculs()
{
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

	cout << endl;
}

void CTestCMatrice::TMAtestExceptions()
{
	cout << "TMAtestExceptions()";

	bool bException = false;

	CMatrice<int> MATm1(2, 3);
	CMatrice<int> MATm2(3, 3);
	CMatrice<int> MATm3(3, 2);

	// operator()

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

	try
	{
		MATm1 * MATm2;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);
	
	try
	{
		MATm1 * MATm3;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	// operator+

	try
	{
		MATm1 + MATm2;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	try
	{
		MATm1 + MATm1;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	// operator-

	try
	{
		MATm1 - MATm2;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	try
	{
		MATm1 - MATm1;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	// operator/

	try
	{
		MATm1 / 0;
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	try
	{
		MATm1 / 2;
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	// MATgetValeur

	try
	{
		MATm1.MATgetValeur(3, 3);
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	try
	{
		MATm1.MATgetValeur(2, 2);
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	// MATsetValeur

	try
	{
		MATm1.MATsetValeur(3, 3, 5);
	}
	catch (Cexception EXCe)
	{
		bException = true;
	}

	assertTrue(bException);

	try
	{
		MATm1.MATsetValeur(2, 2, 5);
	}
	catch (Cexception EXCe)
	{
		bException = false;
	}

	assertFalse(bException);

	bException = false;

	cout << endl;
}

void CTestCMatrice::TMAstart()
{
	CTestCMatrice TMAtest;

	TMAtest.TMAtestEstNulle();
	TMAtest.TMAtestAccesseurs();
	TMAtest.TMAtestOperateurs();
	TMAtest.TMAtestExceptions();
	TMAtest.TMAtestCalculs();
}
