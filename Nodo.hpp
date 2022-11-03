#ifndef __NODO_H__
#define __NODO_H__

template <class TIPO>

class Nodo
{
private:
    TIPO dato;
    Nodo<TIPO> *siguiente;   
public:
    // PRE:
    // POST: Construye un nodo guardando el dato.
    Nodo(TIPO dato);
    // PRE:
    // POST: Designa el siguiente de un Nodo
    void cambiar_siguiente (Nodo<TIPO>* siguiente);
    // PRE:
    // POST: Obtiene el dato de un Nodo    
    TIPO obtener_dato();
    // PRE:
    // POST: Obtiene el Nodo siguiente respecto al Nodo que se le pide.    
    Nodo<TIPO>* obtener_siguiente();
};

template <class TIPO>
Nodo<TIPO>::Nodo(TIPO dato):dato(dato){
    siguiente = nullptr;
}

template <class TIPO>
void Nodo<TIPO>::cambiar_siguiente(Nodo<TIPO>* siguiente){
    this -> siguiente = siguiente;
}

template <class TIPO>
TIPO Nodo<TIPO>::obtener_dato(){
    return this -> dato;
}

template <class TIPO>
Nodo<TIPO>* Nodo<TIPO>::obtener_siguiente(){
    return this -> siguiente;
}

#endif // __NODO_H__
