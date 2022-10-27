#ifndef __ANIMAL_H_
#define __ANIMAL_H_

#include <string>
#include <sstream>

using namespace std;

class Animal {

protected:
    string nombre;
    int edad;
    string tamanio;
    char especie;
    string personalidad;
    int hambre;
    int higiene;
    int espacio_minimo;
    int espacio_maximo;
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
    virtual void ensuciar();

    //PRE:
    //POST: devuelve la higiene del animal
    int obtener_higiene();

    void mostrar_informacion();

    void mostrar_informacion_general();

    bool se_puede_adoptar(int espacio);

    string obtener_informacion_a_guardar();

    virtual ~Animal() = default;


protected:

    //PRE: tamanio valido
    //POST: asigna los espacios que ocupa un animal segun su tamanio
    void asignar_espacios();
};


#endif //__ANIMAL_H_