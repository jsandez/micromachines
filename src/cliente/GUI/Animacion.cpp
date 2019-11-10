#include "includes/cliente/GUI/Animacion.h"

Animacion::Animacion(std::vector<Textura>& texturas, unsigned int ancho, unsigned int alto) :
    ancho_(ancho),
    alto_(alto) {
    for (Textura& t : texturas) {
        frames_.push_back(std::move(t));
    }
}

Textura& Animacion::get(uint32_t numeroIteracion) {
    return frames_[numeroIteracion % frames_.size()];
}

unsigned int Animacion::ancho() {
    return ancho_;
}
unsigned int Animacion::alto() {
    return alto_;
}
