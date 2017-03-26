#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "Matrice.h"
#include "TableauAssociatif.h"


using namespace std;

#define NB_BALISES 4
#define NB_VALEURS_NUMERIQUES 2
#define INDICE_PREMIERE_LIGNE_A_VALEUR_NUMERIQUE 1
#define VALEURS_NUMERIQUES_INDICE_NB_LIGNES 0
#define VALEURS_NUMERIQUES_INDICE_NB_COLONNES 1
#define VALEURS_BALISES_INDICE_MATRICE 3

const char * CParseur::ppcBalises[4] = {
	"TypeMatrice",
	"NBLignes",
	"NBColonnes",
	"Matrice"
};

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
		strcpy(pcMsg, "Erreur syntaxique a la ligne ");
		sprintf(strchr(pcMsg, '\0'), "%d", iLigne);
		strcpy(strchr(pcMsg, '\0'), " du fichier : ");
		strcpy(strchr(pcMsg, '\0'), pcFichier);

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
					strcpy(strchr(pcMsg, '\0'), ", deux '=' sur la meme ligne.");
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
			strcpy(strchr(pcMsg, '\0'), ".");
			throw Cexception(0, pcMsg);
		}

		// S'il y a un crochet fermant mais pas de crochet ouvrant, syntaxe invalide
		if (bCrochetFermant && !bCrochetOuvrant)
		{
			strcpy(strchr(pcMsg, '\0'), ".");
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

		strcpy(pcMsg, "Erreur syntaxique a la ligne ");
		sprintf(strchr(pcMsg, '\0'), "%d", iLigne);
		strcpy(strchr(pcMsg, '\0'), " du fichier ");
		strcpy(strchr(pcMsg, '\0'), pcFichier);
		strcpy(strchr(pcMsg, '\0'), " : '[' trouve mais aucun ']' trouve plus loin.");
		throw Cexception(0, pcMsg);
	}
}

void CParseur::PARremplirMatrice(CMatrice<double>& MATmatrice, char * pcStrMatrice)
{
	unsigned int uiBoucleL, uiBoucleC, uiIndiceCaractere, uiTotalLignes = 0, uiNbValeur = 0;
	double dValeur;

	for (uiBoucleL = 0; uiBoucleL < MATmatrice.MATgetNbLignes(); uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < MATmatrice.MATgetNbColonnes(); uiBoucleC++)
		{
			char pcCoefficient[64] = { 0 };

			// Si ce n'est pas censé être la dernière valeur de la ligne...
			//if (uiBoucleC < MATmatrice.MATgetNbColonnes() - 1)
			//{
				//char * pcTmp = pcStrMatrice;
				// On avance jusqu'au premier caractère après la valeur
				//while (*pcTmp != ' ' && *pcTmp != '\t')
				//{
				//	pcTmp++;
				//}

				// ...mais qu'il n'y en a pas d'autre après...
				//do
				//{
				//	// ...alors le format est invalide
				//	if (*pcTmp == '\n')
				//	{
				//		throw Cexception(0, "Format invalide : Au moins une ligne contient moins de valeurs que prevu.");
				//	}
				//	pcTmp++;
				//} while (*pcTmp == ' ' || *pcTmp == '\t');
			//}

			// On gère le cas ou le coefficient est un double à virgule.
			uiIndiceCaractere = 0;

			while (isspace(*pcStrMatrice) || *pcStrMatrice == '\n' || *pcStrMatrice == '\0')
			{
				// Si on trouve '\n' ici alors qu'on a pas passé la dernière colonnes
				if((*pcStrMatrice == '\n' || *pcStrMatrice == '\0') && uiBoucleC > 0)
					throw Cexception(0, "Format invalide : Au moins une ligne contient moins de valeurs que prevu.");
				pcStrMatrice++;
			}

			pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;

			while (*pcStrMatrice != '\0' && !isspace(*pcStrMatrice) && *pcStrMatrice != '\n')
			{
				pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;
				// On remplace les potentielles ',' par '.'
				if (pcCoefficient[uiIndiceCaractere] == ',')
				{
					pcCoefficient[uiIndiceCaractere] = '.';
				}

				pcStrMatrice++;
				uiIndiceCaractere++;
			}

			// Si le dernier caractère est un '.', on réduit la chaine d'un caractère
			if (pcCoefficient[strlen(pcCoefficient) - 1] == '.')
			{
				pcCoefficient[strlen(pcCoefficient) - 1] = '\0';
			}

			dValeur = atof(pcCoefficient);

			MATmatrice(uiBoucleL, uiBoucleC) = dValeur;
		}

		//  On vérifie qu'il ne reste rien après la dernière colonne.
		// Si c'est le cas, alors le format est invalide.

		if (*pcStrMatrice != '\n' && *pcStrMatrice != '\0')	
		{
			while (*pcStrMatrice != '\n' || *pcStrMatrice != '\0')
			{
				if (*pcStrMatrice != ' ' && *pcStrMatrice != '\t')
				{
					throw Cexception(0, "Format invalide : Une ligne de la matrice contient plus de valeurs que le nombre de colonnes spécifié.");
				}

				pcStrMatrice++;
			}
		}
	}
}

