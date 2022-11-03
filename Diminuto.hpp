#ifndef __DIMINUTO_H__
#define __DIMINUTO_H__

#include "Tamanio.hpp"

class Diminuto : public Tamanio {
public:
    // PRE:
    // POST: Construye un Tamanio de tipo Diminuto.
    Diminuto(string tipo_tamanio);
    // PRE: espacio > 0 .
    // POST: Devuelve true siempre.
    bool es_espacio_adecuado(int espacio);
};

#endif // __DIMINUTO_H__