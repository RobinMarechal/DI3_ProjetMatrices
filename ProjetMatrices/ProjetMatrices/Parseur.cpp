#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"

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

	char * pcValeursBalises[uiNbBalises] = {0};

	const unsigned int uiNbValeursNumeriques = 2;
	const unsigned int uiPremiereLigneAValeurNumerique = 1;
	
	int pValeursNumeriques[uiNbValeursNumeriques];



	ifstream fichier(pcFichier);

	// Pour chaque balise, on récupère la valeur sous forme de char * à traiter
	for (uiBoucle = 0; uiBoucle < uiNbBalises; uiBoucle++)
	{
		char * pcTmp,
			 * pcLines;

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
				throw Cexception(0, "Format invalide");
			}

			pcTmp++;
		}

		if (*pcTmp == '[')
		{
			pcBalises[uiBoucle] = "";
			// Tant qu'on a pas trouvé le ']' de fin de matrice,
			// ET qu'on est pas a la fin du fichier
			while (strchr(pcLines, ']') != NULL && !fichier.eof())
			{
				fichier.getline(pcLines, 1024);
				strcat(pcBalises[uiBoucle], pcLines);
			}

		}
		else
		{
			PARtoLowerString(pcTmp);
			pcValeursBalises[uiBoucle] = pcTmp;
		}

	}

	if (strstr(pcValeursBalises[0], "double") == NULL || strlen(pcValeursBalises[0]) != strlen("double"))
	{
		// TypeMatrice ne vaut pas "double", peu importe la casse
		throw Cexception(0, "Format invalide : le type de la matrice est invalide");
	}

	// 
	for (uiBoucle = 0; uiBoucle < uiNbValeursNumeriques; uiBoucle++)
	{
		pValeursNumeriques[uiBoucle] = atoi(pcValeursBalises[uiBoucle + uiPremiereLigneAValeurNumerique]);
		if (pValeursNumeriques[uiBoucle] <= 0)
		{
			throw Cexception(0, "Dimensions de la matrice invalides");
		}
	}

	//////////////////////////////////////////
    
	
	fichier.getline(pcLignes, 1024);
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

	return MATmatrice;
}