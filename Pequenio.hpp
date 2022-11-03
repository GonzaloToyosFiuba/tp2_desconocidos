#ifndef __PEQUENIO_H__
#define __PEQUENIO_H__

#include "Tamanio.hpp"

class Pequenio : public Tamanio {
public:
    Pequenio(string tipo_tamanio);
    bool es_espacio_adecuado(int espacio);
};

#endif // __PEQUENIO_H__