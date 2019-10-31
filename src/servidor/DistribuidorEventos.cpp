#include "includes/servidor/DistribuidorEventos.h"

DistribuidorEventos::DistribuidorEventos(bool& seguirCorriendo, ColaBloqueante<std::shared_ptr<Evento>>& eventos, SalaDeEspera& salaDeEspera, CoordinadorPartidas& coordinadorPartidas) :
    seguirCorriendo_(seguirCorriendo),
    eventos_(eventos),
    salaDeEspera_(salaDeEspera),
    coordinadorPartidas_(coordinadorPartidas) {

}

DistribuidorEventos::~DistribuidorEventos() {
}

void DistribuidorEventos::run() {
    bool obtenido;
    std::shared_ptr<Evento> evento;
    while(seguirCorriendo_ && (obtenido = eventos_.get(evento))) {
        manejar(*evento);
    }
}

void DistribuidorEventos::manejar(Evento& e) {
    e.actualizar(*this);
}

void DistribuidorEventos::manejar(EventoAcelerar& e) {
    coordinadorPartidas_.manejar(e);
}

void DistribuidorEventos::manejar(EventoCrearPartida& e) {
    coordinadorPartidas_.manejar(e);
}

void DistribuidorEventos::manejar(EventoUnirseAPartida& e) {
    //TODO: redirigir al coordinador de partidas
}

void DistribuidorEventos::manejar(EventoDesconexion& e) {
    salaDeEspera_.manejar(e);
    coordinadorPartidas_.manejar(e);
}

void DistribuidorEventos::manejar(EventoIniciarPartida& e) {
    // TODO: iniciar la partida
}
