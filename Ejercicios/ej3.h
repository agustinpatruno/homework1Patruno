#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <memory>
using namespace std;

//structs del node y de la linked list//

struct node
{
    int valor;

    shared_ptr<node> siguiente;
};

struct linked_list
{
    int cant_nodos;

    shared_ptr<node> head;

    shared_ptr<node> tail;
};

//funciones auxiliares que crea el node y la linked_list//


/*
input: void
ouput: shared_ptr<node>
explicacion: crea un node y lo guarda en una variable con un shared pointer. Lueego lo retorna

*/
shared_ptr<node> create_node(void);

/*
input: void
ouput: shared_ptr<linked_list>
explicacion: crea una linked_list en una variable con shared_ptr con su head y tail a nullptr y 
su tamaño en cero. luego lo  retorna

*/
shared_ptr<linked_list> create_linked_list(void);


/*
input: shared_ptr<linked>, int
ouput: void
explicacion: incerta un node que crea con la funcion create_node(), lo guarda al frente de la lista y aumenta 
el size de la linked list

*/
void push_front(shared_ptr<linked_list> lista, int dato);


/*
input: shared_ptr<linked_list>, int
ouput: void
explicacion: incerta un node que crea con la funcion create_node(), lo guarda al final de la lista y aumenta 
el size de la linked list

*/
void push_back(shared_ptr<linked_list> lista, int dato);


/*
input: shared_ptr, int dato, int posicion
ouput: void
explicacion: inserta un node en la posicion de la lista que le pasen por input. En caso de que la posicion sea 
mayor que el tamaño de la linked list, se agregara al final. Luego aumenta el size de la linked list

*/
void insert(shared_ptr<linked_list> lista, int dato, int posicion);


/*
input: shared_ptr<linked_list>, int
ouput: void
explicacion: borra el node en la posicion que le pasen como input. En caso de que la posicion sea mayor que el tamaño de la linked list,
borra el ultimo node de la misma. Luego reduce el size de la linked list.

*/
void erase(shared_ptr<linked_list> lista, int posicion);


/*
input: shared_ptr
ouput: void
explicacion: imprime por consola los valores que tiene guardados una linked list

*/
void printlist(shared_ptr<linked_list> lista);