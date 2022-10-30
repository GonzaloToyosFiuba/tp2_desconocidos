#ifndef __GRANDE_H__
#define __GRANDE_H__

#include "Tamanio.hpp"

class Grande : public Tamanio {
public:
    Grande(string tipo_tamanio);
    bool se_puede_adoptar(int espacio);
};

#endif // __GRANDE_H__
