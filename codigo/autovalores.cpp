#include <vector>
#include "macros.h"
#include "Matriz.h"
#include <cmath>
#include "autovalores.h"

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
    return (x.transpose() * y).Get(1,1);
}

double norma(const Matriz& x) {
    return sqrt(pi(x,x));
}
