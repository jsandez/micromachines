#include "includes/servidor/CoordinadorPartidas.h"

CoordinadorPartidas::CoordinadorPartidas(SalaDeEspera& salaDeEspera) :
    contadorPartidas_(0),
    salaDeEspera_(salaDeEspera) {
}

void CoordinadorPartidas::manejar(Evento& e) {
    e.actualizar(*this);
}

#include <iostream>
void CoordinadorPartidas::manejar(EventoCrearPartida& e) {
    contadorPartidas_++;
    partidas_[contadorPartidas_] = std::make_shared<Partida>();
    std::shared_ptr<Evento> actualizacion = std::make_shared<EventoPartidaAgregada>(e.uuidRemitente(), contadorPartidas_);
    salaDeEspera_.manejar(*actualizacion);
    std::cout << contadorPartidas_ << std::endl;
}

void CoordinadorPartidas::manejar(EventoDesconexion& e) {
    //TODO: enviar a la partida correspondiente el
    //evento desconexion para que se quite al jugador.
}
