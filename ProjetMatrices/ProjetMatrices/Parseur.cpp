#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"

#define NB_BALISES 4
#define NB_VALEURS_NUMERIQUES 2
#define INDICE_PREMIERE_LIGNE_A_VALEUR_NUMERIQUE 1
#define VALEURS_NUMERIQUES_INDICE_NB_LIGNES 0
#define VALEURS_NUMERIQUES_INDICE_NB_COLONNES 1
#define VALEURS_BALISES_INDICE_MATRICE 3

const char * CParseur::pcBalises[4] = {
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

void CParseur::PARtoLowerString(char * pcStr)
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < strlen(pcStr); uiBoucle++)
	{
		pcStr[uiBoucle] = tolower(pcStr[uiBoucle]);
	}
}

void CParseur::PARremplirMatrice(CMatrice<double>& MATmatrice, unsigned int uiNbLignes, unsigned int uiNbColonnes, char * pcStrMatrice)
{
	unsigned int uiBoucleL, uiBoucleC, uiIndiceCaractere;
	double dValeur;

	for (uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			char pcCoefficient[64] = { 0 };

			// On gère le cas ou le coefficient est un double à virgule.
			uiIndiceCaractere = 0;

			while (*pcStrMatrice == ' ' || *pcStrMatrice == '\t' || *pcStrMatrice == '\n' || *pcStrMatrice == '\0')
			{
				pcStrMatrice++;
			}

			// Si le nombre ressemble à ".3" ou ",3", on rajoute '0' devant pour qu'il ressemble a "0.3" ou "0,3"
			//if (*pcStrMatrice == '.' || *pcStrMatrice == ',')
			//{
			//	pcCoefficient[uiIndiceCaractere] = '0';
			//	uiIndiceCaractere++;
			//}

			pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;

			while (*pcStrMatrice != '\0' && *pcStrMatrice != ' ' && *pcStrMatrice != '\t' && *pcStrMatrice != '\n')
			{
				pcCoefficient[uiIndiceCaractere] = *pcStrMatrice;
				if (pcCoefficient[uiIndiceCaractere] == ',')
				{
					pcCoefficient[uiIndiceCaractere] = '.';
				}

				pcStrMatrice++;
				uiIndiceCaractere++;
			}

			if (pcCoefficient[strlen(pcCoefficient) - 1] == '.')
			{
				pcCoefficient[strlen(pcCoefficient) - 1] = '\0';
			}

			dValeur = atof(pcCoefficient);

			if (dValeur == 0.0 && pcCoefficient[0] != '.' && pcCoefficient[0] != '0')
			{
				// La conversion a echoué
				throw Cexception(0, "Erreur lors de la création de la matrice. Vérifiez les valeurs dans la balise 'Matrice' du fichier.");
			}

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
					throw Cexception(0, "Format invalide : taille de la matrice.");
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

	char ppcValeursBalises[NB_BALISES][1024] = {0};
	
	int pValeursNumeriques[NB_VALEURS_NUMERIQUES];


	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on récupère la valeur sous forme de char * à traiter
	for (uiBoucle = 0; uiBoucle < NB_BALISES; uiBoucle++)
	{
		char * pcTmp,
			pcLines[1024] = { 0 };

		fichier.getline(pcLines, 1024);

		// VERIFICATION DE pcLines

		pcTmp = strchr(pcLines, '=');

		if (pcTmp == NULL)
		{
			throw Cexception(0, "Erreur de lecture du fichier, format invalide (un '=' semble manquer)");
		}

		// On compare le nom des balises.

		unsigned int uiTaille = strlen(pcBalises[uiBoucle]);

		unsigned int uiBoucle2, uiIndiceDepart = 0;

		// On saute tous les espaces qui se trouvent au début de la balise.

		while (pcLines[uiIndiceDepart] == ' ' || pcLines[uiIndiceDepart] == '\t')
		{
			uiIndiceDepart++;
		}

		for (uiBoucle2 = 0; uiBoucle2 < uiTaille; uiBoucle2++)
		{
			if (pcBalises[uiBoucle][uiBoucle2] != pcLines[uiBoucle2 + uiIndiceDepart])
			{
				throw Cexception(0, "Erreur de lecture du fichier, format invalide : vérifiez les balises.");
			}
		}

		// On saute tous les espaces qui se trouvent entre la fin de la balise et le symbole '='.

		while (pcLines[uiBoucle2 + uiIndiceDepart] == ' ' || pcLines[uiBoucle2 + uiIndiceDepart] == '\t')
		{
			uiBoucle2++;
		}

		if (pcLines[uiBoucle2 + uiIndiceDepart] != *pcTmp)
		{
			throw Cexception(0, "Erreur de lecture du fichier, format invalide : vérifiez les balises.");
		}

		pcTmp++;

		// On avance jusqu'au prochain caractère qui n'est pas un espace
		while(*pcTmp == ' ' || *pcTmp == '\t')
		{
			if (*pcTmp == '\0')
			{
				// la valeur de la balise est vide => format invalide
				throw Cexception(0, "Format invalide : au moins une des valeurs est vide.");
			}

			pcTmp++;
		}

		ppcValeursBalises[uiBoucle][0] = '\0';
		if (*pcTmp == '[')
		{
			fichier.getline(pcLines, 1024);

			// Tant qu'on n'est pas a la fin du fichier
			while (!fichier.eof())
			{
				uiTotalLignes++;

				unsigned int uiNouvelleTaille = strlen(pcLines) + strlen(ppcValeursBalises[uiBoucle]) + 1;

				strcat_s(ppcValeursBalises[uiBoucle], uiNouvelleTaille, pcLines);
				strcat_s(ppcValeursBalises[uiBoucle], uiNouvelleTaille + 2, "\n");

				fichier.getline(pcLines, 1024);
			}
			// On retire le dernier \n
			ppcValeursBalises[uiBoucle][strlen(ppcValeursBalises[uiBoucle]) - 1] = '\0';

			// Si on a pas trouvé le ']' de fin de matrice, on soulève une erreur.

			if (strchr(pcLines, ']') == nullptr)
			{
				throw Cexception(0, "Format invalide : borne de la matrice manquante.");
			}
		}
		else
		{
			PARtoLowerString(pcTmp);
			strncpy_s(ppcValeursBalises[uiBoucle], pcTmp, strlen(pcTmp));
		}
	}

	// VERIFICATIONS ET CONVERSIONS ////////////////////////////////////////////////////////////

	// On enlève les espaces de fin.

	while(ppcValeursBalises[0][strlen(ppcValeursBalises[0]) - 1] == ' '
		  || ppcValeursBalises[0][strlen(ppcValeursBalises[0]) - 1] == '\t')
	{
		ppcValeursBalises[0][strlen(ppcValeursBalises[0]) - 1] = '\0';
	}

	if (strstr(ppcValeursBalises[0], "double") == NULL || strlen(ppcValeursBalises[0]) != strlen("double"))
	{
		// TypeMatrice ne vaut pas "double", peu importe la casse
		throw Cexception(0, "Format invalide : le type de la matrice est invalide.");
	}

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

	PARremplirMatrice(MATmatrice, uiNbLignes, uiNbColonnes, ppcValeursBalises[VALEURS_BALISES_INDICE_MATRICE]);

	return MATmatrice;
}