#ifndef __CABALLO_H_
#define __CABALLO_H_

#include "Animal.hpp"

class Caballo : public Animal {
public:
    //PRE:
    //POST: Construye un Animal de tipo Caballo
    Caballo(string nombre, int edad, string tamanio, char especie, string personalidad);

    //PRE:
    //POST: Ensucia al Caballo dependiendo su personalidad
    void ensuciar();
    //PRE:
    //POST: Pone la higiene del Caballo en 100.
    void duchar();
    //PRE:
    //POST: Pone el hambre del Caballo en 0 e Imprime que comio manzanas con su nombre.
    void alimentar();

};



#endif // __CABALLO_H_