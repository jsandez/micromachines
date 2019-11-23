#include "includes/servidor/modelo/entidades/carrera/Checkpoint.h"

#include "includes/servidor/modelo/entidades/carrera/Carrera.h"
#include "includes/servidor/modelo/entidades/Vehiculo.h"

Checkpoint::Checkpoint(Carrera& carrera, int id, int idDelSiguiente, float ancho, float alto, Posicion& posicion) :
    carrera_(carrera),
    id_(id),
    idDelSiguiente_(idDelSiguiente),
    ancho_(ancho),
    alto_(alto),
    puntoRespawn_(posicion) {
}

Checkpoint::~Checkpoint() {

}

int Checkpoint::getTipo() {
    return CHECKPOINT_;
}

Posicion& Checkpoint::posicion() {
    return puntoRespawn_;
}

float Checkpoint::ancho() {
    return ancho_;
}
float Checkpoint::alto() {
    return alto_;
}

int Checkpoint::id() {
    return id_;
}

#include <iostream>

void Checkpoint::registrarPaso(Vehiculo& vehiculo) {
    Checkpoint& ultimoCheckpoint = carrera_.ultimoCheckpointDe(vehiculo);
    if (ultimoCheckpoint.idDelSiguiente_ == id_) {
        //TODO: EN Meta será sumar vuelta
        vehiculo.setPuntoRespawn(puntoRespawn_);
        std::cout << "Vehiculo chocando con checkpoint: " << id_ << std::endl;
        std::cout << "Seteando x: " << puntoRespawn_.x_ << " y: " << puntoRespawn_.y_ << std::endl;
        carrera_.setCheckpoint(vehiculo, *this);
    }
}


