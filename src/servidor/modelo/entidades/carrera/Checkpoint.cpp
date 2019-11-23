#include "includes/servidor/modelo/entidades/carrera/Checkpoint.h"

Checkpoint::Checkpoint(int id, int idDelSiguiente, float ancho, float alto, Posicion& posicion) :
    puntoRespawn_(posicion),
    id_(id),
    idDelSiguiente_(idDelSiguiente),
    ancho_(ancho),
    alto_(alto) {
    
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