#include "Refugio.hpp"
#include "Caballo.hpp"
#include "Gato.hpp"
#include "Perro.hpp"

const string PATH = "mascotas.csv";


Refugio::Refugio(){
    this -> leer_datos();
}

void Refugio::leer_datos(){

    ifstream mis_mascotas(PATH);

    if(!mis_mascotas.is_open()) {
        cout << "Error al abrir el archivo " << PATH << " ." << endl << endl;
        return;
    }

    Datos_mascota mascota;
    string lectura;

    while (getline(mis_mascotas, lectura, ',')) {
        mascota.nombre = lectura;
        getline(mis_mascotas, lectura, ',');
        mascota.edad = stoi(lectura);
        getline(mis_mascotas, lectura, ',');
        mascota.tamanio = lectura;
        getline(mis_mascotas, lectura, ',');
        mascota.especie = lectura[0];
        getline(mis_mascotas, lectura);
        mascota.personalidad = lectura;

        this -> agregar_mascota_a_la_lista(mascota);
    }

    mis_mascotas.close();
}

void Refugio::agregar_mascota_a_la_lista(Datos_mascota mascota){
    Animal* mascota_aux;

    if(mascota.especie == PERRO){
        mascota_aux = new Perro(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);
    } else if (mascota.especie == GATO) {
        mascota_aux = new Gato(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);
    } else if (mascota.especie == CABALLO) {
        mascota_aux = new Caballo(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else if (mascota.especie == ROEDOR) {
        mascota_aux = new Roedor(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else if (mascota.especie == CONEJO) {
        mascota_aux = new Conejo(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else if (mascota.especie == ERIZO) {
        mascota_aux = new Erizo(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else {//lagartija
        mascota_aux = new Lagartija(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    }

    this -> mascotas.alta(mascota_aux, this -> mascotas.obtener_cantidad() + 1);
}