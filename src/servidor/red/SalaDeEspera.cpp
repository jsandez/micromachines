#include "includes/servidor/red/SalaDeEspera.h"

SalaDeEspera::SalaDeEspera() :
    contadorJugadores_(0) {
}

SalaDeEspera::~SalaDeEspera() {
    /*for (auto& kv : jugadores_) {
        kv.second->cerrar();
    }*/
}

void SalaDeEspera::agregarJugador(SocketTCP&& socket, bool& seguirCorriendo) {
    contadorJugadores_++;
    jugadores_[contadorJugadores_] = std::make_shared<Jugador>(std::move(socket), contadorJugadores_, seguirCorriendo);
}
