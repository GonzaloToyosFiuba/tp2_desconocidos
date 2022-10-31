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
    //POST: devuelve la edad del animal 
    int obtener_edad();

    //PRE:
    //POST: devuelve el tamanio del animal
    string obtener_tamanio();

    //PRE:
    //POST: devuelve la especie del animal
    char obtener_especie();

    //PRE:
    //POST: devuelve la personalidad del animal
    string obtener_personalidad();

    //PRE:
    //POST: aumenta el hambre del animal segun corresponda
    virtual void dar_hambre();

    //PRE:
    //POST: pone el hambre del animal en 0
    virtual void alimentar();

    //PRE:
    //POST: devuelve el hambre del animal
    int obtener_hambre();

    //PRE:
    //POST: pone la higiene del animal en 100
    virtual void duchar();

    //PRE:
    //POST: reduce la higiene del animal segun corresponda
    virtual void ensuciar() = 0;

    //PRE:
    //POST: devuelve la higiene del animal
    int obtener_higiene();

    void mostrar_informacion();

    void mostrar_informacion_general();

    bool se_puede_adoptar(int espacio);

    string obtener_informacion_a_guardar();

    virtual ~Animal() ;


protected:

    //PRE: tamanio valido
    //POST: asigna los espacios que ocupa un animal segun su tamanio
    void asignar_tamanio(string tamanio);

    void asignar_personalidad(string personalidad);
};


#endif //__ANIMAL_H_