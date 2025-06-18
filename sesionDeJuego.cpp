#include<iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include "sesionDeJuego.h"
#include "admCasas.h"
#include "admBatallas.h"
#include "menues.h"

using namespace std;


/// ESTADISTICAS
const int batalla_cantidad_victorias = 0;
const int batalla_cantidad_derrotas  = 1;
const int total_gastado_oro          = 2;
const int total_gastado_comida       = 3;
const int total_gastado_soldados     = 4;
const int total_ganado_oro           = 5;
const int total_ganado_comida        = 6;
const int total_ganado_soldados      = 7;

void setRecursosInicialesJugador(int numCasaElegida, std::vector<float>& v_recursosJugador) {
    v_recursosJugador[0] = getOroInicialSegunCasa(numCasaElegida); // oro del jugador
    v_recursosJugador[1] = 0; //  comida del jugador
    v_recursosJugador[2] = 0; //  soldados del jugador
    v_recursosJugador[3] = getChanceHabActivaInicialSegunCasa(numCasaElegida); // % de activacion de la habilidad activa del jugador
    v_recursosJugador[4] = 0.5; // pos pasiva
}

void inicioDeJuego(int estadisticas[], int casaElegida) {
    cout << "CASA SELECCIONADA: " << getNombreCasaSeleccionada(casaElegida);
    system("pause");
    vector<float> recursosJugador(5);
    setRecursosInicialesJugador(casaElegida, recursosJugador);
    const int duracion_guerra = 10;
    int batalla_actual = 0;

    int cin_opcion_menu;
    const int idx_opcion_menu_batalla = 1;
    const int idx_opcion_menu_tienda  = 2;
    const int idx_opcion_menu_volver  = 3;

    while(true) {
        mostrarMenuPrincipal(casaElegida, recursosJugador, batalla_actual);
        cin >> cin_opcion_menu;
        system("cls");
        if (cin.fail()) {
            cin.clear(); // limpia el error
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el búfer
            cout << "Entrada inválida. Ingrese un número"<<endl;
            system("pause");
            system("cls");
           // continue; // vuelve a mostrar el menú
        }

        switch(cin_opcion_menu) {
            case idx_opcion_menu_batalla:
                menuBatalla(casaElegida, recursosJugador, batalla_actual, duracion_guerra);
                break;
            case idx_opcion_menu_tienda:
                menuTienda(recursosJugador, casaElegida, estadisticas);
                break;
            case idx_opcion_menu_volver:
                return;
        }
    }
}

