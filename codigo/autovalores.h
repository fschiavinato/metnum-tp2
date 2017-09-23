#ifndef __AUTOVALORES_H_
#define __AUTOVALORES_H_
#include <vector>
#include "macros.h"
#include <cmath>
#include "autovalores.h"
using namespace std;

void MetodoPotencia(vector<vector<double>>& B, vector<double> x0, int niter, vector<double>& v, double& lambda);

void multiplicar(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& C);

void multiplicar(vector<vector<double>>& A, vector<double>& x, vector<double>& b);

double bilineal(vector<double>& x, vector<vector<double>>& A, vector<double>& y);

double pi(vector<double> x, vector<double> y);

double norma(vector<double> x);


#endif
