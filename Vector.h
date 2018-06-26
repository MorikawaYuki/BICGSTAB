#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<complex>

class Vector
{
private:
	std::complex<double> *v;
	int size;

public:
	Vector(int size);
	Vector() { size = 0; v = nullptr; }
	Vector(const Vector &rhs);
	~Vector()
	{
		if (v != nullptr)
		{
			//delete[] v;
			v = nullptr;
		}
		size = 0;
	}

	void Random();
	double Norm() const;
	int Size() const;
	std::complex<double> &operator[](const int idx) const;
	std::complex<double> InnerProduct(const Vector &rhs) const;
	Vector operator-(const Vector &rhs) const;
	Vector operator+(const Vector &rhs) const;
	Vector operator*(const std::complex<double> & rhs) const;
	
	friend Vector operator*(const std::complex<double> &c, const Vector &v);
};

#endif