#include<iostream>
#include <vector>
#include "admCasas.h"
#include "admBatallas.h"
#include <iomanip>

using namespace std;


/// ESTADISTICAS
const int batalla_cantidad_victorias = 0;
const int batalla_cantidad_derrotas  = 1;
const int total_gastado_oro          = 2;
const int total_gastado_comida       = 3;
const int total_gastado_soldados     = 4;
const int total_ganado_oro           = 5;
const int total_ganado_comida        = 6;
const int total_ganado_soldados      = 7;

void setRecursosInicialesJugador(int numCasaElegida, std::vector<float>& v_recursosJugador) {
    v_recursosJugador[0] = getOroInicialSegunCasa(numCasaElegida);
    v_recursosJugador[1] = 0; //  comida del jugador
    v_recursosJugador[2] = 0; //  soldados del jugador
    v_recursosJugador[3] = getChanceHabActivaInicialSegunCasa(numCasaElegida); // % de activacion de la habilidad activa del jugador
    v_recursosJugador[4] = 0.5; // pos pasiva
}

void inicioDeJuego(int estadisticas[], int casaElegida){
    cout<<"CASA SELECCIONADA: "<<getNombreCasaSeleccionada(casaElegida);
    system("pause");

    /// (1) *************************************    INICIO DECLARACIÓN DE VARIABLES Y CONSTANTES  *************************************///

    /// JUGABILIDAD
    // recursos iniciales
    vector<float> recursosJugador(5);
    setRecursosInicialesJugador(casaElegida, recursosJugador);

    /// TIENDA
    // articulo: objeto que se compra en la tienda, el valor refiere a la cantidad
    const int articulo_soldados        = 1000; // mil soldados
    const int articulo_comida          = 500;
    const int valor_x_comida        = 500;
    const float articulo_mejora_activa = getPorcMejoraHabilidadActivaSegunCasa(casaElegida); // el % de mejora de cada habilidad segun casa
    const float valor_x_soldado      = getValorSoldadoSegunCasa(casaElegida);
    const float valor_x_articulo_soldado       = getValorSoldadoSegunCasa(casaElegida) * articulo_soldados;
    const int valor_x_mejora_activa = getCostoMejorarHabilidadActivaSegunCasa(casaElegida);

    /// BATALLA
    const int duracion_guerra = 10;
    int batalla_actual = 0;

    /// Auxiliares
    int cin_opcion_menu;
    int cin_opcion_tienda;
    int cin_batalla_deseas_continuar;
    bool deseas_continuar;
    /// Opciones de menu
    // Menu principal
    const int idx_opcion_menu_batalla = 1;
    const int idx_opcion_menu_tienda  = 2;
    const int idx_opcion_menu_volver  = 3;

    // Tienda
    const int idx_opcion_tienda_soldados      = 1;
    const int idx_opcion_tienda_comida        = 2;
    const int idx_opcion_tienda_mejora_pasiva = 3;
    const int idx_opcion_tienda_volver        = 4;
    /// (1) *************************************    FIN DECLARACIÓN DE VARIABLES Y CONSTANTES  *************************************///

    /// (2) -----------------------------------    INICIO MENÚ PRINCIPAL  -----------------------------------///
    while(true)
    {
        system("cls");

        cout << "---------------------------------------"               << endl;
        cout << "            Juego de Tronos            "               << endl;
        cout << "---------------------------------------"               << endl;
        cout << getNombreCasaSeleccionada(casaElegida)<< endl;
        cout << "|batallas realizadas : " << batalla_actual                  << endl;
        cout << "|presupuesto inicial       : " << getOroInicialSegunCasa(casaElegida)             << endl;
        cout << "|oro              : " << recursosJugador[0]                             << endl;
        cout << "|comida              : " << recursosJugador[1]                            << endl;
        cout << "|soldados            : " << recursosJugador[2]                          << endl;
        cout << "|pasiva              : " << recursosJugador[4]               << endl;
        cout << "---------------------------------------"               << endl;
        cout << idx_opcion_menu_batalla << ". IR A LA BATALLA"          << endl;
        cout << idx_opcion_menu_tienda  << ". TIENDA"                   << endl;
        cout << idx_opcion_menu_volver  << ". SALIR" << endl;
        cout << "---------------------------------------"               << endl;
        cout << "OPCION: ";
        cin >> cin_opcion_menu;

        system("cls");
    /// (2) -----------------------------------    FIN MENÚ PRINCIPAL  -----------------------------------///

        /// (3) ***********************************  ESTRUCTURA DE SELECCIÓN DEL MENÚ Y LÓGICA DEL JUEGO    ***********************************///
        switch(cin_opcion_menu)
        {
        case idx_opcion_menu_batalla:
        {
            if (batalla_actual > duracion_guerra)
            {
                cout << "No hay mas batallas por luchar, puedes descansar!" << endl;

                cout << endl;

                cout << "Presiona cualquier tecla para volver al menu."<<endl;
                system("pause");
                break;
            }

            cout << "Soldados: "                << recursosJugador[2]              << endl;
            cout << "Comida: "                  << recursosJugador[1]                << endl;
            cout << "Probabilidad  de pasiva: " << recursosJugador[4] << endl;

            cout << endl;


            cout << "Deseas continuar? 1(SI) / 2(NO)" << endl;
            cout << "opcion: ";
            cin >> cin_batalla_deseas_continuar;

            if(cin_batalla_deseas_continuar == 2)
            {
                deseas_continuar=false;

            }
            else
            {
                deseas_continuar=true;
            }

            if (!deseas_continuar) //<--- SI ES FALSO EL VALOR DE DESEAS CONTINUAR
            {
                break;
            }

            system("cls");

            batalla_actual++;

            if (batalla_actual == duracion_guerra)
            {
                cout << "~~ ULTIMA BATALLA ~~" << endl;
                cout << endl;
            }

            cout << "Batalla NRO " << batalla_actual;

            cout << endl;

            cout << "Presiona cualquier tecla para volver al menu.";
            system("pause");

            break;
        }
        case idx_opcion_menu_tienda:
        {
            /// (4) -----------------------------------    MENÚ DE LA TIENDA  -----------------------------------///
           cin_opcion_tienda=0;
            while(true)
            {
                if (cin_opcion_tienda == idx_opcion_tienda_volver)
                {
                    break;
                }

                system("cls");

                cout << "---------------------------------------" << endl;
                cout << getNombreCasaSeleccionada(casaElegida)                              << endl;
                cout << "|presupuesto: " << getOroInicialSegunCasa(casaElegida)   << endl;
                cout << "|oro        : " << recursosJugador[0]                   << endl;
                cout << "|comida     : " << recursosJugador[1]                << endl;
                cout << "|soldados   : " << recursosJugador[2]              << endl;
                cout << "|pasiva     : " << recursosJugador[4]   << endl;
                cout << "---------------------------------------" << endl;
                cout << "TIENDA" << endl;
                cout << "---------------------------------------" << endl;
                cout  << "1. Soldados          $" << valor_x_articulo_soldado << " x  por "<< articulo_soldados << " soldados" << endl;
                cout << "2. Comida            $" << valor_x_comida        << " x " << articulo_comida          << " unidades." << endl;
                cout << "3. Mejorar activa   $" << valor_x_mejora_activa  << " x +" << articulo_mejora_activa   << "." << endl;
                cout << "4. Volver al menu principal" << endl;
                cout << "---------------------------------------" << endl;
                cout << "Opcion: ";
                cin >> cin_opcion_tienda;

                system("cls");
            /// (4) -----------------------------------   FIN MENÚ DE LA TIENDA  -----------------------------------///

                /// (5) ***********************************  ESTRUCTURA DE SELECCIÓN DE LA TIENDA    ***********************************///
                switch(cin_opcion_tienda)
                {
                    case idx_opcion_tienda_soldados:
                    {
                        if (recursosJugador[0] >= valor_x_articulo_soldado)
                        {
                            recursosJugador[2] += articulo_soldados;
                            recursosJugador[0] -= valor_x_articulo_soldado;
                            estadisticas[total_gastado_oro]+=valor_x_articulo_soldado;
                        }
                        else
                        {
                            cout << "No tienes oro suficiente!" << endl;

                            cout << endl;

                            cout << "Presiona cualquier tecla para volver al menu.";
                            system("pause");
                        }

                        break;
                    }
                    case idx_opcion_tienda_comida:
                    {
                        if (recursosJugador[0] >= valor_x_mejora_activa)
                        {
                            recursosJugador[1] += articulo_comida;
                            recursosJugador[0] -= valor_x_mejora_activa;
                            estadisticas[total_gastado_comida]+= valor_x_mejora_activa;
                        }
                        else
                        {
                            cout << "No tienes oro suficiente!" << endl;

                            cout << endl;

                            cout << "Presiona cualquier tecla para volver al menu.";
                            system("pause");
                        }

                        break;
                    }
                    case idx_opcion_tienda_mejora_pasiva:
                    {
                        if (recursosJugador[0] >= valor_x_mejora_activa)
                        {
                            recursosJugador[4]  += articulo_mejora_activa;
                            recursosJugador[0] -= valor_x_mejora_activa;
                        }
                        else
                        {
                            cout << "No tienes oro suficiente!" << endl;

                            cout << endl;

                            cout << "Presiona cualquier tecla para volver al menu.";
                            system("pause");
                        }

                        break;
                    }
                    case idx_opcion_tienda_volver:

                    default:
                    {

                        break;
                    }
                }
                /// (5) ***********************************  FIN ESTRUCTURA DE SELECCIÓN DE LA TIENDA    ***********************************///
            }

            break;
        }

        case idx_opcion_menu_volver:
        {
            return;                   //<---- SALIR DEL JUEGO
        }
        }
        /// (3) ***********************************  FIN ESTRUCTURA DE SELECCIÓN DEL MENÚ Y LÓGICA DEL JUEGO    ***********************************///
    }




}
