#include "includes/servidor/Partida.h"

Partida::Partida(uint16_t uuidPista) :
    mundo_(uuidPista) {
}

Partida::~Partida() {
}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}

void Partida::correr() {
    bool obtenido;
    std::shared_ptr<Evento> evento;
    //FIXME: Esto NO DEBE SER bloqueante
    while(seguirCorriendo_ && (obtenido = eventosEntrantes_.get(evento))) {
        manejar(*evento);
    }
}

void Partida::detener() {
    seguirCorriendo_ = false;
}

void Partida::ocurrio(std::shared_ptr<Evento> unEvento) {
    eventosEntrantes_.put(unEvento);
}

void Partida::manejar(Evento& e) {
    e.actualizar(*this);
}

void Partida::manejar(EventoAcelerar& e) {
    //TODO: Derivar en mundo
}
