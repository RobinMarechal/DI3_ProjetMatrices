#include <iostream>

using namespace std;

#include "Matrice.h"

void gregoire()
{
	
}

void robin()
{
	CMatrice<int> m(2, 2);
	m(0, 0) = 0;
	m(0, 1) = 1;
	m(1, 0) = 2;
	m(1, 1) = 3;

	m.MATafficher();
}


int main(int argc, char * argv[])
{
	robin();
	gregoire();

	return 0;
}