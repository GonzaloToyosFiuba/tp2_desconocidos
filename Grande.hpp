#ifndef __GRANDE_H__
#define __GRANDE_H__

#include "Tamanio.hpp"

class Grande : public Tamanio {
public:
    // PRE:
    // POST: Construye un Tamanio de Tipo Grande.
    Grande(string tipo_tamanio);
    // PRE: espacio > 0 .
    // POST: Devuelve verdadero si espacio >= 10 .
    bool es_espacio_adecuado(int espacio);
};

#endif // __GRANDE_H__
