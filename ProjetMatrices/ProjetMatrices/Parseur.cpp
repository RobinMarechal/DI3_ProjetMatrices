#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"


using namespace std;


/*****************************************
Analyseur syntaxique.
******************************************
Entr�e : le chemin du fichier.
N�cessite : rien.
Sortie : rien.
Entra�ne : soul�ve une Cexception en cas d'erreur de syntaxe dans le fichier
******************************************/
void CParseur::PARanalyseSyntaxique(char * pcFichier)
{
	bool bBalise = false,
		bValeur = false,
		bEgal = false,
		bCrochetOuvrant = false,
		bCrochetFermant = false,
		bSucces = false;

	int iLigne = 0;

	ifstream IFSfichier(pcFichier);

	// pour chaque ligne...
	while (!IFSfichier.eof())
	{
		char pcLigne[256] = { 0 };
		char pcMsg[1024] = { 0 };
		unsigned int uiBoucle = 0;
		iLigne++;
		IFSfichier.getline(pcLigne, 256);

		// Pr�paration du message d'erreur au cas o�
		sprintf(pcMsg, "Erreur syntaxique � la ligne %d du fichier : \n%s", iLigne, pcFichier);

		// ...on analyse chaque caractere
		while (pcLigne[uiBoucle] != '\n' && pcLigne[uiBoucle] != '\0')
		{
			char cChar = pcLigne[uiBoucle];

			// Les espaces/tabulations ne nous interessent pas
			if (cChar == ' ' || cChar == '\t')
			{
				uiBoucle++;
				continue;
			}


			if (cChar == '[')
				bCrochetOuvrant = true;
			else if (cChar == ']')
				bCrochetFermant = true;

			if (cChar == '=')
			{
				if (bEgal)
				{
					// Il y a 2 '=' ou plus sur cette ligne.
					strcat(pcMsg, "\n --> Deux '=' ou plus sur la m�me ligne.");
					throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
				}
				bEgal = true;
			}
			else if (!bEgal)
			{
				// On est avant le '=' => balise
				bBalise = true;
			}
			else
			{
				// On est apr�s le '=' => valeur
				bValeur = true;
			}

			// Ce qu'il y a a l'interieur des crochets ne nous interesse pas
			if (bCrochetOuvrant && !bCrochetFermant)
			{
				uiBoucle++;
				continue;
			}

			uiBoucle++;
		}

		// Si la syntaxe n'est pas [BALISE]=[VALEUR], syntaxe invalide
		if (!bBalise || !bEgal || !bValeur)
		{
			strcat(pcMsg, ".");
			throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
		}

		// S'il y a un crochet fermant mais pas de crochet ouvrant, syntaxe invalide
		if (bCrochetFermant && !bCrochetOuvrant)
		{
			strcat(pcMsg, ".");
			throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
		}

		// Si il n'y a pas de crochet, ou qu'il y a un ouvrant et un fermant, c'est bon
		if((bCrochetFermant && bCrochetOuvrant) || (!bCrochetOuvrant && !bCrochetFermant))
		{
			bBalise = false;
			bValeur = false;
			bEgal = false;
			bCrochetOuvrant = false;
			bCrochetFermant = false;
			bSucces = true;
		}
	}

	// S'il y a un crochet fermant mais pas de crochet ouvrant, syntaxe invalide
	if (!bCrochetFermant && bCrochetOuvrant)
	{
		char pcMsg[1024] = { 0 };
		sprintf(pcMsg, "Ereur syntaxique dans le fichier :\n%s\n-->Un crochet fermant semble manquer.", pcFichier);
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
	}

	// Si les crochets sont ouvert mais jamais ferm�s, syntaxe invalide
	if (bCrochetOuvrant && !bCrochetFermant && !bSucces)
	{
		char pcMsg[1024] = { 0 };
		iLigne++;

		sprintf(pcMsg, "Erreur syntaxique � la ligne %d du fichier :\n%s\n-->'[' trouv� mais aucun ']' trouv� plus loin.", iLigne, pcFichier);
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
	}
}



/*****************************************
Parse un fichier.
******************************************
Entr�e : le chemin du fichier � parser.
N�cessite : rien.
Sortie : une instance de CTableauAssociatif contenant les donn�es du fichier.
Entra�ne : soul�ve une Cexception en cas d'erreur de syntaxe dans le fichier
******************************************/
CTableauAssociatif CParseur::PARparserFichier(char * pcFichier)
{   
	// INITIALISATIONS ////////////////////////////////////////////////////////
	
	CTableauAssociatif TABtab;

	// Souleve une exception si la syntaxe est incorrecte
	PARanalyseSyntaxique(pcFichier);

	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on r�cup�re la valeur sous forme de char * � traiter
	while(!fichier.eof())
	{
		char * pcTmp,
			pcLigne[1024] = { 0 };

		char pcBalise[1024] = { 0 }, pcValeur[1024] = { 0 };

		fichier.getline(pcLigne, 1024);

		// VERIFICATION DE pcLigne

		pcTmp = strchr(pcLigne, '=');

		//pcBalise = chaine avant le = sans les espaces au debut et a la fin
		strcpy_s(pcBalise, 128, pcLigne);
		pcBalise[strchr(pcBalise, '=') - pcBalise] = '\0';
		strcpy_s(pcBalise, 128, trim(pcBalise));

		// pcValeur = chaine apr�s le = sans les espaces au debut et a la fin
		strcpy_s(pcValeur, 128, trim(strchr(pcLigne, '=') + 1));

		toLowerString(pcValeur);

		//ppcValeursBalises[uiBoucle][0] = '\0';
		if (*pcValeur == '[')
		{
			fichier.getline(pcLigne, 1024);

			// Tant qu'on n'est pas a la fin du fichier
			while (strchr(pcLigne, ']') == NULL)
			{
				unsigned int uiNouvelleTaille = strlen(pcLigne) + strlen(pcValeur) + 1;

				strcat_s(pcValeur, uiNouvelleTaille, pcLigne);
				strcat_s(pcValeur, uiNouvelleTaille + 2, "\n");

				fichier.getline(pcLigne, 1024);
			}

			// On retire le dernier \n
			pcValeur[strlen(pcValeur) - 1] = '\0';
		}

		TABtab.TABajouterAuto(pcBalise, pcValeur);
	}

	return TABtab;
}