#include <iostream>

#include "Refugio.hpp"
#include "menu.hpp"

using namespace std;


int main(){
    Refugio* refugio = new Refugio;
    
    int estado = INICIO;

    while (estado != SALIR) {
        aplicacion(refugio, estado);
    }

    delete refugio;
    
    return 0;
}
