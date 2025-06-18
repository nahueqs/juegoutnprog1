#include<iostream>
#include <vector>
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
    int cin_batalla_deseas_continuar;
    bool deseas_continuar;

    const int idx_opcion_menu_batalla = 1;
    const int idx_opcion_menu_tienda  = 2;
    const int idx_opcion_menu_volver  = 3;

    while(true) {
        mostrarMenuPrincipal(casaElegida, recursosJugador, batalla_actual);
        cin >> cin_opcion_menu;
        system("cls");

        switch(cin_opcion_menu) {
            case idx_opcion_menu_batalla:
                if (batalla_actual > duracion_guerra) {
                    cout << "No hay mas batallas por luchar, puedes descansar!" << endl;
                    system("pause");
                    break;
                }

                mostrarResumenBatalla(recursosJugador);

                cout << "Deseas continuar? 1(SI) / 2(NO)\nopcion: ";
                cin >> cin_batalla_deseas_continuar;
                deseas_continuar = (cin_batalla_deseas_continuar != 2);

                if (!deseas_continuar) break;

                system("cls");
                batalla_actual++;

                if (batalla_actual == duracion_guerra) {
                    cout << "~~ ULTIMA BATALLA ~~\n" << endl;
                }

                cout << "Batalla NRO " << batalla_actual << endl;
                cout << "Presiona cualquier tecla para volver al menu.";
                system("pause");
                break;

            case idx_opcion_menu_tienda:
                menuTienda(recursosJugador, casaElegida, estadisticas);
                break;

            case idx_opcion_menu_volver:
                return;
        }
    }
}

