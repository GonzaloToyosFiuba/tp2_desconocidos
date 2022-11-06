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

void Animal::dar_hambre() {
    if(this->hambre < MAX_HAMBRE){
        this->hambre += this->personalidad->perdida_de_hambre(HAMBRE);
    }    
}

void Animal::asignar_tamanio(string tamanio) {
    if(tamanio == TAMANIOS[POSICION_GIGANTE]){
        this->tamanio = new Gigante(tamanio);
    } else if(tamanio == TAMANIOS[POSICION_GRANDE]){
        this->tamanio = new Grande(tamanio);
    } else if(tamanio == TAMANIOS[POSICION_MEDIANO]){
        this->tamanio = new Mediano(tamanio);
    } else if(tamanio == TAMANIOS[POSICION_PEQUENIO]){
        this->tamanio = new Pequenio(tamanio);
    } else if(tamanio == TAMANIOS[POSICION_DIMINUTO]){
        this->tamanio = new Diminuto(tamanio);
    }
    
}

void Animal::mostrar_informacion(){
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Tamaño: " << this->tamanio->obtener_tipo_de_tamanio() << endl;
    cout << "Especie: " << this->definir_especie(this->especie) << endl;
    cout << "Personalidad: " << this->personalidad->obtener_tipo_de_personalidad() << endl;
    cout << "Hambre: " << this->hambre << endl;
    cout << "Higiene: " << this->higiene << endl;
}

void Animal::mostrar_informacion_general(){
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Tamaño: " << this->tamanio->obtener_tipo_de_tamanio() << endl;
    cout << "Especie: " << this->definir_especie(this->especie) << endl;
    cout << "Personalidad: " << this->personalidad->obtener_tipo_de_personalidad() << endl;
}

string Animal::obtener_informacion_a_guardar(){
    return this->nombre + "," + to_string(this->edad) + "," + this->tamanio->obtener_tipo_de_tamanio()
           + "," + this->especie + "," + this->personalidad->obtener_tipo_de_personalidad();
}

void Animal::asignar_personalidad(string personalidad){
    if(personalidad == PERSONALIDADES[POSICION_TRAVIESO]){
        this->personalidad = new Travieso(personalidad);
    } else if(personalidad == PERSONALIDADES[POSICION_JUGUETON]){
        this->personalidad = new Jugueton(personalidad);
    } else if(personalidad == PERSONALIDADES[POSICION_SOCIABLE]){
        this->personalidad = new Sociable(personalidad);
    } else if(personalidad == PERSONALIDADES[POSICION_DORMILON]){
        this->personalidad = new Dormilon(personalidad);
    }
}

bool Animal::se_puede_adoptar(int espacio){
    return this->tamanio->es_espacio_adecuado(espacio);
}

string Animal::definir_especie(char especie) {
    string cadena;

    if(especie == PERRO){
        cadena = NOMBRES_ESPECIES[POSICION_PERRO];
    } else if(especie == GATO){
        cadena = NOMBRES_ESPECIES[POSICION_GATO];
    } else if(especie == CABALLO){
        cadena = NOMBRES_ESPECIES[POSICION_CABALLO];
    } else if(especie == ROEDOR){
        cadena = NOMBRES_ESPECIES[POSICION_ROEDOR];
    } else if(especie == CONEJO){
        cadena = NOMBRES_ESPECIES[POSICION_CONEJO];
    } else if(especie == ERIZO){
        cadena = NOMBRES_ESPECIES[POSICION_ERIZO];
    } else if(especie == LAGARTIJA){
        cadena = NOMBRES_ESPECIES[POSICION_LAGARTIJA];
    }

    return cadena;
}

Animal::~Animal(){
    delete personalidad;
    delete tamanio;
}