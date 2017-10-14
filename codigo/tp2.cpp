#include <istream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "knn.h"

using namespace std;

void print_resultado(vector<pair<int,int> >& labels_predichos,int offset){
  
  cout << "ImageId Label" << endl;

  for (int i = 0; i < labels_predichos.size(); ++i)
    {
      cout << labels_predichos[i].first+offset << " " <<labels_predichos[i].second ;
      cout << endl;
    }
}

int main()
{
  ifstream theFile ("../enunciado/data/train.csv");
 
  vector<vector<double> > data_training;
  vector<int> labels_training;
  vector<vector<double> > data_testing;
  vector<int> labels_testing;
  vector<pair<int,int> > labels_predichos;

  int k = 3;
  int alpha = 10;
  int opcion = 0; //0-knn , 1-pca+knn
  int training_cant = 34000; //tomo las cota primeras muestras
  int count = 0;
  int testing_cant = 4000;
  //int ceros_cant = 0;

  string line;
  getline(theFile, line); // Salta headers

  //---------training-----------
  while (count < training_cant && getline(theFile, line))
  {
    string line_value;
    vector<double> line_values;
    stringstream ss(line);

    getline(ss, line_value, ','); //saco el label
    labels_training.emplace_back(stoi(line_value)); // guardo

    while(getline(ss, line_value, ','))
    {
      //if(valor < 0.00001) ceros_cant++;
      line_values.push_back(stod(line_value));
    }
    data_training.emplace_back(line_values);
    count++;
  }

  //--------testing------------
  count = 0;

  while(count < testing_cant && getline(theFile,line)){

    string line_value;
    vector<double> line_values;
    stringstream ss(line);

    getline(ss, line_value, ','); //saco el label
    labels_testing.emplace_back(stoi(line_value)); // guardo

    while(getline(ss, line_value, ','))
    {
      //if(valor < 0.00001) ceros_cant++;
      line_values.push_back(stod(line_value));
    }
    data_testing.emplace_back(line_values);
    count++;  

  }

  labels_predichos = ocr(data_training, labels_training,data_testing,labels_testing,k,alpha,opcion);

  print_resultado(labels_predichos,training_cant);

  /*cout << values.size() << " " << values[0].size() << endl;
  cout << ceros_cant/(double)values.size() << endl;*/

  //cout << values.capacity()*values[25].capacity() * sizeof(double) /** values.capacity()*/ << endl;
  /*for (int i = 0; i < values.size(); ++i)
    {
      for (int j = 0; j < values[0].size(); ++j)
      {
          cout << values[i][j] << " " ;
      }
      cout << endl;
      cout << endl;
    }
 */

  return 0;
}  

