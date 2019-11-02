#include "includes/servidor/SalaDeEspera.h"

SalaDeEspera::SalaDeEspera(ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos) :
    contadorJugadores_(0),
    destinoEventos_(destinoEventos) {
}

SalaDeEspera::~SalaDeEspera() {
    
}

void SalaDeEspera::agregarJugador(SocketTCP&& socket) {
    contadorJugadores_++;
    jugadores_[contadorJugadores_] = std::make_shared<Jugador>(std::move(socket), contadorJugadores_, destinoEventos_);
}

std::shared_ptr<Jugador> SalaDeEspera::obtenerJugador(uint32_t uuidJugador) {
    std::shared_ptr<Jugador> jugador = jugadores_.at(uuidJugador);
    jugadores_.erase(uuidJugador);
    return jugador;
}

void SalaDeEspera::manejar(Evento& e) {
    e.actualizar(*this);
}

void SalaDeEspera::manejar(EventoDesconexion& e) {
    jugadores_.erase(e.uuidRemitente());
}

void SalaDeEspera::manejar(EventoPartidaAgregada& e) {
    //TODO: enviarle a todos los que hay este evento
    // seria un put.
}
