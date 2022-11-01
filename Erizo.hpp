#ifndef __ERIZO_H_
#define __ERIZO_H_

#include "Animal.hpp"

class Erizo : public Animal {

private:
public:
    Erizo(string nombre, int edad, string tamanio, char especie, string personalidad);

    void ensuciar();

    void dar_hambre();

    void duchar();

    void alimentar();
};

#endif // __ERIZO_H_