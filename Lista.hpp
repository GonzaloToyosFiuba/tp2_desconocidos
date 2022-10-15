#ifndef __LISTA_H__
#define __LISTA_H__

#include "Nodo.hpp"

template<class TIPO>

class Lista
{
private:
    Nodo<TIPO>* primero;
    Nodo<TIPO>* cursor;
    int cantidad;
private:
    Nodo<TIPO>* obtener_nodo(int posicion);
public:
    Lista();
    //*pre :    0 < pos <= cantidad + 1 
    // post: agraga dato a las lista (la primera posicion es la 1)
    void alta(TIPO dato, int posicion);
    
    TIPO consulta(int posicion);

    // post: elimina de la lista
    void baja(int posicion);

    bool esta_vacio();

    int obtener_cantidad();

    bool hay_siguiente_cursor();

    TIPO obtener_cursor();

    void iniciar_cursor();
    
    ~Lista();


};

template<class TIPO>

Lista<TIPO>::Lista(){
    this -> primero = nullptr;
    this -> cantidad = 0;
    this -> cursor = this -> primero;
}

template<class TIPO>

void Lista<TIPO>::alta(TIPO dato, int posicion){
    Nodo<TIPO> *nuevo_nodo = new Nodo<TIPO>(dato);
    Nodo<TIPO> *siguiente = this -> primero;

    if (posicion == 1){
        this -> primero = nuevo_nodo;
    }else{
        Nodo<TIPO> *nodo_anterior = obtener_nodo(posicion - 1);
        siguiente = nodo_anterior -> obtener_siguiente();
        nuevo_nodo -> cambiar_siguiente(siguiente);
        nodo_anterior -> cambiar_siguiente(nuevo_nodo);
    }

    nuevo_nodo->cambiar_siguiente(siguiente);

    this -> cantidad ++;
}

template<class TIPO>

TIPO Lista<TIPO>::consulta(int posicion){
    Nodo<TIPO> *nodo = obtener_nodo(posicion);
    return (nodo -> obtener_dato());
}


template<class TIPO>

void Lista<TIPO>::baja(int posicion){
    Nodo<TIPO> *auxiliar_borrar = primero;
    
    if (posicion == 1){
        this -> primero = this -> primero -> obtener_siguiente();
        delete auxiliar_borrar;
    }else{
        Nodo<TIPO> *nodo_anterior = obtener_nodo(posicion - 1);
        auxiliar_borrar = nodo_anterior->obtener_siguiente();
        nodo_anterior -> cambiar_siguiente(auxiliar_borrar->obtener_siguiente());
        delete auxiliar_borrar;
    }
    this -> cantidad --;
}

template<class TIPO>

bool Lista<TIPO>::esta_vacio(){
    return (cantidad == 0);
}

template<class TIPO>

int Lista<TIPO>::obtener_cantidad(){
    return this -> cantidad;
}

template<class TIPO>

Nodo<TIPO>* Lista<TIPO>::obtener_nodo(int posicion){
    int posicion_actual = 1;
    Nodo<TIPO> *nodo = primero;

    while (posicion_actual != posicion){ // nodo != nullptr
        nodo = nodo->obtener_siguiente();
        posicion_actual ++;
    }
    
    return nodo;
}

template<class TIPO>

bool Lista<TIPO>::hay_siguiente_cursor(){
    return (this->cursor != nullptr);
}

template<class TIPO>

TIPO Lista<TIPO>::obtener_cursor(){
    TIPO dato = this -> cursor -> obtener_dato();
    this -> cursor = this -> cursor -> obtener_siguiente();
    return dato;

}

template<class TIPO>

void Lista<TIPO>::iniciar_cursor(){
    this -> cursor = this -> primero;
}

template<class TIPO>

Lista<TIPO>::~Lista(){
    while (!esta_vacio()){
        baja(1);
    }
    
}

#endif // __LISTA_H__