#ifndef __ERIZO_H_
#define __ERIZO_H_

#include "Animal.hpp"

class Erizo : public Animal {
public:
    //PRE:
    //POST: Construye un Animal de tipo Erizo.
    Erizo(string nombre, int edad, string tamanio, char especie, string personalidad);
    //PRE:
    //POST: Ensucia al Erizo dependiendo su personalidad.
    void ensuciar();
    //PRE:
    //POST: Pone la higiene del Erizo en 100.
    void duchar();
    //PRE:
    //POST: Pone el hambre de un Erizo en 0 e Imprime que comio Insectos con su nombre.
    void alimentar();
};

#endif // __ERIZO_H_