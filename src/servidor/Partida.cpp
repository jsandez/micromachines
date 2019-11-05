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
    //TODO: implementar Partida::correr()
    // Asignar un auto a cada jugador presente, no poner autos vacios
    //bool obtenido;
    //std::shared_ptr<Evento> evento;
    while(seguirCorriendo_) {
        // Tomar eventos
        // Aplicarlos
        // Step()
        // para cada jugador, enviarle estado del juego
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
