#ifndef __MATRIZ_H_
#define __MATRIZ_H_
#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
//#include <math.h>
#include <cmath>
#include <assert.h>

using namespace std;


/// Indexa de 1 a n/m ///

class Matriz
{

public:

    Matriz();

    Matriz(long int filas, long int columnas);

    Matriz(const Matriz& copia);

    long Filas() const;

    long Columnas() const;

    Matriz & Set(double val, long fila, long col); 

    double Get(long, long) const;    

   // void Resize(long,long);

    vector<double> multiply(const vector<double> & x) const;

    void escalar(double k);

    void add(const Matriz & m);

    void sub(const Matriz & m);

    friend bool operator == (const Matriz & a, const Matriz & b);

    friend bool operator != (const Matriz & a, const Matriz & b);

    friend Matriz& operator + (const Matriz & a, const Matriz & b);

    friend Matriz& operator - (const Matriz & a, const Matriz & b);

    friend Matriz& operator * (const Matriz & a, const Matriz & b);

    friend vector<double> operator * (const Matriz & a, const vector<double> & b);

    friend ostream & operator << (ostream & os, const Matriz & matrix);

    friend void prlong(const Matriz & matrix, ostream & os);
		
    Matriz& transpose() const;

    vector<double> valores();


private:
    
    vector<vector<double>>  vals;

};

#endif
