#include <iostream>

using namespace std;

#include "Matrice.h"
#include "Parseur.h"
#include <signal.h>

// pour desactiver les tests : #define NDEBUG
// #define NDEBUG

#ifndef NDEBUG

#include "TestCMatrice.h"

#endif

void handleSIGABRT(int iSignNb)
{
	cout << "TESTS ECHOUES !" << endl;
}


void gregoire()
{
	//CMatrice <double> m = CParseur::PARparserFichier("..\\JePasse\\fichier04.txt");
	//m.MATafficher();
}

void robin()
{
	CMatrice<int> m(2, 2);

	m(0, 0) = 1;
	m(0, 1) = 2;
	m(1, 0) = 3;
	m(1, 1) = 4;

	cout << m << endl;

	m.MATsetNbColonnes(3);

	cout << m << endl;

	// Passent :
	/*try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\JePasse\\fichier00.txt");
		cout << m << endl;
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\JePasse\\fichier01.txt");
		cout << m << endl;
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\JePasse\\fichier02.txt");
		cout << m << endl;
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\JePasse\\fichier03.txt");
		cout << m << endl;
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetMatrices\\JePasse\\fichier04.txt");
		cout << m << endl;
	}
	catch (Cexception e)
	{
		cout << e.EXCgetMessage() << endl;
	}*/

	// Passent pas :
	/*
	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier10.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier11.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier12.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier13.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier14.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier15.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier16.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier17.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier18.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	try {
		CMatrice <double> m = CParseur::PARparserFichier("C:\\Users\\Greg\\Documents\\GitHub\\DI3_ProjetMatrices\\JePassePas\\fichier112.txt");
		cout << m << endl;
	}
	catch (Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}
	*/

#ifndef NDEBUG

	// Permet d'éviter les messages de crash en cas d'appel a la fonction abort() par assert.h
	_set_abort_behavior(0, _WRITE_ABORT_MSG);
	// Récupère le signal SIGABRT envoyé par la fonction abort() et fait quelque chose... (un cout en l'occurrence)
	signal(SIGABRT, &handleSIGABRT);

	// Lancement des tests unitaires
	CTestCMatrice::TMAstart();

#endif
}


int main(int argc, char * argv[])
{
	robin();
	//gregoire();

	return 0;
}