#ifndef __PERRO_H_
#define __PERRO_H_

#include "Animal.hpp"

class Perro : public Animal
{
private:
    
public:
    
    Perro(string nombre, int edad, string tamanio, char especie, string personalidad);

    void ensuciar();
};

#endif//__PERRO_H_