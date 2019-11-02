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
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = e.uuidPartida_;
    std::shared_ptr<Jugador> jugador = salaDeEspera_.obtenerJugador(uuidJugador);
    coordinadorPartidas_.agregarJugadorAPartida(jugador, uuidPartida);
}

void DistribuidorEventos::manejar(EventoDesconexion& e) {
    salaDeEspera_.manejar(e);
    coordinadorPartidas_.manejar(e);
}

void DistribuidorEventos::manejar(EventoIniciarPartida& e) {
    coordinadorPartidas_.manejar(e);   
}
