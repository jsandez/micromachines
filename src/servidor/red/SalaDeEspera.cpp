#include "includes/servidor/red/SalaDeEspera.h"

SalaDeEspera::SalaDeEspera() :
    contadorJugadores_(0) {
}

void SalaDeEspera::agregarJugador(SocketTCP&& socket, bool& seguirCorriendo) {
    contadorJugadores_++;
    jugadores_[contadorJugadores_] = std::make_shared<Jugador>(std::move(socket), contadorJugadores_, seguirCorriendo);
}
