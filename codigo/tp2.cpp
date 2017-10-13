#include <istream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "knn.h"

using namespace std;

int main()
{
  ifstream theFile ("train.csv");

  string line;
  vector<vector<double> > values;
  vector<int> labels;
  getline(theFile, line); // Note

  int cota = 1500; //tomo las cota primeras muestras
  int count = 0;

  while (count < cota && getline(theFile, line))
  {
    
    string line_value;
    vector<double> line_values;
    stringstream ss(line);

    getline(ss, line_value, ','); //saco el label
    labels.emplace_back(stoi(line_value)); // guardo

    while(getline(ss, line_value, ','))
    {
      double valor = stod(line_value);

      line_values.push_back(stod(line_value));
    }
    values.emplace_back(line_values);
    count++;
  }

  
  for (int i = 0; i < values.size(); ++i)
    {
      for (int j = 0; j < values[0].size(); ++j)
      {
          cout << values[i][j] << " " ;
      }
      cout << endl;
      cout << endl;
    }
 

  return 0;
}  

