#ifndef __DORMILON_H__
#define __DORMILON_H__
#include "Personalidad.hpp"

class Dormilon : public Personalidad {
public:
    // PRE:
    // POST: Construye una Personalidad de tipo Dormilon.
    Dormilon(string tipo_personalidad);
    // PRE:
    // POST: Devuelve la mitad del valor de perdida_hambre.
    int perdida_de_hambre(int perdida_hambre);
    // PRE:
    // POST: Devuelve el mismo valor de perdida_higiene.
    int perdida_de_higiene(int perdida_higiene);
};

#endif // __DORMILON_H__