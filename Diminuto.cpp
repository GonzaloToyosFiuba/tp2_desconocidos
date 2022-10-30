#include "Diminuto.hpp"

Diminuto::Diminuto(string tipo_tamanio){
    this->tipo_tamanio = tipo_tamanio;
}

bool Diminuto::se_puede_adoptar(int espacio){
    return true;
}