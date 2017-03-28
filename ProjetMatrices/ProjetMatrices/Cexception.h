#ifndef CEXCEPTION_H

#define CEXCEPTION_H

#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#include "constantes.h"

class Cexception
{
private:
	unsigned int uiEXCValeur;
	char * pcEXCMessage;

public:
	/*****************************************
	Constructeur par défaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	Cexception();


	/***************************************
	Constructeur de recopie
	*****************************************
	Entree : objet de la classe Cexception
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet en recopiant l'objet en param
	*****************************************
	*/
	Cexception(Cexception &EXCexception);


	/***************************************
	Constructeur a 1 argument
	*****************************************
	Entree : unsigned int : code d'erreur
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	Cexception(const unsigned int uiValeur);


	/***************************************
	Constructeur a 2 arguments
	*****************************************
	Entree : unsigned int : code d'erreur
	Entree : char * : message d'erreur
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	Cexception(const unsigned int uivaleur, char * pcMessage);


	/***************************************
	Destructeur
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : (Destruction de l'objet)
	et (libération de la mémoire réservée pour pcEXCMessage)
	*****************************************
	*/
	~Cexception();


	/***************************************
	Surcharge de l'opérateur =
	****************************************
	Entree : objet de la classe Cexception
	Necessite : rien
	Sortie : Objet recopié
	Entraine : Recopie de l'objet en param
	*****************************************
	*/
	Cexception & operator=(Cexception EXCexception);


	/***************************************
	Accesseur pour uiEXCValeur
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : unsigned int : code d'erreur
	Entraine : rien
	*****************************************
	*/
	unsigned int EXCgetValeur() const { return uiEXCValeur; }


	/***************************************
	Accesseur pour pcEXCMessage
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : char * : message d'erreur
	Entraine : rien
	*****************************************
	*/
	char * EXCgetMessage() const { return pcEXCMessage; }


	/***************************************
	Mutateur pour pcEXCMessage
	*****************************************
	Entree : unsigned int : code d'erreur
	Necessite : rien
	Sortie : void
	Entraine : modification de uiEXCValeur
	*****************************************
	*/
	void EXCsetValeur(unsigned int uiValeur) { uiEXCValeur = uiValeur; }


	/***************************************
	Mutateur pour pcEXCMessage
	*****************************************
	Entree : char * : message d'erreur
	Necessite : rien
	Sortie : void
	Entraine : modification de pcEXCMessage
	*****************************************
	*/
	void EXCsetMessage(char * pcMessage) { free(pcEXCMessage); pcEXCMessage = _strdup(pcMessage); }
};

#endif