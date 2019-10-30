#include "includes/common/eventos/EventoAcelerar.h"

EventoAcelerar::EventoAcelerar(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {

}

void EventoAcelerar::enviarse(Protocolo& protocolo) {

}

void EventoAcelerar::actualizar(Handler& handler) {
    handler.manejar(*this);
}
