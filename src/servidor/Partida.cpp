#include "includes/servidor/Partida.h"

Partida::Partida(bool& seguirCorriendo):
    seguirCorriendo_(seguirCorriendo) {

}

Partida::~Partida() {

}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}

void Partida::run() {

}

void Partida::manejar(Evento& e) {
    e.actualizar(*this);
}