CMatrice <double> CParseur::PARparserFichier(char * pcFichier)
{   
	// INITIALISATIONS ////////////////////////////////////////////////////////

	unsigned int uiBoucle, uiTotalLignes = 0;
	
	CTableauAssociatif TABtab;

	// Souleve une exception si la syntaxe est incorrecte
	PARanalyseSyntaxique(pcFichier);

	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on récupère la valeur sous forme de char * à traiter
	for (uiBoucle = 0; uiBoucle < NB_BALISES && !fichier.eof(); uiBoucle++)
	{
		char * pcTmp,
			* pcFinBalise,
			pcLines[1024] = { 0 };

		char * pcBalise = NULL, *pcValeur = NULL;

		fichier.getline(pcLines, 1024);

		// VERIFICATION DE pcLines

		pcTmp = strchr(pcLines, '=');
		pcFinBalise = pcTmp;

		do {
			pcFinBalise--;
		} while (isspace(*pcFinBalise));
		pcFinBalise++;

		pcBalise = subString(pcLines, pcFinBalise);

		pcTmp++;

		// On avance jusqu'au prochain caractère qui n'est pas un espace
		while(isspace(*pcTmp))
		{
			pcTmp++;
		}

		//ppcValeursBalises[uiBoucle][0] = '\0';
		char pcValeurBalise[1024] = { 0 };
		if (*pcTmp == '[')
		{
			fichier.getline(pcLines, 1024);

			// Tant qu'on n'est pas a la fin du fichier
			while (strchr(pcLines, ']') == NULL)
			{
				uiTotalLignes++;

				unsigned int uiNouvelleTaille = strlen(pcLines) + strlen(pcValeurBalise) + 1;

				strcat_s(pcValeurBalise, uiNouvelleTaille, pcLines);
				strcat_s(pcValeurBalise, uiNouvelleTaille + 2, "\n");

				fichier.getline(pcLines, 1024);
			}
			// On retire le dernier \n
			pcValeurBalise[strlen(pcValeurBalise) - 1] = '\0';
		}
		else
		{
			strncpy_s(pcValeurBalise, pcTmp, strlen(pcTmp));
		}

		TABtab.TABajouterAuto(pcBalise, _strdup(pcValeurBalise));
	}


	if (strcmp(TABtab.TABgetValeurChaine("TypeMatrice"), "double") != 0)
	{
		throw Cexception(0, "Erreur : TypeMatrice != 'double'.");
	}

	CMatrice<double> MATmatrice(TABtab.TABgetValeurEntier("NBLignes"), TABtab.TABgetValeurEntier("NBColonnes"));

	PARremplirMatrice(MATmatrice, TABtab.TABgetValeurChaine("Matrice"));

	return MATmatrice;

	/*
	// Remplissage du tableau contentant des valeurs numériques
	// NBLignes, NBColonnes
	for (uiBoucle = 0; uiBoucle < NB_VALEURS_NUMERIQUES; uiBoucle++)
	{
		char * pcReste = nullptr;

		pValeursNumeriques[uiBoucle] = strtod(ppcValeursBalises[uiBoucle + INDICE_PREMIERE_LIGNE_A_VALEUR_NUMERIQUE], &pcReste);

		if (pValeursNumeriques[uiBoucle] <= 0 || strlen(pcReste) > 0)
		{
			throw Cexception(0, "Format invalide : dimensions de la matrice invalides.");
		}
	}

	// CREATION DE LA MATRICE ///////////////////////////////////////////////////////

	unsigned int uiNbLignes = pValeursNumeriques[VALEURS_NUMERIQUES_INDICE_NB_LIGNES];

	if (uiTotalLignes != uiNbLignes)
	{
		throw Cexception(0, "Format invalide : taille de la matrice.");
	}

	unsigned int uiNbColonnes = pValeursNumeriques[VALEURS_NUMERIQUES_INDICE_NB_COLONNES];
	CMatrice<double> MATmatrice(uiNbLignes, uiNbColonnes);

	PARremplirMatrice(MATmatrice, ppcValeursBalises[VALEURS_BALISES_INDICE_MATRICE]);

	return MATmatrice;
	*/
}


