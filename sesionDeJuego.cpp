#include<iostream>
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

void inicioDeJuego(int estadisticas[], int casa){
    cout<<"CASA SELECCIONADA: "<<getNombreCasaSeleccionada(casa);
    system("pause");
    /// (1) *************************************    INICIO DECLARACI�N DE VARIABLES Y CONSTANTES  *************************************///
    /// JUGABILIDAD
    //constante
    const int presupuesto_inicial = getOroInicialSegunCasa(casa);
    //variable
    int oro = presupuesto_inicial;

    const int soldados_inicial = 0;
    int soldados = soldados_inicial;

    const int comida_inicial = 0;
    int comida = comida_inicial;

    const float pasiva_probabilidad_inicial = 0.5;
    float pasiva_probabilidad = pasiva_probabilidad_inicial;

    /// TIENDA
    const float valor_x_soldado      = getValorSoldadoSegunCasa(casa);
    const float valor_x_1000_soldados       = getValorSoldadoSegunCasa(casa) * 1000;
    const int valor_x_comida        = getCostoComidaSegunCasa(casa);
    const int valor_x_mejora_pasiva = getCostoMejorarHabilidadSegunCasa(casa);

    // articulo: objeto que se compra en la tienda, el valor refiere a la cantidad.
    const int articulo_soldados        = 1000;
    const int articulo_comida          = 500;
    const float articulo_mejora_pasiva = 0.1;

    /// BATALLA
    const int duracion_guerra = 5;
    int batalla_actual = 0;



    /// Auxiliares
    int cin_opcion_menu;
    int cin_opcion_tienda;
    int cin_batalla_deseas_continuar;
    bool deseas_continuar;

    // Menu principal
    const int idx_opcion_menu_batalla = 1;
    const int idx_opcion_menu_tienda  = 2;
    const int idx_opcion_menu_volver  = 3;

    // Tienda
    const int idx_opcion_tienda_soldados      = 1;
    const int idx_opcion_tienda_comida        = 2;
    const int idx_opcion_tienda_mejora_pasiva = 3;
    const int idx_opcion_tienda_volver        = 4;
    /// (1) *************************************    FIN DECLARACI�N DE VARIABLES Y CONSTANTES  *************************************///

    /// (2) -----------------------------------    INICIO MEN� PRINCIPAL  -----------------------------------///
    while(true)
    {
        system("cls");

        cout << "---------------------------------------"               << endl;
        cout << "            Juego de Tronos            "               << endl;
        cout << "---------------------------------------"               << endl;
        cout << getNombreCasaSeleccionada(casa)<< endl;
        cout << "|batallas realizadas : " << batalla_actual                  << endl;
        cout << "|presupuesto         : " << presupuesto_inicial             << endl;
        cout << "|oro                 : " << oro                             << endl;
        cout << "|comida              : " << comida                          << endl;
        cout << "|soldados            : " << soldados                        << endl;
        cout << "|pasiva              : " << pasiva_probabilidad             << endl;
        cout << "---------------------------------------"               << endl;
        cout << idx_opcion_menu_batalla << ". IR A LA BATALLA"          << endl;
        cout << idx_opcion_menu_tienda  << ". TIENDA"                   << endl;
        cout << idx_opcion_menu_volver  << ". SALIR" << endl;
        cout << "---------------------------------------"               << endl;
        cout << "OPCION: ";
        cin >> cin_opcion_menu;

        system("cls");
    /// (2) -----------------------------------    FIN MEN� PRINCIPAL  -----------------------------------///

        /// (3) ***********************************  ESTRUCTURA DE SELECCI�N DEL MEN� Y L�GICA DEL JUEGO    ***********************************///
        switch(cin_opcion_menu)
        {
        case idx_opcion_menu_batalla:
        {
            if (batalla_actual > duracion_guerra)
            {
                cout << "No hay mas batallas por luchar, puedes descansar!" << endl;

                cout << endl;

                cout << "Presiona cualquier tecla para volver al menu.";
                system("pause");
                break;
            }

            cout << "Soldados: "                << soldados            << endl;
            cout << "Comida: "                  << comida              << endl;
            cout << "Probabilidad  de pasiva: " << pasiva_probabilidad << endl;

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
            /// (4) -----------------------------------    MEN� DE LA TIENDA  -----------------------------------///
           cin_opcion_tienda=0;
            while(true)
            {
                if (cin_opcion_tienda == idx_opcion_tienda_volver)
                {
                    break;
                }

                system("cls");

                cout << "---------------------------------------" << endl;
                cout << getNombreCasaSeleccionada(casa)                              << endl;
                cout << "|presupuesto: " << presupuesto_inicial   << endl;
                cout << "|oro        : " << oro                   << endl;
                cout << "|comida     : " << comida                << endl;
                cout << "|soldados   : " << soldados              << endl;
                cout << "|pasiva     : " << pasiva_probabilidad   << endl;
                cout << "---------------------------------------" << endl;
                cout << "TIENDA" << endl;
                cout << "---------------------------------------" << endl;
                cout << "1. Soldados          $" << valor_x_soldado        << " x " << articulo_soldados        << " unidades. Total por 1000 soldados = $" << valor_x_1000_soldados << endl;
                cout << "2. Comida            $" << valor_x_comida         << " x " << articulo_comida          << " unidades." << endl;
                cout << "3. Mejorar pasiva    $" << valor_x_mejora_pasiva  << " x +" << articulo_mejora_pasiva   << "." << endl;
                cout << "4. Volver al menu principal" << endl;
                cout << "---------------------------------------" << endl;
                cout << "Opcion: ";
                cin >> cin_opcion_tienda;

                system("cls");
            /// (4) -----------------------------------   FIN MEN� DE LA TIENDA  -----------------------------------///

                /// (5) ***********************************  ESTRUCTURA DE SELECCI�N DE LA TIENDA    ***********************************///
                switch(cin_opcion_tienda)
                {
                case idx_opcion_tienda_soldados:
                {
                    if (oro >= valor_x_soldado)
                    {
                        soldados += articulo_soldados;
                        oro -= valor_x_soldado;
                        estadisticas[total_gastado_oro]+=valor_x_comida;
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
                    if (oro >= valor_x_comida)
                    {
                        comida += articulo_comida;
                        oro -= valor_x_comida;
                        estadisticas[total_gastado_comida]+=valor_x_comida;
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
                    if (oro >= valor_x_mejora_pasiva)
                    {
                        pasiva_probabilidad += articulo_mejora_pasiva;
                        oro -= valor_x_mejora_pasiva;
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
                /// (5) ***********************************  FIN ESTRUCTURA DE SELECCI�N DE LA TIENDA    ***********************************///
            }

            break;
        }

        case idx_opcion_menu_volver:
        {
            return;                   //<---- SALIR DEL JUEGO
        }
        }
        /// (3) ***********************************  FIN ESTRUCTURA DE SELECCI�N DEL MEN� Y L�GICA DEL JUEGO    ***********************************///
    }




}
