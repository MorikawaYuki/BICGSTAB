#include "BICGSTAB.h"
#include <assert.h>
int BICGSTAB::Solve(const Matrix &A, Vector &x, const Vector &b)
{
    
    Vector residual = b - A * x;
}