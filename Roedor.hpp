#ifndef __ROEDOR_H_
#define __ROEDOR_H_

#include "Animal.hpp"

class Roedor : public Animal {
public:
    //PRE:
    //POST: Construye un Animal de tipo Roedor.
    Roedor(string nombre, int edad, string tamanio, char especie, string personalidad);
    //PRE:
    //POST: Avisa por pantalla que un Roedor  no se ducha.
    void duchar();
    //PRE:
    //POST: Una Roedor no se ensucia.
    void ensuciar();
    //PRE:
    //POST: Pone el hambre de un Roedor en 0 e imprime que comio queso con su nombre.    
    void alimentar();
};

#endif // __ROEDOR_H_