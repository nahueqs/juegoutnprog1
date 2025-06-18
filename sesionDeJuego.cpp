#include<iostream>
#include <vector>
#include <limits>
#include <iomanip>

#include "sesionDeJuego.h"
#include "admCasas.h"
#include "admBatallas.h"
#include "menues.h"
#include "indicesVectores.h"

using namespace std;

void setRecursosInicialesJugador(int numCasaElegida, std::vector<float>& v_recursosJugador) {
    v_recursosJugador[oro] = getOroInicialSegunCasa(numCasaElegida); // oro del jugador
    v_recursosJugador[comida] = 0; //  comida del jugador
    v_recursosJugador[soldados] = 0; //  soldados del jugador
    v_recursosJugador[chance_hab_activa] = getChanceHabActivaInicialSegunCasa(numCasaElegida); // % de activacion de la habilidad activa del jugador
    v_recursosJugador[chance_hab_pasiva] = 0.5; // pos pasiva
    v_recursosJugador[casa_elegida] = numCasaElegida; // id de la casa elegida
}

void inicioDeJuego(int estadisticas[], int casaElegida) {
    cout << "CASA SELECCIONADA: " << getNombreCasaSeleccionada(casaElegida);
    system("pause");
    vector<float> recursosJugador(largo_vector_recursos);
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

