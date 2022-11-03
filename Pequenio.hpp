#ifndef __PEQUENIO_H__
#define __PEQUENIO_H__

#include "Tamanio.hpp"

class Pequenio : public Tamanio {
public:
    // PRE: 
    // POST: Contruye un Tamanio de tipo Pequenio.
    Pequenio(string tipo_tamanio);
    // PRE: espacio > 0 .
    // POST: Devuelve true siempre.
    bool es_espacio_adecuado(int espacio);
};

#endif // __PEQUENIO_H__