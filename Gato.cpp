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
    this->alimento = ALIMENTOS[POSICION_ATUN];
}

void Gato::duchar() {

    cout << this->nombre << " no necesita ducharse por ser un gato" << endl;
}

void Gato::ensuciar() {
    cout << "Los gatos no se ensucian." << endl;
}



void Gato::alimentar() {
    this->hambre = MIN_HAMBRE;
    cout << this->nombre << " comio " << this->alimento << " y sacio su hambre." << endl;
}