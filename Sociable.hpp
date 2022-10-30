#ifndef __SOCIABLE_H__
#define __SOCIABLE_H__

#include "Personalidad.hpp"

class Sociable : public Personalidad 
{
private:

public:
    Sociable(string tipo_personalidad);
    int perdida_de_hambre(int perdida_hambre);
    int perdida_de_higiene(int perdida_higiene);    
};

#endif // __SOCIABLE_H__