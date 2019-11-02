#include "includes/servidor/Partida.h"

Partida::Partida() {
}

Partida::~Partida() {
}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}

void Partida::correr() {
    while(seguirCorriendo_) {
        //std::cout << "Hola, corriendo\n";
        //std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void Partida::detener() {
    seguirCorriendo_ = false;
}

void Partida::manejar(Evento& e) {
    e.actualizar(*this);
    //jugando_ = false;
}
