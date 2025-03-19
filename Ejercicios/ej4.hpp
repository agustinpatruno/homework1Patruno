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
(true si lo son, false en caso contrario). Ademas con constexpr se ejecuta en tiempos de compilacion.

*/
constexpr bool comparar_textos_ejecucion(const char* texto1,const char* texto2);


/*
input: const char* texto1, const char* texto2
ouput: bool
explicacion: funcion recursiva que compara si 2 cadenas de texto son iguales o no
(true si lo son, false en caso contrario). se ejecuta normalmente.

*/
bool comparar_textos(const char* texto1,const char* texto2);


/*
input: const char* texto1, const char* texto2
ouput: void
explicacion: llama a la funcion comparar_textos(const char* texto1,const char* texto2) para calcular el 
tiempo que tarda en ejecutarse normalmente

*/
void miprocesoAmedir_normal(const char* texto1, const char* texto2);


/*
input: const char* texto1, const char* texto2
ouput: void
explicacion: llama a la funcion comparar_textos_ejecucion(const char* texto1,const char* texto2) para calcular el 
tiempo que tarda en ejecutarse en tiempo de compilacion

*/
void miprocesoAmedir_ejecucion();