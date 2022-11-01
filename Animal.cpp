#include "Animal.hpp"
#include "constantes.hpp"
#include <iostream>
#include "Travieso.hpp"
#include "Sociable.hpp"
#include "Jugueton.hpp"
#include "Dormilon.hpp"
#include "Gigante.hpp"
#include "Grande.hpp"
#include "Mediano.hpp"
#include "Pequenio.hpp"
#include "Diminuto.hpp"

using namespace std;

string Animal::obtener_nombre() {
    return nombre;
}

int Animal::obtener_edad() {
    return edad;
}

string Animal::obtener_tamanio() {
    return tamanio->obtener_tipo_de_tamanio();
}

char Animal::obtener_especie() {
    return especie;
}


string Animal::obtener_personalidad() {
    return personalidad->obtener_tipo_de_personalidad();
}

int Animal::obtener_hambre() {
    return hambre;
}

int Animal::obtener_higiene() {
    return higiene;
}

void Animal::asignar_tamanio(string tamanio) {
    if(tamanio == "gigante"){
        this->tamanio = new Gigante(tamanio);
    } else if(tamanio == "grande"){
        this->tamanio = new Grande(tamanio);
    } else if(tamanio == "mediano"){
        this->tamanio = new Mediano(tamanio);
    } else if(tamanio == "pequeño"){
        this->tamanio = new Pequenio(tamanio);
    } else if(tamanio == "diminuto"){
        this->tamanio = new Diminuto(tamanio);
    }
    
}

void Animal::mostrar_informacion(){
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Tamaño: " << this->tamanio->obtener_tipo_de_tamanio() << endl;
    cout << "Especie: " << this->especie << endl;
    cout << "Personalidad: " << this->personalidad->obtener_tipo_de_personalidad() << endl;
    cout << "Hambre: " << this->hambre << endl;
    cout << "Higiene: " << this->higiene << endl;
}

void Animal::mostrar_informacion_general(){
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Tamaño: " << this->tamanio->obtener_tipo_de_tamanio() << endl;
    cout << "Especie: " << this->especie << endl;
    cout << "Personalidad: " << this->personalidad->obtener_tipo_de_personalidad() << endl;
}

string Animal::obtener_informacion_a_guardar(){
    return this->obtener_nombre() + "," + to_string(this->obtener_edad()) + "," + this->obtener_tamanio()
           + "," + this->obtener_especie() + "," + this->obtener_personalidad();
}

void Animal::asignar_personalidad(string personalidad){
    if(personalidad == "travieso"){
        this->personalidad = new Travieso(personalidad);
    } else if(personalidad == "jugueton"){
        this->personalidad = new Jugueton(personalidad);
    } else if(personalidad == "sociable"){
        this->personalidad = new Sociable(personalidad);
    } else if(personalidad == "dormilon"){
        this->personalidad = new Dormilon(personalidad);
    }
}

bool Animal::se_puede_adoptar(int espacio){
    return this->tamanio->se_puede_adoptar(espacio);
}

Animal::~Animal(){
    delete personalidad;
    delete tamanio;
}