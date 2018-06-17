#ifndef _MATRIX_H
#define _MATRIX_H

#include "Vector.h"

class Matrix
{
  private:
    double *m;
    int demension;

  public:
    void Init(int demension);
    Vector operator*(const Vector &rhs) const;
};

#endif