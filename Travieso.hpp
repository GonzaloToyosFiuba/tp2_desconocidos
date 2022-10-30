#ifndef __TRAVIESO_H__
#define __TRAVIESO_H__

#include "Personalidad.hpp"

class Travieso : public Personalidad
{
private:
    
public:
    Travieso(string tipo_personalidad);
    int perdida_de_hambre(int perdida_hambre);
    int perdida_de_higiene(int perdida_higiene);
};

#endif // __TRAVIESO_H__
