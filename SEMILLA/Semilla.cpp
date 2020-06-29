#include <iostream>
#include <windows.h>
#include <stdio.h>
#include<time.h>
#include<chrono>
#include<ctime>
#pragma comment(lib, "user32.lib")
using namespace std;

int main()
{
    SYSTEM_INFO siSysInfo;

    GetSystemInfo(&siSysInfo);//funcion sacada de internet para datos del sistema
    cout << "INFORMACION DE HARDWARE: \n";
    cout << "  OEM ID: " << siSysInfo.dwOemId << endl;
    cout << "  Numero de procesadores: " << siSysInfo.dwNumberOfProcessors << endl;
    cout << "  Tamano de pagina: " << siSysInfo.dwPageSize << endl;
    cout << "  Tipo de procesador: " << siSysInfo.dwProcessorType << endl;
    cout << "  Minimum application address: " << siSysInfo.lpMinimumApplicationAddress << endl;
    cout << "  Maximum application address: " << siSysInfo.lpMaximumApplicationAddress << endl;
    cout << "  Active processor mask: " << siSysInfo.dwActiveProcessorMask << endl;
    unsigned tini, tfin;
    float a = 0.5;
    tini = clock();//iniciando el tiempo
    tfin = clock();//fin de tiempo
    for (a; a < 1000000000;)
    {
        a *= 1.25;
    }//incrementamos el valor de a hasta que sea menor al parámetro(10 digitos)
    //utilizando funciones para calcular el tiempo 
    double time = (double(tfin - tini) / 1000000); 
    auto start = chrono::high_resolution_clock::now();//tomamos el tiempo
    auto finish = chrono::high_resolution_clock::now();//tomamos el tiempo 
    cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << " microsegundos";//tomando en cuenta 1 microsegundo=1e-6 
}
//funciones de clock son sacadas de google para ayudarme en hallar tiempos
