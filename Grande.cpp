#include "Grande.hpp"

Grande::Grande(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Grande::se_puede_adoptar(int espacio){
    return (espacio >= 20);
}