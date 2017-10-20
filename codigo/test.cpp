#include "macros.h"
#include <cmath>
#include "autovalores.h"
#include "Matriz.h"
#include <vector>

void test_pca() {
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

void test_autovalores() {
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

int main() {
    // test_pca();
    // test_autovalores();
}