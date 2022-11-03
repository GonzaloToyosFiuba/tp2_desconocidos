#ifndef __TRAVIESO_H__
#define __TRAVIESO_H__

#include "Personalidad.hpp"

class Travieso : public Personalidad {    
public:
    // PRE:
    // POST: Construye una Pesonalidad de tipo Travieso.
    Travieso(string tipo_personalidad);
    // PRE:
    // POST: Devuelve el mismo valor de perdida_hambre.
    int perdida_de_hambre(int perdida_hambre);
    // PRE:
    // POST: Devuelve el doble del valor de perdida_higiene.
    int perdida_de_higiene(int perdida_higiene);
};

#endif // __TRAVIESO_H__
