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
    Animal *mascota_aux;
    
    cout<< "MASCOTAS DEL REGUGIO:" << endl << endl;
    
    mascotas.iniciar_cursor();

    while (mascotas.hay_siguiente_cursor()){
        mascota_aux = mascotas.obtener_cursor();

        cout << "Nombre: " << mascota_aux->obtener_nombre() << endl;
        cout << "Edad: " << mascota_aux->obtener_edad() << endl;
        cout << "tamanio: " << mascota_aux->obtener_tamanio() << endl;
        cout << "Especie: " << mascota_aux->obtener_especie() << endl;
        cout << "Personalidad:" << mascota_aux->obtener_personalidad() << endl; 
        cout << "--------------------------" << endl;
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

void Refugio::guardar_y_salir(){

    this->mascotas.iniciar_cursor();

    while (this->mascotas.hay_siguiente_cursor()){
         
        delete this->mascotas.obtener_cursor();

    }

}