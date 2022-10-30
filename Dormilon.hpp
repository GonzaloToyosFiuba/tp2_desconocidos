#ifndef __DORMILON_H__
#define __DORMILON_H__
#include "Personalidad.hpp"

class Dormilon : public Personalidad
{
private:
    
public:
    Dormilon(string tipo_personalidad);
    int perdida_de_hambre(int perdida_hambre);
    int perdida_de_higiene(int perdida_higiene);
};

#endif // __DORMILON_H__