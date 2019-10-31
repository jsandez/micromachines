#include "includes/common/eventos/EventoUnirseAPartida.h"

#include "includes/common/Handler.h"

EventoUnirseAPartida::EventoUnirseAPartida(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
}

void EventoUnirseAPartida::enviarse(Protocolo& protocolo) {

}

void EventoUnirseAPartida::actualizar(Handler& handler) {
    handler.manejar(*this);
}
