#include "ej3.hpp"

//i)///////////////////////////////////////////////////////////////////

shared_ptr<node> create_node(void)
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

//////////creo la linked list vacia/////////////////

shared_ptr<linked_list> create_linked_list(void)
{
    shared_ptr<linked_list> lista = make_shared<linked_list>();

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
        nuevo_nodo -> siguiente = lista -> head;
    }

    lista -> head = nuevo_nodo;

    lista -> cant_nodos++;

    return;

}

//iii)////////////////////////////////////////////////////////////////////////

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

    return;

}

//iv)////////////////////////////////////////////////////////////////////////////////

void insert(shared_ptr<linked_list> lista, int dato, int posicion)
{
    if (!lista)
    {
        return;
    }
    
    if (posicion > lista -> cant_nodos-1)
    {
        cout << "error, la posicion es mayor que la cantidad de elementos. se insertara al final"<< endl;

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

    cout << "se añadio correctamente el nodo con el valor: "<< dato <<" en la posicion: "<<posicion << endl;

    return;
}

//v)////////////////////////////////////////////////////////

void erase(shared_ptr<linked_list> lista, int posicion)
{

    if (!lista || lista -> cant_nodos == 0)
    {
        return;
    }
    
    shared_ptr<node> temp = lista -> head;

    shared_ptr<node> nodo_borrar;

    int indice_final;

    if (posicion > lista -> cant_nodos)
    {
        cout << "error, la posicion es mayor que la cantidad de elementos. se borrar el nodo final"<< endl;

        indice_final = lista -> cant_nodos;
    }
    else
    {
        indice_final = posicion-1;
    }
    
    for (int i = 0; i < indice_final; i++)
    {
        temp = temp -> siguiente;
    }
    
    nodo_borrar = temp -> siguiente;

    if (indice_final == lista -> cant_nodos)
    {
        temp -> siguiente = nullptr;
    }
    else
    {
        temp -> siguiente = nodo_borrar -> siguiente;
    }
    
    cout << " se borro correctamente el nodo, valor :" << nodo_borrar -> valor<<" en la posicion : "<< posicion << endl;

    lista -> cant_nodos--;

    return;

}

//vi)/////////////////////////////////////////////////////////////////////

void printlist(shared_ptr<linked_list> lista)
{

    if (!lista || lista -> cant_nodos == 0)
    {
        cout << "no hay nada por recorrer" << endl;

        return;
    }
    
    shared_ptr<node> temp = lista -> head;

    for (int i = 0; i < lista -> cant_nodos; i++)
    {
        cout << "->" << temp->valor;

        temp = temp -> siguiente;
    }

    cout << endl;
    
    return;

}

////////////////////////////////////////////////////////////////////////////////////////////////////


/*
compilacion del ejercicio 3:

    make ej3

*/
int main()
{
    //creacion de un nodo

    shared_ptr<node> nuevo = create_node();

    nuevo -> valor = 2;

    cout << "el valor del node creado es :"<<nuevo -> valor << endl;

    //creacion de una lista enlazada, le añado elementos y los imprimo con printlist

    shared_ptr<linked_list> nueva_lista = create_linked_list();

    for (int i = 0; i < 10; i++)
    {
        push_back(nueva_lista, i);
    }

    printlist(nueva_lista);

    insert(nueva_lista,12,4);

    printlist(nueva_lista);

    erase(nueva_lista,7);

    printlist(nueva_lista);

    cout <<  "cantidad final de nodos: "<< nueva_lista -> cant_nodos << endl;

    return 0;
}