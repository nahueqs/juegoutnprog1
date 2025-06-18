#include <vector>

using namespace std;
const int cant_rondas = 10;
const float v_chances_ganar_ronda[cant_rondas] = { 0.50, 0.45, 0.40, 0.35, 0.30, 0.25, 0.20, 0.15, 0.10, 0.10 };

float getChanceGanarSegunRonda(int rondaActual) {
    return v_chances_ganar_ronda[rondaActual];
}

// cada batalla resta tropas, resta comida, ganas o perdes, y suma oro si ganas
bool iniciarBatalla(int rondaActual, const std::vector<float>& recursosJugador) {
   // int casaElegida = recursosJugador[indice_casa_elegida];
    float chanceGanar =  getChanceGanarSegunRonda(rondaActual);
    // combantientes_reales = getCombatientesJugador();
    // seActivaHabilidadActiva = evaluar_Activa();
    // tropas_a_perder = getTropasAPerder(rondaActual);
    // oro_a_ganar = getOroAGanar(rondaActual);
    // comida_a_gastar = getComidaAGastar()




    return false;


}
