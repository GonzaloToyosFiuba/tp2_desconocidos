#include "Caballo.hpp"
#include "constantes.hpp"

Caballo::Caballo(string nombre, int edad, string tamanio, char especie, string personalidad) {

    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = MANZANAS;

    this->asignar_espacios();
}