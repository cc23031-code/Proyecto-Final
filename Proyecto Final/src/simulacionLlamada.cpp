#include <cola.h>

int main(){
    Cola colaLlamadas;

    // Simulación de agregar llamadas a la cola
    Llamada llamada1 = {1, "Juan Perez", "Consulta de saldo", 0, 5};
     colaLlamadas.enqueue(llamada1);
    Llamada llamada2 = {2, "Maria Lopez", "Reporte de tarjeta perdida", 2, 10};
    Llamada llamada3 = {3, "Carlos Sanchez", "Cambio de plan", 4, 7};

    
    colaLlamadas.enqueue(llamada2);
    colaLlamadas.enqueue(llamada3);


    // Mostrar el estado de la cola
    std::cout << "Estado inicial de la cola de llamadas:\n";
     colaLlamadas.mostrarCola() ;
    // std::cout << "Tiempo de espera total: " << colaLlamadas.tiempoEspera() << " minutos\n";
    // Mostrar el tiempo de espera total
std::cout << "\n TIEMPO DE ESPERA TOTAL: " << colaLlamadas.tiempoEspera() << " MINUTOS\n\n";
    // Simulación de atender llamadas
    std::cout << "Llamadas atendidas:\n";
    while (!colaLlamadas.estaVacia()) {
        Llamada atendida = colaLlamadas.dequeue();
        std::cout << "Atendiendo llamada ID: " << atendida.id << ", Nombre: " << atendida.nombre << "\n";
    }

    std::cout << "Atendiendo llamadas...\n";

    return 0;
  



}