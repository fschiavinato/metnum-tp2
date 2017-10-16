#include <vector>
#include "macros.h"
#include "Matriz.h"
#include <cmath>
#include "autovalores.h"
#define NITER 100

using namespace std;


void MetodoPotencia(Matriz& B, Matriz& x0, int niter, Matriz& v, double& lambda) {
    Matriz vi(x0);
    v = x0;
    for(int i = 0; i < niter; i++) {
        v = B * v;
        v.escalar(1 / norma(v));
    }
    lambda = bilineal(v, B, v) / pi(v, v);
}


double bilineal(const Matriz& x, const Matriz& A, const Matriz& y) {
    return pi(y, A * y);
}

double pi(const Matriz& x, const Matriz& y) {
    double res = 0;
    for(int i = 0; i < x.Filas(); i++) {
        res += x.Get(i, 0) * y.Get(i, 0);
    }
    return res;
}

double norma(const Matriz& x) {
    return sqrt(pi(x,x));
}


int main() {
    Matriz x0(2, 1);
    x0.Set(1, 0, 0);
    Matriz v(2, 1);
    double lambda;
    Matriz A(2, 2); 
    A.Set(1, 0, 0);
    A.Set(2, 0, 1);
    A.Set(2, 1, 0);
    A.Set(1, 1, 1);

    MetodoPotencia(A, x0, 100, v, lambda);
    DEBUGMATRIZ(v);
    DEBUG(lambda);
}
