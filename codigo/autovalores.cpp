#include <vector>
#include "macros.h"
#include "Matriz.h"
#include <cmath>
#include "autovalores.h"
#define NITER 100

using namespace std;

void pca(Matriz& A, int alpha, Matriz& tc) {
    for(int i = 0; i < alpha; i++) {
        double autovalor;
        vector<double>& autovector(A.Columnas());
        MetodoPotencia(A, 
    }
}

void MetodoPotencia(Matriz& B, Matriz& x0, int niter, Matriz& v, double& lambda) {
    Matriz vi(x0);
    v = x0;
    for(int i = 0; i < niter; i++) {
        multiplicar(B, v, vi);
        v = vi;
        double normav = norma(v);
        for(int j = 0; j < v.size(); j++) {
            v[j] /= normav;
        }
    }
    lambda = bilineal(v, B, v) / pi(v, v);
}

void multiplicar(Matriz& A, Matriz& B, Matriz& C) {
    for(int i = 0; i < A.Filas(); i++) {
        for(int j = 0; j < B.Columnas(); j++) {
            for(int k = 0; k < A.Columnas(); k++) {
                C.set(C.get(i, j) + A.get(i, k) * B.get(k, i), i, j);
            }
        }
    }
}

double bilineal(Matriz& x, Matriz& A, Matriz& y) {
    Matriz& Ay(y.Filas());
    multiplicar(A, y, Ay);
    return pi(y, Ay);
}

double pi(const Matriz& x, const Matriz& y) {
    double res = 0;
    for(int i = 0; i < x.Filas(); i++) {
        res += x.get(i, 0) * y.get(i, 0);
    }
    return res;
}

double norma(Matriz& x) {
    double res = 0;
    for(int i = 0; i < x.Filas(); i++) {
        res += pow(x.get(i, 0), 2);
    }
    res = sqrt(res);
    return res;
}


int main() {
    vector<double> x0 = {0, 1};
    vector<double> v(2);
    double lambda;
    vector<vector<double> > A(2);
    A[0].resize(2); 
    A[1].resize(2); 
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 2;
    A[1][1] = 1;

    MetodoPotencia(A, x0, 100, v, lambda);
    DEBUGV(v);
    DEBUG(lambda);
}
