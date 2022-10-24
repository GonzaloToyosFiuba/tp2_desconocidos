#ifndef __REFUGIO_H__
#define __REFUGIO_H__

#include "Lista.hpp"
#include "Animal.hpp"
#include <iostream>
#include <fstream>
using namespace std;

struct Datos_mascota{
    string nombre;
    int edad;
    string tamanio;
    char especie;
    string personalidad;
};

const char PERRO = 'P', GATO = 'G', CABALLO = 'C', ROEDOR = 'R';
const char CONEJO = 'O', ERIZO = 'E', LAGARTIJA = 'L';

class Refugio{

private:
    Lista<Animal*> mascotas;//cambiarlo por la clase animales

public:
    Refugio();

    void mostrar_lista_de_mascotas();

    void rescatar_animal();

    void guardar_y_salir();

    void buscar_animal();

    void cuidar_animal();

private:

    void agregar_mascota_a_la_lista(Datos_mascota mascota);

    string pedir_nombre();

    int pedir_edad();

    string pedir_tamanio();

    char pedir_especie();

    string pedir_personalidad();

    bool es_nombre_repetido(string nombre);

    void leer_datos();

    void procesar_opcion_cuidar_animal(int opcion);

    void alimentar_a_todos();

    void duchar_a_todos();

    void pedir_opcion_cuidar_animal(int &opcion);

    void elegir_individualmente();

    void pedir_opcion_cuidar_individual(int &opcion);

    void procesar_opcion_cuidar_individual(int opcion, Animal* mascota);


};

#endif