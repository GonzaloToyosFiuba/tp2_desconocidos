#include "Animal.hpp"
#include "constantes.hpp"
#include <iostream>

using namespace std;

Animal::Animal() {
    nombre = VACIO;
    edad = 0;
    tamanio = VACIO;
    especie = ' ';
    personalidad = VACIO;
    hambre = MIN_HAMBRE;
    higiene = MAX_HIGIENE;
    espacio_minimo = INFINITO;
    espacio_maximo = 0;
    alimento = VACIO;
}

void Animal::asignar_nombre(string nombre) {
    this->nombre = nombre;
}

string Animal::obtener_nombre() {
    return nombre;
}

void Animal::asignar_edad(int edad) {
    this->edad = edad;
}

int Animal::obtener_edad() {
    return edad;
}

void Animal::asignar_tamanio(string tamanio) {
    this->tamanio = tamanio;
    asignar_espacios();
}

string Animal::obtener_tamanio() {
    return tamanio;
}

void Animal::asignar_especie(char especie) {
    this->especie = especie;
}

char Animal::obtener_especie() {
    return especie;
}

void Animal::asignar_personalidad(string personalidad) {
    this->personalidad = personalidad;
}

string Animal::obtener_personalidad() {
    return personalidad;
}

void Animal::dar_hambre() {

    if(personalidad == DORMILON) {
        hambre += HAMBRE/2;
    }
    else if (personalidad == JUGUETON) {
        hambre += 2*HAMBRE;
    }
    else {
        hambre += HAMBRE;
    }
}

void Animal::alimentar() {
    hambre = MIN_HAMBRE;
    cout << nombre << " comio " << alimento << " y sacio su hambre." << endl;
}

int Animal::obtener_hambre() {
    return hambre;
}

void Animal::ensuciar() {

    if (personalidad == SOCIABLE) {
        higiene -= SUCIEDAD/2;
    }
    else if (personalidad == TRAVIESO) {
        higiene -= 2*SUCIEDAD;
    }
    else {
        higiene -= SUCIEDAD;
    }    
}

void Animal::duchar() {
    higiene = MAX_HIGIENE;
}

int Animal::obtener_higiene() {
    return higiene;
}

void Animal::asignar_espacios() {

    if (tamanio == DIMINUTO) {

        espacio_minimo = 0;
        espacio_maximo = MAX_DIMINUTO;
    }
    else if (tamanio == PEQUENIO) {

        espacio_minimo = 0;
        espacio_maximo = MAX_PEQUENIO;
    }
    else if (tamanio == MEDIANO) {

        espacio_minimo = MIN_MEDIANO;
        espacio_maximo = INFINITO;
    }
    else if (tamanio == GRANDE) {

        espacio_minimo = MIN_GRANDE;
        espacio_maximo = INFINITO;
    }
    else if (tamanio == GIGANTE) {

        espacio_minimo = MIN_GIGANTE;
        espacio_maximo = INFINITO;
    }
    
}