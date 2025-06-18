#include "admBatallas.h"
#include "admCasas.h"
using namespace std;
const int cant_rondas = 10;
const float v_chances_ganar_ronda[cant_rondas] = { 0.50, 0.45, 0.40, 0.35, 0.30, 0.25, 0.20, 0.15, 0.10, 0.10 };

float getPorcChanceGanarSegunRonda(int rondaActual) {
    return v_chances_ganar_ronda[rondaActual];
}

void iniciarBatalla(int rondaActual, int numSoldadosCombatientes) {
    float chanceGanar =  getPorcChanceGanarSegunRonda(rondaActual);




}
