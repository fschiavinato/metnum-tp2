#include <vector>

using namespace std;

vector<pair<int,int> > ocr(vector<vector<double> > &data_training, 
					vector<int> &labels_training, vector<vector<double> > &data_testing,
					vector<int> &labels_testing,int k, int alpha, int opcion);

vector<pair<int,int> > predict(vector<vector<double> > &data_training, 
					vector<int> &labels_training, vector<vector<double> > &data_testing,
					vector<int> &labels_testing,int k);
int knn(vector<vector<double> >& datos, vector<int>& labels, vector<double>& observacion, int k);
bool menor_distancia(const pair<int,double>& A,const pair<int,double>& B);
double distancia(vector<double>& muestra, vector<double>& observacion);
int clase_de_mayor_aparicion_entre_los_k_mas_cercanos(vector<pair<int,double> >& distancia_por_muestra, int& k);

