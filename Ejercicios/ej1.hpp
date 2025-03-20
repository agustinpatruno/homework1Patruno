#include <iostream>
#include <vector>
#include <limits>
using namespace std;

/*
inputs: int n
ouput: vector<vector<int>>
explicacion: crea una matriz cuadrada de nxn donde los valores son acendentes
[1,2,...,10]
[11,...,20]
...
*/
vector<vector<int>> devolver_matriz(int n);


/*
inputs: <vector<vector<int>>
ouputs: void
explicacion: imprime una matriz de abajo a la derecha hacia arriba a la izquierda

*/
void imprimir_matriz(vector<vector<int>> matriz);