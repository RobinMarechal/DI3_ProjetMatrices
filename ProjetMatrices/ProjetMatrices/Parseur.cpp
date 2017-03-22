#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"

#define INDICE_VALEURS_NUMERIQUES_NB_LIGNES 0
#define INDICE_VALEURS_NUMERIQUES_NB_COLONNES 1
#define INDICE_VALEURS_BALISES_MATRICE 3

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

			dValeur = atof(pcCoefficient);

			if (dValeur == 0.0 && pcCoefficient[0] != '.' && pcCoefficient[0] != '0')
			{
				// La conversion a echoué
				throw Cexception(0, "Erreur lors de la création de la matrice. Vérifiez les valeurs dans la balise 'Matrice' du fichier.");
			}

			MATmatrice(uiBoucleL, uiBoucleC) = dValeur;
		}
	}
}

CParseur::CParseur() {}


/***********************************************
	Destructeur.

************************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraine : rien.

************************************************/
CParseur::~CParseur() {}


/***********************************************
	Lecture d'un fichier.

************************************************
	Entrée : le chemin du fichier.
	Nécessite : rien.
	Sortie : un objet CMatrice.
	Entraine : l'instanciation d'une matrice avec
			   les élements lus dans le fichier.

************************************************/

CMatrice <double> CParseur::PARparserFichier(char * pcFichier)
{   
	// INITIALISATIONS ////////////////////////////////////////////////////////

	char pcType[1024],
         pcLignes[1024],
         pcColonnes[1024],
         pcDebutMatrice[1024],
		 pcCoefficient[1024];

	char pcBuffer[1024];

	unsigned int uiLigne,
				 uiColonne,
				 uiIndiceCaractere,
				 uiPARnombreLignes,
				 uiPARnombreColonnes;

	unsigned int uiBoucle;

	const unsigned int uiNbBalises = 4;

	char * pcBalises[] = {
		"TypeMatrice", 
		"NBLignes", 
		"NBColonnes", 
		"Matrice"
	};

	char ppcValeursBalises[uiNbBalises][1024] = {0};

	const unsigned int uiNbValeursNumeriques = 2;
	const unsigned int uiPremiereLigneAValeurNumerique = 1;
	
	int pValeursNumeriques[uiNbValeursNumeriques];

	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on récupère la valeur sous forme de char * à traiter
	for (uiBoucle = 0; uiBoucle < uiNbBalises; uiBoucle++)
	{
		char * pcTmp,
			pcLines[1024] = { 0 };

		fichier.getline(pcLines, 1024);

		// VERIFICATION DE pcLines

		//

		pcTmp = strchr(pcLines, '=') + 1;

		// On avance jusqu'au prochain caractère qui n'est pas un espace
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

			// Tant qu'on a pas trouvé le ']' de fin de matrice,
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
			strncpy(ppcValeursBalises[uiBoucle],pcTmp, strlen(pcTmp));
		}
	}

	// VERIFICATIONS ET CONVERSIONS ////////////////////////////////////////////////////////////

	if (strstr(ppcValeursBalises[0], "double") == NULL || strlen(ppcValeursBalises[0]) != strlen("double"))
	{
		// TypeMatrice ne vaut pas "double", peu importe la casse
		throw Cexception(0, "Format invalide : le type de la matrice est invalide.");
	}

	// 
	for (uiBoucle = 0; uiBoucle < uiNbValeursNumeriques; uiBoucle++)
	{
		pValeursNumeriques[uiBoucle] = atoi(ppcValeursBalises[uiBoucle + uiPremiereLigneAValeurNumerique]);
		if (pValeursNumeriques[uiBoucle] <= 0)
		{
			throw Cexception(0, "Format invalide : dimensions de la matrice invalides (0 ou négatives).");
		}
	}

	// CREATION DE LA MATRICE ///////////////////////////////////////////////////////

	unsigned int uiNbLignes = pValeursNumeriques[INDICE_VALEURS_NUMERIQUES_NB_LIGNES];
	unsigned int uiNbColonnes = pValeursNumeriques[INDICE_VALEURS_NUMERIQUES_NB_COLONNES];
	CMatrice<double> MATmatrice(uiNbLignes, uiNbColonnes);

	PARremplirMatrice(MATmatrice, uiNbLignes, uiNbColonnes, ppcValeursBalises[INDICE_VALEURS_BALISES_MATRICE]);

	return MATmatrice;

	//////////////////////////////////////////
    
	
	/*fichier.getline(pcLignes, 1024);
	fichier.getline(pcColonnes, 1024);
	fichier >> pcDebutMatrice;

	// Récupérer le nombre de lignes.

	uiPARnombreLignes = atoi(strstr(strchr(pcLignes, '=') + 1, "\0"));
    
	// Récupérer le nombre de colonnes.

	uiPARnombreColonnes = atoi(strstr(strchr(pcColonnes, '=') + 1, "\0"));
    
    // Création de la matrice.

	CMatrice <double> MATmatrice(uiPARnombreLignes, uiPARnombreColonnes);
        
	for (uiLigne = 0; uiLigne < uiPARnombreLignes; uiLigne++)
    {
		for (uiColonne = 0; uiColonne < uiPARnombreColonnes; uiColonne++)
        {
			fichier >> pcCoefficient;

			// On gère le cas ou le coefficient est un double à virgule.

			uiIndiceCaractere = 0;
            
			while(pcCoefficient[uiIndiceCaractere] != '\0')
            {                
				if (pcCoefficient[uiIndiceCaractere] == ',')
					pcCoefficient[uiIndiceCaractere] = '.';
                
                uiIndiceCaractere++;
            }

			MATmatrice.MATsetValeur(uiLigne, uiColonne, atof(pcCoefficient));
        }
    }

	return MATmatrice;*/
}