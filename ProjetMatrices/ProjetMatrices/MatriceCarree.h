#ifndef CMATRICECARREE_H
#define CMATRICECARREE_H

#include "Matrice.h"

template <class T>
class CMatriceCarree : public CMatrice <T>
{
	public:

	// ----- Constructeurs et destructeurs ----------------------------------------
	CMatriceCarree();
	CMatriceCarree(CMatriceCarree<T> & MACmatrice);
	CMatriceCarree(unsigned int uiDimension);
	CMatriceCarree(unsigned int uiDimension, T ** ptTableau);
	~CMatriceCarree();

	// ----- Getters et Setters ---------------------------------------------------
	unsigned int MACgetDimension();
	void MACsetDimension(unsigned int uiDimension);

	// ----- Calculs --------------------------------------------------------------
	T MACdet();
	T MACtr();
	CMatrice <T> MACcommatrice();
	CMatrice <T> MACinverse();
	bool MACestTriangulaire();
	bool MACestTriangulaireSuperieure();
	bool MACestTriangulaireInferieure();
	bool MACestDiagonale();
	bool MACestInversible();
	bool MACestSymetrique();
	bool MACestAntiSymetrique();
};

#include "MatriceCarree.cpp"

#endif
