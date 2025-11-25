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
Llamada Cola::dequeue() {
    if (estaVacia()){
 std::cout << "No se puede eliminar, la cola está vacía" << std::endl;
        Llamada error;
        error.id = -1;
        return error;
    }

    Nodo* temp = frente;
    Llamada dato = temp->dato;
    frente = frente->siguiente;
    
    if (frente == nullptr){
        final = nullptr;
    }
    
    delete temp;
    tamaño--;
    return dato;
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
       if (estaVacia()) {
        std::cout << "La cola está vacía.\n";
        return;
    }
     std::cout << "\n========== COLA DE LLAMADAS ==========\n";
    Nodo* actual = frente;
    int posicion=1;
    int esperaAcumulada=0;
    std::string llamadas="ID\t Nombre\t Motivo\t Tiempo de Espera \tDuracion Estimada"; // Encabezado de la tabla
  while (actual != nullptr) {
    const Llamada& llamada = actual->dato; // Acceder a la llamada almacenada en el nodo
    int tiempoEspera = esperaAcumulada - llamada.tiempoLLegada;
    
    llamadas = llamadas + "\n" + 
               "Posición " + std::to_string(posicion) + ":\n" +
               "  ID: " + std::to_string(llamada.id) + "\n" +
               "  Nombre: " + llamada.nombre + "\n" +
               "  Motivo: " + llamada.motivo + "\n" +
               "  Duración estimada: " + std::to_string(llamada.duracion) + " min\n" +
               "  Tiempo de espera: " + std::to_string(tiempoEspera) + " min\n" +
               "--------------------------------------\n";
    
    esperaAcumulada += llamada.duracion;
    actual = actual->siguiente;
    posicion++;
}

    std::cout<<llamadas<<"\n";
}