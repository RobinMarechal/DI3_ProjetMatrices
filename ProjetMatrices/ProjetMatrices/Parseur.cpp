#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"

/***********************************************
	Constructeur par d�faut.

************************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entraine : initialisation de l'objet.

************************************************/

CParseur::CParseur() {}


/***********************************************
	Destructeur.

************************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entraine : rien.

************************************************/
CParseur::~CParseur() {}


/***********************************************
	Lecture d'un fichier.

************************************************
	Entr�e : le chemin du fichier.
	N�cessite : rien.
	Sortie : un objet CMatrice.
	Entraine : l'instanciation d'une matrice avec
			   les �lements lus dans le fichier.

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

	const char * pcBalises[] = {
		"TypeMatrice", 
		"NBLignes", 
		"NBColonnes", 
		"Matrice"
	};

	const char * pcValeursBalises[uiNbBalises] = {0};

	ifstream fichier(pcFichier);

	for (uiBoucle = 0; uiBoucle < uiNbBalises; uiBoucle++)
	{
		char * pcTmp,
			 * pcLines;

		fichier.getline(pcLines, 1024);

		pcTmp = strchr(pcLines, '=') + 1;

		while(*pcTmp == ' ')
		{
			if(*pcTmp== '\0')
				throw Cexception(0, "Format invalide");
			pcTmp++;
		}

	}
    
	
	fichier.getline(pcLignes, 1024);
	fichier.getline(pcColonnes, 1024);
	fichier >> pcDebutMatrice;

	// R�cup�rer le nombre de lignes.

	uiPARnombreLignes = atoi(strstr(strchr(pcLignes, '=') + 1, "\0"));
    
	// R�cup�rer le nombre de colonnes.

	uiPARnombreColonnes = atoi(strstr(strchr(pcColonnes, '=') + 1, "\0"));
    
    // Cr�ation de la matrice.

	CMatrice <double> MATmatrice(uiPARnombreLignes, uiPARnombreColonnes);
        
	for (uiLigne = 0; uiLigne < uiPARnombreLignes; uiLigne++)
    {
		for (uiColonne = 0; uiColonne < uiPARnombreColonnes; uiColonne++)
        {
			fichier >> pcCoefficient;

			// On g�re le cas ou le coefficient est un double � virgule.

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