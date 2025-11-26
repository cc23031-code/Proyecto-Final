#include "cola.h"

// Constructor 
Cola::Cola(){
    frente=nullptr;
    final=nullptr;
    tamaño=0;
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
    Nodo* nuevo=new Nodo(llamada); // Crear un nuevo nodo
    nuevo->siguiente=nullptr;
    if(estaVacia()){
        frente=nuevo;
        final=nuevo;
    } else {
        final->siguiente=nuevo;
        final=nuevo;
    }
    tamaño++; // Incrementar el tamaño de la cola
}   
Llamada Cola::dequeue() {
    if (estaVacia()){
 std::cout << "No se puede eliminar, la cola está vacía" << std::endl;
        Llamada error; // Valor de error
        error.id = -1; // Indicador de error
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
int Cola::tiempoEspera() const{ // Calcular el tiempo de espera total de todas las llamadas en la cola
    if(estaVacia()){
        return 0; // Si la cola está vacía, el tiempo de espera es 0
    } 
    int tiempoEsperaTotal = 0;
    int tiempoActual = 0; // Tiempo simulado actual
    Nodo* actual = frente;
    while(actual != nullptr){
       //tiempo que la llamada ha esperado es el tiempo acumulado menos el tiempo de llegada
        int tiempoEsperaLlamada = tiempoActual - actual->dato.tiempoLLegada;
        
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
      if (Cola::estaVacia())
    {
        std::cout << "|               NO HAY LLAMADAS EN ESPERA                              |\n";
        std::cout << "+----------------------------------------------------------------------+\n";
        return;
    }

    int tiempoDuracionTotal = 0; // Tiempo de espera total acumulado
    int esperaAcumulada = 0;
    Nodo *actual = frente;

    std::cout << "\n+------+----------------------+--------------------------------+----------------+----------------+----------------+\n";
    std::cout <<    "| ID   | Nombre               | Motivo                         | Llegada (min)  | Duración (min) | Espera (min)   |\n";
    std::cout <<   "+------+----------------------+--------------------------------+----------------+----------------+----------------+\n";

    while (actual != nullptr)
    {
        const Llamada &llamada = actual->dato;
        std::cout << "| "
                  << std::setw(4) << llamada.id << " | "
                  << std::setw(20) << llamada.nombre << " | "
                  << std::setw(30) << llamada.motivo << " | "
                  << std::setw(14) << llamada.tiempoLLegada << " | "
                  << std::setw(14) << llamada.duracion << " | "
                  << std::setw(14) << std::to_string(tiempoEspera()) << " |\n";

        esperaAcumulada += llamada.duracion; // Actualizar el tiempo de espera acumulada
        actual = actual->siguiente;
        tiempoDuracionTotal += llamada.duracion;
    }

    std::cout << "+------+----------------------+--------------------------------+-----------------+---------------+----------------+\n";
}