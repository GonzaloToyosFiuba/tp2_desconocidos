#include "Mediano.hpp"

Mediano::Mediano(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Mediano::se_puede_adoptar(int espacio){
    return (espacio >= 10);
}