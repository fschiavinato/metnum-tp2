#include <vector>

using namespace std;

bool menor_distancia(const pair<int,double>& A,const pair<int,double>& B);
double distancia(vector<double>& muestra, vector<double>& observacion);
int clase_de_mayor_aparicion_entre_los_k_mas_cercanos(vector<pair<int,double> >& distancia_por_muestra, int& k);

