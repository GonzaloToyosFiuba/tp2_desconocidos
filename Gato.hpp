#ifndef __GATO_H_
#define __GATO_H_

#include "Animal.hpp"

class Gato : public Animal
{
private:
    
public:
  
    Gato(string nombre, int edad, string tamanio, char especie, string personalidad);

    void duchar();

    void ensuciar();

};

#endif // __GATO_H_

