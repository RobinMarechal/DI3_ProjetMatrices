#ifndef CEXCEPTION_H

#define CEXCEPTION_H

#include <string.h>
#include <stdlib.h>

class Cexception
{
private:
	unsigned int uiEXCValeur;
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
	Entr�e : un code d'erreur (unsigned int).
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	*****************************************/

	Cexception(const unsigned int uiValeur);


	/*****************************************
	Constructeur � deux arguments.
	******************************************
	Entr�e : un code d'erreur (unsigned int),
			 un message d'erreur (char *).
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
	Entra�ne : la destruction de l'objet
			   ET la lib�ration de la m�moire r�serv�e pour pcEXCMessage.
	******************************************/

	~Cexception();


	/*****************************************
	Surcharge de l'op�rateur =.
	******************************************
	Entr�e : instance de la classe Cexception.
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
	Sortie : un code d'erreur (unsigned int).
	Entra�ne : rien.
	******************************************/

	unsigned int EXCgetValeur() const { return uiEXCValeur; }


	/*****************************************
	Accesseur pour pcEXCMessage.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un message d'erreur (char *).
	Entra�ne : rien.
	******************************************/

	char * EXCgetMessage() const { return pcEXCMessage; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entr�e : un code d'erreur (unsigned int).
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la modification de uiEXCValeur.
	******************************************/

	void EXCsetValeur(unsigned int uiValeur) { uiEXCValeur = uiValeur; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entr�e : un message d'erreur (char *).
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la modification de pcEXCMessage.
	******************************************/

	void EXCsetMessage(char * pcMessage) { free(pcEXCMessage); pcEXCMessage = _strdup(pcMessage); }
};

#endif