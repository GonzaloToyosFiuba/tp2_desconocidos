#ifndef __MEDIANO_H__
#define __MEDIANO_H__

#include "Tamanio.hpp"

class Mediano : public Tamanio {
public:
    // PRE:
    // POST: Construye un Tamanio de tipo Mediano.
    Mediano(string tipo_tamanio);
    // PRE: espacio > 0 .
    // POST: Devuelve true de espacio >= 10 .
    bool es_espacio_adecuado(int espacio);
};

#endif // __MEDIANO_H__