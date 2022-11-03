#ifndef __JUGUETON_H__
#define __JUGUETON_H__

#include "Personalidad.hpp"

class Jugueton : public Personalidad {
public:
    // PRE:
    // POST: Construye una Personalidad de tipo Jugueton.
    Jugueton(string tipo_personalidad);
    // PRE:
    // POST: Devuelve el doble del valor de perdida_hambre.
    int perdida_de_hambre(int perdida_hambre);
    // PRE:
    // POST: Devuelve el mismo valor de perdida_higiene.
    int perdida_de_higiene(int perdida_higiene);
};

#endif // __JUGUETON_H__