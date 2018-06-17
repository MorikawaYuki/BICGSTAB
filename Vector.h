#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector
{
  private:
	double *v;
	int size;

  public:
	void Init(int size);
	double InnerProduct(const Vector &rhs) const;
	Vector OuterProduct(const Vector &rhs) const;
	Vector operator-(const Vector &rhs) const;
	Vector operator+(const Vector &rhs) const;
	Vector operator*(const double &rhs) const;
	friend Vector operator*(const double &d, const Vector &v);
};

#endif