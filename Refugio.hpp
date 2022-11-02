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


class Refugio{

private:
    Lista<Animal*> mascotas;//cambiarlo por la clase animales

public:
    Refugio();

    void mostrar_lista_de_mascotas();

    void rescatar_animal();

    void guardar();

    void buscar_animal();

    void cuidar_animal();

    void adoptar_animal();

    void actualizar_valores();

    ~Refugio();

private:

    void agregar_mascota_a_la_lista(Datos_mascota mascota);

    string pedir_nombre();

    int pedir_edad();

    string pedir_tamanio();

    char pedir_especie();

    char determinar_especie(string especie);

    bool es_especie_valida(string especie);

    string pedir_personalidad();

    bool es_nombre_repetido(string nombre);

    bool tamanio_es_valido(string tamanio);

    bool especie_es_valida(string especie);

    bool personalidad_es_valida(string personalidad);

    void leer_datos();

    void procesar_opcion_cuidar_animal(int opcion);

    void alimentar_a_todos();

    void duchar_a_todos();

    void pedir_opcion_cuidar_animal(int &opcion);

    void elegir_individualmente();

    void pedir_opcion_cuidar_individual(int &opcion);

    void procesar_opcion_cuidar_individual(int opcion, Animal* mascota);

    void pedir_espacio_disponible(int &espacio);

    void mostrar_animales_adoptables(int espacio, Lista<int>* indices_animales_adoptables);

    void pedir_animal_a_adoptar(Lista<int>* indices_animales_adoptables, int &indice);

    bool es_animal_adoptable(Lista<int>* indices_animales_adoptables, int indice);

};

#endif