#include "Perro.hpp"
#include "constantes.hpp"

Perro::Perro(string nombre, int edad, string tamanio, char especie, string personalidad) {  
    this->nombre = nombre;
    this->edad = edad;
    this->asignar_tamanio(tamanio);
    this->especie = especie;
    this->asignar_personalidad(personalidad);
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = ALIMENTOS[POSICION_HUESOS];
}

void Perro::ensuciar() {
    if(this->higiene > MIN_HIGIENE){
        this->higiene -= this->personalidad->perdida_de_higiene(SUCIEDAD);
    }
}

void Perro::duchar() {
    this->higiene = MAX_HIGIENE;
    cout << this->nombre << " se ducho y esta libre de suciedad." << endl;
}

void Perro::alimentar() {
    this->hambre = MIN_HAMBRE;
    cout << this->nombre << " comio " << this->alimento << " y sacio su hambre." << endl;
}