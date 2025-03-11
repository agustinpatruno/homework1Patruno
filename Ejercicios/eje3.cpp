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
    unique_ptr<node> siguiente;
};

struct linked_list
{
    int cant_nodos;
    unique_ptr<node> head;
    node* tail;
};


//i)///////////////////////////////////////////////////////////////////

node* create_node()
{
   try
   {
        return new node;
   }
   catch(const std::exception& e)
   {
        cerr << "error, no se pudo crear el nodo\n"<< endl;

        return nullptr;
   }
}

////////////////////////////////////////creo la linked list vacia//////////////////////////////////////////////////////////////////////

linked_list* create_linked_list()
{
    linked_list* lista = new linked_list;

    if (!lista)
    {
        return nullptr;
    }

    lista -> head = nullptr;

    lista -> tail = nullptr;

    lista -> cant_nodos = 0;
    
    return lista;

}

//ii)///////////////////////////////////////////////////////////////

void push_front(linked_list* lista, int dato)
{
    if (!lista)
    {
        return;
    }
    
    unique_ptr<node> nuevo_nodo = unique_ptr<node>(create_node());

    nuevo_nodo -> valor = dato;

    if (lista -> cant_nodos == 0)
    {
        nuevo_nodo -> siguiente = nullptr;

        lista -> tail = nuevo_nodo.get();
    }
    else
    {
        nuevo_nodo -> siguiente = move(lista -> head -> siguiente);
    }

    lista -> head = move(nuevo_nodo);

    lista -> cant_nodos++;

    return;

}

//iii)////////////////////////////////////////////////

void push_back(linked_list* lista, int dato)
{
    if (!lista)
    {
        return;
    }
    
    unique_ptr<node> nuevo_nodo = unique_ptr<node>(create_node());

    nuevo_nodo -> valor = dato;

    if (lista -> cant_nodos == 0)
    {
        lista -> head = move(nuevo_nodo);
    }
    else
    {
        lista -> tail -> siguiente = move(nuevo_nodo);
    }

    nuevo_nodo -> siguiente = nullptr;

    lista -> tail = nuevo_nodo.get();

    lista -> cant_nodos++;

    return;

}

//iv)/////////////////////////////////////

void insert(linked_list* lista, int dato, int posicion)
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
    
    unique_ptr<node> nuevo_nodo = unique_ptr<node>(create_node());

    nuevo_nodo -> valor = dato;

    node* temp = lista -> head.get();

    for (int i = 0; i < posicion; i++)
    {
        temp = temp -> siguiente.get();
    }
    
    nuevo_nodo -> siguiente = move(temp -> siguiente);

    temp -> siguiente = move(nuevo_nodo);

    lista -> cant_nodos++;

    return;
}

//v)////////////////////////////////////////////

void erase(linked_list* lista, int posicion)
{

    if (!lista || lista->cant_nodos == 0)
    {
        return;
    }
    
    node* temp = lista -> head.get();

    node* nodo_borrar;

    if (posicion > lista -> cant_nodos)
    {
        cout << "error, la posicion es mayor que la cantidad de elementos. se borrar el nodo final"<< endl;

        while (temp -> siguiente -> siguiente != nullptr)
        {
            temp = temp -> siguiente.get();
        }
        
        nodo_borrar = temp -> siguiente.get();

        temp -> siguiente = nullptr;

    }
    else
    {
        for (int i = 0; i < posicion; i++)
        {
            temp = temp -> siguiente.get();
        }

        nodo_borrar = temp -> siguiente.get();

        temp -> siguiente = move(nodo_borrar -> siguiente);

    }

    lista ->cant_nodos --;

    delete nodo_borrar;

    return;

}

//vi)///////////////////////////////////////

void printlist(linked_list* lista)
{

    if (!lista || lista -> cant_nodos == 0)
    {
        cout << "no hay nada por recorrer" << endl;

        return;
    }
    
    node* temp = lista -> head.get();

    int contador = 0;

    while (temp -> siguiente != nullptr)
    {
        cout << "numero de nodo: " << contador << " valor del nodo: " << temp->valor << endl;

        contador ++;
    }
    
    return;

}