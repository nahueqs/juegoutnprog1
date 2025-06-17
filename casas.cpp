#include<iostream>

using namespace std;
const int cant_casas = 3;
const string vector_nombre_casas[cant_casas] = {"LANNISTER", "STARK", "TARGARYEN" };
// Agregar 4to

const int v_oro_inicial_segun_casa[cant_casas] = {75000, 50000, 50000};

const int v_costo_batallon_segun_casa[cant_casas] = {10000, 8500, 12500};

const int v_costo_comida_batallon_segun_casa[cant_casas] = {5000, 5000, 5000};

const float v_chanceHabActiva_segun_casa[cant_casas] = {0.15, 0.3, 0.1};

const int v_idHabActiva_segun_casa[cant_casas] = {1, 2, 3};

//int getCostoMejorarHabilidadSegunCasa(int numCasa)

float getCostoSoldadoSegunCasa(int numCasa){
    return v_costo_batallon_segun_casa[numCasa] / 10000;
}

int getOroInicialSegunCasa(int numCasa){
    return v_oro_inicial_segun_casa[numCasa - 1];
}

int getCostoComidaSegunCasa(int numCasa){
    return v_costo_comida_batallon_segun_casa[numCasa - 1];
}

int getChanceHabActiva_segun_casa(int numCasa){
    return v_chanceHabActiva_segun_casa[numCasa - 1];
}

int getIdHabActiva_segun_casa(int numCasa){
    return v_idHabActiva_segun_casa[numCasa - 1];
}

