#include "includes/servidor/Partida.h"

Partida::Partida(bool& seguirCorriendo):
    seguirCorriendo_(seguirCorriendo) {

}

Partida::~Partida() {
    Hilo::join();
}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}
#include <iostream>
#include <thread>
#include <chrono>

void Partida::run() {
    while(seguirCorriendo_) {
        std::cout << "Hola, corriendo\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void Partida::manejar(Evento& e) {
    e.actualizar(*this);
    seguirCorriendo_ = false;
}
