#include<iostream>
#include "menues.h"
#include "sesionDeJuego.h"
#include "admCasas.h"
using namespace std;

int seleccionDeCasa(){
    int opcion;
    cout << "---------------------------------------"               << endl;
    cout << "            Juego de Tronos            "               << endl;
    cout << "---------------------------------------"               << endl;
    cout << "          SELECCIONE LA CASA           "               << endl;
    cout << "---------------------------------------"               << endl;
    cout << "1- LANNISTER " <<endl;
    cout << "2- STARK     " <<endl;
    cout << "3- TARGARYEN"<<endl;
    cout << "4- BARATHEON " <<endl;
    cout << "---------------------------------------"               << endl;
    cin>>opcion;
    return opcion;
}

void mostrarEstadisticas(int estadisticas[], int tam){
    cout << "---------------------------------------"               << endl;
    cout <<"Estadisticas de la ultima partida: "<<endl;
    cout << "---------------------------------------"               << endl;
    cout<<" batalla_cantidad_victorias ="<<estadisticas[0]<<endl;
    cout<<" batalla_cantidad_derrotas  ="<<estadisticas[1]<<endl;
    cout<<" total_gastado_oro          ="<<estadisticas[2]<<endl;
    cout<<" total_gastado_comida       ="<<estadisticas[3]<<endl;
    cout<<" total_gastado_soldados     ="<<estadisticas[4]<<endl;
    cout<<" total_ganado_oro           ="<<estadisticas[5]<<endl;
    cout<<" total_ganado_comida        ="<<estadisticas[6]<<endl;
    cout<<" total_ganado_soldados      ="<<estadisticas[7]<<endl;
    cout << "---------------------------------------"               << endl;
}

void mostrarMenuPrincipal(int casaElegida, const std::vector<float>& recursosJugador, int batalla_actual) {
    cout << "---------------------------------------" << endl;
    cout << "            Juego de Tronos            " << endl;
    cout << "---------------------------------------" << endl;
    cout << getNombreCasaSeleccionada(casaElegida) << endl;
    cout << "|batallas realizadas : " << batalla_actual << endl;
    cout << "|presupuesto inicial : " << getOroInicialSegunCasa(casaElegida) << endl;
    cout << "|oro                 : " << recursosJugador[0] << endl;
    cout << "|comida              : " << recursosJugador[1] << endl;
    cout << "|soldados            : " << recursosJugador[2] << endl;
    cout << "|pasiva              : " << recursosJugador[4] << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. IR A LA BATALLA" << endl;
    cout << "2. TIENDA" << endl;
    cout << "3. SALIR" << endl;
    cout << "---------------------------------------" << endl;
    cout << "OPCION: ";
}

void mostrarResumenBatalla(const std::vector<float>& recursosJugador) {
    cout << "Soldados: " << recursosJugador[2] << endl;
    cout << "Comida: " << recursosJugador[1] << endl;
    cout << "Probabilidad de pasiva: " << recursosJugador[4] << endl;
    cout << endl;
}

void menuTienda(vector<float>& recursosJugador, int casaElegida, int estadisticas[]) {
    const int articulo_soldados        = 1000;
    const int articulo_comida          = 500;
    const int valor_x_comida           = 500;
    const float articulo_mejora_activa = getArticuloMejoraHabilidadActivaSegunCasa(casaElegida);
    const float valor_x_articulo_soldado = getValorSoldadoSegunCasa(casaElegida) * articulo_soldados;
    const int valor_x_mejora_activa    = getCostoMejorarHabilidadActivaSegunCasa(casaElegida);

    const int idx_opcion_tienda_soldados      = 1;
    const int idx_opcion_tienda_comida        = 2;
    const int idx_opcion_tienda_mejora_pasiva = 3;
    const int idx_opcion_tienda_volver        = 4;

    int cin_opcion_tienda = 0;

    while (true) {
        if (cin_opcion_tienda == idx_opcion_tienda_volver) break;

        system("cls");

        cout << "---------------------------------------" << endl;
        cout << getNombreCasaSeleccionada(casaElegida) << endl;
        cout << "|presupuesto: " << getOroInicialSegunCasa(casaElegida) << endl;
        cout << "|oro        : " << recursosJugador[0] << endl;
        cout << "|comida     : " << recursosJugador[1] << endl;
        cout << "|soldados   : " << recursosJugador[2] << endl;
        cout << "|pasiva     : " << recursosJugador[4] << endl;
        cout << "---------------------------------------" << endl;
        cout << "TIENDA" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Soldados          $" << valor_x_articulo_soldado << " x por " << articulo_soldados << " soldados" << endl;
        cout << "2. Comida            $" << valor_x_comida << " x " << articulo_comida << " unidades." << endl;
        cout << "3. Mejorar activa    $" << valor_x_mejora_activa << " x +" << articulo_mejora_activa << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> cin_opcion_tienda;
        system("cls");

        switch (cin_opcion_tienda) {
            case idx_opcion_tienda_soldados:
                if (recursosJugador[0] >= valor_x_articulo_soldado) {
                    recursosJugador[2] += articulo_soldados;
                    recursosJugador[0] -= valor_x_articulo_soldado;
         //           estadisticas[total_gastado_oro] += valor_x_articulo_soldado;
                } else {
                    cout << "No tienes oro suficiente!" << endl;
                    system("pause");
                }
                break;
            case idx_opcion_tienda_comida:
                if (recursosJugador[0] >= valor_x_mejora_activa) {
                    recursosJugador[1] += articulo_comida;
                    recursosJugador[0] -= valor_x_mejora_activa;
          //          estadisticas[total_gastado_comida] += valor_x_mejora_activa;
                } else {
                    cout << "No tienes oro suficiente!" << endl;
                    system("pause");
                }
                break;
            case idx_opcion_tienda_mejora_pasiva:
                if (recursosJugador[0] >= valor_x_mejora_activa) {
                    recursosJugador[4] += articulo_mejora_activa;
                    recursosJugador[0] -= valor_x_mejora_activa;
                } else {
                    cout << "No tienes oro suficiente!" << endl;
                    system("pause");
                }
                break;
            case idx_opcion_tienda_volver:
            default:
                break;
        }}
    }
