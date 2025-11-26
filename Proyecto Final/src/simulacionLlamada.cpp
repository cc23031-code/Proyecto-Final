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
std::cout << "========== ESTADO INICIAL DE LA COLA ==========\n";
std::cout << "Estado inicial de la cola de llamadas:\n";
colaLlamadas.mostrarCola();
// std::cout << "Tiempo de espera total: " << colaLlamadas.tiempoEspera() << " minutos\n";
// Mostrar el tiempo de espera total
std::cout << "\n=== METRICAS ===\n";
std::cout << "TIEMPO DE ESPERA TOTAL (CLIENTES): " << colaLlamadas.tiempoEspera() << " MINUTOS\n";
std::cout << "================\n\n";

// Simulación de atender llamadas
std::cout << "========== ATENDIENDO LLAMADAS ==========\n";
std::cout << "Llamadas atendidas:\n";
while (!colaLlamadas.estaVacia()) {
    Llamada atendida = colaLlamadas.dequeue();
    std::cout << "\nAtendiendo llamada ID: " << atendida.id << ", Nombre: " << atendida.nombre << "\n";
    colaLlamadas.mostrarCola();
}

std::cout << "\n========== FIN DEL PROCESO ==========\n";


//Llamada llamada4 = {4, "Ana Gomez", "Consulta de movimientos", 6, 4};
//colaLlamadas.enqueue(llamada4);
//colaLlamadas.mostrarCola();
//colaLlamadas.dequeue();
//colaLlamadas.mostrarCola(); 

return 0;



}