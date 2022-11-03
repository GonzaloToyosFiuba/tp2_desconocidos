#ifndef __GIGANTE_H__
#define __GIGANTE_H__

#include "Tamanio.hpp"

class Gigante : public Tamanio {
public:
    Gigante(string tipo_tamanio);
    bool es_espacio_adecuado(int espacio);
};

#endif // __GIGANTE_H__