#ifndef __CABALLO_H_
#define __CABALLO_H_

#include "Animal.hpp"

class Caballo : public Animal
{
private:
    
public:
    Caballo();

    Caballo(string nombre, int edad, string tamanio, char especie, string personalidad);

};



#endif // __CABALLO_H_