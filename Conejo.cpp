#include "Conejo.hpp"
#include "constantes.hpp"

Conejo::Conejo(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->asignar_tamanio(tamanio);
    this->especie = especie;
    this->asignar_personalidad(personalidad);
    this->hambre = MIN_HAMBRE;
    this->higiene = MAX_HIGIENE;
    this->alimento = ALIMENTOS[POSICION_LECHUGA];
}

void Conejo::ensuciar() {
    if(this->higiene > MIN_HIGIENE){
        this->higiene -= this->personalidad->perdida_de_higiene(SUCIEDAD);
    }
}

void Conejo::duchar() {
    this->higiene = MAX_HIGIENE;
    cout << this->nombre << " se duchó y está libre de suciedad." << endl;
}

void Conejo::alimentar() {
    this->hambre = MIN_HAMBRE;
    cout << this->nombre << " comió " << this->alimento << " y sació su hambre." << endl;
}