#include "cola.h"

// Constructor 
Cola::Cola(){
    frente=nullptr;
    fin=nullptr;
}
//destructor
cola::~Cola(){
    while(!estaVacia()){
        dequeue();
    })
}

bool Cola::estaVacia(){
    return frente==nullptr;
}
 
void Cola::enqueue(const Llamada& llamada){
    
}
