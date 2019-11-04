#include "includes/servidor/CoordinadorPartidas.h"

CoordinadorPartidas::CoordinadorPartidas(SalaDeEspera& salaDeEspera) :
    contadorPartidas_(0),
    salaDeEspera_(salaDeEspera){
}

CoordinadorPartidas::~CoordinadorPartidas() {
    for (const auto& kv : partidas_) {
        kv.second->detener();
        // TODO: Hacer join porque las partidas VAN a estar corriendo
        kv.second->join();
    }
}

void CoordinadorPartidas::agregarJugadorAPartida(std::shared_ptr<Jugador> jugador, uint16_t uuidPartida) {
    partidas_.at(uuidPartida)->agregarJugador(jugador);
    jugadoresAPartidas_[jugador->uuid()] = uuidPartida;
}

void CoordinadorPartidas::manejar(Evento& e) {
    e.actualizar(*this);
}

void CoordinadorPartidas::manejar(EventoCrearPartida& e) {
    contadorPartidas_++;
    partidas_[contadorPartidas_] = std::make_shared<Partida>();
    std::shared_ptr<Evento> actualizacion = std::make_shared<EventoPartidaAgregada>(e.uuidRemitente(), contadorPartidas_);
    salaDeEspera_.manejar(*actualizacion);
}

void CoordinadorPartidas::manejar(EventoIniciarPartida& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    partidas_[uuidPartida]->iniciar();
}

void CoordinadorPartidas::manejar(EventoDesconexion& e) {
    //TODO: enviar a la partida correspondiente el
    //evento desconexion para que se quite al jugador.
    //partidas_[1]->manejar(e);
    //partidas_.erase(1);
}

void CoordinadorPartidas::manejar(EventoAcelerar& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoAcelerar>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}
