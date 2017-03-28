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
	Constructeur par défaut.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	*****************************************/

	Cexception();


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet par copie de l'objet en paramètre.
	*****************************************/

	Cexception(Cexception &EXCexception);


	/*****************************************
	Constructeur à un argument.
	******************************************
	Entrée : un code d'erreur (unsigned int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	*****************************************/

	Cexception(const unsigned int uiValeur);


	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : un code d'erreur (unsigned int),
			 un message d'erreur (char *).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	******************************************/

	Cexception(const unsigned int uivaleur, char * pcMessage);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la destruction de l'objet
			   ET la libération de la mémoire réservée pour pcEXCMessage.
	******************************************/

	~Cexception();


	/*****************************************
	Surcharge de l'opérateur =.
	******************************************
	Entrée : instance de la classe Cexception.
	Nécessite : rien.
	Sortie : l'objet recopié.
	Entraîne : la recopie de l'objet en paramètre.
	******************************************/

	Cexception & operator=(Cexception EXCexception);


	/*****************************************
	Accesseur pour uiEXCValeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un code d'erreur (unsigned int).
	Entraîne : rien.
	******************************************/

	unsigned int EXCgetValeur() const { return uiEXCValeur; }


	/*****************************************
	Accesseur pour pcEXCMessage.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un message d'erreur (char *).
	Entraîne : rien.
	******************************************/

	char * EXCgetMessage() const { return pcEXCMessage; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entrée : un code d'erreur (unsigned int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la modification de uiEXCValeur.
	******************************************/

	void EXCsetValeur(unsigned int uiValeur) { uiEXCValeur = uiValeur; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entrée : un message d'erreur (char *).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la modification de pcEXCMessage.
	******************************************/

	void EXCsetMessage(char * pcMessage) { free(pcEXCMessage); pcEXCMessage = _strdup(pcMessage); }
};

#endif