#include "includes/common/eventos/EventoPartidaAgregada.h"

#include "includes/common/Handler.h"

EventoPartidaAgregada::EventoPartidaAgregada(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
    UUIDEvento_ = UUID_EVENTO_PARTIDA_AGREGADA;
}

EventoPartidaAgregada::EventoPartidaAgregada(uint32_t uuidRemitente, uint16_t cantidadPartidas) :
    Evento(uuidRemitente),
    cantidadPartidas_(cantidadPartidas) {
    UUIDEvento_ = UUID_EVENTO_PARTIDA_AGREGADA;
}

void EventoPartidaAgregada::enviarse(Protocolo& protocolo) {
    protocolo.enviar(UUIDEvento_);
    protocolo.enviar(cantidadPartidas_);
}

void EventoPartidaAgregada::actualizar(Handler& handler) {
    handler.manejar(*this);
}
