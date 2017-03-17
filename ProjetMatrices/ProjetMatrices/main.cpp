#include <iostream>

using namespace std;

#include "Matrice.h"

void gregoire()
{
	CMatrice <int> m(3, 2);
	CMatrice <int> n(3, 2);

	n = m + 3;

	cout << n(0, 0) << endl;
}

void robin()
{

}


int main(int argc, char * argv[])
{
	robin();
	gregoire();

	return 0;
}