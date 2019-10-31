#include "includes/common/eventos/EventoPartidaAgregada.h"

#include "includes/common/Handler.h"

EventoPartidaAgregada::EventoPartidaAgregada(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
}

EventoPartidaAgregada::EventoPartidaAgregada(uint32_t uuidRemitente, uint16_t cantidadPartidas) :
    Evento(uuidRemitente),
    cantidadPartidas_(cantidadPartidas) {

}

void EventoPartidaAgregada::enviarse(Protocolo& protocolo) {

}

void EventoPartidaAgregada::actualizar(Handler& handler) {
    handler.manejar(*this);
}