/*
CMatrice<double> CParseur::PARparserFichier(char * pcFichier)
{
	unsigned int uiBoucle;
	CTableauAssociatif TABtab;
	ifstream IFSfichier(pcFichier);
	bool bCrochet = false;
	char pcContenuCrochets[1024] = { 0 };
	char pcLigne[1024] = { 0 };
	char pcBalise[1024] = { 0 };
	char pcValeur[1024] = { 0 };
	char *pcTrimBalise, *pcTrimValeur;

	// Verification de la syntaxe, leve une exception si elle est incorrecte
	PARanalyseSyntaxique(pcFichier);

	// => la syntaxe est bonne

	while (!IFSfichier.eof())
	{
		IFSfichier.getline(pcLigne, 1024);

		if (bCrochet)
		{
			pcTrimValeur = NULL;
			strcat(pcContenuCrochets, pcLigne);
			strcat(pcContenuCrochets, "\n");
		}
		else
		{
			strcpy(pcValeur, strchr(pcLigne, '=') + 1);
			pcBalise[strchr(pcLigne, '=') - pcBalise] = '\0';

			pcTrimBalise = PARtrim(pcBalise);
			pcTrimValeur = PARtrim(pcValeur);

			TABtab.TABajouterAuto(pcTrimBalise, pcTrimValeur);
		}

		if (pcTrimValeur != NULL && *pcTrimValeur == '[')
		{
			bCrochet = true;
		}
		else if (pcTrimValeur != NULL && *pcTrimValeur == ']')
		{
			pcContenuCrochets[strlen(pcContenuCrochets) - 3] = '\0';
			TABtab.TABajouterAuto(pcTrimBalise, pcContenuCrochets);
			bCrochet = false;
			pcContenuCrochets[1024] = { 0 };

		}
	}

	cout << TABtab.TABgetValeurChaine("A") << endl;
	cout << TABtab.TABgetValeurEntier("B") << endl;
	cout << TABtab.TABgetValeurReel("C") << endl;
}
*/
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

char * trim(char * pcStr)
{
	while (isspace(*pcStr)) 
		pcStr++;

	char* pcFin = pcStr + strlen(pcStr);
	while (isspace(*--pcFin));
	*(pcFin + 1) = '\0';

	return pcStr;
}

void toLowerString(char * pcStr)
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < strlen(pcStr); uiBoucle++)
	{
		pcStr[uiBoucle] = tolower(pcStr[uiBoucle]);
	}
}
