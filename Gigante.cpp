#include "Gigante.hpp"

Gigante::Gigante(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Gigante::se_puede_adoptar(int espacio){
    return (espacio >= MIN_GIGANTE);
}