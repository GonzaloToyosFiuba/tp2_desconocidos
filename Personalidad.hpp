#ifndef __PERSONALIDAD_H__
#define __PERSONALIDAD_H__

#include<iostream>

using namespace std;

class Personalidad {
protected:
    string tipo_personalidad;
public:
    // PRE:
    // POST: Devuelve la perdidad de hambre dependiendo del tipo de personalidad
    virtual int perdida_de_hambre(int perdida_hambre) = 0;
    // PRE:
    // POST: Devuelve la perdidad de higiene dependiendo del tipo de personalidad
    virtual int perdida_de_higiene(int perdida_higiene) = 0;
    // PRE:
    // POST: Devuelve tipo_personalidad
    string obtener_tipo_de_personalidad();
    // PRE:
    // POST: Destruye Personalidad y a sus hijos
    virtual ~Personalidad() = default;
};

#endif // __PERSONALIDAD_H__