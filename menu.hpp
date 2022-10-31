#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "Refugio.hpp"

enum Estados {
    INICIO,
    LISTAR_ANIMALES,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMALES,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
};

void aplicacion(Refugio* mi_refugio, int &estado);


#endif//__MENU_HPP__