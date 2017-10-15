#include "Matriz.h"
#include <vector>
using namespace std;

void pca(vector<Matriz> imgs) {
    const int m = imgs[0].filas();
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

}
