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
    
}   