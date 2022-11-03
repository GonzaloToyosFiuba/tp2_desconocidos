#ifndef __CABALLO_H_
#define __CABALLO_H_

#include "Animal.hpp"

class Caballo : public Animal {
public:

    Caballo(string nombre, int edad, string tamanio, char especie, string personalidad);

    void ensuciar();

    void duchar();

    void alimentar();

};



#endif // __CABALLO_H_