#include<iostream>
using namespace std;
const int cant_casas_en_juego = 3;
const string vector_nombre_casas[cant_casas_en_juego] = {"LANNISTER", "STARK", "TARGARYEN" };
// Agregar 4to

const int v_oro_inicial_segun_casa[cant_casas_en_juego] = {75000,
                                                                                    50000,
                                                                                    50000};

const int v_costo_batallon_segun_casa[cant_casas_en_juego] = {10000,
                                                                                   8500,
                                                                                   12500};

const int v_costo_comida_batallon_segun_casa[cant_casas_en_juego] = {5000, 5000, 5000};

const float v_chanceHabActiva_segun_casa[cant_casas_en_juego] = {0.15, 0.3, 0.1};

const int v_idHabActiva_segun_casa[cant_casas_en_juego] = {1, 2, 3};

const int v_costos_mejorar_habilidad_segun_casa[cant_casas_en_juego] = {10000, 8500, 25000};

int getCostoMejorarHabilidadSegunCasa(int numCasaElegida) {
    return v_costos_mejorar_habilidad_segun_casa[numCasaElegida - 1];
}

float getValorSoldadoSegunCasa(int numCasaElegida){
    return  static_cast<float>(v_costo_batallon_segun_casa[numCasaElegida - 1]) / 10000;
}

int getOroInicialSegunCasa(int numCasaElegida){
    return v_oro_inicial_segun_casa[numCasaElegida - 1];
}

int getCostoComidaSegunCasa(int numCasaElegida){
    return v_costo_comida_batallon_segun_casa[numCasaElegida - 1];
}

int getChanceHabActiva_segun_casa(int numCasaElegida){
    return v_chanceHabActiva_segun_casa[numCasaElegida - 1];
}

int getIdHabActiva_segun_casa(int numCasaElegida){
    return v_idHabActiva_segun_casa[numCasaElegida - 1];
}

string getNombreCasaSeleccionada(int numCasaElegida){
    return vector_nombre_casas[numCasaElegida - 1];
}

