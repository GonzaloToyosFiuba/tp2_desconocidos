#ifndef __TAMANIO_H__
#define __TAMANIO_H__

#include <iostream>
#include "constantes.hpp"

using namespace std;

class Tamanio {
protected:
    string tipo_tamanio;
public:
    // PRE:
    // POST: Devuelve verdadero en caso de que el espacio sea adecuado al tamanio que sea.
    virtual bool es_espacio_adecuado(int espacio) = 0;
    // PRE:
    // POST: Destruye Tamanio a sus hijos.    
    virtual ~Tamanio() = default;
    // PRE:
    // POST: Devuelve tipo_tamanio   
    string obtener_tipo_de_tamanio();
};

#endif //__TAMANIO_H__