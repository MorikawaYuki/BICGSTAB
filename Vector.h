#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector
{
private:
	double *v;
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
	double &operator[](const int idx) const;
	double InnerProduct(const Vector &rhs) const;
	Vector operator-(const Vector &rhs) const;
	Vector operator+(const Vector &rhs) const;
	Vector operator*(const double &rhs) const;
	friend Vector operator*(const double &d, const Vector &v);
};

#endif