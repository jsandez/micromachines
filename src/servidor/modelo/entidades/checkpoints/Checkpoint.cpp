#include "includes/servidor/modelo/entidades/checkpoints/Checkpoint.h"

Checkpoint::Checkpoint(unsigned int id, float ancho, float alto, Posicion& posicion) :
    puntoRespawn_(posicion),
    id_(id),
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