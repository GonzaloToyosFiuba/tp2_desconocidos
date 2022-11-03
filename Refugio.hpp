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
    Lista<Animal*> mascotas;

public:
    /*
    PRE: -
    POS: crea un Refugio y carga su lista de mascotas con los datos del archivo "mascotas.csv"
    */
    Refugio();

    /*
    PRE: -
    POS: imprime todas las mascotas del refugio con sus datos
    */
    void mostrar_lista_de_mascotas();

    /*
    PRE: -
    POS: le pide los datos al usuario de un nuevo animal y lo agrega a la lista
    */
    void rescatar_animal();

    /*
    PRE: -
    POS: guarda la lista de mascotas en el archivo "mascotas.csv"
    */
    void guardar();

    /*
    PRE: -
    POS: imprime los datos del animal si lo encuentra en la lista
    */
    void buscar_animal();

    /*
    PRE: -
    POS: pregunta si se quiere cuidar a todos los animales o elegir individualmente hasta que se quiera salir
    */
    void cuidar_animal();

    /*
    PRE: -
    POS: adopta un animal y lo saca de la lista
    */
    void adoptar_animal();

    /*
    PRE: -
    POS: reduce la higiene y aumenta el hambre de todos los animales cada vez que se elija alguna 
         opción del menú principal
    */
    void actualizar_valores();

    /*
    PRE: -
    POS: destruye al refugio y a sus animales
    */
    ~Refugio();

private:
    /*
    PRE: la especie de la mascota debe ser una válida para el refugio
    POS: agrega una mascota a la lista con su respectiva especie
    */
    void agregar_mascota_a_la_lista(Datos_mascota mascota);

    /*
    PRE: -
    POS: pide un nombre al usuario hasta que ingrese uno no repetido o quiera salir y lo devuelve
    */
    string pedir_nombre();

    /*
    PRE: -
    POS: pide una edad al usuario hasta que ingrese una válida y la devuelve
    */
    int pedir_edad();

    /*
    PRE: -
    POS: pide un tamanio al usuario hasta que ingrese uno válido y lo devuelve
    */
    string pedir_tamanio();

    /*
    PRE: -
    POS: pide una especie al usuario hasta que ingrese una válida y la devuelve
    */
    char pedir_especie();

    /*
    PRE: -
    POS: devuelve el caracter de la especie o un error si esta no está declarada
    */
    char determinar_especie(string especie);

    /*
    PRE: -
    POS: true si la especie es una de las especies válidas en el refugio, false en otro caso
    */
    bool es_especie_valida(string especie);

    /*
    PRE: -
    POS: pide una personalidad al usuario hasta que ingrese una válida y la devuelve
    */
    string pedir_personalidad();

    /*
    PRE: -
    POS: true si el nombre ya está en el refugio
    */
    bool es_nombre_repetido(string nombre);

    /*
    PRE: -
    POS: true si tamanio es uno de los tamanios válidos en el refugio, false en otro caso
    */
    bool tamanio_es_valido(string tamanio);

    /*
    PRE: -
    POS: true si personalidad es una de las personalidades válidas en el refugio, false en otro caso
    */
    bool personalidad_es_valida(string personalidad);

    /*
    PRE: el archivo debe tener el siguiente formato: nombre,edad,tamaño,especie,personalidad
    POS: carga el refugio con los animales del archivo mascotas.csv
    */
    void leer_datos();

    /*
    PRE: -
    POS: procesa la opción del menú para cuidar al animal según opcion
    */
    void procesar_opcion_cuidar_animal(int opcion);

    /*
    PRE: -
    POS: alimenta a todos los animales del refugio
    */
    void alimentar_a_todos();

    /*
    PRE: -
    POS: ducha a todos los animales del refugio
    */
    void duchar_a_todos();

    /*
    PRE: -
    POS: muestra el menú para cuidar el animal y pide una opción
    */
    void pedir_opcion_cuidar_animal(int &opcion);

    /*
    PRE: -
    POS: alimenta/ducha/saltea un animal individualmente
    */
    void elegir_individualmente();

    /*
    PRE: -
    POS: muestra la información de un animal a la vez y pregunta si se lo quiere alimentar/duchar/saltear
    */
    void pedir_opcion_cuidar_individual(int &opcion);

    /*
    PRE: -
    POS: procesa la opción del menú para cuidar al animal individualmente según opcion
    */
    void procesar_opcion_cuidar_individual(int opcion, Animal* mascota);

    /*
    PRE: -
    POS: pide un espacio hasta que se ingrese uno mayor que 0
    */
    void pedir_espacio_disponible(int &espacio);

    /*
    PRE: -
    POS: muestra los animales que puede adoptar el usuario según su espacio disponible
    */
    void mostrar_animales_adoptables(int espacio, Lista<int>* indices_animales_adoptables);

    /*
    PRE: -
    POS: pide el índice del animal que se quiere adoptar hasta que se ingrese un índice válido
    */
    void pedir_animal_a_adoptar(Lista<int>* indices_animales_adoptables, int &indice);

    /*
    PRE: -
    POS: true si el animal está entre los que se puden adoptar, false en otro caso
    */
    bool es_animal_adoptable(Lista<int>* indices_animales_adoptables, int indice);

};

#endif