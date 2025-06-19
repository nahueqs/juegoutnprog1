#include <vector>
#include "indicesVectores.h"
#include "constantesJuego.h"
#include "sesionDeJuego.h"
using namespace std;

float getChanceGanarSegunRonda(int rondaActual) {
    return v_chances_ganar_ronda[rondaActual];
}

// nos devuelve los soldados listos segun la comida. no tiene en cuenta las habilidades
int getCombatientesListos(const std::vector<float> recursosJugador){
    int costo_alimentar_batallon = recursosJugador[costo_alimentar_batallon]; // distinto segun cada casa
    float costo_alimentar_soldado = costo_alimentar_batallon / soldados_x_batallon; // nos da lo que cuesta alimentar a cada soldado
}


// cada batalla resta tropas, resta comida, ganas o perdes la batalla en si, y suma oro si ganas
bool iniciarBatalla(int& rondaActual, const std::vector<float>& recursosJugador) {
    // si no es ultima ronda
    rondaActual++;
  //  int casaElegida = recursosJugador[indice_casa_elegida];
    //float chanceGanar =  getCombatientesListos(rondaActual);
    // combantientes_reales = getSoldadosCombatenEnRonda();
    // seActivaHabilidadActiva = evaluar_Activa();
    // tropas_a_perder = getTropasAPerder(rondaActual);
    // oro_a_ganar = getOroAGanar(rondaActual);
    // comida_a_gastar = getComidaAGastar()
    return false;
}


bool iniciarBatalla2(int rondaActual, const std::vector<float>& recursosJugador) {
//    int casaElegida = recursosJugador[indice_casa_elegida];
     float chanceGanar =  getChanceGanarSegunRonda(rondaActual);
//    combantientes_reales = getCombatientesJugador();
    // si se activa pasiva combantientes_reales +=
   /* switch (casaElegida) {
    case 1:{ //
            // logica casa 1
        break;
    }
    case 2:{ //
            // logica casa 2
        break;
    }
    case 3:{ //
            // logica casa 3
        break;
    }

    return false;

    }
*/}
