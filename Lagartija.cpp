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
    this->alimento = INSECTOS;
}

void Lagartija::duchar() {
    cout << nombre << "no requiere ducha por ser una lagartija";
}

void Lagartija::ensuciar() {
    cout << "Las lagartijas no se ensucian." << endl;
}