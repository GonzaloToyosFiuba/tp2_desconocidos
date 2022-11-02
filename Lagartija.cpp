#include "Lagartija.hpp"
#include "constantes.hpp"

Lagartija::Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->asignar_tamanio(tamanio);
    this->especie = especie;
    this->asignar_personalidad(personalidad);
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = ALIMENTOS[POSICION_INSECTO];
}

void Lagartija::duchar() {
    cout << this->nombre << " no requiere ducha por ser una lagartija" << endl;
}

void Lagartija::ensuciar() {}

void Lagartija::alimentar() {
    this->hambre = MIN_HAMBRE;
    cout << this->nombre << " comió " << this->alimento << " y sació su hambre." << endl;
}