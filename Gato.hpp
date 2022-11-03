#ifndef __GATO_H_
#define __GATO_H_

#include "Animal.hpp"

class Gato : public Animal {
public:
    //PRE: 0 < edad <= 100
    //POST: Construye un Animal de tipo Gato.
    Gato(string nombre, int edad, string tamanio, char especie, string personalidad);
    //PRE:
    //POST: Avisa por pantalla que un gato no se ducha.
    void duchar();
    //PRE:
    //POST: Un gato no se ensucia.
    void ensuciar();
    //PRE:
    //POST: Pone el hambre de un Gato en 0 e imprime que comio Atun con su nombre.
    void alimentar();

};

#endif // __GATO_H_

