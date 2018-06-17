#include "Matrix.h"
#include <assert.h>
void Matrix::Init(int demension)
{
	this->demension = demension;
	this->m = new double[demension*demension];
	for (int i = 0; i < demension*demension; i++)
		m[i] = 0;
	
}

Vector Matrix::operator*(const Vector & rhs) const
{
	assert(rhs.Size() == demension);
	Vector ret(rhs.Size());
	int offset = 0;
	for (int i = 0; i < demension; i++)
	{
		for (int j = 0; j < demension; j++)
		{
			ret[i] += m[offset] * rhs[j];
			offset++;
		}
	}
	return ret;
}
