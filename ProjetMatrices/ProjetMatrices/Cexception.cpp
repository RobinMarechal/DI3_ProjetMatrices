#include "Cexception.h"

#include <string.h>
#include <stdlib.h>
#include "helpers.h"



/*****************************************
Constructeur par d�faut.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'initialisation de l'objet.
*****************************************/
Cexception::Cexception()
{
	uiEXCValeur = 0;
	pcEXCMessage = _strdup("Exception !");
}


/*****************************************
Constructeur de recopie.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'initialisation de l'objet par copie de l'objet en param�tre.
*****************************************/
Cexception::Cexception(Cexception &EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);
}


/*****************************************
Constructeur � un argument.
******************************************
Entr�e : un code d'erreur
N�cessite : rien.
Sortie : rien.
Entra�ne : l'initialisation de l'objet.
*****************************************/
Cexception::Cexception(const unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup("Exception !");
}



/*****************************************
Constructeur � deux arguments.
******************************************
Entr�e : un code d'erreur
Entr�e : un message d'erreur.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'initialisation de l'objet.
******************************************/
Cexception::Cexception(const unsigned int uiValeur, char * pcMessage)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup(pcMessage);
}


/*****************************************
Destructeur.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : Lib�ration de la m�moire allou�e pour pcEXCMessage.
******************************************/
Cexception::~Cexception()
{
	free(pcEXCMessage);
}


/*****************************************
Op�rateur =.
******************************************
Entr�e : instance de la classe Cexception � copier.
N�cessite : rien.
Sortie : l'objet recopi�.
Entra�ne : la recopie de l'objet en param�tre.
******************************************/
Cexception & Cexception::operator=(Cexception EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);

	return *this; 
}
