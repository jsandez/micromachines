#include "includes/servidor/modelo/entidades/Vehiculo.h"

Vehiculo::Vehiculo(uint8_t uuid,
            unsigned int velocidadMaximaAdelante,
            unsigned int velocidadMaximaAtras,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            //FIXME: CAMBIAR SALUD A UINT8T
            unsigned int salud) :
            Identificable(uuid),
            velocidadMaximaAdelante_(velocidadMaximaAdelante),
            velocidadMaximaAtras_(velocidadMaximaAtras),
            aceleracion_(aceleracion),
            maniobrabilidad_(maniobrabilidad),
            agarre_(agarre),
            salud_(salud) {
}

unsigned int Vehiculo::velocidadMaximaAdelante() {
    return velocidadMaximaAdelante_;
}

unsigned int Vehiculo::velocidadMaximaAtras() {
    return velocidadMaximaAtras_;
}

unsigned int Vehiculo::aceleracion() {
    return aceleracion_;
}

unsigned int Vehiculo::maniobrabilidad() {
    return maniobrabilidad_;
}

unsigned int Vehiculo::agarre() {
    return agarre_;
}

unsigned int Vehiculo::salud() {
    return salud_;
}

// Yo en colision con un abstracto, le digo que 
// Choque contra yo específico.
void Vehiculo::enColisionCon(Colisionable& otro) {
    otro.colisionarContra(*this);
}

void Vehiculo::colisionarContra(Vehiculo& vehiculo) {
    
}