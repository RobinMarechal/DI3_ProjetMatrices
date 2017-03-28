#include "Cexception.h"

#include <string.h>
#include <stdlib.h>


Cexception::Cexception()
{
	uiEXCValeur = 0;
	pcEXCMessage = _strdup("Exception !");
}


Cexception::Cexception(Cexception &EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);
}


Cexception::Cexception(const unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup("Exception !");
}


Cexception::Cexception(const unsigned int uiValeur, char * pcMessage)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup(pcMessage);
}


Cexception::~Cexception()
{
	free(pcEXCMessage);
}


Cexception & Cexception::operator=(Cexception EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);

	return *this; 
}
