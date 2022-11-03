#include "Roedor.hpp"
#include "constantes.hpp"

Roedor::Roedor(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->asignar_tamanio(tamanio);
    this->especie = especie;
    this->asignar_personalidad(personalidad);
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = ALIMENTOS[POSICION_QUESO];
}

void Roedor::duchar(){
    cout << this->nombre << " no requiere ducha por ser un roedor" << endl;
}

void Roedor::ensuciar() {}

void Roedor::alimentar() {
    this->hambre = MIN_HAMBRE;
    cout << this->nombre << " comió " << this->alimento << " y sació su hambre." << endl;
}