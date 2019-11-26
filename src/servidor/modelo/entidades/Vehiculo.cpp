#include "includes/servidor/modelo/entidades/Vehiculo.h"

Vehiculo::Vehiculo(uint8_t uuid,
            unsigned int velocidadMaximaAdelante,
            unsigned int velocidadMaximaAtras,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            //FIXME: CAMBIAR SALUD A UINT8T
            unsigned int salud,
            Posicion respawn) :
            Identificable(uuid),
            velocidadMaximaAdelante_(velocidadMaximaAdelante),
            velocidadMaximaAtras_(velocidadMaximaAtras),
            aceleracion_(aceleracion),
            maniobrabilidad_(maniobrabilidad),
            agarre_(agarre),
            salud_(salud),
            saludDefault_(salud),
            respawn_(respawn) {
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

bool Vehiculo::disminuirSalud(uint8_t cantidad) {
    int saludFinal = salud_ - cantidad;
    if (saludFinal <= 0) {
        salud_ = saludDefault_;
        return true;
    }
    salud_ = saludFinal;
    return false;
}

void Vehiculo::sumarSalud(int delta) {
    unsigned int saludFinal = salud_ + delta;
    if (saludFinal > saludDefault_) {
        salud_ = saludDefault_;
    } else {
        salud_ = saludFinal;
    }
}

int Vehiculo::getTipo() {
    return VEHICULO_;
}

Posicion& Vehiculo::getPuntoRespawn() {
    return respawn_;
}

void Vehiculo::setPuntoRespawn(Posicion& posicion) {
    respawn_ = posicion;
}
