#include "includes/servidor/CoordinadorPartidas.h"

CoordinadorPartidas::CoordinadorPartidas(SalaDeEspera& salaDeEspera) :
    contadorPartidas_(0),
    salaDeEspera_(salaDeEspera){
}

CoordinadorPartidas::~CoordinadorPartidas() {
    for (const auto& kv : partidas_) {
        if (kv.second->estaCorriendo()) {
            kv.second->detener();
            kv.second->join();
        }        
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
    // TODO: Acá hay que decir que uuid de mapa se quiere cargar
    // FIXME: No hardcodear esto
    uint16_t uuidPista = 1;
    partidas_[contadorPartidas_] = std::make_shared<Partida>(uuidPista);
    std::shared_ptr<Evento> actualizacion = std::make_shared<EventoPartidaAgregada>(e.uuidRemitente(), contadorPartidas_);
    salaDeEspera_.manejar(*actualizacion);
    //TODO: Quitar partidas finalizadas, que no deben tener jugadores dentro.
}

//TODO: Debería esperar que todos envíen jugar.
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


void CoordinadorPartidas::manejar(EventoDesacelerar& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoDesacelerar>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}

void CoordinadorPartidas::manejar(EventoFrenar& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoFrenar>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}

void CoordinadorPartidas::manejar(EventoDejarDeFrenar& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoDejarDeFrenar>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}

void CoordinadorPartidas::manejar(EventoDoblarIzquierda& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoDoblarIzquierda>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}

void CoordinadorPartidas::manejar(EventoDejarDeDoblarIzquierda& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoDejarDeDoblarIzquierda>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}

void CoordinadorPartidas::manejar(EventoDoblarDerecha& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoDoblarDerecha>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}

void CoordinadorPartidas::manejar(EventoDejarDeDoblarDerecha& e) {
    uint32_t uuidJugador = e.uuidRemitente();
    uint16_t uuidPartida = jugadoresAPartidas_[uuidJugador];
    std::shared_ptr<Evento> evento = std::make_shared<EventoDejarDeDoblarDerecha>(std::move(e));
    partidas_[uuidPartida]->ocurrio(evento);
}
