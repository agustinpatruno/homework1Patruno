#include <ej2.hpp>

//2)

///////////////////////////////////////////////////funciones adicionales////////////////////////////////////////////////////////////////

int evento(void)
{
    int importancia;

    cout << "indique la gravedad del evento (ingrese el numero)" << endl;
    cout << "1) DEBUG" << endl;
    cout << "2) INFO" << endl;
    cout << "3) WARNING" << endl;
    cout << "4) ERROR" << endl;
    cout << "5) CRITICAL" << endl;
    cout <<"ingrese numero: "<<endl;

    cin >> importancia;

    if (cin.fail())
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "error al ingresar el numero"<< endl ;

        return -1;
    }

    while (importancia > 5 || importancia < 1)
    {
        cout << "error, ingrese un numero dentro de las opciones:";

        cin >> importancia;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "error al ingresar el numero"<< endl ;

            return -1;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return importancia;
}

string texto_o_archivo(bool mensaje)
{   
    string texto;

    if (mensaje)
    {
        cout << "ingrese el mensaje:" << endl;
    }
    else
    {
        cout << "ingrese el nombre del archivo: "<< endl;
    }

    getline(cin,texto);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return texto;
   
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//a)

void logMessage(string mensaje, gravedad NivelSeveridad) 
{
    ofstream archivo("archivo_ej2.txt", ios::app);

    if (!archivo.is_open()) 
    { 
        cout << "Error al abrir el archivo" << endl;

        return;
    }

    switch (NivelSeveridad)
    {
        case DEBUG:

            archivo <<"[DEBUG]<"<<mensaje<<">\n";
            break;

        case INFO:

            archivo <<"[INFO]<"<<mensaje<<">\n";
            break;

        case WARNING:

            archivo <<"[WARNING]<"<<mensaje<<">\n";
            break;

        case ERROR:

            archivo <<"[ERROR]<"<<mensaje<<">\n";
            break;

        case CRITICAL:

            archivo <<"[CRITICAL]<"<<mensaje<<">\n";
            break;

        default:

            cout << "error, no se reconoce ese nivel";
            break;
    }

    cout << "se ejecuto correctamente" << endl;

    archivo.close();

    return;
}

///////////////////////////////////////////////////b)/////////////////////////////////////////////////////////////////////////////

//////////////////////////////funciones adicionales////////////////////////////////
int linea_de_codigo(void)
{
    int linea;

    cout << "ingrese linea de codigo: " << endl;

    cin >> linea;

    if (cin.fail())
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "error al ingresar el numero"<< endl ;

        return -1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return linea;
}

string msj_acesso_nombre(bool nombre)
{
    string texto;

    if (nombre)
    {
        cout<<"ingrese el nombre:" << endl;
    }
    else
    {
        cout<<"ingrese el mensaje de acceso: "<<endl;
    }

    getline(cin,texto);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return texto;
}

///////////////////////////////////////////////////////////////
//i)
//ii)

void logMessage(string Mensage_de_Error, string Archivo, int linea_de_codigo) 
{
    ofstream archivo("archivo_ej2.txt", ios::app);

    if (!archivo.is_open()) 
    { 
        cout << "Error al abrir el archivo" << endl;

        return;
    }

    archivo <<"mensaje de error:<"<<Mensage_de_Error<<">. archivo:<"<<Archivo<<">. linea:<"<<linea_de_codigo<<">\n";
    
    cout << "se ejecuto correctamente." << endl;

    archivo.close();
    
    return;
}

//iii)

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario) 
{
    ofstream archivo("archivo_ej2.txt", ios::app);

    if (!archivo.is_open()) 
    { 
        cout << "Error al abrir el archivo" << endl;

        return;
    }

    archivo <<"[SECURITY]< Mensaje de acceso:"<<Mensaje_De_Acceso<<" >< Nombre del ususario:"<<Nombre_de_Usuario<<" >\n"<< endl;

    cout << "se ejecuto correctamente." << endl;

    archivo.close();

    return;
}

//iv)

int error_en_runtime(void)
{
    try
    {
        int denominador = 0;

        int numerador = 20;

        if (denominador == 0)
        {
            throw runtime_error("error,hubo un problema en una division por cero");
        }

        int resultado = denominador / numerador;

        cout << "Resultado: " << resultado << std::endl;
    }
    catch(const std::exception& e)
    {
        logMessage(e.what(),gravedad(4));
    }

    return 1;

}

int main()
{

    logMessage("Hubo un problema de sintaxis",gravedad(1));

    logMessage("se añadieron nuevas librerias",gravedad(2));

    logMessage("segmentacion fault",gravedad(3));

    logMessage("Segmentation fault (core dumped)",gravedad(4));

    logMessage("killed",gravedad(5));



    string nombre_archivo = "datos.cpp";

    string mensaje_error = "[ERROR] División por cero detectada ";

    int linea= 21;

    logMessage(mensaje_error, nombre_archivo, linea);



    string msj_acceso=  "Access Granted";

    string nombre= "Agustinpatruno";

    logMessage(msj_acceso,nombre);


    
    error_en_runtime();
    
    return 0;

    /*(opcional) es una interfaz donde se le pide al usuario que ejercicio quiere probar.

    int r = 0;

    cout << "elije el ejercicio:"<< endl;
    cout << "1) ingresar un mensaje y la gravedad del evento en cuestion."<< endl;
    cout << "2) ingresar el error ocurrido, el archivo y la linea de codigo donde ocurrio."<< endl;
    cout << "3) ingresar un mensaje de acceso del usuario con su nombre."<< endl;
   
    cin >> r;

    if (cin.fail())
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "error al ingresar el numero"<< endl ;

        return -1;
    }

    while (true)
    {
        cout<< "-------------------"<< endl;

       if (r == 1)
        {
            gravedad pedir_gravedad = (gravedad)evento();

            string mensaje = texto_o_archivo(true);
        
            logMessage(mensaje,pedir_gravedad);
        }
       else if (r == 2)
        {
            string nombre_archivo = texto_o_archivo(false);

            string mensaje_error = texto_o_archivo(true);
        
            int linea= linea_de_codigo();
        
            logMessage(mensaje_error, nombre_archivo, linea);
        }
       else if (r == 3)
        {
            string msj_acceso= msj_acesso_nombre(false);

            string nombre= msj_acesso_nombre(true);
        
            logMessage(msj_acceso,nombre);
        }
       else
        {
            cout<< "error, debes ingresar un numero dentro del rango" << endl;
        }

       cout << "quieres seguir ingresando datos.( -1 para cortar / el numero del ejercicio para continuar) "<< endl;
       cin >> r;

       if (cin.fail())
       {
           cin.clear();
   
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
           cout << "error al ingresar el numero"<< endl ;
   
           return -1;
        }

       if (r == -1)
        {
            return 0;
        }

        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    */
}