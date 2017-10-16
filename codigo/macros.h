#ifndef __MACROS_H_
#define __MACROS_H_
#include <iostream>
#define RED(a,i,j)  (unsigned int)a[i*width*3 + j*3 + 0]
#define GREEN(a,i,j)  (unsigned int)a[i*width*3 + j*3 + 1]
#define BLUE(a,i,j)  (unsigned int)a[i*width*3 + j*3 + 2]
#define ILUM(a,i,j) (double)(RED(a,i,j) + GREEN(a,i,j) + BLUE(a,i,j)) / 3
#define DEBUG(x) cerr << #x << " = " << x << endl;
#define DEBUGM(a)  cout << #a << " = " << endl;\
    for(int i = 0; i < a.size(); i++) { \
        for(int j = 0; j < a[0].size(); j++) {\
            cout << a[i][j] << " ";\
        }\
        cout << endl; \
    } \
    cout << endl;\

#define DEBUGMATRIZ(a)  cout << #a << " = " << endl;\
    for(int i = 0; i < a.Filas(); i++) { \
        for(int j = 0; j < a.Columnas(); j++) {\
            cout << a.Get(i, j) << " ";\
        }\
        cout << endl; \
    } \
    cout << endl;\

#define DEBUGV(a)  cout << #a << " = " << endl;\
    for(int i = 0; i < a.size(); i++) {\
        cout << a[i] << " ";\
    }\
    cout << endl;
#endif
