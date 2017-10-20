#ifndef __AUTOVALORES_H_
#define __AUTOVALORES_H_
#include <vector>
#include "macros.h"
#include <cmath>
#include "autovalores.h"
#include "Matriz.h"
#define NITER 100
using namespace std;

void MetodoPotencia(Matriz& B, Matriz& x0, int niter, Matriz& v, double& lambda);

void multiplicar(const Matriz& A, const Matriz& B, Matriz& C);

double bilineal(const Matriz& x, const Matriz& A, const Matriz& y);

double pi(const Matriz& x, const Matriz& y);

double norma(const Matriz& x);


#endif
