#ifndef ADMCASAS_H_INCLUDED
#define ADMCASAS_H_INCLUDED
#include <string>
using std::string;

// obtener valores de tienda segun casa ----------
int getValorSoldadoSegunCasa(int numCasa);
int getCostoComidaSegunCasa(int numCasa);
int getOroInicialSegunCasa(int numCasa);
string getNombreCasaSeleccionada(int numCasa);
int getCostoMejorarHabilidadSegunCasa(int numCasa);

// ejecutar habilidades segun casa ----------
// int ejecutarHabilidadActivaSegunCasa(int numCasa)
// int ejecutarHabilidadPasivaSegunCasa(int numCasa)

// funciones relacionadas a los porcentajes habilidades segun casa ----------
// int getChanceHabilidadActiva(int numCasa)
// int getChanceHabilidadPasiva(int numCasa)

#endif // CASAS_H_INCLUDED
