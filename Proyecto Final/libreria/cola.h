#ifndef COLA_H //Evitar definiciones múltiples de clases/estructuras
#define COLA_H

#include <String>
struct Llamada
{
    int id;
    std::string nombre; //Nombre de la persona que realiza la llamada
    std::string motivo;
    int tiempoLLegada; //Momento en que la llamada llega a la cola
    int duracion; //Duración estimada de la llamada
};

class Cola
{
    private:
    struct Nodo
    {
    Llamada dato; //dato de tipo Llamada para almacenar la información de la llamada
    Nodo* siguiente;
    Nodo(const Llamada& llamada) : dato(llamada), siguiente(nullptr) {} //const es para evitar modificaciones accidentales
    };

    
    Nodo* frente; //puntero al primer nodo de la cola
    Nodo* final; //puntero al último nodo de la cola
    int tamaño; //número de elementos en la cola


    public: 
    Cola();
    ~Cola();

    void enqueue(const Llamada& llamada); //Agregar una llamada al final de la cola
    Llamada dequeue(); //Eliminar y devolver la llamada al frente de la cola
    int mostrarCola() const; //Mostrar todas las llamadas en la cola
    bool estaVacia() const; //Verificar si la cola está vacía
    int tiempoEspera(int tiempoActual) const; //Calcular el tiempo de espera total de todas las llamadas en la cola
};


#endif