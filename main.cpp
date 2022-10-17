#include <iostream>

#include"Refugio.hpp"

using namespace std;


int main(){
    Refugio refugio_de_mascotas;
    refugio_de_mascotas.mostrar_lista_de_mascotas();  
    refugio_de_mascotas.rescatar_animal(); 
    refugio_de_mascotas.guardar_y_salir();
    return 0;
}
