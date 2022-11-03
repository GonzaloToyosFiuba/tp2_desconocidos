#ifndef __TAMANIO_H__
#define __TAMANIO_H__

#include <iostream>
#include "constantes.hpp"

using namespace std;


class Tamanio{
protected:
    string tipo_tamanio;
public:
    virtual bool es_espacio_adecuado(int espacio) = 0;
    virtual ~Tamanio() = default;
    string obtener_tipo_de_tamanio();
};

#endif //__TAMANIO_H__