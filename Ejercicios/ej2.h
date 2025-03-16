#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;
enum gravedad {DEBUG = 1 , INFO, WARNING, ERROR, CRITICAL};

////funciones auxiliares ejercicio a////

/*
input: void
ouput: int
explicacion: pide al usuario por consola que error quiere guardar en un archivo de texto mediante un int 
y devuelve un int asociado a un enum

*/
int evento(void);


/*
input: bool 
ouput: string
explicacion: le pide al usuario por consola que ingrese un texto o el nombre de un archivo 
(dependiendp el valor del input) y lo retorna

*/
string texto_o_archivo(bool mensaje);


////ejercicio a////


/*
input: string , gravedad 
ouput: void
explicacion: guarda en un archivo txt un mensaje con la gravedad asignada con la siguiente estructura
[gravedad]<mensaje>

*/
void logMessage(string mensaje, gravedad NivelSeveridad);


////funciones auxiliares ejercicio b////


/*
input: void
ouput: int
explicacion: pide al usuario por consola la linea de codigo donde se produjo el error 

*/
int linea_de_codigo(void);


/*
input: bool
ouput: string
explicacion: pide al usuario por consola el nombre o un mensaje de acceso (dependiendo el bool que le pasemos como input)

*/
string msj_acesso_nombre(bool nombre);


////ejercicio b////


/*
input: string Mensaje_de_error, string Archivo, int Linea_de_codigo
ouput: void
explicacion: guarda en un archivo txt un mensaje de error con el archivo asociado y la linea de codigo donde se produjo

*/
void logMessage(string Mensage_de_Error, string Archivo, int linea_de_codigo);


/*
input: string Mensaje_de_acceso, string Nombre_de_usuario
ouput: void
explicacion: guarda en un archivo txt un mensaje de acceso con el nombre asociado de la persona que lo ejecuto

*/
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario);


/*
input: void
ouput: int
explicacion: agarra un error en tiempo de compilacion y lo almacena en un archivo txt con la funcion 
logmessage(string mensaje, gravedad Nivelgravedad).

*/
int error_en_runtime(void);