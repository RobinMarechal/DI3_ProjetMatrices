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
int getType(char * pcVal)
{
	int iEtat = 0;
	int iType = TAB_TYPE_CHAINE;
	while (iEtat != -1 && iType == TAB_TYPE_CHAINE)
	{
		char cChar = *pcVal;
		switch (iEtat)
		{
		case 0:
			if (cChar == '0') iEtat = 1;
			else if (cChar == '-') iEtat = 2;
			else if (cChar >= '1' && cChar <= '9') iEtat = 3;
			else if (cChar == '.') iEtat = 4; // car ".7" ==> 7 avec atof()
			else iEtat = -1;
			break;

		case 1:
			if (cChar == '.') iEtat = 4;
			else if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else iType = TAB_TYPE_ENTIER;
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
			else iType = TAB_TYPE_ENTIER;
			break;

		case 4:
			if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else if (cChar == '\0') iType = TAB_TYPE_ENTIER; // Car "7." => 7 avec atof()
			else iEtat = -1;
			break;

		case 5:
			if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else iType = TAB_TYPE_REEL;
			break;

		case 6:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else if (cChar == '+' || cChar == '-') iEtat = 7;
			else iType = -1;
			break;

		case 7:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else iType = -1;
			break;

		case 8:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else iType = TAB_TYPE_REEL;
			break;

		default:
			iType = TAB_TYPE_CHAINE;
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
N�cessite : 'end' >= 'start'.
Sortie : la sous-cha�ne souhait�e (de type char *).
Entra�ne : Allocation dynamique d'un char * (malloc)
******************************************/
char * subString(const char * start, const char * end) {
	int i = 0;
	char * str = (char *)malloc(sizeof(char) * (size_t)(end - start + 1));
	while (start + i != end && start[i] != '\0')
	{
		str[i] = start[i];
		i++;
	}
	str[i] = '\0';

	return str;
}


/*****************************************
transformation d'une chaine de carat�res en minuscule.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : la chaine est en minuscule.
******************************************/
void toLowerString(char * pcStr)
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
Sortie : une cha�ne de caract�res.
Entra�ne : la suppression des espaces au d�but et � la fin de la cha�ne.
******************************************/
char * trim(char pcStr[])
{
	// On suprime les espaces avant le d�but du mot
	while (isspace(*pcStr))
		pcStr++;

	char * pcTmp = strchr(pcStr, '\0') - 1;
	// On supprime les espaces apr�s la fin du mot
	while (isspace(*pcTmp))
		pcTmp--;

	pcTmp[1] = '\0';

	return pcStr;
}

