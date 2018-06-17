#include <iostream>
#include "BICGSTAB.h"
using namespace std;

int main()
{
	int krylovdemension = 3;
	int demension = 3;
	double tolerance = 0.01;

	BICGSTAB solver(krylovdemension, tolerance);
	Matrix A(demension);
	A.Random();
	Vector b(demension), x(demension),temp(demension);
	temp.Random();
	b = A * temp;

	solver.Solve(A,x,b);

	for (int i = 0; i < 3; i++)
		cout << x[i] << " ";
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << temp[i] << " ";
	cout << endl;

	Vector b1 = A * x;

	for (int i = 0; i < 3; i++)
		cout << b1[i] << " ";
	cout << endl;

	for (int i = 0; i < 3; i++)
		cout << b[i] << " ";
	cout << endl;
	getchar();
}