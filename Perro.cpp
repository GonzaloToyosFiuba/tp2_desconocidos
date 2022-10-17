#include "Perro.hpp"
#include "constantes.hpp"

Perro::Perro(string nombre, int edad, string tamanio, char especie, string personalidad) {
    
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = HUESOS;

    this->asignar_espacios();
}