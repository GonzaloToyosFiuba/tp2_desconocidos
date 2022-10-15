#ifndef __NODO_H__
#define __NODO_H__



template <class TIPO>

class Nodo
{
private:
    TIPO dato;
    Nodo<TIPO> *siguiente;   
public:
    Nodo(TIPO dato);
    void cambiar_siguiente (Nodo<TIPO>* siguiente);
    TIPO obtener_dato();
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
