#ifndef __MEDIANO_H__
#define __MEDIANO_H__

#include "Tamanio.hpp"

class Mediano : public Tamanio {
public:
    Mediano(string tipo_tamanio);
    bool es_espacio_adecuado(int espacio);
};

#endif // __MEDIANO_H__