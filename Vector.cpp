#include "Vector.h"
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
Vector::Vector(int size)
{
	this->size = size;
	this->v = new std::complex<double>[size];
	for (int i = 0; i < size; i++)
		v[i] = 0;
}

Vector::Vector(const Vector &rhs)
{
	this->size = rhs.size;
	this->v = new std::complex<double>[size];
	for (int i = 0; i < size; i++)
		v[i] = rhs[i];
}

void Vector::Random()
{

	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
		v[i] = rand() % 10;
}

double Vector::Norm() const
{
	double ret = 0;
	for (int i = 0; i < size; i++)
		ret += std::abs(v[i]) * std::abs(v[i]);
	ret = std::sqrt(ret);
	return ret;
}

int Vector::Size() const
{
	return int(size);
}


std::complex<double> &Vector::operator[](const int idx) const
{
	assert(idx >= 0 && idx < size);
	return v[idx];
}

std::complex<double> Vector::InnerProduct(const Vector &rhs) const
{
	assert(size == rhs.size);
	std::complex<double> ret = 0;
	for (int i = 0; i < size; i++)
		ret = ret + v[i] * rhs[i];

	return ret;
}

Vector Vector::operator-(const Vector &rhs) const
{
	Vector ret = *this;
	for (int i = 0; i < size; i++)
		ret[i] -= rhs[i];
	return ret;
}

Vector Vector::operator+(const Vector &rhs) const
{
	Vector ret = *this;
	for (int i = 0; i < size; i++)
		ret[i] += rhs[i];
	return ret;
}

Vector Vector::operator*(const std::complex<double> &rhs) const
{
	Vector ret = *this;
	for (int i = 0; i < size; i++)
		ret[i] *= rhs;
	return ret;
}

Vector operator*(const std::complex<double> &c, const Vector &v)
{
	Vector ret = v;
	for (int i = 0; i < v.Size(); i++)
		ret[i] *= c;
	return ret;
}
