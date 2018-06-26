#include <iostream>
#include "BICGSTAB.h"
using namespace std;

int main()
{
	int krylovdemension = 100;
	int demension = 50;
	double tolerance = 0.01;

	BICGSTAB solver(krylovdemension, tolerance);

	

	Matrix A(demension);
	A.Random();
	Vector b(demension), x(demension),temp(demension);
	temp.Random();
	b = A * temp;

	cout<<solver.Solve(A,x,b)<<endl;

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
}