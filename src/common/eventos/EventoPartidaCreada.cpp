#include "includes/common/eventos/EventoPartidaCreada.h"

#include "includes/common/Handler.h"

EventoPartidaCreada::EventoPartidaCreada(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
}

EventoPartidaCreada::EventoPartidaCreada(uint16_t uuidPartida) :
    Evento(0),
    uuidPartida_(uuidPartida) {
    
    UUIDEvento_ = UUID_EVENTO_PARTIDA_CREADA;
}

void EventoPartidaCreada::enviarse(Protocolo& protocolo) {
    protocolo.enviar(UUIDEvento_);
}

void EventoPartidaCreada::actualizar(Handler& handler) {
    handler.manejar(*this);
}
