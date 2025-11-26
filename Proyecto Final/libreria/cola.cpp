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
       if (estaVacia()) {
        std::cout << "La cola está vacía.\n";
        return; // Salir si la cola está vacía
    }
     std::cout << "\n========== COLA DE LLAMADAS ==========\n";
    Nodo* actual = frente;
    int posicion=1; // Posición de la llamada en la cola
    int tiempoDuracionTotal = 0;// Tiempo de espera total acumulado
    int esperaAcumulada=0;
   std::string llamadas ;//=//"ID\t Nombre\t Motivo\t Tiempo de Espera \tDuracion Estimada"; // Encabezado de la tabla
  while (actual != nullptr) {
    const Llamada& llamada = actual->dato; // Acceder a la llamada almacenada en el nodo
    int tiempoEspera = esperaAcumulada - llamada.tiempoLLegada; // Calcular el tiempo de espera para esta llamada
    
   llamadas = llamadas + "\n" + 
               "Posicion " + std::to_string(posicion) + ":\n" +
               "  ID: " + std::to_string(llamada.id) + "\n" +
               "  Nombre: " + llamada.nombre + "\n" +
               "  Motivo: " + llamada.motivo + "\n" + 
               "  Tiempo de llegada: " + std::to_string(llamada.tiempoLLegada) + " minutos\n" +
               "  Duracion estimada: " + std::to_string(llamada.duracion) + " minutos\n" +
               "  Tiempo de espera: " + std::to_string(tiempoEspera) + " minutos\n" +
               "--------------------------------------\n";
    
    esperaAcumulada += llamada.duracion; // Actualizar el tiempo de espera acumulada
    actual = actual->siguiente;
    posicion++;
    tiempoDuracionTotal += llamada.duracion;
}

    std::cout<<llamadas<<"\n";
    std::cout << "======================================\n";
    std::cout << "Duracion total estimada: " << tiempoDuracionTotal << " minutos\n";
    std::cout << "======================================\n";
}