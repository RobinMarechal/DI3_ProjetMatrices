#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "Matrice.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"


using namespace std;

/***********************************************
	Constructeur par défaut.

************************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraine : initialisation de l'objet.

************************************************/

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

		// Préparation du message d'erreur au cas où
		strcpy_s(pcMsg, "Erreur syntaxique a la ligne ");
		sprintf_s(strchr(pcMsg, '\0'), 3 , "%d", iLigne);
		strcpy_s(strchr(pcMsg, '\0'), strlen(" du fichier : ") + 1, " du fichier : ");
		strcpy_s(strchr(pcMsg, '\0'), strlen(pcFichier) + 1, pcFichier);

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
					// Il y a 2 '=' sur cette ligne.
					strcpy_s(strchr(pcMsg, '\0'), strlen(", deux '=' sur la meme ligne."), ", deux '=' sur la meme ligne.");
					throw Cexception(0, pcMsg);
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
				// On est après le '=' => valeur
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
			strcpy_s(strchr(pcMsg, '\0'), strlen("."), ".");
			throw Cexception(0, pcMsg);
		}

		// S'il y a un crochet fermant mais pas de crochet ouvrant, syntaxe invalide
		if (bCrochetFermant && !bCrochetOuvrant)
		{
			strcpy_s(strchr(pcMsg, '\0'), strlen("."), ".");
			throw Cexception(0, pcMsg);
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


	// Si les crochets sont ouvert mais jamais fermés, syntaxe invalide
	if (bCrochetOuvrant && !bCrochetFermant && !bSucces)
	{
		char pcMsg[1024] = { 0 };
		iLigne++;

		strcpy_s(pcMsg, strlen("Erreur syntaxique a la ligne "), "Erreur syntaxique a la ligne ");
		sprintf_s(strchr(pcMsg, '\0'), 3, "%d", iLigne);
		strcpy_s(strchr(pcMsg, '\0'), strlen(" du fichier "), " du fichier ");
		strcpy_s(strchr(pcMsg, '\0'), strlen(pcFichier), pcFichier);
		strcpy_s(strchr(pcMsg, '\0'), strlen(" : '[' trouve mais aucun ']' trouve plus loin."), " : '[' trouve mais aucun ']' trouve plus loin.");
		throw Cexception(0, pcMsg);
	}
}

void CParseur::PARremplirMatrice(CMatrice<double>& MATmatrice, char * pcStrMatrice)
{
	
}

CTableauAssociatif CParseur::PARparserFichier(char * pcFichier)
{   
	// INITIALISATIONS ////////////////////////////////////////////////////////
	
	CTableauAssociatif TABtab;

	// Souleve une exception si la syntaxe est incorrecte
	PARanalyseSyntaxique(pcFichier);

	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on récupère la valeur sous forme de char * à traiter
	while(!fichier.eof())
	{
		char * pcTmp,
			pcLines[1024] = { 0 };

		char pcBalise[1024] = { 0 }, pcValeur[1024] = { 0 };

		fichier.getline(pcLines, 1024);

		// VERIFICATION DE pcLines

		pcTmp = strchr(pcLines, '=');

		//pcBalise = chaine avant le = sans les espaces au debut et a la fin
		strcpy_s(pcBalise, 64, pcLines);
		pcBalise[strchr(pcBalise, '=') - pcBalise] = '\0';
		strcpy_s(pcBalise, 64, trim(pcBalise));

		// pcValeur = chaine après le = sans les espaces au debut et a la fin
		strcpy_s(pcValeur, 64, trim(strchr(pcLines, '=') + 1));

		//ppcValeursBalises[uiBoucle][0] = '\0';
		if (*pcValeur == '[')
		{
			fichier.getline(pcLines, 1024);

			// Tant qu'on n'est pas a la fin du fichier
			while (strchr(pcLines, ']') == NULL)
			{
				unsigned int uiNouvelleTaille = strlen(pcLines) + strlen(pcValeur) + 1;

				strcat_s(pcValeur, uiNouvelleTaille, pcLines);
				strcat_s(pcValeur, uiNouvelleTaille + 2, "\n");

				fichier.getline(pcLines, 1024);
			}
			// On retire le dernier \n
			pcValeur[strlen(pcValeur) - 1] = '\0';
			strcat_s(pcValeur, 2 + strlen(pcValeur), "]");
		}
		else
		{
			//strncpy_s(pcValeur, pcTmp, strlen(pcTmp));
		}

		TABtab.TABajouterAuto(pcBalise, pcValeur);
	}

	return TABtab;
}