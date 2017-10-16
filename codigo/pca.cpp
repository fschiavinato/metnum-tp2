#include "Matriz.h"
#include <vector>
#define alpha 10
using namespace std;

void pca(vector<Matriz> imgs) {
    const int m = imgs[0].Filas();
    const int n = imgs.size();
    Matriz X(n, m);
    Matriz mu(m, 1);
    for(int i = 0; i < n; i++) {
        mu.add(imgs[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            X[i][j] = (imgs[i].get(j, 1) - mu.get(j, 1)) / sqrt(n - 1);
        }
    }
    Matriz tc(alpha, m);
    reducir(X, alpha, tc);

}

void reducir(Matriz& A, int alpha, Matriz& tc) {
    for(int i = 0; i < alpha; i++) {
        double autovalor;
        Matriz& autovector(A.Columnas(), 1);
        Matriz& x0(A.Columnas(), 1);
        x0.Set(1, 0, 0);
        MetodoPotencia(A, x0, NITER, autovector, autovalor);
        for(int j = 0; j < autovector.Filas(); j++) {
            tc.Set(autovector.Get(j, 0), i, j);
        }
        A.sub(autovalor * autovector * autovector.transpuesta());
    }
}
