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
	Constructeur par d�faut.

************************************************
	Entr�e : rien.
	N�cessite : rien.
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

			// On g�re le cas ou le coefficient est un double � virgule.
			uiIndiceCaractere = 0;

			while (*pcStrMatrice == ' ' || *pcStrMatrice == '\t' || *pcStrMatrice == '\n' || *pcStrMatrice == '\0')
			{
				pcStrMatrice++;
			}

			// Si le nombre ressemble � ".3" ou ",3", on rajoute '0' devant pour qu'il ressemble a "0.3" ou "0,3"
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

			dValeur = atof(pcCoefficient);

			if (dValeur == 0.0 && pcCoefficient[0] != '.' && pcCoefficient[0] != '0')
			{
				// La conversion a echou�
				throw Cexception(0, "Erreur lors de la cr�ation de la matrice. V�rifiez les valeurs dans la balise 'Matrice' du fichier.");
			}

			MATmatrice(uiBoucleL, uiBoucleC) = dValeur;
		}
	}
}

CMatrice <double> CParseur::PARparserFichier(char * pcFichier)
{   
	// INITIALISATIONS ////////////////////////////////////////////////////////

	unsigned int uiBoucle;

	char ppcValeursBalises[NB_BALISES][1024] = {0};
	
	int pValeursNumeriques[NB_VALEURS_NUMERIQUES];

	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on r�cup�re la valeur sous forme de char * � traiter
	for (uiBoucle = 0; uiBoucle < NB_BALISES; uiBoucle++)
	{
		char * pcTmp,
			pcLines[1024] = { 0 };

		fichier.getline(pcLines, 1024);

		// VERIFICATION DE pcLines

		//

		pcTmp = strchr(pcLines, '=') + 1;

		// On avance jusqu'au prochain caract�re qui n'est pas un espace
		while(*pcTmp == ' ')
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

			// Tant qu'on a pas trouv� le ']' de fin de matrice,
			// ET qu'on est pas a la fin du fichier
			while (strchr(pcLines, ']') == NULL && !fichier.eof())
			{
				unsigned int uiNouvelleTaille = strlen(pcLines) + strlen(ppcValeursBalises[uiBoucle]) + 1;

				strcat_s(ppcValeursBalises[uiBoucle], uiNouvelleTaille, pcLines);
				strcat_s(ppcValeursBalises[uiBoucle], uiNouvelleTaille + 2, "\n");

				fichier.getline(pcLines, 1024);
			}
			// On retire le dernier \n
			ppcValeursBalises[uiBoucle][strlen(ppcValeursBalises[uiBoucle]) - 1] = '\0';
		}
		else
		{
			PARtoLowerString(pcTmp);
			strncpy_s(ppcValeursBalises[uiBoucle], pcTmp, strlen(pcTmp));
		}
	}

	// VERIFICATIONS ET CONVERSIONS ////////////////////////////////////////////////////////////

	if (strstr(ppcValeursBalises[0], "double") == NULL || strlen(ppcValeursBalises[0]) != strlen("double"))
	{
		// TypeMatrice ne vaut pas "double", peu importe la casse
		throw Cexception(0, "Format invalide : le type de la matrice est invalide.");
	}

	// Remplissage du tableau contentant des valeurs num�riques
	// NBLignes, NBColonnes
	for (uiBoucle = 0; uiBoucle < NB_VALEURS_NUMERIQUES; uiBoucle++)
	{
		pValeursNumeriques[uiBoucle] = atoi(ppcValeursBalises[uiBoucle + INDICE_PREMIERE_LIGNE_A_VALEUR_NUMERIQUE]);
		if (pValeursNumeriques[uiBoucle] <= 0)
		{
			throw Cexception(0, "Format invalide : dimensions de la matrice invalides (0 ou n�gatives).");
		}
	}

	// CREATION DE LA MATRICE ///////////////////////////////////////////////////////

	unsigned int uiNbLignes = pValeursNumeriques[VALEURS_NUMERIQUES_INDICE_NB_LIGNES];
	unsigned int uiNbColonnes = pValeursNumeriques[VALEURS_NUMERIQUES_INDICE_NB_COLONNES];
	CMatrice<double> MATmatrice(uiNbLignes, uiNbColonnes);

	PARremplirMatrice(MATmatrice, uiNbLignes, uiNbColonnes, ppcValeursBalises[VALEURS_BALISES_INDICE_MATRICE]);

	return MATmatrice;
}