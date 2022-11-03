#ifndef __PERRO_H_
#define __PERRO_H_

#include "Animal.hpp"

class Perro : public Animal {
public:
    //PRE:
    //POST: Construye un Animal de tipo Perro.
    Perro(string nombre, int edad, string tamanio, char especie, string personalidad);
    //PRE:
    //POST: Ensucia al Perro dependiendo su personalidad.
    void ensuciar();
    //PRE:
    //POST: Pone la higiene del Perro en 100.
    void duchar();
    //PRE:
    //POST: Pone el hambre de un Perro en 0 e imprime que comio Huesos con su nombre.
    void alimentar();
};

#endif//__PERRO_H_