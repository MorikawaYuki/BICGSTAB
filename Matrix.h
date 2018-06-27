#ifndef _MATRIX_H
#define _MATRIX_H

#include "Vector.h"

class Matrix
{
private:
    std::complex<double> *m;
    int demension;

public:
	
	Matrix(int demension);
	void Random();
    Vector operator*(const Vector &rhs) const;
	std::complex<double> &operator[](const int idx) const;
    int GetDemension() const;
};

#endif