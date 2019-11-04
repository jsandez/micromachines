#include "includes/common/Hilo.h"

Hilo::Hilo()
    : seguirCorriendo_(false) {
}

Hilo::~Hilo() {
}

bool Hilo::estaCorriendo() {
    return seguirCorriendo_;
}

Hilo::Hilo(Hilo&& otroHilo) {
    hilo_ = std::move(otroHilo.hilo_);
}

Hilo& Hilo::operator=(Hilo&& otroHilo) {
    hilo_ = std::move(otroHilo.hilo_);
    return *this;
}

void Hilo::iniciar() {
    seguirCorriendo_ = true;
    hilo_ = std::thread(&Hilo::correr, this);
}

void Hilo::join() {
    hilo_.join();
}
