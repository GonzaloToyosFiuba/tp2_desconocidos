#ifndef __GATO_H_
#define __GATO_H_

#include "Animal.hpp"

class Gato : public Animal {
public:
  
    Gato(string nombre, int edad, string tamanio, char especie, string personalidad);

    void duchar();

    void ensuciar();

    void alimentar();

};

#endif // __GATO_H_

