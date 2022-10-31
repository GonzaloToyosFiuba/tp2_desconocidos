#include "Gato.hpp"
#include "constantes.hpp"
#include <iostream>

using namespace std;


Gato::Gato(string nombre, int edad, string tamanio, char especie, string personalidad) {

    this->nombre = nombre;
    this->edad = edad;
    this->asignar_tamanio(tamanio);
    this->especie = especie;
    this->asignar_personalidad(personalidad);
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = ATUN;
}

void Gato::duchar() {

    cout << nombre << " no necesita ducharse por ser un gato" << endl;
}

void Gato::ensuciar() {
    cout << "Los gatos no se ensucian." << endl;
}