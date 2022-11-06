#include "Refugio.hpp"
#include "Caballo.hpp"
#include "Gato.hpp"
#include "Perro.hpp"
#include "Roedor.hpp"
#include "Conejo.hpp"
#include "Erizo.hpp"
#include "Lagartija.hpp"
#include "constantes.hpp"

const string PATH = "mascotas.csv";

Refugio::Refugio(){
    this -> leer_datos();
}


void Refugio::leer_datos(){

    ifstream mis_mascotas(PATH);

    if(!mis_mascotas.is_open()) {
        cout << "Error al abrir el archivo." << PATH << " ." << endl << endl;
        return;
    }

    if(mis_mascotas.eof()){
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

void Refugio::mostrar_lista_de_mascotas(){
    if(this->mascotas.esta_vacio()){
        cout << "El refugio está vacío.";
        return;
    }

    cout<< "MASCOTAS DEL REFUGIO:" << endl << endl;
    
    mascotas.iniciar_cursor();

    while (mascotas.hay_siguiente_cursor()){
        mascotas.obtener_cursor()->mostrar_informacion();        
        cout << "--------------------------" << endl << endl;
    }
    
}

void Refugio::rescatar_animal(){
    Datos_mascota mascota;

    mascota.nombre = pedir_nombre();
    
    if(mascota.nombre == VOLVER_V1){
        cout << "Volviedo al menú" << endl << endl;
        return;
    }
    
    mascota.edad = pedir_edad();
    mascota.tamanio = pedir_tamanio();
    mascota.especie = pedir_especie();
    mascota.personalidad = pedir_personalidad();

    this->agregar_mascota_a_la_lista(mascota);
}

string Refugio::pedir_nombre(){
    string nombre;

    cout << "Ingrese el nombre del animal: ";
    getline(cin >> ws, nombre);
    cout << endl;

    while (es_nombre_repetido(nombre) && nombre != VOLVER_V1 ){
        
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

    while (edad < MIN_EDAD || edad > MAX_EDAD ){
        cout << "Reingrese la edad:" << endl;
        cout << "Edad: ";
        cin >> edad;
    }
    
    return edad;
}

string Refugio::pedir_tamanio(){
    string tamanio;

    cout << endl << "Ingrese el tamaño del animal (respetar minúsculas)." << endl;
    cout << "Los tamaños válidos son: diminuto, pequeño, mediano, grande y gigante." << endl;
    cout << "Tamaño: ";
    cin >> tamanio;

    while (!tamanio_es_valido(tamanio)){
        cout << endl << "Los tamaños válidos son: diminuto, pequeño, mediano, grande y gigante." << endl;
        cout << "Ingrese un tamaño válido: " ;
        cin >> tamanio;
    }

    return tamanio;
}

string Refugio::pedir_personalidad(){
    string personalidad;

    cout << endl << "Ingrese la personalidad del animal (respetar minúsculas).";
    cout << "Las personalidades válidas son: dormilon, jugueton, sociable, travieso." << endl;
    cout << "Personalidad: ";
    cin >> personalidad;

    while(!personalidad_es_valida(personalidad)){
        cout << "Las personalidades válidas son: dormilon, jugueton, sociable, travieso." << endl;
        cout << "Ingrese una personalidad válida: ";
        cin >> personalidad;
    }

    return personalidad;
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

bool Refugio::tamanio_es_valido(string tamanio){
    return (tamanio == TAMANIOS[POSICION_DIMINUTO] || tamanio == TAMANIOS[POSICION_PEQUENIO] || tamanio == TAMANIOS[POSICION_MEDIANO] ||
            tamanio == TAMANIOS[POSICION_GRANDE] || tamanio == TAMANIOS[POSICION_GIGANTE]);
}

string convertir_a_mayuscula(string palabra){
    for (int i = 0; i < (int)palabra.length(); i++){
        palabra[i] = (char)toupper(palabra[i]);
    }
    return palabra;
}

bool Refugio::es_especie_valida(string especie){
    especie = convertir_a_mayuscula(especie);
    return (especie == NOMBRES_ESPECIES[POSICION_PERRO] || especie == NOMBRES_ESPECIES[POSICION_GATO] || especie == NOMBRES_ESPECIES[POSICION_CABALLO] || 
            especie == NOMBRES_ESPECIES[POSICION_ROEDOR] || especie == NOMBRES_ESPECIES[POSICION_CONEJO] || especie == NOMBRES_ESPECIES[POSICION_ERIZO] ||
            especie == NOMBRES_ESPECIES[POSICION_LAGARTIJA]);
}

char Refugio::determinar_especie(string especie){
    if (es_especie_valida(especie)){
        if(especie == NOMBRES_ESPECIES[POSICION_CONEJO]){
            return CONEJO;
        }
        return (char)toupper(especie[0]);
    } else {
        return LETRA_ERROR;
    }
}

char Refugio::pedir_especie(){
    string especie;

    cout << endl << "Ingrese la especie del animal: " ;
    cout << "Las especies válidas son: Perro, Gato, Caballo, Roedor, Conejo, Erizo, Lagartija." << endl;
    cout << "Especie: ";
    cin >> especie;

    char especie_letra = determinar_especie(especie);

    while (especie_letra == LETRA_ERROR){
        cout << "Las especies válidas son: Perro, Gato, Caballo, Roedor, Conejo, Erizo, Lagartija." << endl;
        cout << "Ingrese una especie válida: ";
        cin >> especie;
        especie_letra = determinar_especie(especie);
    }

    return especie_letra;
}

bool Refugio::personalidad_es_valida(string personalidad){
    return(personalidad == PERSONALIDADES[POSICION_DORMILON] || personalidad == PERSONALIDADES[POSICION_JUGUETON] ||
           personalidad == PERSONALIDADES[POSICION_SOCIABLE] || personalidad == PERSONALIDADES[POSICION_TRAVIESO]);
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

void Refugio::guardar(){
    this->mascotas.iniciar_cursor();

    ofstream archivoMascotas(PATH);
    
    while (this->mascotas.hay_siguiente_cursor()) {
        //cout << this->mascotas.obtener_cursor()->obtener_informacion_a_guardar();
        archivoMascotas << this->mascotas.obtener_cursor()->obtener_informacion_a_guardar() << endl;
    }
    
    archivoMascotas.close();
}

Refugio::~Refugio(){
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
    cout << endl << "¿Qué desea hacer con la mascota?" << endl;
    cout << "1) Duchar mascota" << endl;
    cout << "2) Alimentar mascota." << endl;
    cout << "3) Saltear" << endl;
    cout << "Opción: ";
    cin >> opcion;

    while(opcion < DUCHAR || opcion > SALTEAR){
        cout << endl << "Ingresar una opción válida." << endl;
        cout << "1) Duchar mascota" << endl;
        cout << "2) Alimentar mascota." << endl;
        cout << "3) Saltear" << endl;
        cout << "Opción: ";
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
    cout << "Opción: ";
    cin >> opcion;

    while(opcion < ELEGIR_INDIVIDUALMENTE || opcion > SALIR){
        cout << "Ingresar una opción válida." << endl;
        cout << "1) Elegir individualmente." << endl;
        cout << "2) Alimentar a todos." << endl;
        cout << "3) Bañar a todos." << endl;
        cout << "4) Salir." << endl;
        cout << "Opción: ";
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

void Refugio::pedir_espacio_disponible(int &espacio){
    cout << "Ingresar espacio disponible en casa (en metros cuadrados). " << endl;
    cout << "Espacio: ";
    cin >> espacio;

    while(espacio <= 0){
        cout << "Ingresar un espacio válido." << endl;
        cout << "Ingresar espacio disponible en casa (en metros cuadrados)." << endl;
        cout << "Espacio: ";
        cin >> espacio;
    }
}

void Refugio::mostrar_animales_adoptables(int espacio , Lista<int>* indices_animales_adoptables){
    int indice = 1;
    int posicion = 1;
    Animal* mascota_aux;
    this->mascotas.iniciar_cursor();

    while (this->mascotas.hay_siguiente_cursor()){
        mascota_aux = this->mascotas.obtener_cursor();

        if (mascota_aux->se_puede_adoptar(espacio)){
            cout << "Mascota N° " << indice << endl;
            mascota_aux->mostrar_informacion_general();
            cout << "-------------------------" << endl;
            indices_animales_adoptables->alta(indice, posicion);
            posicion ++;
        }
        indice ++;
    }

    if(indices_animales_adoptables->esta_vacio()){
        cout << "No hay animales disponibles para su espacio actual." << endl;
    }
}

bool Refugio::es_animal_adoptable(Lista<int>* indices_animales_adoptables, int indice){
    bool se_puede_adoptar = false;

    indices_animales_adoptables->iniciar_cursor();

    while (indices_animales_adoptables->hay_siguiente_cursor() && !se_puede_adoptar){
        if (indices_animales_adoptables->obtener_cursor() == indice){
            se_puede_adoptar = true;
        }
    }
    
    return se_puede_adoptar;
}

void Refugio::pedir_animal_a_adoptar(Lista<int>* indices_animales_adoptables, int &indice){
    if(indices_animales_adoptables->esta_vacio()){
        indice = VOLVER_V2;
        return;
    }

    cout << "Ingresar el numero de la mascota que quiere adoptar (ingrese '-1' para volver al menu). " << endl;
    cout << "Numero: ";
    cin >> indice;

    while (indice != VOLVER_V2 && !this->es_animal_adoptable(indices_animales_adoptables, indice)){
        cout << "Animal fuera de la lista de los que puede adoptar" << endl;
        cout << "Ingresar el numero de la mascota que quiere adoptar (ingrese '-1' para volver al menu). " << endl;
        cout << "Numero: ";
        cin >> indice;
    }
    
    
}

void Refugio::adoptar_animal(){
    int espacio;
    int indice = VOLVER_V2;
    Lista<int> *indices_animales_adoptables = new Lista<int>;

    this->pedir_espacio_disponible(espacio);
    this->mostrar_animales_adoptables(espacio, indices_animales_adoptables);
    this->pedir_animal_a_adoptar(indices_animales_adoptables,indice);
    
    if (indice != VOLVER_V2){
        delete this->mascotas.consulta(indice);
        this->mascotas.baja(indice);
    }

    delete indices_animales_adoptables;
}

void Refugio::actualizar_valores(){
    this->mascotas.iniciar_cursor();

    Animal* mascota_aux;

    while(this->mascotas.hay_siguiente_cursor()){
        mascota_aux = this->mascotas.obtener_cursor();

        mascota_aux->ensuciar();
        mascota_aux->dar_hambre();
    }
}