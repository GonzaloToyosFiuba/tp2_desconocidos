#ifndef __JUGUETON_H__
#define __JUGUETON_H__

#include "Personalidad.hpp"

class Jugueton : public Personalidad
{
private:
   
public:
    Jugueton(string tipo_personalidad);
    int perdida_de_hambre(int perdida_hambre);
    int perdida_de_higiene(int perdida_higiene);
};

#endif // __JUGUETON_H__