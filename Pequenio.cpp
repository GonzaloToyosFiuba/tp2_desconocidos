#include "Pequenio.hpp"

Pequenio::Pequenio(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Pequenio::se_puede_adoptar(int espacio){
    return true;
}