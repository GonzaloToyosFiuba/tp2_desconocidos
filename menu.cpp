#include "menu.hpp"

/*
PRE: -
POS: imprime el menú de opciones
*/
void mostrarMenu(){
    cout << "MENÚ PRINCIPAL " << endl;
    cout << "1. Listar animales" << endl;
    cout << "2. Rescatar animal" << endl;
    cout << "3. Buscar animal" << endl;
    cout << "4. Cuidar animales" << endl;
    cout << "5. Adoptar animal" << endl;
    cout << "6. Guardar y salir" << endl;
}

int preguntar_opcion_usuario(){
    int opcion;
    do {
        cout << "Ingresá una opción" << endl;
        cin >> opcion;
    } while (opcion < INICIO || opcion > GUARDAR_Y_SALIR);

    return opcion;
}

void aplicacion(Refugio* mi_refugio, int &estado){
    switch (estado) {
        case INICIO:
            mostrarMenu();
            estado = preguntar_opcion_usuario();
            mi_refugio->actualizar_valores();
        break;

        case LISTAR_ANIMALES:
            mi_refugio->mostrar_lista_de_mascotas();
            estado = INICIO;
        break;

        case RESCATAR_ANIMAL:
            mi_refugio->rescatar_animal();
            estado = INICIO;
        break;

        case BUSCAR_ANIMAL:
            mi_refugio->buscar_animal();
            estado = INICIO;
        break;
    
        case CUIDAR_ANIMALES:
            mi_refugio->cuidar_animal();
            estado = INICIO;
        break;
    
        case ADOPTAR_ANIMAL:
            mi_refugio->adoptar_animal();
            estado = INICIO;
        break;
    
        case GUARDAR_Y_SALIR:
            mi_refugio->guardar();
        break;
    
        default:
            estado = INICIO;
        break;
    }
}