#include "cola.h"

// Constructor 
Cola::Cola(){
    frente=nullptr;
    final=nullptr;
}
//destructor
Cola::~Cola(){
    while(!estaVacia()){
        dequeue();
    }
}

bool Cola::estaVacia() const {
    return frente==nullptr;
}
 
void Cola::enqueue(const Llamada& llamada){
    Nodo* nuevo=new Nodo(llamada);
    nuevo->siguiente=nullptr;
    if(estaVacia()){
        frente=nuevo;
        final=nuevo;
    } else {
        final->siguiente=nuevo;
        final=nuevo;
    }
}   

int Cola::tiempoEspera() const{
    int total=0;
    Nodo* actual = Cola::frente;
    while(actual!=nullptr){
        total=total+actual->dato.duracion;
        actual=actual->siguiente;
    }
    return total;
}

void Cola::mostrarCola() const{
    Nodo* actual = frente;
    int esperaAcumulada=0;
    std::string llamadas="ID\t Nombre\t Motivo\t Tiempo de Espera \tDuracion Estimada";
    while(actual!=nullptr){
        llamadas=llamadas+"\n"+std::to_string(actual->dato.id)+"\t"+actual->dato.nombre+
        "\t"+actual->dato.motivo+"\t"+std::to_string(esperaAcumulada)+"\t"+std::to_string(actual->dato.duracion);
        esperaAcumulada+= actual->dato.duracion;
        actual=actual->siguiente;
    }

    std::cout<<llamadas<<"\n";
}