#include <vector>
#include <cmath>
#include <iostream>
#include <utility>
#include <algorithm>
#include "knn.h"

#ifndef KNN_H
#define KNN_H

using namespace std;

vector<pair<int,int> > ocr(vector<vector<double> > &data_training, 
					vector<int> &labels_training, vector<vector<double> > &data_testing,
					vector<int> &labels_testing,int k, int alpha, int opcion){

	vector<pair<int,int> > labels_predichos(data_testing.size());	

	switch(opcion){

		case 0:{	//knn
		 		labels_predichos =
		 		predict(data_training, labels_training, data_testing,labels_testing,k);
		 }break;
				
		case 1:{ // pca + knn
			//pca(data_training, data_testing, alpha);
			//labels_predichos = 
			//predict(data_training, labels_training,data_testing,labels_testing,k);

		}break;

	}

	return labels_predichos;
}

vector<pair<int,int> > predict(vector<vector<double> > &data_training, 
					vector<int> &labels_training, vector<vector<double> > &data_testing,
					vector<int> &labels_testing,int k){

	vector<pair<int,int> > labels_predichos(data_testing.size());

	for (int i = 0; i < data_testing.size(); ++i)
	{	
		
		labels_predichos[i] = make_pair(i,knn(data_training,labels_training,data_testing[i],k));
		
	}
	return labels_predichos;
}

int knn(vector<vector<double> >& datos, vector<int>& labels, vector<double>& observacion, int k){

	int cant_muestras = datos.size();
	double distance = 0.0;
	vector<pair<int,double> > distancia_por_muestra(datos.size());
	
	for (int i = 0; i < cant_muestras; ++i)
	{
		
		distance = distancia(datos[i],observacion);
		distancia_por_muestra[i] = make_pair(labels[i],distance);

	}

	sort(distancia_por_muestra.begin(),distancia_por_muestra.end(),menor_distancia);
	
	return clase_de_mayor_aparicion_entre_los_k_mas_cercanos(distancia_por_muestra,k);

}

bool menor_distancia(const pair<int,double> &A,const pair<int,double>& B){

	return (A.second < B.second);

}

double distancia(vector<double>& muestra, vector<double>& observacion){

	double res = 0;
	for (int i = 0; i < muestra.size(); ++i)
	{
		res += pow(muestra[i]-observacion[i],2);
	}
	res = sqrt(res);
}

double norma(vector<double> x) {
    double res = 0;
    for(int i = 0; i < x.size(); i++) {
        res += pow(x[i], 2);
    }
    res = sqrt(res);
    return res;
}

int clase_de_mayor_aparicion_entre_los_k_mas_cercanos(vector<pair<int,double> >& distancia_por_muestra, int& k){

	vector<int> labels_count(10,0);
	for (int i = 0; i < k; ++i)
	{
		labels_count[distancia_por_muestra[i].first]++;
	}

	int res = 0;
	int max = labels_count[0];
	for (int i = 0; i < labels_count.size(); ++i)
	{	
		if (labels_count[i] > max)
		{
			res = i;
			max = labels_count[i];
		}
	}

	return res; 
}
/*
int main(int argc, char const *argv[])
{
	vector<int> labels(3,0);

	labels[0] = 1;
	labels[1] = 0;
	labels[2] = 1;


	vector<double> vec,vec1,vec2 ;//
	vec = {1,2} ;
	vec1 = {0,0};
	vec2 = {-1,-3};
	vector<vector<double> > datos = {vec,vec1,vec2};

	vector<double> observacion = {0,1};
	cout << knn(datos,labels,observacion,3) << endl;

	 //cout << datos[1][1] << endl;
	 //cout << vec1[0] << " " << vec1[1] << endl;//(2,[1,2]);// [1,2]; //variables
	//vector<vector<double> > datos(3,0); //muestras

	
	return 0;
}*/

#endif
