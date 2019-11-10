#include "includes/cliente/Cliente.h"

#include <iostream>

Cliente::Cliente(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana) :
    ventana_(anchoVentana, altoVentana, pantallaCompleta, tituloVentana),
    renderizador_(ventana_),
    dibujador_(ventana_, renderizador_) {
}

Cliente::~Cliente() {
    dibujador_.join();
}

void Cliente::correr() {
    dibujador_.iniciar();
    char c;
    while ((c = std::cin.get()) != 'q') {
        // pass
    }
    cerrar();
}

void Cliente::cerrar() {
    dibujador_.detener();
}
