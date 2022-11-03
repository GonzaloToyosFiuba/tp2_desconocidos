#ifndef __LAGARTIJA_H_
#define __LAGARTIJA_H_

#include "Animal.hpp"

class Lagartija : public Animal {
public:
    //PRE: 0 < edad <= 100
    //POST: Construye un Animal de tipo Lagartija.
    Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad);
    //PRE:
    //POST: Avisa por pantalla que un Lagatija  no se ducha.
    void duchar();
    //PRE:
    //POST: Una Lagartija no se ensucia.
    void ensuciar();
    //PRE:
    //POST: Pone el hambre de una Lagartija en 0 e imprime que comio Insectos con su nombre.
    void alimentar();

};

#endif // __LAGARTIJA_H_