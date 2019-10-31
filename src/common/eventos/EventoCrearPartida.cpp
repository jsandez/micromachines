#include "includes/common/eventos/EventoCrearPartida.h"

#include "includes/common/Handler.h"

EventoCrearPartida::EventoCrearPartida(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
}

void EventoCrearPartida::enviarse(Protocolo& protocolo) {

}

void EventoCrearPartida::actualizar(Handler& handler) {
    handler.manejar(*this);
}
