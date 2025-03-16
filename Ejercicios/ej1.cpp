//#include <ej1.h>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//1)
//a)

vector<vector<int>> devolver_matriz(int n)
{   
    vector<vector<int>> matriz(n, vector<int>(n));

    int valor = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = valor;

            valor+=1;
        }
    }

    return matriz;   

}

//b)

void imprimir_matriz(vector<vector<int>> matriz)
{
    if (matriz.empty())
    {
        cout << "la matriz esta vacia" << endl;

        return;
    } 

    int cant_filas = matriz.size();

    int columnas = matriz[0].size();

    cout << cant_filas << columnas << endl;

    for (size_t i = 0; i < matriz.size()*matriz[0].size()+matriz.size()-1; i++) 
    {

        if (columnas == 0)
        {   
            cant_filas = cant_filas-1;

            columnas = matriz[cant_filas].size();
        }
        else
        {
            cout << "fila: " << cant_filas << " columna: "<< columnas <<" valor: " <<matriz[cant_filas-1][columnas-1] << endl;
            
            columnas-=1 ; 
        }
    }
    return;
}

int main()
{
    int valor = 5;

    vector<vector<int>> matriz = devolver_matriz(valor);

    imprimir_matriz(matriz);
    
    return 0;

    /*(opcional) es una interfaz donde se le pide al usuario el tamaño de la matriz
    cout << "ingrese un numero: "<<endl;
    cin >> valor;

    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "error al ingresar el numero"<< endl ;
        return -1;
    }

    while (valor == 1)
    {
        cout << "error, ingrese un numero mayor a 1:";
        cin >> valor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "error al ingresar el numero"<< endl ;
            return -1;
        }
    }
    */
    
}