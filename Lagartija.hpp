#ifndef __LAGARTIJA_H_
#define __LAGARTIJA_H_

#include "Animal.hpp"

class Lagartija : public Animal {

private:
public:
    Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad);

    void duchar();

    void ensuciar();

    void alimentar();

};

#endif // __LAGARTIJA_H_