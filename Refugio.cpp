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
    }/*0 else if (mascota.especie == ROEDOR) {
        mascota_aux = new Roedor(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else if (mascota.especie == CONEJO) {
        mascota_aux = new Conejo(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else if (mascota.especie == ERIZO) {
        mascota_aux = new Erizo(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    } else {//lagartija
        mascota_aux = new Lagartija(mascota.nombre, mascota.edad, mascota.tamanio, mascota.especie, mascota.personalidad);        
    }
    */
    this -> mascotas.alta(mascota_aux, this -> mascotas.obtener_cantidad() + 1);
}

void Refugio::mostrar_lista_de_mascotas(){    
    cout<< "MASCOTAS DEL REGUGIO:" << endl << endl;
    
    mascotas.iniciar_cursor();

    while (mascotas.hay_siguiente_cursor()){
        mascotas.obtener_cursor()->mostrar_informacion();        
        cout << "--------------------------" << endl << endl;
    }
    
}

void Refugio::rescatar_animal(){
    Datos_mascota mascota;

    mascota.nombre = pedir_nombre();
    
    if(mascota.nombre == "*"){
        cout << "Volviedo al Menu" << endl << endl;
        return;
    }
    
    mascota.edad = pedir_edad();
    //mascota.tamanio = pedir_tamanio();
    //mascota.especie = pedir_especie();
    //mascota.personalidad = pedir_personalidad();

}

string Refugio::pedir_nombre(){
    string nombre;

    cout << "Ingrese el nombre del animal: ";
    getline(cin >> ws, nombre);
    cout << endl;

    while (es_nombre_repetido(nombre) && nombre != "*" ){
        
        cout << "El nombre existe, que desea hacer:" << endl;  
        cout << '\t' << "INGRESE:" << endl;
        cout << '\t' << "   -> (*) Para salir."<< endl;
        cout << '\t' << "   ->  Otro nombre, no repetido, para seguir." << endl;

        cout << "Nombre: ";
        getline(cin >> ws, nombre);
        cout << endl;
    }
    
    return nombre;
}

int Refugio::pedir_edad(){
    int edad;

    cout << "Ingrese la edad del animal: " ;
    cin >> edad;
    cout << endl;

    while (edad < 0 ){
        cout << "Reingrese la edad:" << endl;
        cout << "Edad: ";
        cin >> edad;
    }
    
    return edad;
}

bool Refugio::es_nombre_repetido(string nombre){
    bool es_repetido = false;

    this->mascotas.iniciar_cursor();

    while ( this->mascotas.hay_siguiente_cursor() && !es_repetido){

        if(nombre == mascotas.obtener_cursor()->obtener_nombre()){
            es_repetido = true;
        }
    }
    return es_repetido;
}

void Refugio::buscar_animal(){
    string nombre;
    bool encontrado = false;
    Animal *mascota_aux;

    
    cout << "Ingresar nombre del animal buscado: ";
    getline(cin >> ws, nombre);
    cout << endl;

    this->mascotas.iniciar_cursor();


    while (mascotas.hay_siguiente_cursor() && !encontrado){
        mascota_aux = mascotas.obtener_cursor();

        if(mascota_aux->obtener_nombre() == nombre){
            mascota_aux->mostrar_informacion();
            encontrado = true;
        }
    }

    if(!encontrado){
        cout << "No se encontró a la mascota." << endl;
        cout << "Volviendo al menú..." << endl;
    }
}

void Refugio::guardar_y_salir(){

    this->mascotas.iniciar_cursor();

    while (this->mascotas.hay_siguiente_cursor()){
         
        delete this->mascotas.obtener_cursor();

    }

}

enum Opciones_menu_principal{
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_A_TODOS,
    DUCHAR_A_TODOS,
    SALIR
};

enum Opciones_menu_individual{
    DUCHAR = 1,
    ALIMENTAR,
    SALTEAR
};

void Refugio::alimentar_a_todos(){
    this->mascotas.iniciar_cursor();

    while (this->mascotas.hay_siguiente_cursor()){
        this->mascotas.obtener_cursor()->alimentar();
    }
}

void Refugio::duchar_a_todos(){
    this->mascotas.iniciar_cursor();

    while (this->mascotas.hay_siguiente_cursor()){
        this->mascotas.obtener_cursor()->duchar();
    }
}

void Refugio::pedir_opcion_cuidar_individual(int &opcion){
    cout << "¿Qué desea hacer con la mascota?" << endl;
    cout << "1) Duchar mascota" << endl;
    cout << "2) Alimentar mascota." << endl;
    cout << "3) Saltear" << endl;
    cin >> opcion;

    while(opcion < DUCHAR || opcion > SALTEAR){
        cout << "Ingresar una opción válida." << endl;
        cout << "1) Duchar mascota" << endl;
        cout << "2) Alimentar mascota." << endl;
        cout << "3) Saltear" << endl;
        cin >> opcion;
    }
}

void Refugio::procesar_opcion_cuidar_individual(int opcion, Animal* mascota){

    switch (opcion) {
        case DUCHAR:
            mascota->duchar();
        break;

        case ALIMENTAR:
            mascota->alimentar();
        break;
    }
}

void Refugio::elegir_individualmente(){
    Animal* mascota_aux;
    this->mascotas.iniciar_cursor();
    int opcion = -1;

    while (this->mascotas.hay_siguiente_cursor()){
        mascota_aux = this->mascotas.obtener_cursor();
        
        while (opcion != SALTEAR){
            cout << endl;
            mascota_aux->mostrar_informacion();
            this->pedir_opcion_cuidar_individual(opcion);
            this->procesar_opcion_cuidar_individual(opcion, mascota_aux);
        }
        
        opcion = -1;
    }
}

void Refugio::procesar_opcion_cuidar_animal(int opcion){
    switch (opcion) {
        case ELEGIR_INDIVIDUALMENTE:
            this->elegir_individualmente();
        break;

        case ALIMENTAR_A_TODOS:
            this->alimentar_a_todos();
        break;

        case DUCHAR_A_TODOS:
            this->duchar_a_todos();
        break;
    }
}

void Refugio::pedir_opcion_cuidar_animal(int &opcion){
    cout << "Ingresar opción: " << endl;
    cout << "1) Elegir individualmente." << endl;
    cout << "2) Alimentar a todos." << endl;
    cout << "3) Bañar a todos." << endl;
    cout << "4) Salir." << endl;
    cin >> opcion;

    while(opcion < ELEGIR_INDIVIDUALMENTE || opcion > SALIR){
        cout << "Ingresar una opción válida." << endl;
        cout << "1) Elegir individualmente." << endl;
        cout << "2) Alimentar a todos." << endl;
        cout << "3) Bañar a todos." << endl;
        cout << "4) Salir." << endl;
        cin >> opcion;
    }
}

void Refugio::cuidar_animal(){
    int opcion = -1;

    while (opcion != SALIR){
        this->pedir_opcion_cuidar_animal(opcion);
        this->procesar_opcion_cuidar_animal(opcion);
    }
}