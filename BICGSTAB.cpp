#include "BICGSTAB.h"
#include <vector>
#include <iostream>

using std::complex;
using std::vector;
int BICGSTAB::Solve(const Matrix &A, Vector &x, const Vector &b)
{
    int demension = b.Size();
    vector<Vector> v, p;
    vector<complex<double>> rho, omega;
    complex<double> alpha = 1;

    Vector v0(demension), p0(demension);
    v.push_back(v0);
    p.push_back(p0);
    rho.push_back(1);
    omega.push_back(1);

    Vector residual = b - A * x;
    Vector res_hat = residual;

    for (int i = 1; i < krylovdemension; i++)
    {
        rho.push_back(res_hat.InnerProduct(residual));
        complex<double> beta = (rho[i] / rho[i - 1]) * (alpha / omega[i - 1]);
        p.push_back(residual + beta * (p[i - 1] - omega[i - 1] * v[i - 1]));
        v.push_back(A * p[i]);
        alpha = rho[i] / res_hat.InnerProduct(v[i]);
        Vector s = residual - alpha * v[i];
        Vector t = A * s;
        omega.push_back((t.InnerProduct(s)) / (t.InnerProduct(t)));
        x = x + alpha * p[i] + omega[i] * s;
        residual = s - omega[i] * t;
        double error = residual.Norm() / b.Norm();
        if (i % 10 == 0)
            std::cout << i << " :" << error << std::endl;
        if (error < tolerance)
        {
            std::cout << "error:" << error << std::endl;
            return i;
        }
    }
    std::cout << "error:" << residual.Norm() / b.Norm() << std::endl;
    return -1;
}

BICGSTAB::BICGSTAB(int krylovdemension, double tolerance)
{
    this->krylovdemension = krylovdemension;
    this->tolerance = tolerance;
}