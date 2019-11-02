#include "includes/servidor/Partida.h"

Partida::Partida(bool& seguirCorriendo):
    jugando_(false),
    seguirCorriendo_(seguirCorriendo) {
}

Partida::~Partida() {
    join();
}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}

void Partida::run() {
    jugando_ = true;
    while(seguirCorriendo_ && jugando_) {
        //std::cout << "Hola, corriendo\n";
        //std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void Partida::manejar(Evento& e) {
    e.actualizar(*this);
    //jugando_ = false;
}
