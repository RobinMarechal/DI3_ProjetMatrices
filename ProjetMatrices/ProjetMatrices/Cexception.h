#ifndef CEXCEPTION_H

#define CEXCEPTION_H

#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#include "constantes.h"

/*************************************
Classe de gestion d'exceptions
**************************************
Permet de g�rer des exceptions soulev�es
dans le programme, avec un code d'erreur
et un message d'erreur particulier.
**************************************/
class Cexception
{
private:
	/**********************
	Code d'erreur
	***********************/
	unsigned int uiEXCValeur;

	/**********************
	Message d'erreur
	***********************/
	char * pcEXCMessage;

public:

	/*****************************************
	Constructeur par d�faut.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	*****************************************/
	Cexception();


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet par copie de l'objet en param�tre.
	*****************************************/
	Cexception(Cexception &EXCexception);


	/*****************************************
	Constructeur � un argument.
	******************************************
	Entr�e : un code d'erreur
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	*****************************************/
	Cexception(const unsigned int uiValeur);


	/*****************************************
	Constructeur � deux arguments.
	******************************************
	Entr�e : un code d'erreur
	Entr�e : un message d'erreur.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	******************************************/
	Cexception(const unsigned int uivaleur, char * pcMessage);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : Lib�ration de la m�moire allou�e pour pcEXCMessage.
	******************************************/
	~Cexception();


	/*****************************************
	Op�rateur =.
	******************************************
	Entr�e : instance de la classe Cexception � copier.
	N�cessite : rien.
	Sortie : l'objet recopi�.
	Entra�ne : la recopie de l'objet en param�tre.
	******************************************/
	Cexception & operator=(Cexception EXCexception);


	/*****************************************
	Accesseur pour uiEXCValeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le code d'erreur
	Entra�ne : rien.
	******************************************/
	unsigned int EXCgetValeur() const { return uiEXCValeur; }


	/*****************************************
	Accesseur pour pcEXCMessage.
	******************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : un message d'erreur
	Entra�ne : rien
	******************************************/
	char * EXCgetMessage() const { return pcEXCMessage; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entr�e : un code d'erreur
	N�cessite : rien
	Sortie : rien
	Entra�ne : la modification du code d'erreur
	******************************************/
	void EXCsetValeur(unsigned int uiValeur) { uiEXCValeur = uiValeur; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entr�e : un message d'erreur
	N�cessite : rien
	Sortie : rien
	Entra�ne : la modification du message d'erreur
	******************************************/
	void EXCsetMessage(char * pcMessage) { free(pcEXCMessage); pcEXCMessage = _strdup(pcMessage); }
};

#endif