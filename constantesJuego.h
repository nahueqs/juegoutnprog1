#ifndef CONSTANTESJUEGO_H_INCLUDED
#define CONSTANTESJUEGO_H_INCLUDED

    //constantes config juego
    const int maxRondas = 10;
    const int soldados_x_batallon = 10000;
    const float v_chances_ganar_ronda[maxRondas] = {0.50, 0.45, 0.40, 0.35, 0.30, 0.25, 0.20, 0.15, 0.10, 0.10};

    // menu principal
    const int idx_opcion_menu_batalla = 1;
    const int idx_opcion_menu_tienda  = 2;
    const int idx_opcion_menu_volver  = 3;

    // ID casas
    const int id_lannister = 1;
    const int id_stark  = 2;
    const int id_targaryen = 3;

    // tienda
    const int articulo_soldados= 1000;
    const int articulo_comida = 10000; // UNIDADES DE COMIDA
    const int valor_x_comida = 500;

    const int idx_opcion_tienda_soldados = 1;
    const int idx_opcion_tienda_comida = 2;
    const int idx_opcion_tienda_mejora_pasiva = 3;
    const int idx_opcion_tienda_volver = 4;



#endif // CONSTANTESJUEGO_H_INCLUDED
