#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "indicesVectores.h"
#include "constantesJuego.h"
#include "sesionDeJuego.h"
#include "menues.h"
#include "admCasas.h"

using namespace std;

float getChanceGanarSegunRonda(int rondaActual) {
    return v_chances_ganar_ronda[rondaActual];
}

float getCostoComidaPorSoldado(float costoPorBatallon, int soldadosPorBatallon){
    return costoPorBatallon / soldadosPorBatallon;
}

int getComidaGastadaRonda(int cantSoldados, std::vector<float>& recursosJugador, int casaElegida){
     float costo_alimentar_soldado = getCostoComidaPorSoldado(getCostoComidaxBatallonSegunCasa(casaElegida), soldados_x_batallon);
     int auxResult =cantSoldados * costo_alimentar_soldado;
     cout << "En esta batalla gastas "  << auxResult <<" comida alimentar a tus soldados. "<< endl;
     return auxResult;
}

int getTotalPuedeAlimentar(const std::vector<float> recursosJugador){
    int casaElegida = getNumCasaElegida(recursosJugador);
    float costo_alimentar_soldado = getCostoComidaPorSoldado(getCostoComidaxBatallonSegunCasa(casaElegida), soldados_x_batallon); // distinto segun cada casa
    return static_cast<int>(recursosJugador[comida] / costo_alimentar_soldado);
}

int getTropasListas(const std::vector<float> recursosJugador){
    int soldadosDisponibles =  static_cast<int>(recursosJugador[soldados]);
    int puedeAlimentar = getTotalPuedeAlimentar(recursosJugador);
    if (soldadosDisponibles < puedeAlimentar) {
        return soldadosDisponibles;
    } else {
        return puedeAlimentar;
    }
}

bool seActivoChanceHabActiva(float chance_hab_activa){
    srand(static_cast<unsigned int>(time(0)));
    return  (static_cast<float>(rand()) / RAND_MAX) < chance_hab_activa;
}

void ejecutarActiva(std::vector<float>& recursosJugador){
    int casaElegida = getNumCasaElegida(recursosJugador);
    switch (casaElegida) {
        case id_lannister :

        break;
        case id_stark :

        break;

        case id_targaryen :

        break;
    }
}

int getOroAGanar(int rondaActual, std::vector<float>& recursosJugador){
    return 10000 + (rondaActual * 5000);
}

int getTropasCaidas(int rondaActual, int combatientes_reales){
    float auxPorcentajeAPerder = 5.0f * rondaActual;
    float auxResult = (auxPorcentajeAPerder / 100.0f) * combatientes_reales;
    return static_cast<int>(auxResult);
}

void ejecutarPasiva(std::vector<float>& recursosJugador, int rondaActual, int casaElegida, int& tropasCaidas, int& tropasListas ){
    switch (casaElegida) {
        case id_lannister :{
            // Tras cada batalla recuperan un 50% del oro correspondiente a los soldados caídos durante la batalla.
            float oro_a_recuperar = getValorSoldadoSegunCasa(casaElegida) * tropasCaidas * 0.5;
            recursosJugador[oro] += oro_a_recuperar;
            cout << "Gracias a tu habilidad pasiva recuperas "  << oro_a_recuperar << " de oro por el 50% del costo de " << tropasCaidas << " soldados caidos en batalla. (costo por soldado "
            << getValorSoldadoSegunCasa(casaElegida) <<")."<< endl;
        break;
        }
        case id_stark : {
          //  El porcentaje de tropas perdidas en cada batalla se reduce un (nro de ronda*1%)
          float porcentajeTropasARecuperar = 1.0f * rondaActual;
          float auxTropasRecuperar =  (porcentajeTropasARecuperar / 100.0f ) * tropasCaidas;
          int auxTropasRecuperarInt =  static_cast<int>(auxTropasRecuperar);
          tropasCaidas += auxTropasRecuperarInt;
          recursosJugador[soldados] += auxTropasRecuperarInt;
          cout << "Gracias a tu habilidad pasiva recuperas "  << porcentajeTropasARecuperar << "% de los soldados caidos en batalla, que representan "<< auxTropasRecuperarInt <<endl;
        break;
        }
        /*
        case id_targaryen :

        break;*/
    }
}


// cada batalla resta tropas, resta comida, ganas o perdes la batalla en si, y suma oro si ganas
bool iniciarBatalla(int& rondaActual, std::vector<float>& recursosJugador, int casaElegida) {
    // si la ronda no se pasa del limite de rondas (ejecuta hasta la ultima inclusive)
    if (rondaActual < maxRondas) {
        bool rondaGanada = false;
        // incremento ronda y muestro mensaje con num de batalla
        rondaActual++;
        mostrarNumeroDeBatalla(rondaActual, maxRondas);

        // obtengo los soldados que van a pelear segun comida disponible y muestro
        int auxTropasListasRonda = getTropasListas(recursosJugador);
        cout << "Combaten " <<auxTropasListasRonda << " soldados." <<endl;

        // calculo tropas caidas, muestro y resto de los recursos
        int auxTropasCaidasRonda = getTropasCaidas(rondaActual, auxTropasListasRonda);
        recursosJugador[soldados] -= auxTropasCaidasRonda; // resto las tropas que va a perder
        cout << "En la batalla pierdes " << auxTropasCaidasRonda << " soldados." <<endl;

        // calculo comida a gastar, muestro y resto
        int auxComidaGastadaRonda = getComidaGastadaRonda(auxTropasListasRonda, recursosJugador, casaElegida);
        recursosJugador[comida] -= auxComidaGastadaRonda;
        cout << "En la batalla pierdes " << auxComidaGastadaRonda << " comida." <<endl;

        // habilidad pasiva siempre se ejecuta
        ejecutarPasiva(recursosJugador, rondaActual, casaElegida, auxTropasCaidasRonda, auxTropasListasRonda);

         // habilidad activa ejecuta si se activa segun porcentaje
        if (seActivoChanceHabActiva(recursosJugador[chance_hab_activa])) {
            ejecutarActiva(recursosJugador);
        }
        system("pause");
        //
        // oro_a_ganar = getOroAGanar(rondaActual);
        // comida_a_gastar = getComidaAGastar()
        return false;
        }
}

