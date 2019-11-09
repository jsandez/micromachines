#include "includes/cliente/GUI/Animacion.h"

Animacion::Animacion(std::vector<Textura>& texturas) {
    for (Textura& t : texturas) {
        frames_.push_back(std::move(t));
    }
}

Textura& Animacion::get(uint32_t numeroIteracion) {
    return frames_[numeroIteracion % frames_.size()];
}
