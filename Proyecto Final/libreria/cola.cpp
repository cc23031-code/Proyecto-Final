#include "cola.h"

// Constructor 
Cola::Cola(){
    frente=nullptr;
    final=nullptr;
    tamaño=0;
}
//destructor
Cola::~Cola(){
    limpiarCola();
}
void Cola::limpiarCola(){
    while(!estaVacia()){
        dequeue();
    }
}


bool Cola::estaVacia() const {
    return frente==nullptr;
}
 
void Cola::enqueue(const Llamada& llamada){// Agregar una llamada al final de la cola
    Nodo* nuevo=new Nodo(llamada); // Crear un nuevo nodo
    nuevo->siguiente=nullptr; // El siguiente del nuevo nodo es nulo
    if(estaVacia()){
        frente=nuevo;
        final=nuevo;
    } else {
        final->siguiente=nuevo; // El siguiente del final actual apunta al nuevo nodo
        final=nuevo;
    }
    tamaño++; // Incrementar el tamaño de la cola
}   
Llamada Cola::dequeue() {
    if (estaVacia()){
 std::cout << "No se puede eliminar, la cola está vacía" << std::endl;
     throw std::runtime_error("No se puede eliminar, la cola está vacía");
    }

    Nodo* temp = frente; // Almacenar el nodo frente temporalmente
    Llamada dato = temp->dato; // Obtener el dato del nodo frente
    frente = frente->siguiente;
    
    if (frente == nullptr){
        final = nullptr;
    }
    
    delete temp;
    tamaño--;
    return dato;
}
int Cola::tiempoEspera() const{ // Calcular el tiempo de espera total de todas las llamadas en la cola
    if(estaVacia()){
        return 0; // Si la cola está vacía, el tiempo de espera es 0
    } 
    int tiempoEsperaTotal = 0;
    int tiempoActual = 0; // Tiempo simulado actual
    Nodo* actual = frente;
    while(actual != nullptr){
       //tiempo que la llamada ha esperado es el tiempo acumulado menos el tiempo de llegada
        int tiempoEsperaLlamada = tiempoActual - actual->dato.tiempoLLegada; // Calcular el tiempo de espera para esta llamada
        
        if(tiempoEsperaLlamada < 0){
            tiempoEsperaLlamada=0; // Si la llamada no ha esperado, el tiempo de espera es 0
        }
        //
        tiempoEsperaTotal += tiempoEsperaLlamada;
  // Actualizar el tiempo actual sumando la duración de la llamada
        tiempoActual += actual->dato.duracion;
        actual = actual->siguiente;
    }
  
    return tiempoEsperaTotal;
}

void Cola::mostrarCola() const{
     if (Cola::estaVacia()) {
        std::cout << "|               NO HAY LLAMADAS EN ESPERA                              |\n";
        std::cout << "+----------------------------------------------------------------------+\n";
        return;
    }

    int esperaAcumulada = 0;
    Nodo *actual = frente;

    std::cout << "\n+------+----------------------+--------------------------------+----------------+----------------+----------------+\n";
    std::cout <<    "| ID   | Nombre               | Motivo                         | Llegada (min)  | Duracion (min) | Espera (min)   |\n";
    std::cout <<   "+------+----------------------+--------------------------------+----------------+----------------+----------------+\n";

    while (actual != nullptr) {
        const Llamada &llamada = actual->dato;
        
        std::cout << "| "
                  << std::left << std::setw(4) << llamada.id << " | "
                  << std::left << std::setw(20) << llamada.nombre << " | "
                  << std::left << std::setw(30) << llamada.motivo << " | "
                  << std::right << std::setw(14) << llamada.tiempoLLegada << " | "
                  << std::right << std::setw(14) << llamada.duracion << " | "
                  << std::right << std::setw(14) << esperaAcumulada << " |\n";

        esperaAcumulada += llamada.duracion;
        actual = actual->siguiente;
    }

    std::cout << "+------+----------------------+--------------------------------+----------------+----------------+----------------+\n";
    std::cout << "Tiempo total de espera: " << esperaAcumulada << " minutos\n";

}