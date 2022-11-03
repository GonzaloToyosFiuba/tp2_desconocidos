#include "Mediano.hpp"

Mediano::Mediano(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Mediano::es_espacio_adecuado(int espacio){
    return (espacio >= MIN_MEDIANO);
}