#include "includes/servidor/Servidor.h"

Servidor::Servidor(const std::string& puerto) :
    hiloAceptador_(puerto) {
}

void Servidor::correr() {
    hiloAceptador_.start();
}

void Servidor::cerrar() {
    hiloAceptador_.join();
}
