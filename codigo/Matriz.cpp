#include "Matriz.h"


Matriz::Matriz()
{
}

Matriz::Matriz(const Matriz& copia) : vals(copia.vals) {
}

Matriz::Matriz(long int filas, long int columnas) : vals(filas)
{
    for(auto&& fila: this->vals) {
        fila = vector<double>(columnas);
    }
}

long Matriz::Filas() const
{
    return this->vals.size();
}

long Matriz::Columnas() const
{
    long res = 0;
    if(this->vals.size() != 0) {
        res = this->vals[0].size();
    }
    return res;
}

Matriz & Matriz::Set(double val, long fila, long col)
{
    this->vals[fila-1][col-1] = val;
    return *this;
}



double Matriz::Get(long fila, long col) const
{
    return this->vals[fila-1][col-1];
}

void imprimirvector80(std::vector<double> v) {
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << "," << endl;
    }
}

void Matriz::escalar(double k)
{
    //Matriz result(this->filas, this->columnas)   

    for (int i = 0; i < this->Filas(); i++) {
        for (int j = 0; j < this->Columnas(); j++)
        {
            this->Set((double)(k*this->Get(i,j)), i, j);
        }
    }
}


void Matriz::add(const Matriz & mat)
{
    if (this->Filas() != mat.Filas()|| this->Columnas() != mat.Columnas()) {
        throw "No matchea dimension";
    }

    for (int i = 1; i <= this->Filas(); i++) {
        for (int j = 1; j <= this->Columnas(); j++) {
            this->Set(this->Get(i, j) + mat.Get(i, j), i, j);
        }
    }
}

void Matriz::sub(const Matriz & mat)
{
    if (this->Filas() != mat.Filas() || this->Columnas() != mat.Columnas()) {
        throw "No matchea dimension";
    }

    for (int i = 1; i <= this->Filas(); i++) {
        for (int j = 1; j <= this->Columnas(); j++) {
            this->Set(this->Get(i, j) - mat.Get(i, j), i, j);
        }
    }

}


bool operator == (const Matriz & a, const Matriz & b)
{
    return ((a.vals).empty() && b.vals.empty())
                || (!(a.vals).empty() && !(b.vals).empty() && (a.vals) == (b.vals));
}


bool operator != (const Matriz & a, const Matriz & b)
{
    return !(a == b);
}


ostream & operator << (ostream & os, const Matriz & matrix)
{
    for (int i = 1; i <= matrix.Filas(); i++) {
        for (int j = 1; j <= matrix.Columnas(); j++) {
            if (j != 1) {
                os << " ";
            }

            os << matrix.Get(i, j);
        }

        if (i < matrix.Filas()) {
            os << endl;
        }
    }

    return os;
}

Matriz& operator * (const Matriz & a, const Matriz & b) {
    if (a.Columnas() != b.Filas()) {
        throw "No matchea la dimension";
    }

    Matriz& result = *(new Matriz(a.Filas(), b.Columnas()));

    double resFilaXCol;

    for (long i = 1; i <= a.Filas(); i++) {
        for (long j = 1; j <= b.Columnas(); j++) {
            resFilaXCol = 0;

            for (long k = 1; k <= a.Columnas(); k++) {
                resFilaXCol += a.Get(i, k) * b.Get(k, j);
            }

            result.Set(resFilaXCol, i, j);
        }
    }

    return result;
    
}

Matriz& operator + (const Matriz & a, const Matriz & b){
    Matriz& res = *(new Matriz(a));
    res.add(b);
    return res;

}

Matriz& operator - (const Matriz & a, const Matriz & b){
    Matriz& res = *(new Matriz(a));
    res.sub(b);
    return res;
}


Matriz& Matriz::transpose() const
{
	long m = this->Filas();
	long n = this->Columnas();

	Matriz& res = *(new Matriz(n,m));
	for(long i = 1; i <= m; i++)
		for(long j = 1; j <= n; j++)
			res.Set(this->Get(i,j),j,i);
	return res;
}
