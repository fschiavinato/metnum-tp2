#include "macros.h"
#include <cmath>
#include "autovalores.h"
#include "pca.h"
#include "Matriz.h"
#include <vector>

void test_pca() {
    Matriz img1(2, 1);
    Matriz img2(2, 1); 
    img1.Set(1, 1, 1);
    img1.Set(2, 2, 1);
    img2.Set(2, 1, 1);
    img2.Set(1, 2, 1);
    vector<Matriz> imgs;
    imgs.push_back(img1);
    imgs.push_back(img2);
    int alpha = 1;
    Matriz tc(alpha, 2);

    pca(imgs, tc);

}

void test_autovalores() {
    Matriz x0(2, 1);
    x0.Set(1, 1, 1);
    Matriz v(2, 1);
    double lambda;
    Matriz A(2, 2); 
    A.Set(1, 1, 1);
    A.Set(2, 1, 2);
    A.Set(2, 2, 1);
    A.Set(1, 2, 2);

    MetodoPotencia(A, x0, 100, v, lambda);
    DEBUGMATRIZ(v);
    DEBUG(lambda);

}

int main() {
    test_pca();
    //test_autovalores();
}
