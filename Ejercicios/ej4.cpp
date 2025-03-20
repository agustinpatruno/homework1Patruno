#include "ej4.hpp"

//4)
//a)
/*en este ejercicio voy a elegir utilizar el tipo de dato char para comparar los textos ya que si quiero que la funcion se ejecute 
en tiempos de compilacion necesito que sus parametros sean de tipo literal(int, bool, char) y en el caso de string, es una clase 
mas compleja que no esta incluida en estos tipos literales.*/

constexpr bool comparar_textos_ejecucion(const char* texto1,const char* texto2)
{
    if (texto1[0] != texto2[0])
    {
        return false;
    }
    else if (texto1[0] == '\0' && texto2[0] == '\0')
    {
        return true;
    }
    else
    {
        return comparar_textos_ejecucion(texto1+1,texto2+1);
    }
}

//c)///////////////////////////////////////////////////////

bool comparar_textos(const char* texto1,const char* texto2)
{
    if (texto1[0] != texto2[0])
    {
        return false;
    }
    else if (texto1[0] == '\0' && texto2[0]== '\0')
    {
        return true;
    }
    else
    {
        return comparar_textos(texto1+1,texto2+1);
    }
}

//b)/////////////////////////////////////////////////////////////////

void miprocesoAmedir_normal(const char* texto1, const char* texto2)
{
    auto startTime = chrono::high_resolution_clock::now(); 

    bool result = comparar_textos(texto1,texto2);

    auto endTime = chrono::high_resolution_clock::now(); 

    cout << result << endl;

    auto elapsedTime1 = std::chrono::duration_cast<chrono::nanoseconds>( endTime - startTime); 

    cout << "A miProcesoAMedir le tomó: " << elapsedTime1.count() << " nanosegundos ejecutarlo normalmente" << endl; 

    return;
}

void miprocesoAmedir_ejecucion()
{

 constexpr const char* texto1 = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales";

 constexpr const char* texto2 = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales";

    auto startTime = chrono::high_resolution_clock::now(); 

    constexpr bool result = comparar_textos_ejecucion(texto1,texto2);

    auto endTime = chrono::high_resolution_clock::now(); 

    cout << result << endl;

    auto elapsedTime2 = std::chrono::duration_cast<chrono::nanoseconds>( endTime - startTime); 

    cout << "A miProcesoAMedir le tomó: " << elapsedTime2.count() << " nanosegundos ejecutar en tiempos de compilacion" << endl; 

    return;

}

int main()
{
 const char* texto1 = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales";

 const char* texto2 = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales";
 
 bool comparacion = comparar_textos(texto1,texto2);

 if (comparacion)
 {
    cout << "ambos textos son iguales"<< endl;
 }
 else
 {
    cout << "los textos son distintos" << endl;
 }

 miprocesoAmedir_normal(texto1,texto2);

 miprocesoAmedir_ejecucion();

 return 0;

 /*(opcional) una interfaz donde se le pide al usuario que punto quiere probar su funcionamiento.
 int ejercicio = 0;

 cout << "que ejercicio quieres probar(poner numero) ?: "<< endl ;
 cout << "1) funcion recursiva que se ejecuta en tiempo de compilacion donde evalua si 2 textos son iguales "<< endl ;
 cout << "2) funcion que evalua el tiempo que toma la ejecucion de la funcion del punto 1" << endl ;
 cout << "3) funcion que compara el tiempo de una funcion cuando se ejecuta en tiempos de compilacion y otra funcion que se compila y ejecuta"<< endl;
 cout <<"ingrese numero: "<<endl;
 
 cin >> ejercicio;

 if (cin.fail())
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "error al ingresar el numero"<< endl ;

        return 0;
    }

 while (true)
    {
        cout << "---------------------------"<< endl;
        
        if (ejercicio == 1)
        {
            bool comparacion = comparar_textos(texto1,texto2);

            if (comparacion)
            {
            cout << "ambos textos son iguales"<< endl;
            }
            else
            {
            cout << "los textos son distintos" << endl;
            }
        }
        else if (ejercicio == 2)
        {
            miprocesoAmedir(texto1,texto2,false);
        }
        else if (ejercicio == 3)
        {
            miprocesoAmedir(texto1,texto2,true);
        }
        else
        {
            cout << "error, ingrese un numero dentro de las opciones." << endl;
        }
        
        cout << "queres probar otro ejercicio (-1 para cortar/ numero del ejercicio para continuar):"<< endl;

        cin>> ejercicio;

        if (cin.fail())
        {
            cin.clear();
        
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
            cout << "error al ingresar el numero"<< endl ;
        
            return 0;
        }

        if (ejercicio == -1)
        {
            return 0;
        }
    }
    */
}
