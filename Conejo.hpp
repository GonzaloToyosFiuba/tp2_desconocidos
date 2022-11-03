#ifndef __CONEJO_H_
#define __CONEJO_H_

#include "Animal.hpp"

class Conejo : public Animal {
public:
    //PRE:
    //POST: Construye un Animal de tipo Conejo.
    Conejo(string nombre, int edad, string tamanio, char especie, string personalidad);
    //PRE:
    //POST: Ensucia al Conejo dependiendo su personalidad.
    void ensuciar();
    //PRE:
    //POST: Pone la higiene del Conejo en 100. 
    void duchar();
    //PRE:
    //POST: Pone el hambre de un Conejo en 0 e Imprime que comio lechuga con su nombre.
    void alimentar();
};

#endif // __CONEJO_H_