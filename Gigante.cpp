#include "Gigante.hpp"

Gigante::Gigante(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Gigante::es_espacio_adecuado(int espacio){
    return (espacio >= MIN_GIGANTE);
}