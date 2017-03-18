#ifndef CMATRICECARREE_H
#define CMATRICECARREE_H

#include "Matrice.h"

template <class T>
class CMatriceCarree : public CMatrice <T>
{
	public:

	// ----- Constructeurs et destructeurs----------------------------------------

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatriceCarree();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatriceCarree(CMatriceCarree<T> & MACmatrice);


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatriceCarree(unsigned int uiDimension);


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	~CMatriceCarree();

	// ----- Operateurs ---------------------------------------------------

	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatriceCarree<T> operator^(int iPuissance);

	// ----- Getters et Setters ---------------------------------------------------


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	unsigned int MACgetDimension();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	void MACsetDimension(unsigned int uiDimension);

	// ----- Calculs --------------------------------------------------------------


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	T MACdet();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	T MACtr();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatriceCarree <T> MACcommatrice();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	CMatriceCarree <T> MACinverse();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestTriangulaire();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestTriangulaireSuperieure();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestTriangulaireInferieure();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestDiagonale();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestInversible();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestSymetrique();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	bool MACestAntiSymetrique();


	/*****************************************
	Constructeur par defaut
	*****************************************
	Entree : void
	Necessite : rien
	Sortie : rien
	Entraine : Initialisation de l'objet
	*****************************************
	*/
	static CMatriceCarree<T> MACdiag(unsigned int uiDim, T * ptDiag);
};

#include "MatriceCarree.cpp"

#endif
