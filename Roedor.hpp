#ifndef __ROEDOR_H_
#define __ROEDOR_H_

#include "Animal.hpp"

class Roedor : public Animal {
public:
    Roedor(string nombre, int edad, string tamanio, char especie, string personalidad);

    void duchar();

    void ensuciar();

    void dar_hambre();
    
    void alimentar();
};

#endif // __ROEDOR_H_