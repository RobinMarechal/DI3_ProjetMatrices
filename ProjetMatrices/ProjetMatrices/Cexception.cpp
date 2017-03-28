#include "Cexception.h"

#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#include "constantes.h"

/*****************************************
Constructeur par défaut
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
Cexception::Cexception()
{
	uiEXCValeur = 0;
	pcEXCMessage = _strdup("Exception !");
}


/***************************************
Constructeur de recopie
*****************************************
Entree : objet de la classe Cexception
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet en recopiant l'objet en param
*****************************************
*/
Cexception::Cexception(Cexception &EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);
}


/*****************************************
Constructeur a 1 argument
*****************************************
Entree : unsigned int : code d'erreur
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
Cexception::Cexception(const unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup("Exception !");
}


/****************************************
Constructeur a 2 arguments
*****************************************
Entree : unsigned int : code d'erreur
Entree : char * : message d'erreur
Necessite : rien
Sortie : rien
Entraine : Initialisation de l'objet
*****************************************
*/
Cexception::Cexception(const unsigned int uiValeur, char * pcMessage)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup(pcMessage);
}


/****************************************
Destructeur
*****************************************
Entree : void
Necessite : rien
Sortie : rien
Entraine : (Destruction de l'objet)
et (libération de la mémoire réservée pour pcEXCMessage)
*****************************************
*/
Cexception::~Cexception()
{
	free(pcEXCMessage);
}


/***************************************
Surcharge de l'opérateur =
****************************************
Entree : objet de la classe Cexception
Necessite : rien
Sortie : Objet recopié
Entraine : Recopie de l'objet en param
*****************************************
*/
Cexception & Cexception::operator=(Cexception EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);

	return *this; 
}
