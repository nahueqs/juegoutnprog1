#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "indicesVectores.h"
#include "constantesJuego.h"
#include "sesionDeJuego.h"
#include "menues.h"
using namespace std;

float getChanceGanarSegunRonda(int rondaActual) {
    return v_chances_ganar_ronda[rondaActual];
}

float getCostoComidaPorSoldado(float costoPorBatallon, int soldadosPorBatallon){
    return costoPorBatallon / soldadosPorBatallon;
}

// nos devuelve los soldados listos segun la comida. no tiene en cuenta las habilidades
int getCombatientesListos(const std::vector<float> recursosJugador){
    int casaElegida = getNumCasaElegida(recursosJugador);
    float costo_alimentar_soldado = getCostoComidaPorSoldado(getCostoComidaxBatallonSegunCasa(casaElegida), soldados_x_batallon); // distinto segun cada casa
    return static_cast<int>(recursosJugador[comida] / costo_alimentar_soldado);
}

bool seActivoHabActiva(const std::vector<float> recursosJugador){
    srand(static_cast<unsigned int>(time(0)));
    float porc_activacion = recursosJugador[chance_hab_activa];
    bool seActivo = (static_cast<float>(rand()) / RAND_MAX) < porc_activacion;

}

// cada batalla resta tropas, resta comida, ganas o perdes la batalla en si, y suma oro si ganas
bool iniciarBatalla(int& rondaActual, const std::vector<float>& recursosJugador) {
    // si no es ultima ronda
    rondaActual++;
    mostrarNumeroDeBatalla(rondaActual, maxRondas);
    int combantientes_reales = getCombatientesListos(recursosJugador);
    cout << "Combaten " <<combantientes_reales << " soldados. " <<endl;
    system("pause");
    bool flagSeActivoHabilidad = seActivoHabActiva(recursosJugador);
      //  int casaEl egida = recursosJugador[indice_casa_elegida];
    //float chanceGanar =  getCombatientesListos(rondaActual);

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
