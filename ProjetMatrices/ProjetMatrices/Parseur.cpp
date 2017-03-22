#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

/***********************************************
	Constructeur par défaut.

************************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraine : initialisation de l'objet.

************************************************/

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

	unsigned int uiLigne,
				 uiColonne,
				 uiIndiceCaractere,
				 uiPARnombreLignes,
				 uiPARnombreColonnes;

	ifstream fichier(pcFichier);
    
	fichier.getline(pcType, 1024);
	fichier.getline(pcLignes, 1024);
	fichier.getline(pcColonnes, 1024);
	fichier >> pcDebutMatrice;

	// Récupérer le nombre de lignes.

	uiPARnombreLignes = atoi(strstr(pcLignes + 9, "\0"));
    
	// Récupérer le nombre de colonnes.

	uiPARnombreColonnes = atoi(strstr(pcColonnes + 11, "\0"));
    
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