#ifndef BATALLAS_H_INCLUDED
#define BATALLAS_H_INCLUDED

// funciones relacionadas a las batallas ----------
// void iniciarBatalla(int numRonda, int numSoldadosCombatientes); FUNCION GRANDE
// boolean esRondaFinal() devuelve true si rondaActual > duracionGuerra
// boolean esJuegoPerdido() devuelve true si cant_batallas_perdidas >= cantidad_para_derrota (4 por defecto)
// int getSoldadosCombatientes(); devuelve la cant de soldados que pueden pelear (segun comida)
// getResultadoBatalla() *posiblemente es llamada por iniciarBatalla y hace los calculos finales
// getTropasPerdidasTrasBatalla(int numRonda, int numSoldados)
// getOroTrasBatallaGanada(int numRonda)
// int getPorcChanceGanarSegunRonda(int numRonda);
// void mostrarBalancePostBatalla(int numRonda); (modifica el oro, las tropas perdidas, etc

float getChanceGanarSegunRonda();
bool iniciarBatalla(int& rondaActual, std::vector<float>& recursosJugador, int casaElegida);
bool evaluarHabActiva(const std::vector<float>& recursosJugador);

#endif // BATALLAS_H_INCLUDED
