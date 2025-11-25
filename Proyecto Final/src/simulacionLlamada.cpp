#include <cola.h>

int main(){
    Cola colaLlamadas;

    // Simulación de agregar llamadas a la cola
    Llamada llamada1 = {1, "Juan Perez", "Consulta de saldo", 0, 5};
    Llamada llamada2 = {2, "Maria Lopez", "Reporte de tarjeta perdida", 2, 10};
    Llamada llamada3 = {3, "Carlos Sanchez", "Cambio de plan", 4, 7};

    colaLlamadas.enqueue(llamada1);
    colaLlamadas.enqueue(llamada2);
    colaLlamadas.enqueue(llamada3);

    // Mostrar el estado de la cola
    std::cout << "Estado inicial de la cola de llamadas:\n";
     colaLlamadas.mostrarCola() ;
    // std::cout << "Tiempo de espera total: " << colaLlamadas.tiempoEspera() << " minutos\n";

    // Simulación de atender llamadas
    std::cout << "Atendiendo llamadas...\n";
    while (!colaLlamadas.estaVacia()) {
        Llamada atendida = colaLlamadas.dequeue();
        std::cout << "Atendiendo llamada ID: " << atendida.id << ", Nombre: " << atendida.nombre << "\n";
    }

    std::cout << "Todas las llamadas han sido atendidas.\n";

    return 0;
  



}