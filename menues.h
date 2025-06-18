#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED
#include "sesionDeJuego.h"
#include <vector>

int seleccionDeCasa();

void mostrarEstadisticas(int estadisticas[], int tam);
void mostrarMenuPrincipal(int casaElegida, const std::vector<float>& recursosJugador, int batalla_actual);
void mostrarResumenBatalla(const std::vector<float>& recursosJugador);
void menuTienda(std::vector<float>& recursosJugador, int casaElegida, int estadisticas[]);


#endif // MENUES_H_INCLUDED
