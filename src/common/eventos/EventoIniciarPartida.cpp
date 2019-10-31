#include "includes/common/eventos/EventoIniciarPartida.h"

#include "includes/common/Handler.h"

EventoIniciarPartida::EventoIniciarPartida(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
}

void EventoIniciarPartida::enviarse(Protocolo& protocolo) {

}

void EventoIniciarPartida::actualizar(Handler& handler) {
    handler.manejar(*this);
}
