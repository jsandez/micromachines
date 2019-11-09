#include "includes/cliente/Cliente.h"

#include <iostream>

#include "includes/cliente/utils/ConfigCliente.h"

Cliente::Cliente() :
    dibujador_(CONFIG_CLIENTE.anchoVentana(),
        CONFIG_CLIENTE.altoVentana(),
        CONFIG_CLIENTE.pantallaCompleta(),
        CONFIG_CLIENTE.tituloVentana()) {
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
