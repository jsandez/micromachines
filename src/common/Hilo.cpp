#include "includes/common/Hilo.h"

Hilo::Hilo() {
}

Hilo::Hilo(Hilo&& otroHilo) {
    hilo_ = std::move(otroHilo.hilo_);
}

Hilo& Hilo::operator=(Hilo&& otroHilo) {
    hilo_ = std::move(otroHilo.hilo_);
    return *this;
}

void Hilo::start() {
    hilo_ = std::thread(&Hilo::run, this);
}

void Hilo::join() {
    hilo_.join();
}
