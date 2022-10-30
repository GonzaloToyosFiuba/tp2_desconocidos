#ifndef __PERSONALIDAD_H__
#define __PERSONALIDAD_H__

#include<iostream>

using namespace std;

class Personalidad
{
protected:
    string tipo_personalidad;
public:
    virtual int perdida_de_hambre(int perdida_hambre) = 0;
    virtual int perdida_de_higiene(int perdida_higiene) = 0;
    string obtener_tipo_de_personalidad();
    virtual ~Personalidad() = default;
};

#endif // __PERSONALIDAD_H__