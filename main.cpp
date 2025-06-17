#include <iostream>
#include "menues.h"
#include "sesionDeJuego.h"

using namespace std;

int main()
{
    const int tamanio=8;
    int estadisticas[8]={};

    inicioDeJuego(estadisticas, seleccionDeCasa());

    cout<<"Elegi volver de mi sesion."<<endl;

    mostrarEstadisticas(estadisticas,tamanio);
    system("pause");

}
