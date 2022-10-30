#include "Dormilon.hpp"

Dormilon::Dormilon(string tipo_personalidad){
    this->tipo_personalidad = tipo_personalidad;
}

int Dormilon::perdida_de_hambre(int perdida_hambre){
    return (int)(perdida_hambre * 0.5);
}

int Dormilon::perdida_de_higiene(int perdida_higiene){
    return perdida_higiene;
}