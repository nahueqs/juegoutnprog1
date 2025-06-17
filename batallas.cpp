#include "batallas.h"
#include "casas.h"
using namespace std;
cant_rondas = 10;
const int v_chances_ganar_ronda[cant_rondas] = { 0.50, 0.45, 0.40, 0.35, 0.30, 0.25, 0.20, 0.15, 0.10, 0.10 }

int getPorcChanceGanarSegunRonda(rondaActual){
    return v_chances_ganar_ronda[rondaActual];
}

void iniciarBatalla(int rondaActual, int numSoldadosCombatientes) {
    int chanceGanar =  getPorcChanceGanarSegunRonda(rondaActual);
}
