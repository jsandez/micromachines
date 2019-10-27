#include "includes/servidor/HiloAceptador.h"

#include <iostream>

#include "includes/servidor/utils/ConfigServidor.h"

HiloAceptador::HiloAceptador(const std::string& puerto) :
    sktAceptador_(puerto) {
}

void HiloAceptador::run() {
    try {
    sktAceptador_.enlazar();
    sktAceptador_.escuchar(CONFIG_SERVIDOR.maxClientesEnEspera());
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    while (true) {
        try {
            SocketTCP aceptado = sktAceptador_.aceptar();
            socketsClientes_.push_back(std::move(aceptado));
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void HiloAceptador::join() {
    Hilo::join();
}

HiloAceptador::~HiloAceptador() {
    sktAceptador_.cerrarLectoEscritura();
}
