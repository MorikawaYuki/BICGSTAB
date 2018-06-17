#include "BICGSTAB.h"
#include <vector>
int BICGSTAB::Solve(const Matrix &A, Vector &x, const Vector &b)
{
    vector<Vector> v, p;
    vector<double> rho, omega;
    double alpha;

    Vector v0, p0;
    v0.Init(A.GetDemension());
    p0.Init(A.GetDemension());
    v.push_back(v0);
    p.push_back(p0);
    rho.push_back(0);
    omega.push_back(0);
    alpha = 0;

    Vector residual = b - A * x;
    Vector res_hat = residual;

    for (size_t i = 1; i < krylovdemension; i++)
    {
        rho.push_back(res_hat.InnerProduct(residual));
        double beta = (rho[i] / rho[i - 1]) * (alpha / omega[i - 1]);
        p.push_back(residual + beta * (p[i - 1] - omega[i - 1].InnerProduct(v[i - 1]));
        v.push_back(A*p[i]);
        alpha = rho[i]/res_hat.InnerProduct(v[i]);
        Vector s = residual  - alpha * v[i];
        Vector t = A * s;
        omega.push_back((t.InnerProduct(s))/(t.InnerProduct(t)));
        x = x+alpha*p[i]+mega[i]*s;
        residual = s-omega[i]*t;
        if(residual.Norm()/b.Norm()<tolerance)
        {
            cout << "error:" << residual.Norm() / b.Norm() << endl;
            return i;
        }
    }

    return -1;
}