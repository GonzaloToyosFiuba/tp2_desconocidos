#ifndef __CONEJO_H_
#define __CONEJO_H_

#include "Animal.hpp"

class Conejo : public Animal {
public:
    Conejo(string nombre, int edad, string tamanio, char especie, string personalidad);

    void ensuciar();

    void duchar();

    void alimentar();
};

#endif // __CONEJO_H_