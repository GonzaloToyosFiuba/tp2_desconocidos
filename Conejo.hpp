#ifndef __CONEJO_H_
#define __CONEJO_H_

#include "Animal.hpp"

class Conejo : public Animal {

private:
public:
    Conejo(string nombre, int edad, string tamanio, char especie, string personalidad);

    void ensuciar();
};

#endif // __CONEJO_H_