#include "Sociable.hpp"

Sociable::Sociable(string tipo_personalidad){
    this->tipo_personalidad = tipo_personalidad;
}

int Sociable::perdida_de_hambre(int perdida_hambre){
    return perdida_hambre;
}

int Sociable::perdida_de_higiene(int perdida_higiene){
    return (int)(perdida_higiene * 0.5);
}