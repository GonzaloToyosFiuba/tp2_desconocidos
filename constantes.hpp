#ifndef __CONSTANTES_H_
#define __CONSTANTES_H_

#include <string>

using namespace std;

const int MIN_EDAD = 0;
const int MAX_EDAD = 100;

const int MIN_HAMBRE = 0;
const int MAX_HAMBRE = 100;

const int MIN_HIGIENE = 0;
const int MAX_HIGIENE = 100;

//const int MAX_DIMINUTO = 2;
//const int MAX_PEQUENIO = 10;
const int MIN_MEDIANO = 10;
const int MIN_GRANDE = 20;
const int MIN_GIGANTE = 50;

const char PERRO = 'P';
const char GATO = 'G';
const char CABALLO = 'C';
const char ROEDOR = 'R';
const char CONEJO = 'O';
const char ERIZO = 'E';
const char LAGARTIJA = 'L';

const string VOLVER_V1 = "*";
const int    VOLVER_V2 = -1; 

enum Posiciones_especies{
    POSICION_PERRO,
    POSICION_GATO,
    POSICION_CABALLO,
    POSICION_ROEDOR,
    POSICION_CONEJO,
    POSICION_ERIZO,
    POSICION_LAGARTIJA
};

enum Posiciones_tamanios{
    POSICION_DIMINUTO,
    POSICION_PEQUENIO,
    POSICION_MEDIANO,
    POSICION_GRANDE,
    POSICION_GIGANTE
};

enum Posiciones_personalidades{
    POSICION_DORMILON,
    POSICION_JUGUETON,
    POSICION_SOCIABLE,
    POSICION_TRAVIESO
};

enum Posiciones_alimetos{
    POSICION_HUESOS,
    POSICION_ATUN,
    POSICION_MANZANAS,
    POSICION_QUESO,
    POSICION_LECHUGA,
    POSICION_INSECTO
};

const string NOMBRES_ESPECIES[7] = {"Perro", "Gato", "Caballlo", "Roedor", "Conejo", "Erizo", "Lagartija"};

const string TAMANIOS[5] = {"diminuto", "pequeño", "mediano", "grande" , "gigante"};

const string PERSONALIDADES[4] = {"dormilon", "jugueton", "sociable", "travieso"};

const string ALIMENTOS[6] = {"huesos", "atun", "manzanas", "queso", "lechuga", "insecto"};

const int HAMBRE = 10;
const int SUCIEDAD = 10;

#endif //__CONSTANTES_H_