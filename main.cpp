#include <iostream>
#include <complex>
#include <vector>
#include <fstream>
#include <tbb/tbb.h>
#include "BICGSTAB.h"
using namespace std;
using namespace tbb;
int main()
{
	int krylovdemension = 1000;
	double tolerance = 0.01;

	BICGSTAB solver(krylovdemension, tolerance);

	ifstream in;
	in.open("F.txt");
	complex<double> temp;
	vector<complex<double>> ftemp;
	while (in >> temp)
	{
		ftemp.push_back(temp);
	}
	in.close();

	int num_unknow = ftemp.size();

	Matrix Z_mat(num_unknow);
	Vector Feed(num_unknow);
	for (size_t i = 0; i < ftemp.size(); i++)
		Feed[i] = ftemp[i];

	in.open("Z.txt");
	int offset = 0;
	while (in >> temp)
	{
		Z_mat[offset] = temp;
		offset++;
	}

	Vector I(num_unknow);

	tick_count t0 = tick_count::now();

	cout << solver.Solve(Z_mat, I, Feed) << endl;

	tick_count t1 = tick_count::now();
	printf("time for action = %g seconds\n", (t1 - t0).seconds());

	// Matrix A(demension);
	// A.Random();
	// Vector b(demension), x(demension),temp(demension);
	// temp.Random();
	// b = A * temp;

	// cout<<solver.Solve(A,x,b)<<endl;

	// for (int i = 0; i < 3; i++)
	// 	cout << x[i] << " ";
	// cout << endl;
	// for (int i = 0; i < 3; i++)
	// 	cout << temp[i] << " ";
	// cout << endl;

	// Vector b1 = A * x;

	// for (int i = 0; i < 3; i++)
	// 	cout << b1[i] << " ";
	// cout << endl;

	// for (int i = 0; i < 3; i++)
	// 	cout << b[i] << " ";
	// cout << endl;
}