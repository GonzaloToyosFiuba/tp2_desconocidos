#ifndef __PERRO_H_
#define __PERRO_H_

#include "Animal.hpp"

class Perro : public Animal {
public:
    
    Perro(string nombre, int edad, string tamanio, char especie, string personalidad);

    void ensuciar();

    void duchar();

    void alimentar();
};

#endif//__PERRO_H_