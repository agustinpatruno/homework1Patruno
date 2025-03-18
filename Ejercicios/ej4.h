#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <chrono> 
using namespace std;


/*
input: const char* texto1, const char* texto2
ouput: bool
explicacion: funcion recursiva que compara si 2 cadenas de texto son iguales o no
(true si lo son, false en caso contrario). Ademas con constexpr se ejecuta en tiempos de compilacion

*/
constexpr bool comparar_textos(const char* texto1,const char* texto2);


/*
input: const char* texto1, const char* texto2
ouput: bool
explicacion: funcion recursiva que compara si 2 cadenas de texto son iguales o no
(true si lo son, false en caso contrario)

*/
bool comparar_textos_ejecucion(const char* texto1,const char* texto2);


/*
input: const char* texto1, const char* texto2, bool comparar
ouput: void
explicacion: llama a la funcion comparar_textos(const char* texto1,const char* texto2) para calcular el 
tiempo que tarda en ejecutarse y dependiendo el bool que le pasemos, luego llamara a la funcion 
comparar_textos_ejecucion(const char* texto1,const char* texto2) para comparar el tiempo de diferencia entre ambas

*/
void miprocesoAmedir(const char* texto1, const char* texto2, bool comparar);