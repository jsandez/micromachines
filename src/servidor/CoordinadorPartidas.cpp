#include "includes/servidor/CoordinadorPartidas.h"

CoordinadorPartidas::CoordinadorPartidas(SalaDeEspera& salaDeEspera, bool& seguirCorriendo) :
    contadorPartidas_(0),
    salaDeEspera_(salaDeEspera),
    seguirCorriendo_(seguirCorriendo) {
}

void CoordinadorPartidas::agregarJugadorAPartida(std::shared_ptr<Jugador> jugador, uint16_t uuidPartida) {
    partidas_.at(uuidPartida)->agregarJugador(jugador);
}

void CoordinadorPartidas::manejar(Evento& e) {
    e.actualizar(*this);
}

void CoordinadorPartidas::manejar(EventoCrearPartida& e) {
    contadorPartidas_++;
    partidas_[contadorPartidas_] = std::make_shared<Partida>(seguirCorriendo_);
    std::shared_ptr<Evento> actualizacion = std::make_shared<EventoPartidaAgregada>(e.uuidRemitente(), contadorPartidas_);
    salaDeEspera_.manejar(*actualizacion);
}

void CoordinadorPartidas::manejar(EventoIniciarPartida& e) {
    partidas_[1]->start();
}
#include <iostream>
void CoordinadorPartidas::manejar(EventoDesconexion& e) {
    //TODO: enviar a la partida correspondiente el
    //evento desconexion para que se quite al jugador.
    partidas_[1]->manejar(e);
    partidas_.erase(1);
    std::cout << "Hardcodeando el manejar finalizar partida, para ver si joinea\n";
}
