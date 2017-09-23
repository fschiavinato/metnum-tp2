#include <vector>
#include "macros.h"
#include <cmath>
#include "autovalores.h"
using namespace std;

void MetodoPotencia(vector<vector<double>>& B, vector<double> x0, int niter, vector<double>& v, double& lambda) {
    vector<double> vi(v.size());
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

void multiplicar(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& C) {
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B[0].size(); j++) {
            for(int k = 0; k < B.size(); k++) {
                C[i][j] += A[i][k] * B[k][i];
            }
        }
    }
}

void multiplicar(vector<vector<double>>& A, vector<double>& x, vector<double>& b) {
    for(int i = 0; i < A.size(); i++) {
        for(int k = 0; k < x.size(); k++) {
            b[i] += A[i][k] * x[k];
        }
    }
}

double bilineal(vector<double>& x, vector<vector<double>>& A, vector<double>& y) {
    vector<double> Ay(y.size());
    multiplicar(A, y, Ay);
    return pi(y, Ay);
}

double pi(vector<double> x, vector<double> y) {
    double res = 0;
    for(int i = 0; i < x.size(); i++) {
        res += x[i] * y[i];
    }
    return res;
}

double norma(vector<double> x) {
    double res = 0;
    for(int i = 0; i < x.size(); i++) {
        res += pow(x[i], 2);
    }
    res = sqrt(res);
    return res;
}


int main() {
    vector<double> x0 = {0, 1};
    vector<double> v(2);
    double lambda;
    vector<vector<double>> A(2);
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
