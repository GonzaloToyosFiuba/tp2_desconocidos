#include "Travieso.hpp"

Travieso::Travieso(string tipo_personalidad){
    this->tipo_personalidad = tipo_personalidad;
}

int Travieso::perdida_de_hambre(int perdida_hambre){
    return perdida_hambre;
}

int Travieso::perdida_de_higiene(int perdida_higiene){
    return (int)(perdida_higiene * 2);
}