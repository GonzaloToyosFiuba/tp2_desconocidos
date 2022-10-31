#include "Erizo.hpp"
#include "constantes.hpp"

Erizo::Erizo(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->asignar_tamanio(tamanio);
    this->especie = especie;
    this->asignar_personalidad(personalidad);
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = INSECTOS;
}

void Erizo::ensuciar() {
    if(this->higiene > MIN_HIGIENE){
        this->higiene -= this->personalidad->perdida_de_higiene(SUCIEDAD);
    }
}