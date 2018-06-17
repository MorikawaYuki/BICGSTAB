#ifndef _BICGSTAB_H_
#define _BICGSTAB_H_

#include "Matrix.h"
#include "Vector.h"

class BICGSTAB
{
  private:
	int krylovdemension;
	double tolerance;

  public:
	BICGSTAB(int krylovdemension, double tolerance);
	int Solve(const Matrix &A, Vector &x, const Vector &b);
};

#endif