#include<iostream>
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
    cout << "3- BARATHEON " <<endl;
    cout << "4- TARGARYEN " <<endl;
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
