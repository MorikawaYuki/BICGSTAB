#include "Matrix.h"
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <omp.h>

Matrix::Matrix(int demension)
{
	this->demension = demension;
	this->m = new std::complex<double>[demension * demension];
	for (int i = 0; i < demension * demension; i++)
		m[i] = 0;
}

void Matrix::Random()
{

	srand((unsigned)time(NULL));
	for (int i = 0; i < demension * demension; i++)
	{
		m[i] = rand() % 10;
	}
}

Vector Matrix::operator*(const Vector &rhs) const
{
	// assert(rhs.Size() == demension);
	Vector ret(rhs.Size());
	#pragma omp parallel for  num_threads(10)
	for (int i = 0; i < demension; i++)
	{
		for (int j = 0; j < demension; j++)
		{
			ret[i] += m[i * demension + j] * rhs[j];
		}
	}

	return ret;
}

std::complex<double> &Matrix::operator[](const int idx) const
{
	assert(idx >= 0 && idx < demension * demension);
	return m[idx];
}

int Matrix::GetDemension() const
{
	return demension;
}
