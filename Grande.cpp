#include "Grande.hpp"

Grande::Grande(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Grande::es_espacio_adecuado(int espacio){
    return (espacio >= MIN_GRANDE);
}