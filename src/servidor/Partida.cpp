#include "includes/servidor/Partida.h"

#include <iostream>

Partida::Partida() {
}

Partida::~Partida() {
}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}

void Partida::correr() {
    bool obtenido;
    std::shared_ptr<Evento> evento;
    while(seguirCorriendo_ && (obtenido = eventosEntrantes_.get(evento))) {
        manejar(*evento);
    }
}

void Partida::detener() {
    seguirCorriendo_ = false;
    eventosEntrantes_.detener();

}

void Partida::ocurrio(std::shared_ptr<Evento> unEvento) {
    eventosEntrantes_.put(unEvento);
}

void Partida::manejar(Evento& e) {
    e.actualizar(*this);
}

void Partida::manejar(EventoAcelerar& e) {
    std::cout << "Hola, estoy en una partida y alguien mando acelerar\n";
}
