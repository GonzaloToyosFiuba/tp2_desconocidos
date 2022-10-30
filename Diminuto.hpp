#ifndef __DIMINUTO_H__
#define __DIMINUTO_H__

#include "Tamanio.hpp"

class Diminuto : public Tamanio {
public:
    Diminuto(string tipo_tamanio);
    bool se_puede_adoptar(int espacio);
};

#endif // __DIMINUTO_H__