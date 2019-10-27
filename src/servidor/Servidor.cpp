#include "includes/servidor/Servidor.h"

#include <iostream>

Servidor::Servidor(const std::string& puerto) :
    seguirCorriendo_(true),
    hiloAceptador_(puerto, seguirCorriendo_) {
}

void Servidor::correr() {
    hiloAceptador_.start();
    char c;
    while ((c = std::cin.get()) != CARACTER_SALIR) {
        // pass
    }
    seguirCorriendo_ = false,
    cerrar();
}

void Servidor::cerrar() {
    hiloAceptador_.join();
}
