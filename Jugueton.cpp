#include "Jugueton.hpp"

Jugueton::Jugueton(string tipo_personalidad){
    this->tipo_personalidad = tipo_personalidad;
}

int Jugueton::perdida_de_hambre(int perdida_hambre){
    return perdida_hambre * 2;
}

int Jugueton::perdida_de_higiene(int perdida_higiene){
    return perdida_higiene;
}