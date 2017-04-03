#include "helpers.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


/*****************************************
Retourne le type correspondant � la chaine en param�tre
******************************************
Entr�e : la chaine � analyser
N�cessite : rien
Sortie : l'entier correspondant au type de la chaine
Entra�ne : (0 = entier) || (1 = r�el) || (3 = chaine)
******************************************/
int analyserType(char * pcVal)
{
	int iEtat = 0;
	int iType = TAB_TYPE_CHAINE;
	bool bStop = false;
	while (!bStop)
	{
		char cChar = *pcVal;
		switch (iEtat)
		{
		case 0:
			if (cChar == '0') iEtat = 1;
			else if (cChar == '-') iEtat = 2;
			else if (cChar >= '1' && cChar <= '9') iEtat = 3;
			else if (cChar == '.') iEtat = 4; // car ".7" ==> 0.7 avec atof()
			else iEtat = -1;
			break;

		case 1:
			if (cChar == '.') iEtat = 4;
			else if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else { iType = TAB_TYPE_ENTIER; bStop = true; }
			break;

		case 2:
			if (cChar == '0') iEtat = 1;
			else if (cChar >= '1' && cChar <= '9') iEtat = 3;
			else iEtat = -1;
			break;

		case 3:
			if (cChar == '.') iEtat = 4;
			else if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else if (cChar >= '0' && cChar <= '9') iEtat = 3;
			else if (cChar == '\0') { iType = TAB_TYPE_ENTIER; bStop = true; }
			else { iType = TAB_TYPE_CHAINE; bStop = true; }
			break;

		case 4:
			if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else if (cChar == '\0') { iType = TAB_TYPE_ENTIER; bStop = true; } // Car "7." => 7 avec atof()
			else iEtat = -1;
			break;

		case 5:
			if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else { iType = TAB_TYPE_REEL; bStop = true; }
			break;

		case 6:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else if (cChar == '+' || cChar == '-') iEtat = 7;
			else iEtat = -1;
			break;

		case 7:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else iEtat = -1;
			break;

		case 8:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else { iType = TAB_TYPE_REEL; bStop = true; }
			break;

		case -1:
			iType = TAB_TYPE_CHAINE;
			bStop = true;
			break;
		}
		pcVal++;
	}

	return iType;
}


/*****************************************
Extraction d'une sous chaine
******************************************
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
Entr�e : un pointeur sur la fin de la sous-cha�ne.
N�cessite : pcStart >= pcEnd.
Sortie : la sous-cha�ne souhait�e (de type char *).
Entra�ne : Allocation dynamique d'un char * (malloc)
******************************************/
char * sousChaine(const char * pcStart, const char * pcEnd) {
	unsigned int uiBoucle = 0;
	char * pcStr = (char *)malloc(sizeof(char) * (size_t)(pcEnd - pcStart + 1));
	while (pcStart + uiBoucle != pcEnd && pcStart[uiBoucle] != '\0')
	{
		pcStr[uiBoucle] = pcStart[uiBoucle];
		uiBoucle++;
	}
	pcStr[uiBoucle] = '\0';

	return pcStr;
}


/*****************************************
transformation d'une chaine de carat�res en minuscule.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : Modification de la chaine point�e par pcStr
-> tous les caract�res sont en minuscule.
******************************************/
void transformerEnMinuscule(char * pcStr)
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < strlen(pcStr); uiBoucle++)
	{
		pcStr[uiBoucle] = tolower(pcStr[uiBoucle]);
	}
}


/*****************************************
Suppression des espaces en d�but et fin de chaine.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : Une copie de la chaine de caract�re sans les espaces de d�but et de fin.
Entra�ne : rien.
******************************************/
char * supprimerEspaces(char pcStr[])
{
	if (strlen(pcStr) == 0)
		return "";

	char pcResultat[1024] = { 0 };
	char * pcTmp = strchr(pcStr, '\0') - 1;
	// On suprime les espaces avant le d�but du mot
	while (isspace(*pcStr))
		pcStr++;

	// On supprime les espaces apr�s la fin du mot
	while (isspace(*pcTmp))
		pcTmp--;

	strncpy_s(pcResultat, 1024 , pcStr, pcTmp - pcStr + 1);

	return pcResultat;
}

