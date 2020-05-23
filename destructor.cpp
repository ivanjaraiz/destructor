// destructor.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Demo
{
    private:
        int *p;
    public:
        Demo() 
        { 
            p = new int[10]; // Si metemos esto en la clase, su se crea en stack memory, el objeto no elimina el heap memory. 
            cout << "Constructor of Demo" << endl; 
        }
        ~Demo() 
        { 
            delete []p;//  ASI SI, al terminar el objeto en stack, se lanza el destructor y elimina el heap !!  
            cout << "Destructor of Demo" << endl; 
        }
};

void fun()
{
    //Demo d; // con esto se lanza el constructor y destructor, ya que estamos en stack memory y es un objeto y se elimina automáticamente. 
    Demo *p = new Demo(); //Con este no se lanza el destructor, memory leak!! no se destruye en objeto. 
    delete p;// este lanza el destructor. 
}

int main()
{
    fun();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
