#ifndef __PEQUENIO_H__
#define __PEQUENIO_H__

#include "Tamanio.hpp"

class Pequenio : public Tamanio {
public:
    Pequenio(string tipo_tamanio);
    bool se_puede_adoptar(int espacio);
};

#endif // __PEQUENIO_H__