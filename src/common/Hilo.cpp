#include "includes/common/Hilo.h"

Hilo::Hilo()
    : seguirCorriendo_(true) {
}

Hilo::~Hilo() {
}

Hilo::Hilo(Hilo&& otroHilo) {
    hilo_ = std::move(otroHilo.hilo_);
}

Hilo& Hilo::operator=(Hilo&& otroHilo) {
    hilo_ = std::move(otroHilo.hilo_);
    return *this;
}

void Hilo::iniciar() {
    hilo_ = std::thread(&Hilo::correr, this);
}

void Hilo::join() {
    hilo_.join();
}
