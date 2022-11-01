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

void Roedor::ensuciar() {
    cout << "Los roedores no se ensucian." << endl;
}

void Roedor::dar_hambre() {
    if(this->hambre < MAX_HAMBRE){
        this->hambre += this->personalidad->perdida_de_hambre(HAMBRE);
    }    
}

void Roedor::alimentar() {
    this->hambre = MIN_HAMBRE;
    cout << this->nombre << " comio " << this->alimento << " y sacio su hambre." << endl;
}