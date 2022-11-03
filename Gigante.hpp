#ifndef __GIGANTE_H__
#define __GIGANTE_H__

#include "Tamanio.hpp"

class Gigante : public Tamanio {
public:
    // PRE:
    // POST: Construye un Tamanio de tipo Gigante.
    Gigante(string tipo_tamanio);
    // PRE: espacio > 0 .
    // POST: Devuelve true si espacio >= 50 .
    bool es_espacio_adecuado(int espacio);
};

#endif // __GIGANTE_H__