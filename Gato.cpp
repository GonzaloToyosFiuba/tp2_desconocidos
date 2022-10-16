#include "Gato.hpp"
#include "constantes.hpp"
#include <iostream>

using namespace std;

Gato::Gato() {

    nombre = VACIO;
    edad = 0;
    tamanio = VACIO;
    especie = ' ';
    personalidad = VACIO;
    hambre = MIN_HAMBRE;
    higiene = MAX_HIGIENE;
    espacio_minimo = INFINITO;
    espacio_maximo = 0;
    alimento = ATUN;
}

Gato::Gato(string nombre, int edad, string tamanio, char especie, string personalidad) {

    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = ATUN;

    this->asignar_espacios();
}

void Gato::duchar() {

    cout << nombre << " no necesita ducharse por ser un gato" << endl;
}

void Gato::ensuciar() {
    
}