#include "includes/servidor/HiloAceptador.h"

#include <iostream>

#include "includes/servidor/utils/ConfigServidor.h"

HiloAceptador::HiloAceptador(const std::string& puerto, bool& seguirCorriendo, SalaDeEspera& salaDeEspera) :
    sktAceptador_(puerto),
    salaDeEspera_(salaDeEspera),
    seguirCorriendo_(seguirCorriendo) {
}

void HiloAceptador::run() {
    try {
    sktAceptador_.enlazar();
    sktAceptador_.escuchar(CONFIG_SERVIDOR.maxClientesEnEspera());
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    while (seguirCorriendo_) {
        try {
            SocketTCP aceptado = sktAceptador_.aceptar();
            salaDeEspera_.agregarJugador(std::move(aceptado));
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void HiloAceptador::join() {
    sktAceptador_.cerrarLectoEscritura();
    Hilo::join();
}

HiloAceptador::~HiloAceptador() {
}
