#ifndef __SOCIABLE_H__
#define __SOCIABLE_H__

#include "Personalidad.hpp"

class Sociable : public Personalidad {
public:
    // PRE:
    // POST: Construye una Personalidad de tipo Sociable
    Sociable(string tipo_personalidad);
    // PRE:
    // POST: Devuelve el mismo valor perdida_hambre.
    int perdida_de_hambre(int perdida_hambre);
    // PRE:
    // POST: Devuelve la mitad del valor de perdida_higiene.
    int perdida_de_higiene(int perdida_higiene);    
};

#endif // __SOCIABLE_H__