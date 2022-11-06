#ifndef __ANIMAL_H_
#define __ANIMAL_H_

#include <string>
#include "Personalidad.hpp"
#include "Tamanio.hpp"

using namespace std;

class Animal {

protected:
    string nombre;
    int edad;
    Tamanio* tamanio;
    char especie;
    Personalidad* personalidad;
    int hambre;
    int higiene;
    string alimento;
    
public:

    //PRE:
    //POST: devuelve el nombre del animal
    string obtener_nombre();
    
    //PRE:
    //POST: aumenta el hambre del animal segun corresponda
    void dar_hambre();

    //PRE:
    //POST: pone el hambre del animal en 0
    virtual void alimentar() = 0;

    //PRE:
    //POST: pone la higiene del animal en 100
    virtual void duchar() = 0;

    //PRE:
    //POST: reduce la higiene del animal segun corresponda
    virtual void ensuciar() = 0;

    //PRE:
    //POST: Imprime por pantalla toda la informacion de un animal
    void mostrar_informacion();
    //PRE:
    //POST: Imprime por pantalla solo informacion general de una anima (nombre,edad,especie,personalidad).
    void mostrar_informacion_general();
    //PRE: espacio > 0
    //POST: Devuelve true si es un animal adoptable segun el espacio.
    bool se_puede_adoptar(int espacio);
    //PRE:
    //POST: Devuelve la información que se va a guardar sobre un animal (nombre,edad,especie,personalidad).
    string obtener_informacion_a_guardar();
    //PRE:
    //POST: Destruye animal, sus clases hijas , Tamanio y Personalidad
    virtual ~Animal() ;


protected:

    //PRE: tamanio valido
    //POST: Asigna el tamanio de un animal
    void asignar_tamanio(string tamanio);
    //PRE:
    //POST: Asigana la personalidad de un animal
    void asignar_personalidad(string personalidad);

private:
    //PRE: especie valida
    //POST: Devuelve el nombre completo de la especie. 
    string definir_especie(char especie);
};


#endif //__ANIMAL_H_