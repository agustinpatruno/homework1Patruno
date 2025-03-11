#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <memory>
using namespace std;

//////////////////////////////////////////////structs del node y de la linked list///////////////////////////////////////////////////

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


//i)///////////////////////////////////////////////////////////////////

shared_ptr<node> create_node()
{
   try
   {
        return make_shared<node>();
   }
   catch(const std::exception& e)
    {
        cerr << "error, no se pudo crear el nodo\n"<< endl;

        return nullptr;
    }

}

////////////////////////////////////////creo la linked list vacia//////////////////////////////////////////////////////////////////////

shared_ptr<linked_list> create_linked_list()
{
    shared_ptr<linked_list> lista = make_shared<linked_list>();

    if (!lista)
    {
        return nullptr;
    }

    lista -> head = nullptr;

    lista -> tail = nullptr;

    lista -> cant_nodos = 0;

    cout << "funcion bien la creacion" << endl; 
    
    return lista;

}

//ii)///////////////////////////////////////////////////////////////

void push_front(shared_ptr<linked_list> lista, int dato)
{
    if (!lista)
    {
        return;
    }
    
    shared_ptr<node> nuevo_nodo = create_node();

    nuevo_nodo -> valor = dato;

    if (lista -> cant_nodos == 0)
    {
        nuevo_nodo -> siguiente = nullptr;

        lista -> tail = nuevo_nodo;
    }
    else
    {
        nuevo_nodo -> siguiente = lista -> head -> siguiente;
    }

    lista -> head = nuevo_nodo;

    lista -> cant_nodos++;

    cout << "se añadio correctamente el nodo(push_front)" << endl;

    return;

}

//iii)////////////////////////////////////////////////

void push_back(shared_ptr<linked_list> lista, int dato)
{
    if (!lista)
    {
        return;
    }
    
    shared_ptr<node> nuevo_nodo = create_node();

    nuevo_nodo -> valor = dato;

    if (lista -> cant_nodos == 0)
    {
        lista -> head = nuevo_nodo;
    }
    else
    {
        lista -> tail -> siguiente = nuevo_nodo;
    }

    nuevo_nodo -> siguiente = nullptr;

    lista -> tail = nuevo_nodo;

    lista -> cant_nodos++;

    cout << "se añadio correctamente el nodo(push_back)" << endl;

    return;

}

//iv)////////////////////////////////////////////////////////////////////////////////

void insert(shared_ptr<linked_list> lista, int dato, int posicion)
{
    if (!lista)
    {
        return;
    }
    
    if (posicion > lista -> cant_nodos)
    {
        cout << "error, la posicion es mayor que la cantidad de elementos. se insertar al final"<< endl;

        push_back(lista,dato);

        return;
    }
    
    shared_ptr<node> nuevo_nodo = create_node();

    nuevo_nodo -> valor = dato;

    shared_ptr<node> temp = lista -> head;

    for (int i = 0; i < posicion-1; i++)
    {
        temp = temp -> siguiente;
    }
    
    nuevo_nodo -> siguiente = temp -> siguiente;

    temp -> siguiente = nuevo_nodo;

    lista -> cant_nodos++;

    cout << "se añadio correctamente el nodo"<< endl;

    return;
}

//v)////////////////////////////////////////////

void erase(shared_ptr<linked_list> lista, int posicion)
{

    if (!lista || lista -> cant_nodos == 0)
    {
        return;
    }
    
    shared_ptr<node> temp = lista -> head;

    shared_ptr<node> nodo_borrar;

    if (posicion > lista -> cant_nodos)
    {
        cout << "error, la posicion es mayor que la cantidad de elementos. se borrar el nodo final"<< endl;

        while (temp -> siguiente -> siguiente != nullptr)
        {
            temp = temp -> siguiente;
        }
        
        nodo_borrar = temp -> siguiente;

        temp -> siguiente = nullptr;

    }
    else
    {
        for (int i = 0; i < posicion; i++)
        {
            temp = temp -> siguiente;
        }

        nodo_borrar = temp -> siguiente;

        temp -> siguiente = nodo_borrar -> siguiente;

    }

    cout << " se borro correctamente el nodo, valor :" << nodo_borrar -> valor << endl;

    lista -> cant_nodos--;

    return;

}

//vi)///////////////////////////////////////

void printlist(shared_ptr<linked_list> lista)
{

    if (!lista || lista -> cant_nodos == 0)
    {
        cout << "no hay nada por recorrer" << endl;

        return;
    }
    
    shared_ptr<node> temp = lista -> head;

    int contador = 0;

    for (int i = 0; i < lista -> cant_nodos-1; i++)
    {
        cout << "->"<< temp->valor << endl;

        temp = temp -> siguiente;

        contador ++;
    }
    return;

}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //creacion de un nodo
    shared_ptr<node> nuevo = create_node();

    nuevo -> valor = 2;

    cout << nuevo -> valor << endl;

    //creacion de una lista enlazada, le añado elementos y los imprimo con printlist

    shared_ptr<linked_list> nueva_lista = create_linked_list();

    for (int i = 0; i < 10; i++)
    {
        push_back(nueva_lista, i);
    }

    cout << "cant " << nueva_lista -> cant_nodos << endl;
    
    push_front(nueva_lista,11);

    cout << "cant " <<nueva_lista -> cant_nodos << endl;

    insert(nueva_lista,12,10);

    cout << "cant " << nueva_lista -> cant_nodos << endl;


    erase(nueva_lista,7);

    printlist(nueva_lista);

    cout << nueva_lista -> cant_nodos << endl;

    return 0;
}