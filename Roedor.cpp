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
    this->alimento = QUESO;
}

void Roedor::duchar(){
    cout << nombre << " no requiere ducha por ser un roedor" << endl;
}

void Roedor::ensuciar() {
    cout << "Los roedores no se ensucian." << endl;
}