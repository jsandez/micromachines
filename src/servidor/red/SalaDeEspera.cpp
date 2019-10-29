#include "includes/servidor/red/SalaDeEspera.h"

SalaDeEspera::SalaDeEspera(ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos) :
    contadorJugadores_(0),
    destinoEventos_(destinoEventos) {
}

SalaDeEspera::~SalaDeEspera() {
    
}

void SalaDeEspera::agregarJugador(SocketTCP&& socket, bool& seguirCorriendo) {
    contadorJugadores_++;
    jugadores_[contadorJugadores_] = std::make_shared<Jugador>(std::move(socket), contadorJugadores_, seguirCorriendo, destinoEventos_);
}
